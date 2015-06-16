package org.elsys.themp;

import java.util.ArrayList;
import java.util.HashMap;

import android.app.ListActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.SimpleAdapter;

public class PlayListActivity extends ListActivity {
	public ArrayList<Files> songsList = new ArrayList<Files>();
	public ArrayList<HashMap<String, String>> songsListArr = new ArrayList<HashMap<String, String>>();

	public void onCreate(Bundle savedInstancestate) {
		super.onCreate(savedInstancestate);
		setContentView(R.layout.playlist);
		songsList = getIntent().getParcelableArrayListExtra("songs");

		for (Files i : songsList) {
			HashMap<String, String> temp = new HashMap<String, String>();
			temp.put("songTitle", i.getName());
			songsListArr.add(temp);
		}

		// Adding menuItems to ListView
		ListAdapter adapter = new SimpleAdapter(this, songsListArr,
				R.layout.playlist_item, new String[] { "songTitle" },
				new int[] { R.id.songTitle });

		setListAdapter(adapter);

		// selecting single ListView item
		ListView lv = getListView();
		// listening to single listitem click
		lv.setOnItemClickListener(new OnItemClickListener() {

			@Override
			public void onItemClick(AdapterView<?> parent, View view,
					int position, long id) {
				// getting listitem index
				int songIndex = position;

				// Starting new intent
				Intent in = new Intent(getApplicationContext(),
						MainActivity.class);
				// Sending songIndex to PlayerActivity
				in.putExtra("songIndex", songIndex);
				setResult(100, in);
				// Closing PlayListView
				finish();
			}

		});

	}

}
