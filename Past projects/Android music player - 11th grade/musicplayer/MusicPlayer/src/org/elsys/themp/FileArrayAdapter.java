package org.elsys.themp;

import java.util.List;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

public class FileArrayAdapter extends ArrayAdapter<Files> {

	private Context c;
	private int id;
	private List<Files> items;

	public FileArrayAdapter(Context context, int textViewResourceId,
			List<Files> objects) {
		super(context, textViewResourceId, objects);
		c = context;
		id = textViewResourceId;
		items = objects;
	}

	public Files getItem(int i) {
		return items.get(i);
	}

	@Override
	public View getView(int position, View convertView, ViewGroup parent) {
		View v = convertView;
		if (v == null) {
			LayoutInflater vi = (LayoutInflater) c
					.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
			v = vi.inflate(id, null);
		}
		final Files o = items.get(position);
		if (o != null) {
			TextView t1 = (TextView) v.findViewById(R.id.text1);
			TextView t2 = (TextView) v.findViewById(R.id.text2);

			if (t1 != null)
				t1.setText(o.getName());
			if (t2 != null)
				t2.setText(o.getData());

		}
		return v;
	}

}
