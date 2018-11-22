//
// Created by Rafagan Abreu on 22/11/18.
//


#include "AudioPlayer.h"

#include "logging_macros.h"

using namespace oboe;

AudioPlayer::AudioPlayer(AAssetManager* assetManager)
        : assetManager(assetManager)
{
    builder.setDirection(oboe::Direction::Output);
    builder.setPerformanceMode(oboe::PerformanceMode::LowLatency);
    builder.setSharingMode(oboe::SharingMode::Exclusive);
    builder.setCallback(this);

    sound = SoundRecording::loadFromAssets(assetManager, "CLAP.raw");
}

void AudioPlayer::playSound() {
    sound->setPlaying(true);
    sound->setLooping(true);

    AudioStream *stream = nullptr;
    Result result = builder.openStream(&stream);
    if (result != Result::OK) {
        LOGE("Failed to create stream. Error: %s", convertToText(result));
    }

    result = stream->requestStart();
    if (result != Result::OK) {
        LOGE("Error starting stream. Error: %s", convertToText(result));
    }
}

DataCallbackResult AudioPlayer::onAudioReady(AudioStream *oboeStream, void *audioData, int32_t numFrames) {
//    int64_t nextClapEvent;

//    for (int i = 0; i < numFrames; ++i) {
//
//        if (mClapEvents.peek(nextClapEvent) && mCurrentFrame == nextClapEvent){
//            mClap->setPlaying(true);
//            mClapEvents.pop(nextClapEvent);
//        }
//        mMixer.renderAudio(static_cast<int16_t*>(audioData)+(kChannelCount*i), 1);
//        mCurrentFrame++;
//    }
//
//    mLastUpdateTime = nowUptimeMillis();

    return DataCallbackResult::Continue;
}