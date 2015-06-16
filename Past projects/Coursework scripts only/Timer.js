private var startTimer;
private var Timer : int;
private var roundedTimer : int;
private var Current;
private var displaySeconds : int;
private var displayMinutes : int;
private var Last;
private var LastMinutes : int;
private var LastSeconds : int;
private var Best;
private var BestMinutes : int;
private var BestSeconds : int;
private var Lastlap;
private var currentTime : float;
var startTimer2 : float;
var font : Font;

function OnTriggerExit(car : Collider)  
{
	startTimer = Time.time;
}

function OnTriggerEnter(car : Collider)
{
	LastMinutes = displayMinutes;
	LastSeconds = displaySeconds;
	Lastlap = ((LastMinutes*60) + LastSeconds);
}

function OnGUI () 

{
	startTimer2 = startTimer;
	var currentTime = Time.time - startTimer2;
    Timer = currentTime;
	roundedTimer = Mathf.CeilToInt(Timer);
	displaySeconds = roundedTimer % 60;
	displayMinutes = roundedTimer / 60; 

Current = String.Format ("{0:00}:{1:00}", displayMinutes, displaySeconds);

    GUI.BeginGroup (Rect (540,10,200,200));
	GUI.skin.font = font;
	GUI.contentColor = Color.black;
	GUI.Label (Rect (0, 0, 150, 50), "Current Lap:" +(Current));
	GUI.EndGroup ();

Last = String.Format("{0:00}:{1:00}", LastMinutes, LastSeconds);

    GUI.BeginGroup (Rect (540,10,200,200));
	GUI.skin.font = font;
	GUI.contentColor = Color.black;
	GUI.Label (Rect (0, 20, 150, 50), "Last Lap:" +(Last));
 	GUI.EndGroup ();

   if(BestMinutes > LastMinutes)
	{
    	BestMinutes = LastMinutes;
		BestSeconds = LastSeconds;
	}
	else if(BestMinutes == LastMinutes)
	{
		if(BestSeconds == 0){
			BestSeconds = LastSeconds;
		}
	 	if(BestSeconds > LastSeconds)
	 	{
	 		BestSeconds = LastSeconds;
	 	}
	}

Best = String.Format("{0:00}:{1:00}", BestMinutes, BestSeconds);

    GUI.BeginGroup (Rect (540,10,200,200));
	GUI.skin.font = font;
 	GUI.contentColor = Color.black;
 	GUI.Label (Rect (0, 40, 150, 50), "Best Lap:" +(Best));
	GUI.EndGroup ();
}