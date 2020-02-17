#include <jni.h>
#include <string>

#include <teacher.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jstring JNICALL Java_com_hsf1002_sky_Teacher_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    //std::string hello = "Hello world from C++";
    teacher t;
    return env->NewStringUTF(t.getString().c_str());
}

#ifdef __cplusplus
}
#endif