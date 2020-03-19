package com.hsf1002.sky.jni;

import com.hsf1002.sky.Animal;

public class ConstructorClass {
    static
    {
        System.loadLibrary("native-lib");
    }

    // 通过JNI调用构造函数创建Java对象
    public native Animal invokeAnimalConstructors();
    // 通过JNI调用其他函数创建Java对象
    public native Animal allocObjectConstructor();
}
