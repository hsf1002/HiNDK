//
// Created by  sky on 2020-02-18.
//
#include <jni.h>
#include <string>


#ifdef __cplusplus
extern "C" {
#endif


JNIEXPORT jint JNICALL Java_com_hsf1002_sky_Hello_intFromJNI(
        JNIEnv* env,
        jobject /* this */, jint x, jint y) {
    //jint i = 2048;

    return x + y;
}

JNIEXPORT jstring JNICALL Java_com_hsf1002_sky_Hello_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello, what a big world!";

    return env->NewStringUTF(hello.c_str());
}


#ifdef __cplusplus
}
#endif