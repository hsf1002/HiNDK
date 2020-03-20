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

extern "C"
JNIEXPORT jstring JNICALL
Java_com_hsf1002_sky_jni_RefType_callNativeStringArray(JNIEnv *env, jobject thiz,
                                                       jobjectArray str_array) {
    int len = env->GetArrayLength(str_array);
    //LOGD("string array len is %d", len);

    jstring first_str = static_cast<jstring>(env->GetObjectArrayElement(str_array, 1));
    const char *str = env->GetStringUTFChars(first_str, 0);
    //LOGD("first str of string array is %s", str);
    env->ReleaseStringUTFChars(first_str, str);

    return env->NewStringUTF(str);
}


extern "C"
JNIEXPORT void JNICALL
Java_com_hsf1002_sky_jni_AccessField_accessInstanceField(JNIEnv *env, jobject thiz,
                                                         jobject animal) {
    // 获取类名
    jclass cls = env->GetObjectClass(animal);
    // 根据名称+类型获取成员
    jfieldID fid = env->GetFieldID(cls, "name", "Ljava/lang/String;");
    jstring str = env->NewStringUTF("gorilla");
    // 修改成员
    env->SetObjectField(animal, fid, str);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_hsf1002_sky_jni_AccessField_accessStaticField(JNIEnv *env, jobject thiz, jobject animal) {
    // 获取类名
    jclass cls = env->GetObjectClass(animal);
    // 根据名称+类型获取静态成员
    jfieldID fid = env->GetStaticFieldID(cls, "num", "I");
    int num = env->GetStaticIntField(cls, fid);
    // 修改静态成员
    env->SetStaticIntField(cls, fid, ++num);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_hsf1002_sky_jni_AccessField_accessStaticInstanceField(JNIEnv *env, jclass clazz) {
    // 根据名称+类型获取静态成员
    jfieldID fid = env->GetStaticFieldID(clazz, "number", "I");
    int num = env->GetStaticIntField(clazz, fid);
    // 修改静态成员
    env->SetStaticIntField(clazz, fid, ++num);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_hsf1002_sky_jni_AccessMethod_accessInstanceMethod(JNIEnv *env, jobject thiz,
                                                           jobject animal) {
    // 获取类名
    jclass cls = env->GetObjectClass(animal);
    // 根据函数名+参数类型返回类型获取成员函数ID
    jmethodID mid = env->GetMethodID(cls, "callInstanceMethod", "(I)V");
    // 调用普通成员函数，2是所传参数
    env->CallVoidMethod(animal, mid, 64);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_hsf1002_sky_jni_AccessMethod_accessStaticMethod(JNIEnv *env, jobject thiz,
                                                         jobject animal) {
    // 获取类名
    jclass cls = env->GetObjectClass(animal);
    // 根据函数名+参数类型返回类型获取成员函数ID
    jmethodID mid = env->GetStaticMethodID(cls, "callStaticMethod", "(Ljava/lang/String;)Ljava/lang/String;");
    jstring str = env->NewStringUTF("lion");
    // 调用静态成员函数，str是所传参数
    env->CallStaticObjectMethod(cls, mid, str);

    // 根据函数名+参数类型返回类型获取成员函数ID
    mid = env->GetStaticMethodID(cls, "callStaticMethod", "([Ljava/lang/String;I)Ljava/lang/String;");
    jclass strClass = env->FindClass("java/lang/String");
    int size = 3;
    // jni中没有StringArray
    jobjectArray strArray = env->NewObjectArray(size, strClass, nullptr);
    jstring strItem = env->NewStringUTF("duck");
    env->SetObjectArrayElement(strArray, 0, strItem);
    strItem = env->NewStringUTF("cow");
    env->SetObjectArrayElement(strArray, 1, strItem);
    strItem = env->NewStringUTF("horse");
    env->SetObjectArrayElement(strArray, 2, strItem);
    // 调用静态成员函数，str是所传参数
    env->CallStaticObjectMethod(cls, mid, strArray, size);
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_hsf1002_sky_jni_ConstructorClass_invokeAnimalConstructors(JNIEnv *env, jobject thiz) {
    // 获取类名
    jclass cls = env->FindClass("com/hsf1002/sky/Animal");
    // 根据函数名+参数类型返回类型获取构造函数ID，名称直接传init
    jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
    jstring str = env->NewStringUTF("tiger");
    // 构造一个新的对象
    jobject animal = env->NewObject(cls, mid, str);

    return animal;
}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_hsf1002_sky_jni_ConstructorClass_allocObjectConstructor(JNIEnv *env, jobject thiz) {
    // 获取类名
    jclass cls = env->FindClass("com/hsf1002/sky/Animal");
    // 根据函数名+参数类型返回类型获取构造函数ID，名称直接传init
    jmethodID mid = env->GetMethodID(cls, "<init>", "(Ljava/lang/String;)V");
    jstring str = env->NewStringUTF("elephant");
    // 构造一个新的对象
    jobject animal = env->AllocObject(cls);
    env->CallNonvirtualVoidMethod(animal, cls, mid, str);

    return animal;
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_hsf1002_sky_jni_Reference_useLocalReference(JNIEnv *env, jobject thiz) {
    // 获取类名，局部引用，函数返回自动销毁
    jclass local_ref = env->FindClass("java/lang/String");

    // 如果局部引用过多，则需手动销毁
//    for (int i=0; i<1024; i++)
//    {
//        jclass cls = env->FindClass("java/lang/String");
//        env->DeleteLocalRef(cls);
//    }
    // 根据函数名+参数类型返回类型获取构造函数ID，名称直接传init
    jmethodID mid = env->GetMethodID(local_ref, "<init>", "(Ljava/lang/String;)V");
    jstring str = env->NewStringUTF("local ref");
    // 构造一个新的对象
    return static_cast<jstring>(env->NewObject(local_ref, mid, str));
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_hsf1002_sky_jni_Reference_useGlobalReference(JNIEnv *env, jobject thiz) {
    static jclass global_ref = nullptr;

    // 第一次新建一个
    if (nullptr == global_ref)
    {
        jclass cls = env->FindClass("java/lang/String");
        global_ref = static_cast<jclass>(env->NewGlobalRef(cls));
        env->DeleteLocalRef(cls);
        // 不需要的时候手动释放
        //env->DeleteGlobalRef(global_ref);
    }
    else{
        // 以后直接返回
    }
    jmethodID mid = env->GetMethodID(global_ref, "<init>", "(Ljava/lang/String;)V");
    jstring str = env->NewStringUTF("global ref");
    // 构造一个新的对象
    return static_cast<jstring>(env->NewObject(global_ref, mid, str));
}

extern "C"
JNIEXPORT void JNICALL
Java_com_hsf1002_sky_jni_Reference_useWeakReference(JNIEnv *env, jobject thiz) {
    static jclass weak_ref = nullptr;

    // 第一次新建一个
    if (nullptr == weak_ref)
    {
        jclass cls = env->FindClass("java/lang/String");
        weak_ref = static_cast<jclass>(env->NewWeakGlobalRef(cls));
        env->DeleteLocalRef(cls);
    }
    else{
        // 以后直接返回
    }
    jmethodID mid = env->GetMethodID(weak_ref, "<init>", "(Ljava/lang/String;)V");
    // 判断弱引用是否被释放
    jboolean is_gc = env->IsSameObject(weak_ref, nullptr);

    if (is_gc)
    {
        // do something
    } else
    {
        // do nothing
    }
}

#ifdef __cplusplus
}
#endif