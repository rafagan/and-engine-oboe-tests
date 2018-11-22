#include <jni.h>
#include <string>
#include <iostream>
#include <android/log.h>
#include <oboe/Oboe.h>
#include "androidbuf.h"
#include "logging_macros.h"
#include "AudioPlayer.h"

using namespace std;
using namespace oboe;

extern "C" JNIEXPORT jstring JNICALL
Java_tilemusicgame_tutorial_rafagan_tilemusicgame_NativeCallsKt_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    std::cout.rdbuf(new androidbuf);
    cout << "Testeeeeeeeeeeeeeeeeee" << endl;
    __android_log_print(ANDROID_LOG_INFO, "teste", "This is my first log in LogCat");
    delete std::cout.rdbuf(0);

    return env->NewStringUTF(hello.c_str());
}


AudioPlayer player;

extern "C" JNIEXPORT jint JNICALL
Java_tilemusicgame_tutorial_rafagan_tilemusicgame_NativeCallsKt_playSound(
        JNIEnv *env,
        jobject /* this */) {

    LOGI("Inciando algoritmo para tocar som");
    player.playSound();
    LOGI("Finalzando algoritmo para tocar som");
    return 0;
}