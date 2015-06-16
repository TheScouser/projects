using UnityEngine;
using System.Collections;

public class NetworkManager : MonoBehaviour
{
    private const string typeName = "Mobile Racer";
    private const string gameName = "Room";

    private bool isRefreshingHostList = false;
    private HostData[] hostList;
	
    public GameObject playerPrefab;
	public GameObject playerPrefab2;
	private GameObject camera;
	private GameObject car;
	private bool isWhite;
	private bool speed = false;
	private Transform Sp1;
	private Transform Sp2;
	private Transform target2;
	private CarCamera cc;
    void OnGUI()
    {
        if (!Network.isClient && !Network.isServer)
        {
			if (GUI.Button(new Rect(Screen.width/12, Screen.height/11, Screen.width/6, Screen.height/6), "Start Server"))
                StartServer();
			
			if (GUI.Button(new Rect(Screen.width/4, Screen.height/11, Screen.width/6, Screen.height/6), "Red car"))
                isWhite = false;
			
			if (GUI.Button(new Rect(Screen.width/4, Screen.height/4, Screen.width/6, Screen.height/6), "White car"))
                isWhite = true;
			if (GUI.Button(new Rect(Screen.width/12, Screen.height/4, Screen.width/6, Screen.height/6), "Refresh Hosts"))
                RefreshHostList();

            if (hostList != null)
            {
                for (int i = 0; i < hostList.Length; i++)
                {
                    if (GUI.Button(new Rect(Screen.width/2, (Screen.height/11) * i , Screen.width/6, Screen.height/6), hostList[i].gameName))
                        JoinServer(hostList[i]);
                }
            }
        }
    }

    private void StartServer()
    {
        Network.InitializeServer(2, 25000, !Network.HavePublicAddress());
        MasterServer.RegisterHost(typeName, gameName);
    }

    void OnServerInitialized()
    {	
     	SpawnPlayer();		
    }


    void Update()
    {
        if (isRefreshingHostList && MasterServer.PollHostList().Length > 0)
        {
            isRefreshingHostList = false;
            hostList = MasterServer.PollHostList();
        }
    }

    private void RefreshHostList()
    {
        if (!isRefreshingHostList)
        {
            isRefreshingHostList = true;
            MasterServer.RequestHostList(typeName);
        }
    }


    private void JoinServer(HostData hostData)
    {
        Network.Connect(hostData);
    }

    void OnConnectedToServer()
    {		
        SpawnPlayer2();			
    }

	private void SpawnPlayer()
    {	
		GameObject camera = GameObject.Find("Main_Camera");
        CarCamera cameraScript = camera.GetComponent<CarCamera>();
        Sp1 = GameObject.Find("Sp1").transform;
		if(!isWhite)
		{		
			car = Network.Instantiate(playerPrefab, Sp1.position, Sp1.rotation, 0) as GameObject;
			target2 = car.transform;
			cameraScript.target = target2;
		}
		else
		{		
			car = Network.Instantiate(playerPrefab2, Sp1.position, Sp1.rotation, 0) as GameObject;
			target2 = car.transform;
			cameraScript.target = target2;		
		}
    }
 	private void SpawnPlayer2()
    {	
		GameObject camera = GameObject.Find("Main_Camera");
        CarCamera cameraScript = camera.GetComponent<CarCamera>();
	Sp2 = GameObject.Find("Sp2").transform;
		if(!isWhite)
		{		
			car = Network.Instantiate(playerPrefab, Sp2.position, Sp2.rotation, 0) as GameObject;
			target2 = car.transform;
			cameraScript.target = target2;	
		}
		else
		{		
			car = Network.Instantiate(playerPrefab2, Sp2.position, Sp2.rotation, 0) as GameObject;	
			target2 = car.transform;
			cameraScript.target = target2;	
		}
    }
	
}
