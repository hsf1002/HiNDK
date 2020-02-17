package com.hsf1002.sky.hindk;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

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
        tv.setText(t.stringFromJNI());
    }

}
