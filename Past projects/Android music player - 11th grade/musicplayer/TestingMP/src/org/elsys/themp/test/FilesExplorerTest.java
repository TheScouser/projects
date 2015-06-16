package org.elsys.themp.test;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

import org.elsys.themp.FileArrayAdapter;
import org.elsys.themp.Files;
import org.elsys.themp.FilesExplorer;
import org.elsys.themp.MainActivity;
import org.elsys.themp.R;

import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;
import android.test.ActivityUnitTestCase;
import android.view.KeyEvent;
import android.widget.Button;
import android.widget.ImageButton;
import junit.framework.TestCase;

public class FilesExplorerTest extends ActivityUnitTestCase<FilesExplorer> {
	private FilesExplorer activity;
	private Bundle icicle;
	private int buttonId;
	List<Files> dir;
	Cursor cursor;

	public FilesExplorerTest() {
		super(FilesExplorer.class);
		// TODO Auto-generated constructor stub
	}

	protected void setUp() throws Exception {
		super.setUp();
		Intent intent = new Intent(getInstrumentation().getTargetContext(),
				FilesExplorer.class);
		startActivity(intent, null, null);
		activity = getActivity();
	}

	public void tearDown() throws Exception {
		// /CLOVER:FLUSH
		super.tearDown();
	}

	public void testOnCreate() {
		activity.onCreate(icicle);
		assertNotNull(activity.listv);

		buttonId = org.elsys.themp.R.id.button2;
		Button btn2 = (Button) activity.findViewById(R.id.button2);
		assertTrue(btn2.performClick());
		assertNotNull(activity.findViewById(buttonId));

		buttonId = org.elsys.themp.R.id.buttonName1;
		Button btn3 = (Button) activity.findViewById(R.id.buttonName1);
		assertTrue(btn3.performClick());
		assertNotNull(activity.findViewById(buttonId));
	}

	public void testFill() {
		File f = new File("");
		activity.fill(f);
		assertNotNull(f);

	}

	public void testOneFileClick() {
		Files f = new Files("", "", "");
		activity.onFileClick(f);
		assertTrue(activity.songs.contains(f));
		assertTrue(activity.isAlreadyAdded(f));
	}

	public void testGetMediaFromSD() {
		assertNotNull(activity.getMeadiaFromSD());
	}

	public void testIsThereSuchPlaylist() {
		assertFalse(activity.isThereSuchPlaylist("Pl"));
	}

	public void testIsAlreadyAdded() {
		Files song = new Files("test", "test", "test");
		assertFalse(activity.isAlreadyAdded(song));
	}

	public void testFillMp3() {
		cursor = activity.getMeadiaFromSD();
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
		}
		FileArrayAdapter adapterTest = new FileArrayAdapter(
				activity.getBaseContext(), R.layout.custom_row_view, dir);
		activity.fillMp3(cursor);

		assertEquals(adapterTest.getCount(), activity.listv.getAdapter()
				.getCount());
	}

	public void testOnBackPressed() {
		activity.onBackPressed();
		assertTrue(this.isFinishCalled());
	}

	public void testWritePlaylist() {
		activity.writePlaylist("Mu");
		assertTrue(activity.isThereSuchPlaylist("Mu"));
	}

}
