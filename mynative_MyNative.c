#include "mynative_MyNative.h"

/*
 * Class:     mynative_MyNative
 * Method:    multi01
 * Signature: ([Ljava/lang/Double;[Ljava/lang/Double;)Ljava/lang/Double;
 */
JNIEXPORT jobject JNICALL Java_mynative_MyNative_multi01
(JNIEnv *env, jobject thisObj, jobjectArray dJNIArrayA, jobjectArray dJNIArrayB) {

    jclass classDouble = (*env)->FindClass(env, "java/lang/Double");
    jmethodID midDoubleValue = (*env)->GetMethodID(env, classDouble, "doubleValue", "()D");

    if (NULL == midDoubleValue) return NULL;

    jsize length = (*env)->GetArrayLength(env, dJNIArrayA);
    
    jdouble sum = 0.0;
    int i;

    for (i=0; i<length; i++) {
        jobject objDoubleA = (*env)->GetObjectArrayElement(env, dJNIArrayA, i);
        jobject objDoubleB = (*env)->GetObjectArrayElement(env, dJNIArrayB, i);

        if (NULL == objDoubleA || NULL == objDoubleB) return NULL;

        jdouble valueA = (*env)->CallDoubleMethod(env, objDoubleA, midDoubleValue);
        jdouble valueB = (*env)->CallDoubleMethod(env, objDoubleB, midDoubleValue);

        sum += valueA * valueB;
    }

    jmethodID midDoubleInit = (*env)->GetMethodID(env, classDouble, "<init>", "(D)V");
    if (NULL == midDoubleInit) return NULL;
    jobject result = (*env)->NewObject(env, classDouble, midDoubleInit, (double)sum);

    return result;
}

/*
* Class:     mynative_MyNative
* Method:    multi02
* Signature: ([Ljava/lang/Double;)Ljava/lang/Double;
*/
JNIEXPORT jobject JNICALL Java_mynative_MyNative_multi02
(JNIEnv *env, jobject thisObj, jobjectArray dJNIArrayA) {

    jclass myNativeClass = (*env)->GetObjectClass(env, thisObj);
    jmethodID getBMethodId = (*env)->GetMethodID(env, myNativeClass, "getB", "()[Ljava/lang/Double;");
    if (NULL == getBMethodId) return NULL;

    jclass classDouble = (*env)->FindClass(env, "java/lang/Double");
    jmethodID midDoubleValue = (*env)->GetMethodID(env, classDouble, "doubleValue", "()D");
    if (NULL == midDoubleValue) return NULL;

    jobjectArray dJNIArrayB = (jobjectArray) (*env)->CallObjectMethod(env, thisObj, getBMethodId);
    jsize length = (*env)->GetArrayLength(env, dJNIArrayA);
    
    jdouble sum = 0.0;
    int i;

    for (i=0; i<length; i++) {
        jobject objDoubleA = (*env)->GetObjectArrayElement(env, dJNIArrayA, i);
        jobject objDoubleB = (*env)->GetObjectArrayElement(env, dJNIArrayB, i);

        if (NULL == objDoubleA || NULL == objDoubleB) return NULL;

        jdouble valueA = (*env)->CallDoubleMethod(env, objDoubleA, midDoubleValue);
        jdouble valueB = (*env)->CallDoubleMethod(env, objDoubleB, midDoubleValue);

        sum += valueA * valueB;
    }

    jmethodID midDoubleInit = (*env)->GetMethodID(env, classDouble, "<init>", "(D)V");
    if (NULL == midDoubleInit) return NULL;
    jobject result = (*env)->NewObject(env, classDouble, midDoubleInit, (double)sum);

    return result;
}

/*
* Class:     mynative_MyNative
* Method:    multi03
* Signature: ()V
*/
JNIEXPORT void JNICALL Java_mynative_MyNative_multi03
(JNIEnv *env, jobject thisObj) {
    jclass myNativeClass = (*env)->GetObjectClass(env, thisObj);
    jmethodID setAMethodId = (*env)->GetMethodID(env, myNativeClass, "setA", "([Ljava/lang/Double;)V");
    jmethodID setBMethodId = (*env)->GetMethodID(env, myNativeClass, "setB", "([Ljava/lang/Double;)V");
    jmethodID multi04MethodId = (*env)->GetMethodID(env, myNativeClass, "multi04", "()V");
    jclass classDouble = (*env)->FindClass(env, "java/lang/Double");
    jmethodID midDoubleInit = (*env)->GetMethodID(env, classDouble, "<init>", "(D)V");

    if (NULL == setAMethodId || NULL == setBMethodId || NULL == multi04MethodId || NULL == midDoubleInit) return;

    int len = 3;
    double a[] = {3.0, 4.0, 5.0};
    double b[] = {6.0, 7.0, 8.0};

    
    jobjectArray aJNIArray = (*env)->NewObjectArray(env, len, classDouble, NULL);
    jobjectArray bJNIArray = (*env)->NewObjectArray(env, len, classDouble, NULL);

    int i;

    for (i=0; i<len; i++) {
        jobject elA = (*env)->NewObject(env, classDouble, midDoubleInit, a[i]);
        jobject elB = (*env)->NewObject(env, classDouble, midDoubleInit, b[i]);

        (*env)->SetObjectArrayElement(env, aJNIArray, i, elA);
        (*env)->SetObjectArrayElement(env, bJNIArray, i, elB);
    }

    (*env)->CallObjectMethod(env, thisObj, setAMethodId, aJNIArray);
    (*env)->CallObjectMethod(env, thisObj, setBMethodId, bJNIArray);
    (*env)->CallObjectMethod(env, thisObj, multi04MethodId);
}