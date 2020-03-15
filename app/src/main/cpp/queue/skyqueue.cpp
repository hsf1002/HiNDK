//
// Created by  sky on 2020-03-09.
//


#include <jni.h>
#include <string>
#include <android/log.h>
#include "../../../../../../../../../Library/Android/sdk/ndk-bundle/sysroot/usr/include/pthread.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_SIZE (1024 * 1024)
//typedef char DataType;

#define  LOG_TAG "sky"

#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG, __VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG, __VA_ARGS__)
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG, __VA_ARGS__)
#define LOGF(...)  __android_log_print(ANDROID_LOG_FATAL,LOG_TAG, __VA_ARGS__)

typedef struct
{

    int queue[MAX_SIZE];
    int front;                  // front pointer    always point to the top of the real data
    int rear;                   // rear pointer     point to the real data when not empty
    int count;                  // pointer 0 means empty, or full when front == rear
}SeqQueue;

static SeqQueue q;

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


// initialize
JNIEXPORT void JNICALL Java_com_hsf1002_sky_Auxinout_QueueInit(JNIEnv* env, jobject /* this */)
{
    q.front = 0;
    q.rear = 0;
    q.count = 0;
    printf("queue initializing.....\n");
}

JNIEXPORT jboolean JNICALL Java_com_hsf1002_sky_Auxinout_QueueEmpty(JNIEnv* env, jobject /* this */)
{
    if (q.count == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

JNIEXPORT jboolean JNICALL Java_com_hsf1002_sky_Auxinout_QueueFull(JNIEnv* env, jobject /* this */)
{
    if (q.front == q.rear && q.count > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// enqueue
JNIEXPORT jboolean JNICALL Java_com_hsf1002_sky_Auxinout_QueueEnqueue(JNIEnv* env, jobject ob/* this */, int x)
{
    int s = 0;

    if (Java_com_hsf1002_sky_Auxinout_QueueFull(env, ob))
    {
        printf("queue is full.\n");
        return false;
    }

    if (0 != (s = pthread_mutex_lock(&mutex)))
        perror("mutex lock error");

    q.queue[q.rear] = x;
    q.rear = (q.rear + 1) % MAX_SIZE;
    q.count++;

    if (0 != (s = pthread_mutex_unlock(&mutex)))
        perror("mutex unlock error");

    printf("queue enqueue data success, x = %d \n", x);
    return  true;
}

JNIEXPORT void JNICALL Java_com_hsf1002_sky_Auxinout_QueuePreset(JNIEnv* env, jobject ob /* this */)
{
    for (int i=0; i<10; ++i)
    {
        Java_com_hsf1002_sky_Auxinout_QueueEnqueue(env, ob, rand() % 100);
    }
}


// dequeue
JNIEXPORT jint JNICALL Java_com_hsf1002_sky_Auxinout_QueueDequeue(JNIEnv* env, jobject ob/* this */)
{
    int s = 0;
    int ret = 0;

    if (Java_com_hsf1002_sky_Auxinout_QueueEmpty(env, ob))
    {
        printf("queue is empty.\n");
        return -1;
    }

    if (0 != (s = pthread_mutex_lock(&mutex)))
        perror("mutex lock error");

    ret = q.queue[q.front];
    q.front = (q.front + 1) % MAX_SIZE;
    q.count--;

    if (0 != (s = pthread_mutex_unlock(&mutex)))
        perror("mutex unlock error");

    printf("queue dequeue data success, x = %d\n", ret);
    return ret;
}

JNIEXPORT void JNICALL Java_com_hsf1002_sky_Auxinout_QueuePrint(JNIEnv* env, jobject ob /* this */)
{
    //printf("queue data below.....................\n");
    //LOGD("queue data: count = %d ", q.count);
    //LOGD("print queue\n");
    //__android_log_print(ANDROID_LOG_DEBUG, "sky", "print queue\n");

    if (!Java_com_hsf1002_sky_Auxinout_QueueEmpty(env, ob))
    {
        for (int i=0; i<q.count; ++i)
        {
            //printf("count = %d , queue[%d] = %c \n", q.count, i, q.queue[i]);
            //LOGD("queue[%d] = %d", i, q.queue[i]);
        }
        printf("\n");
    }
}



#ifdef __cplusplus
}
#endif