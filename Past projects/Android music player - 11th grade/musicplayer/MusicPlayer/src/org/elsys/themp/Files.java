package org.elsys.themp;

import java.io.Serializable;

import android.os.Parcel;
import android.os.Parcelable;

public class Files implements Comparable<Files>, Parcelable, Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	

	private String name;
	private String data;
	private String path;

	public Files(String n, String d, String p) {
		name = n;
		data = d;
		path = p;
	}

	public String getName() {
		return name;
	}

	public String getData() {
		return data;
	}

	public String getPath() {
		return path;
	}

	public int compareTo(Files o) {
		if (this.name != null)
			return this.name.toLowerCase().compareTo(o.getName().toLowerCase());
		else
			throw new IllegalArgumentException();
	}
	
	// Parceling part
	

	public Files(Parcel in){			//constructor for parcel (string[])
        String[] data = new String[3];

        in.readStringArray(data);
        this.name = data[0];
        this.path = data[1];
        this.data = data[2];
    }
	
	
	public int describeContents() {
		// TODO Auto-generated method stub
		return 0;
	}
	
	public void writeToParcel(Parcel arg0, int arg1) {
		arg0.writeStringArray(new String[] {this.name,this.path,this.data});
		
	}
	
	public static final Parcelable.Creator CREATOR = new Parcelable.Creator() { //parcing string[]
        public Files createFromParcel(Parcel in) {
            return new Files(in); 
        }

        public Files[] newArray(int size) {
            return new Files[size];
        }
    };
}
