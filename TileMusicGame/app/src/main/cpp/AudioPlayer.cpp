//
// Created by Rafagan Abreu on 22/11/18.
//


#include "AudioPlayer.h"

#include "logging_macros.h"

using namespace oboe;

void AudioPlayer::playSound() {
    AudioStreamBuilder builder;
    builder.setDirection(oboe::Direction::Output);
    builder.setPerformanceMode(oboe::PerformanceMode::LowLatency);
    builder.setSharingMode(oboe::SharingMode::Exclusive);

    AudioStream *stream = nullptr;
    Result result = builder.openStream(&stream);
    if (result != Result::OK){
        LOGE("Failed to create stream. Error: %s", oboe::convertToText(result));
    }


}
