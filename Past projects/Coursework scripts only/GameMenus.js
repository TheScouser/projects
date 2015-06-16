#pragma strict


function OnGUI () {
	
	if (GUI.Button (Rect (Screen.width/2 - Screen.height/6,Screen.height/2 - Screen.height/3.5, Screen.width/3, Screen.height/7), "Race Track")) {
		Application.LoadLevel(1);
	}
	
	if (GUI.Button (Rect (Screen.width/2 - Screen.height/6,Screen.height/2 - Screen.height/7, Screen.width/3, Screen.height/7), "Arcade Track")) {
		Application.LoadLevel(2);
	}

	if (GUI.Button (Rect (Screen.width/2 - Screen.height/6,Screen.height/2, Screen.width/3, Screen.height/7), "Quit")) {
		Application.Quit();
	}
	
	
}