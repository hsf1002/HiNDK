package com.hsf1002.sky.hindk.load;

public class JNIDynamicload {
    static {
        System.loadLibrary("dynamic-lib");
    }

    public native int sum(int x, int y);
    public native String getNativeString();
}
