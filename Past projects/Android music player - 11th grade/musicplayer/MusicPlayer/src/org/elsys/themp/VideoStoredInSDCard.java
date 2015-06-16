package org.elsys.themp;

import org.elsys.themp.PlayListView.MyGestureDetector;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.net.Uri;
import android.os.Bundle;
import android.provider.MediaStore;
import android.util.Log;
import android.view.GestureDetector;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.GestureDetector.SimpleOnGestureListener;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.BaseAdapter;
import android.widget.ListView;
import android.widget.TextView;

public class VideoStoredInSDCard extends Activity {
	private static final int SWIPE_MIN_DISTANCE = 120;
	private static final int SWIPE_MAX_OFF_PATH = 250;
	private static final int SWIPE_THRESHOLD_VELOCITY = 200;
	private GestureDetector gestureDetector;
	private Cursor videoCursor;
	private ListView lv;
	private int videoColumnIndex;
	ListView videolist;
	int count;
	String thumbPath;
	private Uri myUri;
	String[] thumbColumns = { MediaStore.Video.Thumbnails.DATA,
			MediaStore.Video.Thumbnails.VIDEO_ID };

	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.videolist);
		initialization();
		gestureDetector = new GestureDetector(new MyGestureDetector());
		lv = (ListView) findViewById(R.id.PhoneVideoList);
		lv.setOnTouchListener(new View.OnTouchListener() {
			public boolean onTouch(View v, MotionEvent event) {
				if (gestureDetector.onTouchEvent(event)) {
					return true;
				}
				return false;
			}
		});
	}

	private void initialization() {
		System.gc();
		String[] videoProjection = { MediaStore.Video.Media._ID,
				MediaStore.Video.Media.DATA,
				MediaStore.Video.Media.DISPLAY_NAME,
				MediaStore.Video.Media.SIZE };
		videoCursor = managedQuery(MediaStore.Video.Media.EXTERNAL_CONTENT_URI,
				videoProjection, null, null, null);
		count = videoCursor.getCount();
		videolist = (ListView) findViewById(R.id.PhoneVideoList);

		videolist
				.setAdapter(new VideoListAdapter(this.getApplicationContext()));
		videolist.setOnItemClickListener(videogridlistener);
	}

	private OnItemClickListener videogridlistener = new OnItemClickListener() {
		public void onItemClick(AdapterView parent, View v, int position,
				long id) {
			System.gc();
			videoColumnIndex = videoCursor
					.getColumnIndexOrThrow(MediaStore.Video.Media.DATA);
			videoCursor.moveToPosition(position);
			String filename = videoCursor.getString(videoColumnIndex);
			Log.i("FileName: ", filename);
			Intent intent = new Intent(VideoStoredInSDCard.this,
					VideoPlayer.class);
			intent.putExtra("videofilename", filename);
			startActivity(intent);
		}
	};

	public class VideoListAdapter extends BaseAdapter {
		private Context vContext;
		int layoutResourceId;

		public VideoListAdapter(Context c) {
			vContext = c;
		}

		public int getCount() {
			return videoCursor.getCount();
		}

		public Object getItem(int position) {
			return position;
		}

		public long getItemId(int position) {
			return position;
		}

		public View getView(int position, View convertView, ViewGroup parent) {
			View listItemRow = null;
			listItemRow = LayoutInflater.from(vContext).inflate(
					R.layout.videolistitem, parent, false);

			TextView txtTitle = (TextView) listItemRow
					.findViewById(R.id.txtTitle);
			TextView txtSize = (TextView) listItemRow
					.findViewById(R.id.txtSize);

			videoColumnIndex = videoCursor
					.getColumnIndexOrThrow(MediaStore.Video.Media.DISPLAY_NAME);
			videoCursor.moveToPosition(position);
			txtTitle.setText(videoCursor.getString(videoColumnIndex));

			videoColumnIndex = videoCursor
					.getColumnIndexOrThrow(MediaStore.Video.Media.SIZE);
			videoCursor.moveToPosition(position);
			txtSize.setText(" Size(KB):"
					+ videoCursor.getString(videoColumnIndex));

			return listItemRow;

		}

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
				finish();
				VideoStoredInSDCard.this.overridePendingTransition(
						R.anim.slide_in_right, R.anim.slide_out_left);
			}
			return false;
		}
	}
	
}