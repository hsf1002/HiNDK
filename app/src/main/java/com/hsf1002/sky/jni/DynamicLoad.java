package com.hsf1002.sky.jni;

public class DynamicLoad {

    static
    {
        System.loadLibrary("dynamic-lib");
    }

    public native int sum(int x, int y);
    public native String getNativeString();
}
