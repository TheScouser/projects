package org.elsys.themp.test;

import java.io.IOException;

import org.elsys.themp.MainActivity;
import org.elsys.themp.R;
import android.test.TouchUtils;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.Handler;
import android.content.Intent;
import android.test.ActivityUnitTestCase;
import android.widget.Button;
import android.widget.ImageButton;

import org.elsys.themp.*;
import android.test.ActivityUnitTestCase;

public class MainActivityTestStandart extends
		ActivityUnitTestCase<MainActivity> {
	private Bundle icicle;
	private Handler mHandler;
	private Runnable mUpdateTimeTask;
	private MediaPlayer mp;
	private int buttonId, progressId, labelId;
	private MainActivity activity;

	public MainActivityTestStandart() {
		super(MainActivity.class);
	}

	@Override
	protected void setUp() throws Exception {
		super.setUp();
		mHandler = new Handler();
		mp = new MediaPlayer();
		Intent intent = new Intent(getInstrumentation().getTargetContext(),
				MainActivity.class);
		startActivity(intent, null, null);
		activity = getActivity();
	}

	public void tearDown() throws Exception {
		// /CLOVER:FLUSH
		super.tearDown();
	}

	public void testOnCreate() {
		testButtons();
		testProgress();
		activity.onCreate(icicle);
		assertNotNull(activity.mp);
		assertNotNull(activity.utils);
	}

	public void testOnBackPressed() {
		activity.onBackPressed();
		assertEquals(1, activity.check);
	}

	public void testSetupEqualizerFxAndUI() {
		activity.setupEqualizerFxAndUI();
		assertEquals(6, activity.mEqualizer.getNumberOfBands());
	}

	public void testOnStartTrackingTouch() {
		activity.onStartTrackingTouch(activity.songProgressBar);
		assertFalse(activity.mHandler.hasMessages(0));
	}

	public void testOnStopTrackingTouch() {
		activity.onStopTrackingTouch(activity.songProgressBar);
		assertTrue(activity.mHandler.hasMessages(0));
	}

	public void testUpdateProgressBar() {
		activity.updateProgressBar();
		assertTrue(activity.mHandler.hasMessages(0));
	}

	public void testThread() {
		getInstrumentation().waitForIdle(new Runnable() {
			public void run() {
				assertNotNull(getStartedActivityIntent());
				assertTrue(isFinishCalled());
			}
		});
	}

	public void testPlaySong() throws IOException {
		activity.playSong(0);
		assertTrue(!activity.mp.isPlaying());
	}

	public void testProgress() {
		progressId = R.id.songProgressBar;
		assertNotNull(activity.findViewById(progressId));
		labelId = R.id.songTitle;
		assertNotNull(activity.findViewById(labelId));
		labelId = R.id.songCurrentDurationLabel;
		assertNotNull(activity.findViewById(labelId));
		labelId = R.id.songTotalDurationLabel;
		assertNotNull(activity.findViewById(labelId));
	}

	public void testButtons() {
		buttonId = org.elsys.themp.R.id.btnNext;
		ImageButton btnNext = (ImageButton) activity.findViewById(R.id.btnNext);
		assertTrue(btnNext.performClick());
		assertNotNull(activity.findViewById(buttonId));

		buttonId = org.elsys.themp.R.id.btnPlay;
		ImageButton btnPlay = (ImageButton) activity.findViewById(R.id.btnPlay);
		assertTrue(btnPlay.performClick());
		assertNotNull(activity.findViewById(buttonId));

		buttonId = org.elsys.themp.R.id.btnPrevious;
		ImageButton btnPrevious = (ImageButton) activity
				.findViewById(R.id.btnPrevious);
		assertTrue(btnPrevious.performClick());
		assertNotNull(activity.findViewById(buttonId));

		buttonId = org.elsys.themp.R.id.btnEQ;
		ImageButton btnEQ = (ImageButton) activity.findViewById(R.id.btnEQ);
		assertTrue(btnEQ.performClick());
		assertNotNull(activity.findViewById(buttonId));

		buttonId = org.elsys.themp.R.id.btnBackward;
		ImageButton btnBackward = (ImageButton) activity
				.findViewById(R.id.btnBackward);
		assertTrue(btnBackward.performClick());
		assertNotNull(activity.findViewById(buttonId));

		buttonId = org.elsys.themp.R.id.btnForward;
		ImageButton btnForward = (ImageButton) activity
				.findViewById(R.id.btnForward);
		assertTrue(btnForward.performClick());
		assertNotNull(activity.findViewById(buttonId));

		buttonId = org.elsys.themp.R.id.btnPlaylist;
		ImageButton btnPlaylist = (ImageButton) activity
				.findViewById(R.id.btnPlaylist);
		assertTrue(btnPlaylist.performClick());
		assertNotNull(activity.findViewById(buttonId));

		buttonId = org.elsys.themp.R.id.btnRepeat;
		ImageButton btnRepeat = (ImageButton) activity
				.findViewById(R.id.btnRepeat);
		assertTrue(btnRepeat.performClick());
		assertTrue(btnRepeat.performClick());
		assertNotNull(activity.findViewById(buttonId));

		buttonId = org.elsys.themp.R.id.btnShuffle;
		ImageButton btnShuffle = (ImageButton) activity
				.findViewById(R.id.btnShuffle);
		assertTrue(btnShuffle.performClick());
		assertTrue(btnShuffle.performClick());
		assertNotNull(activity.findViewById(buttonId));
	}

	public void testOnCompletion() {

		activity.onCompletion(mp);
		assertEquals(0, activity.currentSongIndex);
	}
}
