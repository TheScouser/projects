package org.elsys.themp.test;

import org.elsys.themp.FilesExplorer;
import org.elsys.themp.PlayListView;
import org.elsys.themp.R;

import android.app.AlertDialog;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.test.ActivityInstrumentationTestCase2;
import android.view.MenuItem;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class PlayListViewTest extends
		ActivityInstrumentationTestCase2<PlayListView> {

	private PlayListView activity;
	private Bundle icicle;
	private ListView l;
	private MenuItem item;
	private int itemId;
	private String[] playlists;

	@Override
	protected void setUp() throws Exception {
		super.setUp();
		setActivityInitialTouchMode(false);
		activity = getActivity();
	}

	public PlayListViewTest() {
		super(PlayListView.class);
	}

	public void testOnCreateBundle() {

		activity.runOnUiThread(new Runnable() {
			public void run() {

				activity.onCreate(icicle);
				l = (ListView) activity.findViewById(R.id.listview_playlists);
				assertEquals(l, activity.lv);

			}
		});
	}

	public void testDeletePlaylist() {

		activity.deletePlaylist(0);
		assertTrue(activity.isThereSuchPlaylist("Mu"));
	}

	public void testShowPlaylist() {

		activity.runOnUiThread(new Runnable() {
			public void run() {

				playlists = activity.fileList();
				if (playlists.length == 0) {
					new AlertDialog.Builder(activity.getBaseContext())
							.setMessage("You Dont have Any PlayLists !")
							.setNeutralButton("Create playlist",
									new DialogInterface.OnClickListener() {

										public void onClick(
												DialogInterface dialog,
												int which) {
											Intent i = new Intent(activity
													.getApplicationContext(),
													FilesExplorer.class);
											activity.startActivityForResult(i,
													50);
										}
									}).show();
				}

				ArrayAdapter<String> adapter = new ArrayAdapter<String>(
						activity.getBaseContext(),
						android.R.layout.simple_list_item_1,
						android.R.id.text1, playlists);

				activity.showPlaylists();

				assertEquals(adapter.getCount(), activity.lv.getAdapter()
						.getCount());
			}
		});
	}

	public void testIsThereSuchPlaylist() {
		assertTrue(activity.isThereSuchPlaylist("Mu"));
	}

	public void testRenamed() {

		activity.runOnUiThread(new Runnable() {
			public void run() {
				// activity.renamePlaylist(0);
				activity.writeRenamedPlaylist("Mu", "Hl");
				assertTrue(activity.isThereSuchPlaylist("Hl"));
			}
		});

	}
}
