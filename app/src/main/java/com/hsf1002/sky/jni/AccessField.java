package com.hsf1002.sky.jni;

import com.hsf1002.sky.Animal;

public class AccessField {
    static
    {
        System.loadLibrary("native-lib");
    }

    public static int number;
    // 访问实例成员
    public native void accessInstanceField(Animal animal);
    // 访问静态成员
    public native void accessStaticField(Animal animal);
    // 访问静态实例成员number
    public static native void accessStaticInstanceField();
}
