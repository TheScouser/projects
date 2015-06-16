package org.elsys.themp;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.ContextMenu;
import android.view.ContextMenu.ContextMenuInfo;
import android.view.GestureDetector;
import android.view.GestureDetector.SimpleOnGestureListener;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.AdapterView.OnItemLongClickListener;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

public class PlayListView extends Activity {
	private static final int SWIPE_MIN_DISTANCE = 120;
	private static final int SWIPE_MAX_OFF_PATH = 250;
	private static final int SWIPE_THRESHOLD_VELOCITY = 200;
	private GestureDetector gestureDetector;
	private Button button;
	private ListView lv;
	private String[] playlists;
	private int itemId; // so id of the chosen playlist can be saved, and later
						// be used in different parts of the program(like
						// "old name" in rename)

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		this.setTitle("Choose Playlist:");
		setContentView(R.layout.activity_play_list_view);
		gestureDetector = new GestureDetector(new MyGestureDetector());
		button = (Button) findViewById(R.id.button_create_new_playlist);
		lv = (ListView) findViewById(R.id.listview_playlists);
		registerForContextMenu(lv);
		showPlaylists();

		lv.setOnTouchListener(new View.OnTouchListener() {
			public boolean onTouch(View v, MotionEvent event) {
				if (gestureDetector.onTouchEvent(event)) {
					return true;
				}
				return false;
			}
		});

		lv.setOnItemClickListener(new OnItemClickListener() {

			@Override
			public void onItemClick(AdapterView<?> arg0, View arg1, int arg2,
					long arg3) {
				try {

					FileInputStream fis = openFileInput((String) lv
							.getItemAtPosition(arg2));
					ObjectInputStream ois = new ObjectInputStream(fis);
					ArrayList<Files> songs = (ArrayList<Files>) ois
							.readObject();
					Intent in = new Intent(getApplicationContext(),
							MainActivity.class);
					// Sending songIndex to PlayerActivity
					in.putExtra("songs", songs);
					setResult(10, in);
					// Closing PlayListView
					finish();

				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (ClassNotFoundException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}

			}
		});

		/*
		 * lv.setOnItemLongClickListener(new OnItemLongClickListener() {
		 * 
		 * @Override public boolean onItemLongClick(AdapterView<?> arg0, View
		 * arg1, final int arg2, long arg3) { new
		 * AlertDialog.Builder(PlayListView.this) .setMessage(
		 * "Are you sure you want to delete: " + (String)
		 * lv.getItemAtPosition(arg2)) .setPositiveButton("Yes", new
		 * DialogInterface.OnClickListener() {
		 * 
		 * public void onClick(DialogInterface dialog, int which) { File dir =
		 * getFilesDir(); File file = new File(dir, (String) lv
		 * .getItemAtPosition(arg2)); file.delete();
		 * 
		 * showPlaylists();
		 * 
		 * } }).setNegativeButton("No", null).show();
		 * 
		 * return false; }
		 * 
		 * });
		 */

		button.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick(View v) {
				Intent i = new Intent(PlayListView.this, FilesExplorer.class);
				startActivityForResult(i, 50);

			}

		});
	}

	@Override
	public boolean onContextItemSelected(MenuItem item) {
		// used to get the item num from the listview
		AdapterView.AdapterContextMenuInfo info = (AdapterView.AdapterContextMenuInfo) item
				.getMenuInfo();
		itemId=info.position;
		if (item.getTitle() == "Delete") {
			deletePlaylist(itemId);
		} else if (item.getTitle() == "Rename") {
			renamePlaylist(itemId);
		}else if(item.getTitle() == "Edit"){
			editPlaylist(itemId);
		}else {
			return false;
		}
		return true;
	}

	private void editPlaylist(int Id) {
		Intent in = new Intent(getApplicationContext(), PlayListEdit.class);
		in.putExtra("name", (String) lv.getItemAtPosition(Id));
		startActivityForResult(in, 5);
		
	}

	private void renamePlaylist(int Id) {
		
		Intent in = new Intent(getApplicationContext(), EnterName.class);
		in.putExtra("id", Id);
		startActivityForResult(in, 5);
		
	}

	private void deletePlaylist(final int Id) {
		new AlertDialog.Builder(PlayListView.this)
				.setMessage(
						"Are you sure you want to delete: "
								+ (String) lv.getItemAtPosition(Id))
				.setPositiveButton("Yes",
						new DialogInterface.OnClickListener() {

							public void onClick(DialogInterface dialog,
									int which) {
								File dir = getFilesDir();
								File file = new File(dir, (String) lv
										.getItemAtPosition(Id));
								file.delete();

								showPlaylists();

							}
						}).setNegativeButton("No", null).show();

	}

	@Override
	public void onCreateContextMenu(ContextMenu menu, View v,
			ContextMenuInfo menuInfo) {
		super.onCreateContextMenu(menu, v, menuInfo);
		menu.setHeaderTitle("Choose option:");
		menu.add(0, v.getId(), 0, "Rename");
		menu.add(0, v.getId(), 0, "Delete");
		menu.add(0, v.getId(), 0, "Edit");
	}

	private void showPlaylists() {
		playlists = fileList();
		if (playlists.length == 0) {
			new AlertDialog.Builder(this)
					.setMessage("You Dont have Any PlayLists !")
					.setNeutralButton("Create playlist",
							new DialogInterface.OnClickListener() {

								public void onClick(DialogInterface dialog,
										int which) {
									Intent i = new Intent(
											getApplicationContext(),
											FilesExplorer.class);
									startActivityForResult(i, 50);
								}
							}).show();
		}

		ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
				android.R.layout.simple_list_item_1, android.R.id.text1,
				playlists);

		lv.setAdapter(adapter);
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

	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		super.onActivityResult(requestCode, resultCode, data);
		if (resultCode == 50) {
			Intent in = new Intent(getApplicationContext(), MainActivity.class);
			// Sending songIndex to PlayerActivity
			in.putExtra("songs",
					data.getExtras().getParcelableArrayList("songs"));
			setResult(10, in);
			// Closing PlayListView
			finish();
		}
		if (resultCode == 5) {
			
			final String name = data.getExtras().getString("name");
			
			//playlists = fileList();
			if (isThereSuchPlaylist(name)) {
				new AlertDialog.Builder(this)
						.setMessage("Do you want to Override: " + name + " ?")
						.setPositiveButton("Yes",
								new DialogInterface.OnClickListener() {

									public void onClick(DialogInterface dialog,
											int which) {
										writeRenamedPlaylist(playlists[itemId],
												name);
										showPlaylists();
									}
								}).setNegativeButton("No", null).show();
			} else {
				
				writeRenamedPlaylist(playlists[itemId],
						name);
				showPlaylists();
			}
		}

	}

	private void writeRenamedPlaylist(String oldOne, String newOne) {
		if (oldOne.equals(newOne)) {
			return;
		}
		File dir = getFilesDir();
		File oldFile = new File(dir, oldOne);
		File newFile = new File(dir, newOne);
		oldFile.renameTo(newFile);
		File file = new File(dir, oldOne);
		file.delete();
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
				PlayListView.this.overridePendingTransition(
						R.anim.slide_in_left, R.anim.slide_out_right);
			}

			return false;
		}
	}

}
