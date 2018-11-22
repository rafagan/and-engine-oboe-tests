//
// Created by Rafagan Abreu on 22/11/18.
//

#ifndef TILEMUSICGAME_AUDIOPLAYER_H
#define TILEMUSICGAME_AUDIOPLAYER_H

#include <oboe/Oboe.h>
#include "SoundRecording.h"

constexpr int kSampleRateHz = 48000;
constexpr int kBufferSizeInBursts = 2;

class AudioPlayer: public oboe::AudioStreamCallback {
private:
    AAssetManager* assetManager{nullptr};
    SoundRecording* backingTrack{nullptr};
    SoundRecording* clap{nullptr};
    oboe::AudioStream *audioStream{nullptr};

    oboe::DataCallbackResult onAudioReady(
            oboe::AudioStream *oboeStream,
            void *audioData,
            int32_t numFrames) override;
public:
    explicit AudioPlayer(AAssetManager* assetManager);
    void playSound();
};


#endif //TILEMUSICGAME_AUDIOPLAYER_H
