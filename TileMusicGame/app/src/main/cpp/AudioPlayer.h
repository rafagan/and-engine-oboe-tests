//
// Created by Rafagan Abreu on 22/11/18.
//

#ifndef TILEMUSICGAME_AUDIOPLAYER_H
#define TILEMUSICGAME_AUDIOPLAYER_H

#include <oboe/Oboe.h>

class AudioPlayer {
private:
    oboe::AudioStreamBuilder builder;
public:
    void playSound();
};


#endif //TILEMUSICGAME_AUDIOPLAYER_H
