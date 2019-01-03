#include "usq.h"
#include <assert.h>
#include <QAndroidJniEnvironment>
#include <QAndroidJniObject>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <unistd.h>
//#include <QLabel>

//QObject *g_listener = 0;
static JavaVM* g_jvm;


#ifdef __cplusplus
extern "C"{
#else

#endif

 //jstring   Java_com_example_yons_test_MainActivity_GetQtVersion(JNIEnv *env, jobject thiz)
static jstring GetQtVersion(JNIEnv *env, jobject thiz)
{
    LOGE("enter jni ver");
    QString version(qVersion());
   // QAndroidJniObject javaString = QAndroidJniObject::fromString(version);
   // LOGE("jni ver:"+version);
   // return javaString.object<jstring>();
    char str[50];
    snprintf(str,"%s",version.toStdString().c_str());
    jstring app_str = env->NewStringUTF(str);
    return app_str;
}


static jstring GetQtVersion2(JNIEnv *env, jobject thiz, jint arg)
{
    qDebug() <<"arg:"<<arg;
    QString version(qVersion());
    QAndroidJniObject javaString = QAndroidJniObject::fromString(version);
    return javaString.object<jstring>();
}
/*
// result: RESULT_OK(-1),RESULT_CANCLED(0)
static void onLocationReady(JNIEnv *env, jobject thiz,int result, double longitude, double latitude)
{
    qDebug() << "onLocationReady, result - " << result
             << " longtitude - " << longitude
             << " latitude - " << latitude;
    QString info = QString("%1,%2").arg(longitude).arg(latitude);
    //QCoreApplication::postEvent(g_listener, new SimpleCustomEvent(result == -1 ? 1: -1, info));
}

static void onImageCaptured(JNIEnv *env, jobject thiz,int result, jstring imageFile)
{
    QString image;
    const char *nativeString = env->GetStringUTFChars(imageFile, 0);
    image = nativeString;
    env->ReleaseStringUTFChars(imageFile, nativeString);
    qDebug() << "onImageCaptured, result - " << result << " image - " << image;
    int ret = result;
    if(result == -1 && QFile::exists(image))
    {
        ret = 2;
    }
    else
    {
        ret = -2;
        qDebug() << "could not read the captured image!";
    }
    //QCoreApplication::postEvent(g_listener, new SimpleCustomEvent(ret, image));
}
*/
jclass g_extendsNative = 0;

bool registerNativeMethods(JNIEnv* env)
{
    JNINativeMethod methods[] {
        {"GetQtVersion","()Ljava/lang/String;", (void*)GetQtVersion},
        //{"OnLocationReady", "(IDD)V", (void*)onLocationReady},
        //{"OnImageCaptured", "(ILjava/lang/String;)V", (void*)onImageCaptured}
    };

    const char *classname = JNI_CLASS_USQ;

    jclass clazz;
    //QAndroidJniEnvironment env;

    QAndroidJniObject javaClass(classname);
    clazz = env->FindClass(classname);
    LOGE("find clazz=%d",clazz);
    bool result = false;
    if(clazz)
    {
        jint ret = env->RegisterNatives(clazz,
                                        methods,
                                        sizeof(methods) / sizeof(methods[0]));
        env->DeleteLocalRef(clazz);
        LOGE("RegisterNative ret=%d",ret);
        result = ret >= 0;
    }
    if(env->ExceptionCheck()) env->ExceptionClear();
    return result;
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    JNIEnv* env = NULL;

    LOGE("enter jni onLoad");
    g_jvm = vm;  LOGL();

    if ( vm->GetEnv( (void**) &env, JNI_VERSION_1_6) != JNI_OK) {
        LOGE("exit,device jni ver=0x%x", vm->GetEnv( (void**)&env, JNI_VERSION_1_6));
        return -1;
    }
    assert(env != NULL);
    registerNativeMethods(env);
    LOG("jni_onload over");
    //QLabel * TestLabe = new QLabel("test");

    return JNI_VERSION_1_6;
}
/*
USQ::USQ()
{
   qDebug() <<"enter USQ";
}
*/
#ifdef __cplusplus
}
#endif
