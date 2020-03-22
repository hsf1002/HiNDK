package com.hsf1002.sky.jni;

public class JNIThread {
    static
    {
        System.loadLibrary("dynamic-lib");
    }

    // 创建线程
    public native void createNativeThread();
    // 互斥锁-条件变量-wait
    public native void waitNativeThread();
    // 互斥锁-条件变量-notify
    public native void notifyNativeThread();
}
