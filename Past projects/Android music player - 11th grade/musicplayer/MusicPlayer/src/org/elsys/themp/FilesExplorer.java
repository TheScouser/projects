package org.elsys.themp;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.AlertDialog.Builder;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;
import android.os.Environment;
import android.provider.MediaStore;
import android.view.GestureDetector;
import android.view.GestureDetector.SimpleOnGestureListener;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.SimpleAdapter;
import android.widget.Toast;

public class FilesExplorer extends Activity {
	private static final int SWIPE_MIN_DISTANCE = 120;
	private static final int SWIPE_MAX_OFF_PATH = 250;
	private static final int SWIPE_THRESHOLD_VELOCITY = 200;
	private GestureDetector gestureDetector;
	
	private File currentDir;
	List<Files> dir;

	ArrayList<Files> songs = new ArrayList<Files>();

	ListView listv;
	private boolean coming_from_edit=false;
	private Button button;
	private Button buttonMp3;
	private String name;

	boolean option;

	@SuppressWarnings("deprecation")
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_files_explorer);
		listv = (ListView) findViewById(R.id.listView1);
		button = (Button) findViewById(R.id.buttonName1);
		buttonMp3 = (Button) findViewById(R.id.button2);
		option = true;
		gestureDetector = new GestureDetector(new MyGestureDetector());
		final AlertDialog.Builder Mydialog = new AlertDialog.Builder(this);
		final EditText input = new EditText(this);

		currentDir = new File(Environment.getExternalStorageDirectory()
				.getPath());
		
		//check if there is incoming intent from activity like PlaylistEdit
		Intent it=getIntent();
		if(it.getExtras()!=null){
			songs=it.getExtras().getParcelableArrayList("songs");
			coming_from_edit=true;
		}
		fill(currentDir);

		listv.setOnTouchListener(new View.OnTouchListener() {
			public boolean onTouch(View v, MotionEvent event) {
				if (gestureDetector.onTouchEvent(event)) {
					return true;
				}
				return false;
			}
		});

		listv.setOnItemClickListener(new OnItemClickListener() {
			public void onItemClick(AdapterView<?> arg0, View arg1, int arg2,
					long arg3) {

				Files o = dir.get(arg2);
				if (o.getData().equalsIgnoreCase("folder")
						|| o.getData().equalsIgnoreCase("parent directory")) {
					currentDir = new File(o.getPath());
					fill(currentDir);
				} else {
					onFileClick(o);
				}

			}

		});

		buttonMp3.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) {
				if (option) {

					Cursor cursor = getMeadiaFromSD();
					fillMp3(cursor);

				} else {
					currentDir = new File(Environment
							.getExternalStorageDirectory().getPath());
					fill(currentDir);

				}

				option = !option;
			}

		});

		button.setOnClickListener(new OnClickListener() {
			public void onClick(View v) {
				// getting user name for the playlist
				if (songs.isEmpty()) {
					finish();
				}
				
				if(coming_from_edit==true){
					Intent in = new Intent();

					in.putExtra("songs", songs);
					setResult(505, in);

					finish();
				}else{
				
					Intent in = new Intent(FilesExplorer.this, EnterName.class);
					startActivityForResult(in, 5);
				}
			}
		});

	}

	private void fill(File f) {
		File[] dirs = f.listFiles();
		this.setTitle("Current Dir: " + f.getName());
		dir = new ArrayList<Files>();
		List<Files> fls = new ArrayList<Files>();
		try {
			for (File ff : dirs) {
				if (ff.isDirectory())
					dir.add(new Files(ff.getName(), "Folder", ff
							.getAbsolutePath()));
				else {
					if (ff.getName().endsWith(".mp3")) {
						fls.add(new Files(ff.getName(), "File Size: "
								+ (float) ff.length() / 1024.00 + " kb", ff
								.getAbsolutePath()));

					}
				}
			}
		} catch (Exception e) {

		}
		Collections.sort(dir);
		Collections.sort(fls);
		dir.addAll(fls);
		if (!f.getPath().equalsIgnoreCase(
				Environment.getExternalStorageDirectory().getAbsolutePath()))
			dir.add(0, new Files("..", "Parent Directory", f.getParent()));

		/*
		 * ArrayList<HashMap<String, String>> temp = new
		 * ArrayList<HashMap<String, String>>(); for (Files o : dir) {
		 * HashMap<String, String> ss = new HashMap<String, String>();
		 * ss.put("Name", o.getName()); ss.put("Data", o.getData());
		 * temp.add(ss); }
		 * 
		 * SimpleAdapter adapter = new SimpleAdapter(this, temp,
		 * R.layout.custom_row_view, new String[] { "Name", "Data" }, new int[]
		 * { R.id.text1, R.id.text2 });
		 */

		FileArrayAdapter adapter = new FileArrayAdapter(this,
				R.layout.custom_row_view, dir);
		listv.setAdapter(adapter);

	}

	/*
	 * protected void onListItemClick(ListView l, View v, int position, long id)
	 * { // TODO Auto-generated method stub super.onListItemClick(l, v,
	 * position, id); Option o = dir.get(position); if
	 * (o.getData().equalsIgnoreCase("folder") ||
	 * o.getData().equalsIgnoreCase("parent directory")) { currentDir = new
	 * File(o.getPath()); fill(currentDir); } else { onFileClick(o); }
	 * 
	 * }
	 */

	private void onFileClick(Files o) {

		if (isAlreadyAdded(o)) {
			new AlertDialog.Builder(this)
					.setMessage("Already Added!")
					.setNeutralButton("OK",
							new DialogInterface.OnClickListener() {

								public void onClick(DialogInterface dialog,
										int which) {

								}
							}).show();
		} else {

			songs.add(o);
			Toast.makeText(this, o.getName() + " was added!",
					Toast.LENGTH_SHORT).show();
		}
	}

	/*
	 * private boolean isAlreadyAdded(HashMap<String, String> song) { for
	 * (HashMap<String, String> temp : songs) { if
	 * (temp.get("songPath").equalsIgnoreCase(song.get("songPath"))) { return
	 * true; } }
	 * 
	 * return false; }
	 */

	private Cursor getMeadiaFromSD() {

		Cursor cursor = getContentResolver().query(
				MediaStore.Audio.Media.EXTERNAL_CONTENT_URI, null, null, null,
				null);

		return cursor;
	}

	private boolean isThereSuchPlaylist(String name) {
		String[] playlists = fileList();
		for (String temp : playlists) {
			if (temp.equals(name)) {
				return true;
			}

		}
		return false;
	}

	private boolean isAlreadyAdded(Files song) {
		for (Files temp : songs) {
			if (temp.getPath().equalsIgnoreCase(song.getPath())) {
				return true;
			}
		}

		return false;
	}

	private void fillMp3(Cursor cursor) {
		dir = new ArrayList<Files>();

		if (cursor.moveToFirst()) {

			for (cursor.moveToFirst(); !cursor.isAfterLast(); cursor
					.moveToNext()) {
				File file = new File(cursor.getString(1));
				Files temp = new Files(file.getName(), "File Size: "
						+ (float) file.length() / 1024.00 + " kb",
						file.getAbsolutePath());
				dir.add(temp);
			}

			FileArrayAdapter adapter = new FileArrayAdapter(this,
					R.layout.custom_row_view, dir);
			listv.setAdapter(adapter);

		}
	}

	@Override
	public void onBackPressed() {
		// TODO Auto-generated method stub
		if (currentDir.getAbsolutePath().equalsIgnoreCase(
				Environment.getExternalStorageDirectory().getAbsolutePath())
				&& option == true) {
			finish();

		} else if (currentDir.getAbsolutePath() != Environment
				.getExternalStorageDirectory().getPath() && option == true) {
			currentDir = currentDir.getParentFile();
			fill(currentDir);

		}
	}

	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		super.onActivityResult(requestCode, resultCode, data);
		if (resultCode == 5) {
			final String name = data.getExtras().getString("name");
			if (isThereSuchPlaylist(name)) {
				new AlertDialog.Builder(this)
						.setMessage("Do you want to Override: " + name + " ?")
						.setPositiveButton("Yes",
								new DialogInterface.OnClickListener() {

									public void onClick(DialogInterface dialog,
											int which) {
										writePlaylist(name);
									}
								})
								.setNegativeButton("No",null)
								.show();
			} else {
				writePlaylist(name);
			}
		}

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

		Intent in = new Intent();

		in.putExtra("songs", songs);
		setResult(50, in);

		finish();
	}

	class MyGestureDetector extends SimpleOnGestureListener {
		@Override
		public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX,
				float velocityY) {

			if (Math.abs(e1.getY() - e2.getY()) > SWIPE_MAX_OFF_PATH) {
				return false;
			}
			if (e2.getX() - e1.getX() > SWIPE_MIN_DISTANCE
					&& Math.abs(velocityX) > SWIPE_THRESHOLD_VELOCITY) {
				finish();
				FilesExplorer.this.overridePendingTransition(
						R.anim.slide_in_left, R.anim.slide_out_right);
			}

			return false;
		}
	}
}
