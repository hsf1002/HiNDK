//
// Created by  sky on 2020/3/15.
//

#include <base.h>
#include <jni.h>

#define  CLASS_NAME "com/hsf1002/sky/jni/DynamicLoad"


/**
 * 对应于 getNativeString，函数名字没必要一样
 * @param env
 * @param jobj
 * @return
 */
jstring get_message(JNIEnv *env, jobject jobj)
{
    return env->NewStringUTF("this is dynamic msg");
}

/**
 * 对应于 sum，函数名字没必要一样
 * @param env
 * @param jobj
 * @param x
 * @param y
 * @return
 */
jint plus(JNIEnv *env, jobject jobj, int x, int y)
{
    return (x + y);
}

static JNINativeMethod g_methods[] =
        {
                // 函数名  (参数名)返回值  函数指针
                {"sum", "(II)I", (void *)plus},
                {"getNativeString", "()Ljava/lang/String;", (void *)get_message},

        };

/**
 * 根据指定类名进行动态注册
 * @param env
 * @param name
 * @param method
 * @param nMethods
 * @return
 */
int register_native_methods(JNIEnv *env, const char *name, JNINativeMethod *method, jint nMethods)
{
    jclass  jcls;

    if ((jcls = env->FindClass(name)) == nullptr)
    {
        return JNI_FALSE;
    }

    if (env->RegisterNatives(jcls, method, nMethods) < 0)
    {
        return JNI_FALSE;
    }

    return  JNI_TRUE;
}

/**
 * 系统会自动调用，动态注册，由于无需将c和java的函数名保持一致，省去了查找过程，效率更高
 * @param vm
 * @param reserved
 * @return
 */
JNIEXPORT int JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{
    JNIEnv *env;

    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK)
    {
        return JNI_FALSE;
    }

    // 动态注册
    register_native_methods(env, CLASS_NAME, g_methods, 2);

    //LOGD("jni onload call");

    return JNI_VERSION_1_6;
}