package com.hsf1002.sky;

public class Hello {

    public native String stringFromJNI();

    public native int intFromJNI(int x, int y);


    static
    {
        System.loadLibrary("hello-lib");
    }
}
