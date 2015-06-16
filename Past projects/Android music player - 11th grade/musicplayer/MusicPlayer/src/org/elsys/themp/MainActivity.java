package org.elsys.themp;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;

import android.annotation.SuppressLint;
import android.annotation.TargetApi;
import android.app.Activity;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.media.MediaMetadataRetriever;
import android.media.MediaPlayer;
import android.media.MediaPlayer.OnCompletionListener;
import android.media.audiofx.Equalizer;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.view.GestureDetector;
import android.view.GestureDetector.SimpleOnGestureListener;
import android.view.Gravity;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.SeekBar;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ViewSwitcher;

@TargetApi(Build.VERSION_CODES.GINGERBREAD)
@SuppressLint("NewApi")
public class MainActivity extends Activity implements OnCompletionListener,
		SeekBar.OnSeekBarChangeListener {
	private static final int SWIPE_MIN_DISTANCE = 120;
	private static final int SWIPE_MAX_OFF_PATH = 250;
	private static final int SWIPE_THRESHOLD_VELOCITY = 200;

	private GestureDetector gestureDetector;

	int check = 1;
	private ImageButton btnPlay;
	private ImageButton btnForward;
	private ImageButton btnBackward;
	private ImageButton btnNext;
	private ImageButton btnPrevious;
	private ImageButton btnPlaylist;
	private ImageButton btnRepeat;
	private ImageButton btnShuffle;
	private ImageButton btnEQ;
	private ImageView coverArt;
	private SeekBar songProgressBar;
	private TextView songTitleLabel;
	private TextView songCurrentDurationLabel;
	private TextView songTotalDurationLabel;
	
	
	// Equalizer
	private Equalizer mEqualizer;
	// Media Player
	private MediaPlayer mp;
	// Handler to update UI timer, progress bar etc,.
	private Handler mHandler = new Handler();;
	private Utilities utils;
	private int seekForwardTime = 5000; // 5000 milliseconds
	private int seekBackwardTime = 5000; // 5000 milliseconds
	private int currentSongIndex = 0;
	private boolean isShuffle = false;
	private boolean isRepeat = false;

	private ArrayList<Files> songsList = new ArrayList<Files>();
	private ViewSwitcher switcher;
	private LinearLayout mLinearLayout;
	private TextView mStatusTextView;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.player);
		mStatusTextView = new TextView(this);
		// ----------------------------------------------------------playlist
		Intent i = new Intent(this, PlayListView.class);
		startActivityForResult(i, 10);
		// ----------------------------------------------------------playlist
		mp = new MediaPlayer();
		utils = new Utilities();

		switcher = (ViewSwitcher) findViewById(R.id.profileSwitcher);

		mLinearLayout = new LinearLayout(this);
		mLinearLayout.setOrientation(LinearLayout.VERTICAL);
		mLinearLayout.addView(mStatusTextView);

		switcher.addView(mLinearLayout);
		gestureDetector = new GestureDetector(new MyGestureDetector());
		View mainview = (View) findViewById(R.id.mainView);

		setupEqualizerFxAndUI();

		// Set the touch listener for the main view to be our custom gesture
		// listener
		mainview.setOnTouchListener(new View.OnTouchListener() {
			public boolean onTouch(View v, MotionEvent event) {
				if (gestureDetector.onTouchEvent(event)) {
					return true;
				}
				return false;
			}
		});

		btnEQ = (ImageButton) findViewById(R.id.btnEQ);
		btnPlay = (ImageButton) findViewById(R.id.btnPlay);
		btnForward = (ImageButton) findViewById(R.id.btnForward);
		btnBackward = (ImageButton) findViewById(R.id.btnBackward);
		btnNext = (ImageButton) findViewById(R.id.btnNext);
		btnPrevious = (ImageButton) findViewById(R.id.btnPrevious);
		btnPlaylist = (ImageButton) findViewById(R.id.btnPlaylist);
		btnRepeat = (ImageButton) findViewById(R.id.btnRepeat);
		btnShuffle = (ImageButton) findViewById(R.id.btnShuffle);
		coverArt = (ImageView) findViewById(R.id.coverArt);
		
		LinearLayout row = new LinearLayout(this);
		
		row.setOrientation(LinearLayout.HORIZONTAL);

		LinearLayout.LayoutParams layoutParams = new LinearLayout.LayoutParams(
				ViewGroup.LayoutParams.FILL_PARENT,
				ViewGroup.LayoutParams.WRAP_CONTENT);
		layoutParams.weight = 1;
		songProgressBar = (SeekBar) findViewById(R.id.songProgressBar);
		((ViewGroup) mainview).addView(row);

		songTitleLabel = (TextView) findViewById(R.id.songTitle);
		songCurrentDurationLabel = (TextView) findViewById(R.id.songCurrentDurationLabel);
		songTotalDurationLabel = (TextView) findViewById(R.id.songTotalDurationLabel);
		songProgressBar.setOnSeekBarChangeListener(this);
		mp.setOnCompletionListener(this);

		btnEQ.setOnClickListener(new View.OnClickListener() {

			@Override
			public void onClick(View v) {
				switcher.showNext();
				check--;
			}
		});

		/**
		 * Play button click event plays a song and changes button to pause
		 * image pauses a song and changes button to play image
		 * */
		btnPlay.setOnClickListener(new View.OnClickListener() {

			@Override
			public void onClick(View arg0) {
				// check for already playing
				if (mp.isPlaying()) {
					if (mp != null) {
						mp.pause();
						// Changing button image to play button
						btnPlay.setImageResource(R.drawable.button_play);
					}
				} else {
					// Resume song
					if (mp != null) {
						mp.start();
						// Changing button image to play_focused button
						btnPlay.setImageResource(R.drawable.button_play_focused);
					}
				}

			}
		});

		/**
		 * Forward button click event Forwards song specified seconds
		 * */
		btnForward.setOnClickListener(new View.OnClickListener() {

			@Override
			public void onClick(View arg0) {
				// get current song position
				int currentPosition = mp.getCurrentPosition();
				// check if seekForward time is lesser than song duration
				if (currentPosition + seekForwardTime <= mp.getDuration()) {
					// forward song
					mp.seekTo(currentPosition + seekForwardTime);
				} else {
					// forward to end position
					mp.seekTo(mp.getDuration());
				}
			}
		});

		/**
		 * Backward button click event Backward song to specified seconds
		 * */
		btnBackward.setOnClickListener(new View.OnClickListener() {

			@Override
			public void onClick(View arg0) {
				// get current song position
				int currentPosition = mp.getCurrentPosition();
				// check if seekBackward time is greater than 0 sec
				if (currentPosition - seekBackwardTime >= 0) {
					// forward song
					mp.seekTo(currentPosition - seekBackwardTime);
				} else {
					// backward to starting position
					mp.seekTo(0);
				}

			}
		});

		/**
		 * Next button click event Plays next song by taking currentSongIndex +
		 * 1
		 * */
		btnNext.setOnClickListener(new View.OnClickListener() {

			@Override
			public void onClick(View arg0) {
				// check if next song is there or not
				if (currentSongIndex < (songsList.size() - 1)) {
					playSong(currentSongIndex + 1);
					currentSongIndex = currentSongIndex + 1;
				} else {
					// play first song
					playSong(0);
					currentSongIndex = 0;
				}

			}
		});

		/**
		 * Back button click event Plays previous song by currentSongIndex - 1
		 * */
		btnPrevious.setOnClickListener(new View.OnClickListener() {

			@Override
			public void onClick(View arg0) {
				if (currentSongIndex > 0) {
					playSong(currentSongIndex - 1);
					currentSongIndex = currentSongIndex - 1;
				} else {
					// play last song
					playSong(songsList.size() - 1);
					currentSongIndex = songsList.size() - 1;
				}

			}
		});

		/**
		 * Button Click event for Repeat button Enables repeat flag to true
		 * */
		btnRepeat.setOnClickListener(new View.OnClickListener() {

			@Override
			public void onClick(View arg0) {
				if (isRepeat) {
					isRepeat = false;
					Toast.makeText(getApplicationContext(), "Repeat is OFF",
							Toast.LENGTH_SHORT).show();
					btnRepeat.setImageResource(R.drawable.button_repeat_off);
				} else {
					// make repeat to true
					isRepeat = true;
					Toast.makeText(getApplicationContext(), "Repeat is ON",
							Toast.LENGTH_SHORT).show();
					// make shuffle to false
					isShuffle = false;
					btnRepeat.setImageResource(R.drawable.button_repeat_on);
					btnShuffle.setImageResource(R.drawable.button_shuffle_off);
				}
			}
		});

		/**
		 * Button Click event for Shuffle button Enables shuffle flag to true
		 * */
		btnShuffle.setOnClickListener(new View.OnClickListener() {

			@Override
			public void onClick(View arg0) {
				if (isShuffle) {
					isShuffle = false;
					Toast.makeText(getApplicationContext(), "Shuffle is OFF",
							Toast.LENGTH_SHORT).show();
					btnShuffle.setImageResource(R.drawable.button_shuffle_off);
				} else {
					// make repeat to true
					isShuffle = true;
					Toast.makeText(getApplicationContext(), "Shuffle is ON",
							Toast.LENGTH_SHORT).show();
					// make shuffle to false
					isRepeat = false;
					btnShuffle.setImageResource(R.drawable.button_shuffle_on);
					btnRepeat.setImageResource(R.drawable.button_repeat_off);
				}
			}
		});

		/**
		 * Button Click event for Play list click event Launches list activity
		 * which displays list of songs
		 * */
		btnPlaylist.setOnClickListener(new View.OnClickListener() {

			@Override
			public void onClick(View arg0) {
				Intent i = new Intent(getApplicationContext(),
						PlayListActivity.class);
				i.putExtra("songs", songsList);
				startActivityForResult(i, 100);
			}
		});

	}

	/**
	 * Receiving song index from playlist view and play the song
	 * */
	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		super.onActivityResult(requestCode, resultCode, data);
		if (resultCode == 100) {
			currentSongIndex = data.getExtras().getInt("songIndex");
			// play selected song
			playSong(currentSongIndex);
		}

		if (resultCode == 10) {
			songsList = data.getExtras().getParcelableArrayList("songs");
			// play first song
			playSong(0);
		}

	}

	/**
	 * Function to play a song
	 * 
	 * @param songIndex
	 *            - index of song
	 * */
	public void playSong(int songIndex) {
		// Play song
		try {
			mp.reset();
			mp.setDataSource(songsList.get(songIndex).getPath());
			mp.prepare();
			mp.start();
			// Displaying Song title
			String songTitle = songsList.get(songIndex).getName();
			MediaMetadataRetriever MMDR= new MediaMetadataRetriever();
			MMDR.setDataSource(songsList.get(songIndex).getPath());
			byte[] Cover = MMDR.getEmbeddedPicture();
			
			if(Cover != null){
				Bitmap bmpCover=BitmapFactory.decodeByteArray(Cover,0,Cover.length);
				coverArt.setImageBitmap(bmpCover);
			}
			
			
			songTitleLabel.setText(songTitle);
			btnPlay.setImageResource(R.drawable.button_play);
			// set Progress bar values
			songProgressBar.setProgress(0);
			songProgressBar.setMax(100);

			// Updating progress bar
			updateProgressBar();
		} catch (IndexOutOfBoundsException e) {
			e.printStackTrace();
		}

		catch (IllegalArgumentException e) {
			e.printStackTrace();
		} catch (IllegalStateException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * Update timer on seekbar
	 * */
	public void updateProgressBar() {
		mHandler.postDelayed(mUpdateTimeTask, 100);
	}

	/**
	 * Background Runnable thread
	 * */
	private Runnable mUpdateTimeTask = new Runnable() {
		public void run() {
			try {
				long totalDuration = mp.getDuration();
				long currentDuration = mp.getCurrentPosition();

				// Displaying Total Duration time
				songTotalDurationLabel.setText(""
						+ utils.milliSecondsToTimer(totalDuration));
				// Displaying time completed playing
				songCurrentDurationLabel.setText(""
						+ utils.milliSecondsToTimer(currentDuration));

				// Updating progress bar
				int progress = (int) (utils.getProgressPercentage(
						currentDuration, totalDuration));
				// Log.d("Progress", ""+progress);
				songProgressBar.setProgress(progress);

				// Running this thread after 100 milliseconds
				mHandler.postDelayed(this, 100);
			} catch (IllegalStateException e) {
				finish();
			}
		}
	};

	/**
	     *
	     * */
	@Override
	public void onProgressChanged(SeekBar seekBar, int progress,
			boolean fromTouch) {

	}

	/**
	 * When user starts moving the progress handler
	 * */
	@Override
	public void onStartTrackingTouch(SeekBar seekBar) {
		// remove message Handler from updating progress bar
		mHandler.removeCallbacks(mUpdateTimeTask);
	}

	/**
	 * When user stops moving the progress hanlder
	 * */
	@Override
	public void onStopTrackingTouch(SeekBar seekBar) {
		mHandler.removeCallbacks(mUpdateTimeTask);
		int totalDuration = mp.getDuration();
		int currentPosition = utils.progressToTimer(seekBar.getProgress(),
				totalDuration);

		// forward or backward to certain seconds
		mp.seekTo(currentPosition);

		// update timer progress again
		updateProgressBar();
	}

	/**
	 * On Song Playing completed if repeat is ON play same song again if shuffle
	 * is ON play random song
	 * */
	@Override
	public void onCompletion(MediaPlayer arg0) {

		// check for repeat is ON or OFF
		if (isRepeat) {
			// repeat is on play same song again
			playSong(currentSongIndex);
		} else if (isShuffle) {
			// shuffle is on - play a random song
			Random rand = new Random();
			currentSongIndex = rand.nextInt((songsList.size() - 1) - 0 + 1) + 0;
			playSong(currentSongIndex);
		} else {
			// no repeat or shuffle ON - play next song
			if (currentSongIndex < (songsList.size() - 1)) {
				playSong(currentSongIndex + 1);
				currentSongIndex = currentSongIndex + 1;
			} else {
				// play first song
				playSong(0);
				currentSongIndex = 0;
			}
		}

	}

	@SuppressLint("NewApi")
	private void setupEqualizerFxAndUI() {
		// Create the Equalizer object (an AudioEffect subclass) and attach it
		// to our media player
		mEqualizer = new Equalizer(0, mp.getAudioSessionId());
		mEqualizer.setEnabled(true);

		TextView eqTextView = new TextView(this);
		eqTextView.setText("Equalizer:");
		mLinearLayout.addView(eqTextView);

		short bands = mEqualizer.getNumberOfBands();

		final short minEQLevel = mEqualizer.getBandLevelRange()[0];
		final short maxEQLevel = mEqualizer.getBandLevelRange()[1];

		for (short i = 0; i < bands; i++) {
			final short band = i;

			TextView freqTextView = new TextView(this);
			freqTextView.setLayoutParams(new ViewGroup.LayoutParams(
					ViewGroup.LayoutParams.FILL_PARENT,
					ViewGroup.LayoutParams.WRAP_CONTENT));
			freqTextView.setGravity(Gravity.CENTER_HORIZONTAL);
			freqTextView.setText((mEqualizer.getCenterFreq(band) / 1000)
					+ " Hz");
			mLinearLayout.addView(freqTextView);

			LinearLayout row = new LinearLayout(this);
			row.setOrientation(LinearLayout.HORIZONTAL);

			TextView minDbTextView = new TextView(this);
			minDbTextView.setLayoutParams(new ViewGroup.LayoutParams(
					ViewGroup.LayoutParams.WRAP_CONTENT,
					ViewGroup.LayoutParams.WRAP_CONTENT));
			minDbTextView.setText((minEQLevel / 100) + " dB");

			TextView maxDbTextView = new TextView(this);
			maxDbTextView.setLayoutParams(new ViewGroup.LayoutParams(
					ViewGroup.LayoutParams.WRAP_CONTENT,
					ViewGroup.LayoutParams.WRAP_CONTENT));
			maxDbTextView.setText((maxEQLevel / 100) + " dB");

			LinearLayout.LayoutParams layoutParams = new LinearLayout.LayoutParams(
					ViewGroup.LayoutParams.FILL_PARENT,
					ViewGroup.LayoutParams.WRAP_CONTENT);
			layoutParams.weight = 1;
			SeekBar bar = new SeekBar(this);
			bar.setLayoutParams(layoutParams);
			bar.setMax(maxEQLevel - minEQLevel);
			bar.setProgress(mEqualizer.getBandLevel(band));

			bar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
				public void onProgressChanged(SeekBar seekBar, int progress,
						boolean fromUser) {
					mEqualizer.setBandLevel(band,
							(short) (progress + minEQLevel));
				}

				public void onStartTrackingTouch(SeekBar seekBar) {
				}

				public void onStopTrackingTouch(SeekBar seekBar) {
				}
			});

			row.addView(minDbTextView);
			row.addView(bar);
			row.addView(maxDbTextView);

			mLinearLayout.addView(row);
		}
	}

	public void onBackPressed() {
		if (check == 0) {
			switcher.showPrevious();
			check++;
		} else {
			finish();
		}
		return;
	}

	@Override
	public void onDestroy() {
		super.onDestroy();
		mp.release();
	}

	class MyGestureDetector extends SimpleOnGestureListener {
		@Override
		public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX,
				float velocityY) {

			if (Math.abs(e1.getY() - e2.getY()) > SWIPE_MAX_OFF_PATH) {
				return false;
			}

			// right to left swipe
			if (e1.getX() - e2.getX() > SWIPE_MIN_DISTANCE
					&& Math.abs(velocityX) > SWIPE_THRESHOLD_VELOCITY) {

				Intent i = new Intent(MainActivity.this.getBaseContext(),
						PlayListView.class);
				startActivityForResult(i, 10);
				MainActivity.this.overridePendingTransition(
						R.anim.slide_in_right, R.anim.slide_out_left);

				// right to left swipe
			} else if (e2.getX() - e1.getX() > SWIPE_MIN_DISTANCE
					&& Math.abs(velocityX) > SWIPE_THRESHOLD_VELOCITY) {

				Intent intent = new Intent(MainActivity.this.getBaseContext(),
						VideoStoredInSDCard.class);

				startActivity(intent);
				MainActivity.this.overridePendingTransition(
						R.anim.slide_in_left, R.anim.slide_out_right);
			}

			return false;
		}

		// It is necessary to return true from onDown for the onFling event to
		// register
		@Override
		public boolean onDown(MotionEvent e) {
			return true;
		}
	}

}
