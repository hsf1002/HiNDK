#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_hsf1002_sky_hindk_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello world from C++";
    return env->NewStringUTF(hello.c_str());
}
