package org.elsys.themp;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.res.Resources;
import android.media.AudioManager;
import android.media.MediaPlayer;

import android.media.MediaPlayer.OnCompletionListener;
import android.media.MediaPlayer.OnErrorListener;
import android.net.Uri;
import android.os.Bundle;
import android.os.PowerManager;
import android.util.AttributeSet;
import android.util.Log;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;
import android.widget.MediaController;
import android.widget.VideoView;
import android.widget.MediaController.*;

import java.io.IOException;
import java.util.Map;

public class VideoPlayer extends Activity {
   private VideoView mVideoview;
		
   	
   public void onCreate(Bundle savedInstanceState)   
   {   
       super.onCreate(savedInstanceState);   
       setContentView(R.layout.main);  
       //get the VideoView from the layout file  
       mVideoview = (VideoView)findViewById(R.id.mVideoView);  
       //use this to get touch events  
       mVideoview.requestFocus();  
 
       Intent intent = getIntent();
       String path = intent.getExtras().getString("videofilename");
       mVideoview.setVideoPath(path);   
       mVideoview.setMediaController(new MediaController(this));  
       mVideoview.start();  
   }  
	
}