//
// Created by  sky on 2020/3/18.
//

#include "base.h"

static JavaVM *gVM = nullptr;

#ifdef __cplusplus
extern "C" {
#endif

void set_JVM(JavaVM *jvm)
{
    gVM = jvm;
}

JavaVM *get_JVM()
{
    return gVM;
}

#ifdef __cplusplus
}
#endif