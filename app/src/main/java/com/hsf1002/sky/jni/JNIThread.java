package com.hsf1002.sky.jni;

public class JNIThread {
    static
    {
        System.loadLibrary("dynamic-lib");
    }

    public native void createNativeThread();
}
