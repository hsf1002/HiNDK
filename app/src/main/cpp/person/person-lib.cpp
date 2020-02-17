#include <jni.h>
#include <string>

#include <person.h>

#ifdef __cplusplus
extern "C" {
#endif


JNIEXPORT jstring JNICALL Java_com_hsf1002_sky_Person_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    //std::string hello = "Hello world from C++";
    person p;
    return env->NewStringUTF(p.getString().c_str());
}

#ifdef __cplusplus
}
#endif