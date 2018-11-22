#include <jni.h>
#include <string>
#include <iostream>
#include <android/log.h>
#include <oboe/Oboe.h>
#include "androidbuf.h"
#include "logging_macros.h"
#include "AudioPlayer.h"
#include <android/asset_manager_jni.h>
#include <memory>

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


std::unique_ptr<AudioPlayer> player;

extern "C" JNIEXPORT void JNICALL
Java_tilemusicgame_tutorial_rafagan_tilemusicgame_NativeCallsKt_playSound(
        JNIEnv *env,
        jobject /* this */,
        jobject jAssetManager) {

    LOGI("Inciando algoritmo para tocar som");
    AAssetManager* assetManager = AAssetManager_fromJava(env, jAssetManager);
    player = make_unique<AudioPlayer>(assetManager);
    player->playSound();
    LOGI("Finalzando algoritmo para tocar som");
}