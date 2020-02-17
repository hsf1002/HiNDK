package com.hsf1002.sky;


public class Teacher {

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();


    static
    {
        System.loadLibrary("teacher-lib");
    }
}
