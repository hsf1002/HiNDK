//
// Created by  sky on 2020/3/15.
//

#ifndef HINDK_BASE_H
#define HINDK_BASE_H

#include <android/log.h>
#include <jni.h>

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

#endif //HINDK_BASE_H
