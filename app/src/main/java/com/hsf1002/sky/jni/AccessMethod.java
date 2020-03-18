package com.hsf1002.sky.jni;

import com.hsf1002.sky.Animal;

public class AccessMethod {
    static
    {
        System.loadLibrary("native-lib");
    }

    // 访问普通成员函数
    public native void accessInstanceMethod(Animal animal);
    // 访问静态成员函数
    public native void accessStaticMethod(Animal animal);
}
