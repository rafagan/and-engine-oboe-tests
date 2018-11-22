//
// Created by Rafagan Abreu on 22/11/18.
//


#include "AudioPlayer.h"

#include "logging_macros.h"

using namespace oboe;
constexpr int kChannelCount{2};

AudioPlayer::AudioPlayer(AAssetManager* assetManager)
        : assetManager(assetManager)
{
    backingTrack = SoundRecording::loadFromAssets(assetManager, "music.raw");
    clap = SoundRecording::loadFromAssets(assetManager, "clap.raw");
}

void AudioPlayer::playSound() {
    backingTrack->setPlaying(true);
    backingTrack->setLooping(true);

    // Create a builder
    AudioStreamBuilder builder;
    builder.setFormat(AudioFormat::I16);
    builder.setChannelCount(2);
    builder.setSampleRate(kSampleRateHz);
    builder.setCallback(this);
    builder.setPerformanceMode(PerformanceMode::LowLatency);
    builder.setSharingMode(SharingMode::Exclusive);

    Result result = builder.openStream(&audioStream);
    if (result != Result::OK){
        LOGE("Failed to open stream. Error: %s", convertToText(result));
    }

    // Reduce stream latency by setting the buffer size to a multiple of the burst size
    auto setBufferSizeResult = audioStream->setBufferSizeInFrames(audioStream->getFramesPerBurst() * kBufferSizeInBursts);
    if (setBufferSizeResult != Result::OK){
        LOGW("Failed to set buffer size. Error: %s", convertToText(setBufferSizeResult.error()));
    }

    result = audioStream->requestStart();
    if (result != Result::OK){
        LOGE("Failed to start stream. Error: %s", convertToText(result));
    }
}

DataCallbackResult AudioPlayer::onAudioReady(AudioStream *oboeStream, void *audioData, int32_t numFrames) {
    for (int i = 0; i < numFrames; ++i) {
        backingTrack->renderAudio(static_cast<int16_t*>(audioData)+(kChannelCount*i), 1);
    }

    return DataCallbackResult::Continue;
}
