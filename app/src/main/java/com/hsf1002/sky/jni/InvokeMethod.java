package com.hsf1002.sky.jni;

public class InvokeMethod {
    static
    {
        System.loadLibrary("dynamic-lib");
    }

    public native void nativeCallback(IMethodCB cb);
    // 因为要在JNI的子线程调用java的回调，需要在JNI_OnLoad保存虚拟机状态，所以必须引用动态库
    public native void nativeThreadCallback(IThreadCB cb);
}
