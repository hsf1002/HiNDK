#include <jni.h>
#include <string>

#include <person.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_hsf1002_sky_hindk_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    //std::string hello = "Hello world from C++";
    person p;
    return env->NewStringUTF(p.getString().c_str());
}
