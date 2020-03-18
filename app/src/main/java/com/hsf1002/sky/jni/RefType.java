package com.hsf1002.sky.jni;

public class RefType {
    static
    {
        System.loadLibrary("native-lib");
    }

    public native String callNativeStringArray(String[] strArray);
}
