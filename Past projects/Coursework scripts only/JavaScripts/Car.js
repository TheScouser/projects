private var wheelRadius : float = 0.4;
var suspensionRange : float = 0.1;
var suspensionDamper : float = 50;
var suspensionSpringFront : float = 18500;
var suspensionSpringRear : float = 9000;

var topSpeed : float = 160;
var numberOfGears : int = 5;
var maximumTurn : int = 15;
var minimumTurn : int = 10;
var resetTime : float = 5.0;
var centerOfMass : Transform;
var frontWheels : Transform[];
var rearWheels : Transform[];
var dragMultiplier : Vector3 = new Vector3(2, 5, 1);
var throttle : float = 0; 
private var accel : Vector3;
private var deadZone : float = 0.001;
public var brakeLights : Material;
private var steer : float = 0;
private var handbrake : boolean = false;
private var wheels : Wheel[];
wheels = new Wheel[frontWheels.Length + rearWheels.Length];
private var wheelFrictionCurve : WheelFrictionCurve;

private var resetTimer : float = 0.0;
private var engineForceValues : float[];
private var gearSpeeds : float[];
private var currentGear : int;
private var currentEnginePower : float = 0.0;
private var initialDragMultiplierX : float = 10.0;
private var skidmarks : Skidmarks = null;
private var skidSmoke : ParticleEmitter = null;
var skidmarkTime : float[];
private var sound : SoundController = null;
sound = transform.GetComponent(SoundController);
private var canSteer : boolean;
private var canDrive : boolean;
private var syncPosition : Vector3;
private var lastSynchronizationTime : float = 0f;
private var syncDelay : float = 0f;
private var syncTime : float = 0f;
private var syncStartPosition : Vector3 = Vector3.zero;
private var syncEndPosition : Vector3 = Vector3.zero;


class Wheel
{
	var collider : WheelCollider;
	var wheelGraphic : Transform;
	var tireGraphic : Transform;
	var driveWheel : boolean = false;
	var steerWheel : boolean = false;
	var lastSkidmark : int = -1;
	var lastEmitPosition : Vector3 = Vector3.zero;
	var lastEmitTime : float = Time.time;
	var wheelVelo : Vector3 = Vector3.zero;
	var groundSpeed : Vector3 = Vector3.zero;
}


function OnSerializeNetworkView(stream : BitStream , info : NetworkMessageInfo)
{
    var syncPosition : Vector3  = Vector3.zero;
     var syncVelocity : Vector3  = Vector3.zero;
    if (stream.isWriting)
    {
        syncPosition = rigidbody.position;
        stream.Serialize(syncPosition);
 
        syncVelocity = rigidbody.velocity;
        stream.Serialize(syncVelocity);
    }
    else
    {
        stream.Serialize(syncPosition);
        stream.Serialize(syncVelocity);
 
        syncTime = 0f;
        syncDelay = Time.time - lastSynchronizationTime;
        lastSynchronizationTime = Time.time;
 
        syncEndPosition = syncPosition + syncVelocity * syncDelay;
        syncStartPosition = rigidbody.position;
    }
}


function Start()
{	
	
	var accelerationTimer = Time.time;
	InitializeWheelColliders();
	InitializeCenterOfMass();
	topSpeed = Convert_Miles_Per_Hour_To_Meters_Per_Second(topSpeed);
	InitializeGears();
	InitializeSkidmarks();
	initialDragMultiplierX = dragMultiplier.x;
}

function Update()
{		
	var relativeVelocity : Vector3 = transform.InverseTransformDirection(rigidbody.velocity);
		
	if (networkView.isMine)
    {
        GetInput();
    }
    else
    {
        SyncedMovement();
    }	
	isCarFlipped();
	
	UpdateWheelGraphics(relativeVelocity);
	
	UpdateGear(relativeVelocity);
}

function FixedUpdate()
{	
	// The rigidbody velocity is always given in world space, but in order to work in local space of the car model we need to transform it first.
	var relativeVelocity : Vector3 = transform.InverseTransformDirection(rigidbody.velocity);
	
	CalculateState();	
	
	UpdateFriction(relativeVelocity);
	
	UpdateDrag(relativeVelocity);
	
	CalculateEnginePower(relativeVelocity);
	
	ApplyThrottle(canDrive, relativeVelocity);
	
	ApplySteering(canSteer, relativeVelocity);
}

function SyncedMovement() 
{
    syncTime += Time.deltaTime;
    rigidbody.position = Vector3.Lerp(syncStartPosition, syncEndPosition, syncTime / syncDelay);
}



/**************************************************/
/* Functions called from Start()                  */
/**************************************************/

function InitializeWheelColliders()
{
	InitializeWheelFrictionCurve();
		
	var wheelCount : int = 0;
	
	for (var t : Transform in frontWheels)
	{
		wheels[wheelCount] = InitializeWheel(t, true);
		wheelCount++;
	}
	
	for (var t : Transform in rearWheels)
	{
		wheels[wheelCount] = InitializeWheel(t, false);
		wheelCount++;
	}
}

function InitializeWheelFrictionCurve()
{
	wheelFrictionCurve = new WheelFrictionCurve();
	wheelFrictionCurve.extremumSlip = 1;
	wheelFrictionCurve.extremumValue = 50;
	wheelFrictionCurve.asymptoteSlip = 2;
	wheelFrictionCurve.asymptoteValue = 25;
	wheelFrictionCurve.stiffness = 1;
}

function InitializeWheel(wheelTransform : Transform, isFrontWheel : boolean)
{
	var gameObject : GameObject = new GameObject(wheelTransform.name + " Collider");
	gameObject.transform.position = wheelTransform.position;
	gameObject.transform.parent = transform;
	gameObject.transform.rotation = wheelTransform.rotation;
		
	var wheelCollider : WheelCollider = gameObject.AddComponent(typeof(WheelCollider)) as WheelCollider;
	wheelCollider.suspensionDistance = suspensionRange;
	var jointSpring : JointSpring = wheelCollider.suspensionSpring; 
	
	if (isFrontWheel)
		jointSpring.spring = suspensionSpringFront;
	else
		jointSpring.spring = suspensionSpringRear;
		
	jointSpring.damper = suspensionDamper;
	wheelCollider.suspensionSpring = jointSpring;
		
	var wheel = new Wheel(); 
	wheel.collider = wheelCollider;
	wheelCollider.sidewaysFriction = wheelFrictionCurve;
	wheel.wheelGraphic = wheelTransform;
	wheel.tireGraphic = wheelTransform.GetComponentsInChildren(Transform)[1];
	
	wheelRadius = wheel.tireGraphic.renderer.bounds.size.y / 2;	
	wheel.collider.radius = wheelRadius;
	
	if (isFrontWheel)
	{
		wheel.steerWheel = true;
		
		gameObject = new GameObject(wheelTransform.name + " Steer Column");
		gameObject.transform.position = wheelTransform.position;
		gameObject.transform.rotation = wheelTransform.rotation;
		gameObject.transform.parent = transform;
		wheelTransform.parent = gameObject.transform;
	}
	else
		wheel.driveWheel = true;
		
	return wheel;
}

function InitializeSkidmarks()
{
	if(FindObjectOfType(Skidmarks))
	{
		skidmarks = FindObjectOfType(Skidmarks);
		skidSmoke = skidmarks.GetComponentInChildren(ParticleEmitter);
	}
	else
		Debug.Log("No skidmarks object found. Skidmarks will not be drawn");
		
	skidmarkTime = new float[4];
	for (var f : float in skidmarkTime)
		f = 0.0;
}


function InitializeGears()
{
	engineForceValues = new float[numberOfGears];
	gearSpeeds = new float[numberOfGears];
	
	var tempTopSpeed : float = topSpeed;
		
	for(var i = 0; i < numberOfGears; i++)
	{
		if(i > 0)
			gearSpeeds[i] = tempTopSpeed / 4 + gearSpeeds[i-1];
		else
			gearSpeeds[i] = tempTopSpeed / 4;
		
		tempTopSpeed -= tempTopSpeed / 4;
	}
	
	var engineFactor : float = topSpeed / gearSpeeds[gearSpeeds.Length - 1];
	
	for(i = 0; i < numberOfGears; i++)
	{
		var maxLinearDrag : float = gearSpeeds[i] * gearSpeeds[i];// * dragMultiplier.z;
		engineForceValues[i] = maxLinearDrag * engineFactor;
	}
}



function InitializeCenterOfMass()
{
	if(centerOfMass != null)
		rigidbody.centerOfMass = centerOfMass.localPosition;
}

/**************************************************/
/* Functions called from Update()                 */
/**************************************************/
private var deviceAccelerometerSensitivity : float = 2;
function GetInput()
{
	if (Input.GetKey(KeyCode.Escape))

            {
           		Network.Disconnect();
			MasterServer.UnregisterHost();
				Application.LoadLevel(0);
				
                return;

            }
	if( Application.platform == RuntimePlatform.IPhonePlayer || Application.platform == RuntimePlatform.Android)
	{
	
	  
	
		accel = Input.acceleration * deviceAccelerometerSensitivity;
		if(accel.x > deadZone || accel.x < -deadZone){
			steer = accel.x;
		}
		else{
			steer = 0;
		}
		throttle = 0;
		for(var touch : Touch in Input.touches){
			if(touch.position.x > Screen.width - Screen.width/3 && touch.position.y < Screen.height/3)
			{
				throttle = 1;
			}
			else if(touch.position.x < Screen.width - Screen.width/3 && touch.position.y < Screen.height/3)
			{
				throttle = -1;
			}
		}
	}	
	else if (Application.platform == RuntimePlatform.WindowsEditor || RuntimePlatform.WindowsWebPlayer)
	{
		steer = Input.GetAxis("Horizontal");
		throttle = Input.GetAxis("Vertical");
	}	
	if(throttle < 0.0)
		brakeLights.SetFloat("_Intensity", Mathf.Abs(throttle));
	else
		brakeLights.SetFloat("_Intensity", 0.0);
}


function isCarFlipped()
{
	if(transform.localEulerAngles.z > 80 && transform.localEulerAngles.z < 280)
		resetTimer += Time.deltaTime;
	else
		resetTimer = 0;
	
	if(resetTimer > resetTime)
		FlipCar();
}

function FlipCar()
{
	transform.rotation = Quaternion.LookRotation(transform.forward);
	transform.position += Vector3.up * 0.5;
	rigidbody.velocity = Vector3.zero;
	rigidbody.angularVelocity = Vector3.zero;
	resetTimer = 0;
	currentEnginePower = 0;
}

var wheelCount : float;
function UpdateWheelGraphics(relativeVelocity : Vector3)
{
    wheelCount = -1;
 
    for(var w : Wheel in wheels)
    {
       wheelCount++;
       var wheel : WheelCollider = w.collider;
       var wh : WheelHit = new WheelHit();
 
       // First we get the velocity at the point where the wheel meets the ground, if the wheel is touching the ground
       if(wheel.GetGroundHit(wh))
       {
         w.wheelGraphic.localPosition = wheel.transform.up * (wheelRadius + wheel.transform.InverseTransformPoint(wh.point).y);
         w.wheelVelo = rigidbody.GetPointVelocity(wh.point);
         w.groundSpeed = w.wheelGraphic.InverseTransformDirection(w.wheelVelo);
 
         
         if(skidmarks)
         {
          if(skidmarkTime[wheelCount] < 0.02 && w.lastSkidmark != -1)
          {
              skidmarkTime[wheelCount] += Time.deltaTime;
          }
          else
          {
              var dt : float = skidmarkTime[wheelCount] == 0.0 ? Time.deltaTime : skidmarkTime[wheelCount];
              skidmarkTime[wheelCount] = 0.0;
 
              var handbrakeSkidding : float = handbrake && w.driveWheel ? w.wheelVelo.magnitude * 0.3 : 0;
              var skidGroundSpeed = Mathf.Abs(w.groundSpeed.x) - 15;
              if(skidGroundSpeed > 0 || handbrakeSkidding > 0)
              {
                 var staticVel : Vector3 = transform.TransformDirection(skidSmoke.localVelocity) + skidSmoke.worldVelocity;
                 if(w.lastSkidmark != -1)
                 {
                   var emission : float = UnityEngine.Random.Range(skidSmoke.minEmission, skidSmoke.maxEmission);
                   var lastParticleCount : float = w.lastEmitTime * emission;
                   var currentParticleCount : float = Time.time * emission;
                   var noOfParticles : int = Mathf.CeilToInt(currentParticleCount) - Mathf.CeilToInt(lastParticleCount);
                   var lastParticle : int = Mathf.CeilToInt(lastParticleCount);
 
                   for(var i = 0; i <= noOfParticles; i++)
                   {
                    var particleTime : float = Mathf.InverseLerp(lastParticleCount, currentParticleCount, lastParticle + i);
                    skidSmoke.Emit( Vector3.Lerp(w.lastEmitPosition, wh.point, particleTime) + new Vector3(Random.Range(-0.1, 0.1), Random.Range(-0.1, 0.1), Random.Range(-0.1, 0.1)), staticVel + (w.wheelVelo * 0.05), Random.Range(skidSmoke.minSize, skidSmoke.maxSize) * Mathf.Clamp(skidGroundSpeed * 0.1,0.5,1), Random.Range(skidSmoke.minEnergy, skidSmoke.maxEnergy), Color.white);
                   }
                 }
                 else
                 {
                   skidSmoke.Emit(  wh.point + new Vector3(Random.Range(-0.1, 0.1), Random.Range(-0.1, 0.1), Random.Range(-0.1, 0.1)), staticVel + (w.wheelVelo * 0.05), Random.Range(skidSmoke.minSize, skidSmoke.maxSize) * Mathf.Clamp(skidGroundSpeed * 0.1,0.5,1), Random.Range(skidSmoke.minEnergy, skidSmoke.maxEnergy), Color.white);
                 }
 
                 w.lastEmitPosition = wh.point;
                 w.lastEmitTime = Time.time;
 
                 w.lastSkidmark = skidmarks.AddSkidMark(wh.point + rigidbody.velocity * dt, wh.normal, (skidGroundSpeed * 0.1 + handbrakeSkidding) * Mathf.Clamp01(wh.force / wheel.suspensionSpring.spring), w.lastSkidmark);
                 sound.Skid(true, Mathf.Clamp01(skidGroundSpeed * 0.1));
              }
              else
              {
                 w.lastSkidmark = -1;
                 sound.Skid(false, 0);
              }
          }
         }
       }
       else
       {
         // If the wheel is not touching the ground we set the position of the wheel graphics to
         // the wheel's transform position + the range of the suspension.
         w.wheelGraphic.position = wheel.transform.position + (-wheel.transform.up * suspensionRange);
         if(w.steerWheel)
          w.wheelVelo *= 0.9;
         else
          w.wheelVelo *= 0.9 * (1 - throttle);
 
         if(skidmarks)
         {
          w.lastSkidmark = -1;
          sound.Skid(false, 0);
         }
       }
      
       if(w.steerWheel)
       {
         var ea : Vector3 = w.wheelGraphic.parent.localEulerAngles;
         ea.y = steer * maximumTurn;
         w.wheelGraphic.parent.localEulerAngles = ea;
         w.tireGraphic.Rotate(Vector3.right * (w.groundSpeed.z / wheelRadius) * Time.deltaTime * Mathf.Rad2Deg);
       }
       else if(!handbrake && w.driveWheel)
       {
         w.tireGraphic.Rotate(Vector3.right * (w.groundSpeed.z / wheelRadius) * Time.deltaTime * Mathf.Rad2Deg);
       }
    }
}

function UpdateGear(relativeVelocity : Vector3)
{
	currentGear = 0;
	for(var i = 0; i < numberOfGears - 1; i++)
	{
		if(relativeVelocity.z > gearSpeeds[i])
			currentGear = i + 1;
	}
}

/**************************************************/
/* Functions called from FixedUpdate()            */
/**************************************************/

function UpdateFriction(relativeVelocity : Vector3)
{
	var sqrVel : float = relativeVelocity.x * relativeVelocity.x;
	
	// Add extra sideways friction based on the car's turning velocity to avoid slipping
	wheelFrictionCurve.extremumValue = Mathf.Clamp(300 - sqrVel, 0, 300);
	wheelFrictionCurve.asymptoteValue = Mathf.Clamp(150 - (sqrVel / 2), 0, 150);
		
	for(var w : Wheel in wheels)
	{
		w.collider.sidewaysFriction = wheelFrictionCurve;
		w.collider.forwardFriction = wheelFrictionCurve;
	}
}

function CalculateEnginePower(relativeVelocity : Vector3)
{
	if(throttle == 0)
	{
		currentEnginePower -= Time.deltaTime * 200;
	}
	else if( HaveTheSameSign(relativeVelocity.z, throttle) )
	{
		var normPower = (currentEnginePower / engineForceValues[engineForceValues.Length - 1]) * 2;
		currentEnginePower += Time.deltaTime * 200 * EvaluateNormPower(normPower);
	}
	else
	{
		currentEnginePower -= Time.deltaTime * 300;
	}
	
	if(currentGear == 0)
		currentEnginePower = Mathf.Clamp(currentEnginePower, 0, engineForceValues[0]);
	else
		currentEnginePower = Mathf.Clamp(currentEnginePower, engineForceValues[currentGear - 1], engineForceValues[currentGear]);
}

function UpdateDrag(relativeVelocity : Vector3)
{
	var relativeDrag : Vector3 = new Vector3(	-relativeVelocity.x * Mathf.Abs(relativeVelocity.x), 
												-relativeVelocity.y * Mathf.Abs(relativeVelocity.y), 
												-relativeVelocity.z * Mathf.Abs(relativeVelocity.z) );
	
	var drag = Vector3.Scale(dragMultiplier, relativeDrag);
		
	
		drag.x *= topSpeed / relativeVelocity.magnitude;
	
	
	if(Mathf.Abs(relativeVelocity.x) < 5 && !handbrake)
		drag.x = -relativeVelocity.x * dragMultiplier.x;
		

	rigidbody.AddForce(transform.TransformDirection(drag) * rigidbody.mass * Time.deltaTime);
}





function CalculateState()
{
	canDrive = false;
	canSteer = false;
	
	for(var w : Wheel in wheels)
	{
		if(w.collider.isGrounded)
		{
			if(w.steerWheel)
				canSteer = true;
			if(w.driveWheel)
				canDrive = true;
		}
	}
}

function ApplySteering(canSteer : boolean, relativeVelocity : Vector3)
{
	if(canSteer)
	{
		var turningRadius : float = 3.0 / Mathf.Sin((90 - (steer * 30)) * Mathf.Deg2Rad);
		var minimalMaximalTurn : float = EvaluateSpeedToTurn(rigidbody.velocity.magnitude);
		var turningSpeed : float = Mathf.Clamp(relativeVelocity.z / turningRadius, -minimalMaximalTurn / 10, minimalMaximalTurn / 10);
		
		transform.RotateAround(	transform.position + transform.right * turningRadius * steer, 
								transform.up, 
								turningSpeed * Mathf.Rad2Deg * Time.deltaTime * steer);
		
		if(initialDragMultiplierX > dragMultiplier.x) 
		{
			var rotationDirection : float = Mathf.Sign(steer); // rotationDirection is -1 or 1 by default, depending on steering
			if(steer == 0)
			{
				if(rigidbody.angularVelocity.y < 1) 
					rotationDirection = Random.Range(-1.0, 1.0);
				else
					rotationDirection = rigidbody.angularVelocity.y; // If we are rotating fast we are applying that rotation to the car
			}
			//Finally apply this rotation around a point between the cars front wheels.
			transform.RotateAround( transform.TransformPoint( (	frontWheels[0].localPosition + frontWheels[1].localPosition) * 0.5), 
																transform.up, 
																rigidbody.velocity.magnitude * Mathf.Clamp01(1 - rigidbody.velocity.magnitude / topSpeed) * rotationDirection * Time.deltaTime * 2);
		}
	}
}


function ApplyThrottle(canDrive : boolean, relativeVelocity : Vector3)
{
	if(canDrive)
	{
		var throttleForce : float = 0;
		var brakeForce : float = 0;
		
		if (HaveTheSameSign(relativeVelocity.z, throttle))
		{
			if (!handbrake)
				throttleForce = Mathf.Sign(throttle) * currentEnginePower * rigidbody.mass;
		}
		else
			brakeForce = Mathf.Sign(throttle) * engineForceValues[0] * rigidbody.mass;
		
		rigidbody.AddForce(transform.forward * Time.deltaTime * (throttleForce + brakeForce));
	}
}



/**************************************************/
/*               Utility Functions                */
/**************************************************/

function Convert_Miles_Per_Hour_To_Meters_Per_Second(value : float) : float
{
	return value * 0.44704;
}

function Convert_Meters_Per_Second_To_Miles_Per_Hour(value : float) : float
{
	return value * 2.23693629;	
}

function HaveTheSameSign(first : float, second : float) : boolean
{
	if (Mathf.Sign(first) == Mathf.Sign(second))
		return true;
	else
		return false;
}

function EvaluateSpeedToTurn(speed : float)
{
	if(speed > topSpeed / 2)
		return minimumTurn;
	
	var speedIndex : float = 1 - (speed / (topSpeed / 2));
	return minimumTurn + speedIndex * (maximumTurn - minimumTurn);
}

function EvaluateNormPower(normPower : float)
{
	if(normPower < 1)
		return 10 - normPower * 9;
	else
		return 1.9 - normPower * 0.9;
}

function GetGearState()
{
	var relativeVelocity : Vector3 = transform.InverseTransformDirection(rigidbody.velocity);
	var lowLimit : float = (currentGear == 0 ? 0 : gearSpeeds[currentGear-1]);
	return (relativeVelocity.z - lowLimit) / (gearSpeeds[currentGear - lowLimit]) * (1 - currentGear * 0.1) + currentGear * 0.1;
}