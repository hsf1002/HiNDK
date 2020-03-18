//
// Created by  sky on 2020/3/15.
//

#ifndef HINDK_BASE_H
#define HINDK_BASE_H

#include <android/log.h>
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

#define  LOG_TAG "sky"

#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG, __VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG, __VA_ARGS__)
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG, __VA_ARGS__)
#define LOGF(...)  __android_log_print(ANDROID_LOG_FATAL,LOG_TAG, __VA_ARGS__)


/********************** 基本类型 ************************/
//java类型	Native类型	符号属性	字长
//boolean	jboolean	无符号	8位
//byte	    jbyte	    有符号	8位
//char	    jchar	    无符号	16位
//short	    jshort	    有符号	16位
//int	    jint	    有符号	32位
//long	    jlong	    有符号	64位
//float	    jfloat	    有符号	32位
//double	jdouble	    有符号	64位


/********************** 引用类型 ************************/
//java类型	            Native类型
//java.lang.Class	    jclass
//java.lang.Throwable	jthrowable
//java.lang.String	    jstring
//java.lang.Object[]	jobjectArray
//Boolean[]	            jbooleanArray
//Byte[]	            jbyteArray
//Char[]	            jcharArray
//Short[]	            jshortArray
//int[]	                jintArray
//long[]	            jlongArray
//float[]	            jfloatArray
//double[]	            jdoubleArray


/********************** 类 ************************/
//java    native
//boolean    Z
//byte       B
//char       C
//short      S
//int        I
//long       J
//float      F
//double     D
/*
//String     Ljava/lang/String;
//Class      Ljava/lang/Class;
//Throwable  Ljava/lang/Throwable;
//int[]      [I
//Object[]   [Ljava/lang/Object;

当一个函数不需要返回参数类型时，就使用”V”来表示
()Ljava/lang/String;     String f();
(ILjava/lang/Class;)J    long f(int i, Class c);
([B)V                    void String(byte[] bytes);

()V                      void Func();
(II)V                    void Func(int, int);
(Ljava/lang/String;Ljava/lang/String;)I  int Func(String,String)
*/

void set_JVM(JavaVM *jvm);

JavaVM *get_JVM();

#ifdef __cplusplus
}
#endif
#endif //HINDK_BASE_H
