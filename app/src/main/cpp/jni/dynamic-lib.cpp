//
// Created by  sky on 2020/3/15.
//

#include <base.h>
#include <jni.h>
#include <pthread.h>
#include <cstring>
#include <cstdio>
#include <unistd.h>

#ifdef __cplusplus
extern "C" {
#endif


#define  CLASS_NAME "com/hsf1002/sky/jni/DynamicLoad"

jobject threadObject;
jclass threadClass;
jmethodID threadMethod;

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

    set_JVM(vm);

    // 动态注册
    register_native_methods(env, CLASS_NAME, g_methods, 2);

    //LOGD("jni onload call");

    return JNI_VERSION_1_6;
}


extern "C"
JNIEXPORT void JNICALL
Java_com_hsf1002_sky_jni_InvokeMethod_nativeCallback(JNIEnv *env, jobject thiz, jobject cb) {
    // 获取类名
    jclass cls = env->GetObjectClass(cb);
    // 根据函数名+参数类型返回类型获取回调函数ID
    jmethodID mid = env->GetMethodID(cls, "callback", "()V");
    // 调用回调函数
    env->CallVoidMethod(cb, mid);
}


void *thread_cb(void *)
{
    JavaVM *gvm = get_JVM();
    JNIEnv *env = nullptr;

    if (0 == gvm->AttachCurrentThread(&env, nullptr))
    {
        env->CallVoidMethod(threadObject, threadMethod);
        gvm->DetachCurrentThread();
    }

    return nullptr;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_hsf1002_sky_jni_InvokeMethod_nativeThreadCallback(JNIEnv *env, jobject thiz, jobject cb) {
    threadObject = env->NewGlobalRef(cb);
    threadClass = env->GetObjectClass(cb);
    threadMethod = env->GetMethodID(threadClass, "callback", "()V");

    pthread_t handle;
    pthread_create(&handle, nullptr, thread_cb, nullptr);
}

struct Person
{
    char name[32];
    int age;
};

void *handle_thr(void *arg)
{
    Person *p = static_cast<Person *>(arg);
    printf("handle_thr name = %s\n", p->name);
    printf("handle_thr age = %d\n", p->age);

    sleep(3);
    return reinterpret_cast<void *>(p->age);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_hsf1002_sky_jni_JNIThread_createNativeThread(JNIEnv *env, jobject thiz) {
    pthread_t thr;
    int ret;
    struct Person person;
    strcpy(person.name, "sky");
    person.age = 24;

    if ((ret = pthread_create(&thr, nullptr, handle_thr, &person)) == 0)
    {
        // success;
    } else
    {
        // failed;
    }

    void *status = nullptr;
    pthread_join(thr, &status);
    printf("jni thread exit status = %d\n", status);
}

pthread_t wait_thr;
pthread_t notify_thr;
pthread_mutex_t mutex;
pthread_cond_t cond;
bool flag = false;

void *handle_wait_thr(void *)
{
    pthread_mutex_lock(&mutex);

    while (!flag)
    {
        pthread_cond_wait(&cond, &mutex);
    }

    pthread_mutex_unlock(&mutex);

    return nullptr;
}

void *handle_notify_thr(void *)
{
    pthread_mutex_lock(&mutex);
    flag = true;
    pthread_mutex_unlock(&mutex);

    pthread_cond_signal(&cond);

    return nullptr;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_hsf1002_sky_jni_JNIThread_waitNativeThread(JNIEnv *env, jobject thiz) {
    pthread_mutex_init(&mutex, nullptr);
    pthread_cond_init(&cond, nullptr);

    pthread_create(&wait_thr, nullptr, handle_wait_thr, nullptr);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_hsf1002_sky_jni_JNIThread_notifyNativeThread(JNIEnv *env, jobject thiz) {
    pthread_create(&notify_thr, nullptr, handle_notify_thr, nullptr);
}

#ifdef __cplusplus
}
#endif
