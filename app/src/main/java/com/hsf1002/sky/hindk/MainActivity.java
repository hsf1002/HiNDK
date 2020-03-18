package com.hsf1002.sky.hindk;

import androidx.annotation.LongDef;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.hsf1002.sky.jni.BasicType;
import com.hsf1002.sky.jni.DynamicLoad;
import com.hsf1002.sky.Hello;
import com.hsf1002.sky.Person;
import com.hsf1002.sky.Teacher;
import com.hsf1002.sky.jni.RefType;
import com.hsf1002.sky.jni.StringType;

public class MainActivity extends AppCompatActivity {
private static final String TAG = "skyMainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);

        Person p = new Person();
        Teacher t = new Teacher();
        //tv.setText(p.stringFromJNI());
        //tv.setText(t.stringFromJNI());

        Hello h = new Hello();
        StringBuilder sb = new StringBuilder();
        sb.append(h.stringFromJNI()).append(h.intFromJNI(1024, 1024));

//        Auxinout aux = new Auxinout();
//        aux.QueueInit();
//        aux.QueuePreset();
//        aux.QueuePrint();
//        sb.append(aux.QueueDequeue());

        tv.setText(sb.toString());

        TextView tv2 = findViewById(R.id.sample_text_2);
        DynamicLoad dynamicLoad = new DynamicLoad();
        tv2.setText(dynamicLoad.getNativeString() + " " + dynamicLoad.sum(1024, 1024));

        BasicType basicType = new BasicType();
        byte b = 2;
        short sh = 10;
        // int+1: 2, byte+1: 3, short+1: 11, long+1: 21, char+1: B, float+1: 101.0, double+1: 201.0, !bool: true
        Log.d(TAG, "int+1: " + basicType.callNativeInt(1) + ", byte+1: " + basicType.callNativeByte(b) +
                    ", short+1: " + basicType.callNativeShort(sh) + ", long+1: " + basicType.callNativeLong(20) +
                    ", char+1: " + basicType.callNativeChar('A') + ", float+1: " + basicType.callNativeFloat(100) +
                    ", double+1: " + basicType.callNativeDouble(200) + ", !bool: " + basicType.callNativeBool(false));

        StringType stringType = new StringType();
        Log.d(TAG, "native-str: " + stringType.callNativeString("java string")); // native-str: this is C style string
        Log.d(TAG, "string-size: " + stringType.stringMethod("java string"));    // string-size: 11

        RefType refType = new RefType();
        String[] strArray = {"Apple", "Banana", "Cux"};
        Log.d(TAG, "refType: " + refType.callNativeStringArray(strArray));       // refType: Banana
    }

}
