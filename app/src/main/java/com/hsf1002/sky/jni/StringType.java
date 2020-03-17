package com.hsf1002.sky.jni;

public class StringType {
    static
    {
        System.loadLibrary("native-lib");
    }

    public native String callNativeString(String str);
    public native int stringMethod(String str);
}
