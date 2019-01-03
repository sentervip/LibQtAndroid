#ifndef USQ_H
#define USQ_H
#include <jni.h>
#include "usq_global.h"
#include <android/log.h>


#define LOG(...)     __android_log_print(ANDROID_LOG_INFO,"MAVT",__VA_ARGS__)
#define LOGE(...)    __android_log_print(ANDROID_LOG_ERROR,"MAVT",__VA_ARGS__)
#define LOGL()       LOGE("L=%d",__LINE__);

#define JNI_MODULE_PACKAGE   "com/example/yons/test"
#define JNI_CLASS_USQ        "com/example/yons/test/MainActivity"
#define JNI_USQ_EXCEPTION    "com/example/yons/test/MainActivity/exceptions/IjkMediaException"


/*
class USQSHARED_EXPORT USQ
{

public:
    USQ();
};
*/
#endif // USQ_H
