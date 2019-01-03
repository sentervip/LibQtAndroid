package com.example.yons.test;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;


public class MainActivity extends AppCompatActivity {
    public String tag = "mavt";
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("gnustl_shared");
        System.loadLibrary("Qt5Core");
        //System.loadLibrary("Qt5Widgets");
        System.loadLibrary("Qt5Gui");
        System.loadLibrary("USQ");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        Log.v(tag,"enter onCreate");
        TextView tv = (TextView) findViewById(R.id.sample_text);
        String ver = GetQtVersion();
        Log.v(tag,"qt ver:"+ver);
        tv.setText(ver);


    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    //public native String stringFromJNI();
    static public native String GetQtVersion();
}
