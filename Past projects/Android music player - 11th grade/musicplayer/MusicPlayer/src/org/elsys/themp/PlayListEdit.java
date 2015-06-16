package org.elsys.themp;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.StreamCorruptedException;
import java.util.ArrayList;
import java.util.HashMap;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.Button;
import android.widget.ListView;
import android.widget.Toast;

public class PlayListEdit extends Activity {

	private String playlist_name;
	private Button add_songs;
	private Button done;
	private ListView lv;
	private ArrayList<Files> songs;
	
	public ArrayList<HashMap<String, String>> songsListArr = new ArrayList<HashMap<String, String>>();
	
	
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_play_list_edit);
		this.setTitle("Remove Songs:");
		lv=(ListView) findViewById(R.id.listView_edit_playlist);
		done=(Button) findViewById(R.id.button_done);
		add_songs= (Button) findViewById(R.id.button_add_songs);
		
		Intent it=getIntent();
		playlist_name=it.getExtras().getString("name");
		
		
		
		try {
			FileInputStream fis;
			fis = openFileInput(playlist_name);
			ObjectInputStream ois = new ObjectInputStream(fis);
			songs = (ArrayList<Files>) ois.readObject();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (StreamCorruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		print_songs();
	
		add_songs.setOnClickListener(new OnClickListener(){
			
			@Override
			public void onClick(View v) {
				Intent it=new Intent(PlayListEdit.this,FilesExplorer.class);
				it.putExtra("songs", songs);
				startActivityForResult(it,5);
			}
			
		});
		
		
		lv.setOnItemClickListener(new OnItemClickListener(){

			@Override
			public void onItemClick(AdapterView<?> arg0, View arg1, final int arg2,
					long arg3) {
				
				new AlertDialog.Builder(PlayListEdit.this)
				.setMessage("Are you sure you want to delete: " + songs.get(arg2).getName() + " ?")
				.setPositiveButton("Yes",
						new DialogInterface.OnClickListener() {

							public void onClick(DialogInterface dialog,
									int which) {
									songs.remove(arg2);
									print_songs();
							}
						})
						.setNegativeButton("No",null)
						.show();
				
			}
			
		});
		
		done.setOnClickListener(new OnClickListener(){

			@Override
			public void onClick(View v) {
				writePlaylist(playlist_name);
				Intent in = new Intent();
				setResult(505, in);

				finish();
			}
			
		});
	
	}
	
	private void writePlaylist(String name) {
		try {
			FileOutputStream fos = openFileOutput(name, Context.MODE_PRIVATE);

			ObjectOutputStream oos = new ObjectOutputStream(fos);
			oos.writeObject(songs);

			fos.close();
			Toast.makeText(getApplicationContext(), name + " was saved!",
					Toast.LENGTH_SHORT).show();
		} catch (IOException e) {
			Toast.makeText(getApplicationContext(), name + " was NOT saved!",
					Toast.LENGTH_SHORT).show();
			e.printStackTrace();
		}

	}
	
	public void print_songs(){
		
		FileArrayAdapter adapter = new FileArrayAdapter(this,
				R.layout.custom_row_view, songs);

		lv.setAdapter(adapter);
	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		super.onActivityResult(requestCode, resultCode, data);
		
		if(resultCode==505){
			songs=data.getExtras().getParcelableArrayList("songs");
			print_songs();
		}
		
	}
	
	
}
