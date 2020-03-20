package com.hsf1002.sky.jni;

public class Reference {
    static
    {
        System.loadLibrary("native-lib");
    }

    // 局部引用
    public native String useLocalReference();
    // 全局引用
    public native String useGlobalReference();
    // 弱引用
    public native void useWeakReference();
}
