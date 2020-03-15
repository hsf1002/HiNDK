package com.hsf1002.sky.hindk;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.hsf1002.sky.jni.BasicType;
import com.hsf1002.sky.jni.DynamicLoad;
import com.hsf1002.sky.Hello;
import com.hsf1002.sky.Person;
import com.hsf1002.sky.Teacher;

public class MainActivity extends AppCompatActivity {


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

        TextView tv3 = findViewById(R.id.sample_text_3);
        BasicType basicType = new BasicType();
        byte b = 2;
        short sh = 10;
        tv3.setText("int+1: " + basicType.callNativeInt(1) + ", byte+1: " + basicType.callNativeByte(b) +
                    ", short+1: " + basicType.callNativeShort(sh) + ", long+1: " + basicType.callNativeLong(20) +
                    ", char+1: " + basicType.callNativeChar('A') + ", float+1: " + basicType.callNativeFloat(100) +
                    ", double+1: " + basicType.callNativeDouble(200));
    }

}
