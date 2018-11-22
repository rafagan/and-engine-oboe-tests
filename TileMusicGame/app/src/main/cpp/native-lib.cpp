#include <jni.h>
#include <string>
#include <iostream>
#include <android/log.h>
#include <oboe/Oboe.h>
#include "androidbuf.h"
#include "logging_macros.h"

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


extern "C" JNIEXPORT jint JNICALL
Java_tilemusicgame_tutorial_rafagan_tilemusicgame_NativeCallsKt_playSound(
        JNIEnv *env,
        jobject /* this */) {

    LOGI("Inciando algoritmo para tocar som");

    AudioStreamBuilder builder;
    builder.setDirection(oboe::Direction::Output);
    builder.setPerformanceMode(oboe::PerformanceMode::LowLatency);
    builder.setSharingMode(oboe::SharingMode::Exclusive);

    AudioStream *stream = nullptr;
    Result result = builder.openStream(&stream);
    if (result != Result::OK){
        LOGE("Failed to create stream. Error: %s", oboe::convertToText(result));
    }

    LOGI("Finalzando algoritmo para tocar som");
    return 0;
}