package org.elsys.themp;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class EnterName extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		this.requestWindowFeature(Window.FEATURE_NO_TITLE); // no activity name
		setContentView(R.layout.activity_enter_name);
		
		Button button = (Button) findViewById(R.id.buttonName1);
		final EditText edText = (EditText) findViewById(R.id.editText1);

		button.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View arg0) {
				String name = edText.getText().toString();
				if (name.length() == 0) {
					name = "Playlist Number " + (fileList().length + 1);
				}
				//for playlistactivity.class
				
				
				Intent in = new Intent();
				
				in.putExtra("name", name);
				
				setResult(5, in);

				finish();

			}
		});
	}

}
