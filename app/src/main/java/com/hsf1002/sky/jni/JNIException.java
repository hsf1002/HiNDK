package com.hsf1002.sky.jni;

public class JNIException {
    static
    {
        System.loadLibrary("native-lib");
    }

    public native void nativeInvokeJavaException();

    // 从jni抛出异常，让java上层处理
    public native void nativeThrowException() throws IllegalArgumentException;

    private int wrongDivide()
    {
        return 2/0;
    }
}
