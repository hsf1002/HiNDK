package com.hsf1002.sky;

public class Auxinout {

    public native void QueueInit();
    public native void QueuePreset();
    public native int QueueDequeue();
    public native void QueuePrint();




    static {
        System.loadLibrary("skyqueue-lib");
    }
}
