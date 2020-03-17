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
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_hsf1002_sky_jni_BasicType_callNativeInt(JNIEnv *env, jobject thiz, jint num) {
    int i = num + 1;
    return i;
}

extern "C"
JNIEXPORT jbyte JNICALL
Java_com_hsf1002_sky_jni_BasicType_callNativeByte(JNIEnv *env, jobject thiz, jbyte b) {
    jbyte jb = b + 1;
    return jb;
}

extern "C"
JNIEXPORT jchar JNICALL
Java_com_hsf1002_sky_jni_BasicType_callNativeChar(JNIEnv *env, jobject thiz, jchar ch) {
    jchar jc = ch + 1;
    return jc;
}

extern "C"
JNIEXPORT jshort JNICALL
Java_com_hsf1002_sky_jni_BasicType_callNativeShort(JNIEnv *env, jobject thiz, jshort sh) {
    short sho = sh + 1;
    return  sho;
}

extern "C"
JNIEXPORT jfloat JNICALL
Java_com_hsf1002_sky_jni_BasicType_callNativeFloat(JNIEnv *env, jobject thiz, jfloat f) {
    float  fl = f + 1;
    return fl;
}

extern "C"
JNIEXPORT jlong JNICALL
Java_com_hsf1002_sky_jni_BasicType_callNativeLong(JNIEnv *env, jobject thiz, jlong l) {
    long lo = l + 1;
    return lo;
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_hsf1002_sky_jni_BasicType_callNativeBool(JNIEnv *env, jobject thiz, jboolean b) {
    bool bo = !b;
    return bo;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_hsf1002_sky_jni_StringType_callNativeString(JNIEnv *env, jobject thiz, jstring str_) {
    const char *str = env->GetStringUTFChars(str_, 0);
    //LOGD("java string is %s", str);
    env->ReleaseStringUTFChars(str_, str);

    return env->NewStringUTF("this is C style string");
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_hsf1002_sky_jni_StringType_stringMethod(JNIEnv *env, jobject thiz, jstring str_) {
    const char *str = env->GetStringUTFChars(str_, 0);
    int len = env->GetStringLength(str_);
    //LOGD("java string length is %d", len);

    char buf[128];
    env->GetStringUTFRegion(str_, 0, len - 1, buf); // 长度减1后拷贝到buf
    //LOGD("java string is %s", buf);

    env->ReleaseStringUTFChars(str_, str);

    return len;
}

#ifdef __cplusplus
}
#endif