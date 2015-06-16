package org.elsys.themp.test;

import org.elsys.themp.FilesExplorer;
import org.elsys.themp.VideoStoredInSDCard;

import android.content.Intent;
import android.os.Bundle;
import android.test.ActivityUnitTestCase;
import android.view.View;
import junit.framework.TestCase;

public class TestVideoStored extends ActivityUnitTestCase<VideoStoredInSDCard> {

	private VideoStoredInSDCard activity;
	private Bundle icicle;

	public TestVideoStored() {
		super(VideoStoredInSDCard.class);
	}

	protected void setUp() throws Exception {
		super.setUp();
		Intent intent = new Intent(getInstrumentation().getTargetContext(),
				VideoStoredInSDCard.class);
		startActivity(intent, null, null);
		activity = getActivity();
	}

	public void testOnCreate() {
		activity.onCreate(icicle);
		assertNotNull(activity.gestureDetector);
		assertNotNull(activity.lv);
	}

	public void testInit() {
		activity.initialization();
		assertNotNull(activity.videoCursor);
	}
}
