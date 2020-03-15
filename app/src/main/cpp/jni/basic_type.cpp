//
// Created by  sky on 2020/3/16.
//
#include <jni.h>
#include <string>
#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_hsf1002_sky_jni_BasicType_callNativeDouble(JNIEnv *env, jobject thiz, jdouble d) {
    double dou = d + 1;
    return dou;
}extern "C"
JNIEXPORT jint JNICALL
Java_com_hsf1002_sky_jni_BasicType_callNativeInt(JNIEnv *env, jobject thiz, jint num) {
    int i = num + 1;
    return i;
}extern "C"
JNIEXPORT jbyte JNICALL
Java_com_hsf1002_sky_jni_BasicType_callNativeByte(JNIEnv *env, jobject thiz, jbyte b) {
    jbyte jb = b + 1;
    return jb;
}extern "C"
JNIEXPORT jchar JNICALL
Java_com_hsf1002_sky_jni_BasicType_callNativeChar(JNIEnv *env, jobject thiz, jchar ch) {
    jchar jc = ch + 1;
    return jc;
}extern "C"
JNIEXPORT jshort JNICALL
Java_com_hsf1002_sky_jni_BasicType_callNativeShort(JNIEnv *env, jobject thiz, jshort sh) {
    short sho = sh + 1;
    return  sho;
}extern "C"
JNIEXPORT jfloat JNICALL
Java_com_hsf1002_sky_jni_BasicType_callNativeFloat(JNIEnv *env, jobject thiz, jfloat f) {
    float  fl = f + 1;
    return fl;
}extern "C"
JNIEXPORT jlong JNICALL
Java_com_hsf1002_sky_jni_BasicType_callNativeLong(JNIEnv *env, jobject thiz, jlong l) {
    long lo = l + 1;
    return lo;
}

#ifdef __cplusplus
}
#endif