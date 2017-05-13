#include "sound.h"
#include <stdbool.h>


// did we already init sound?
bool soundInit = false;

bool inLoop = false;

void enableSound(bool enable){
    soundInit = enable;
}

int timer = 0;
void playSound(signed char* input){

        // guard statement. Ignore this when there is no sound requested
        if(soundInit == false){
            return;
        }

        if(inLoop == true) {
            timer++;
            if(timer > 5){
                timer = 0;
                REG_DMA1CNT = 0;
                soundInit = false;
                inLoop = false;
            }
            return;
        }

       REG_TM0D   = TIMER_INTERVAL;
       REG_TM0CNT = TIMER_ENABLED;

       REG_SOUNDCNT_H = SND_OUTPUT_RATIO_100 |
                                DSA_OUTPUT_RATIO_100 |
                                DSA_OUTPUT_TO_BOTH |
                                DSA_TIMER0 |
                                DSA_FIFO_RESET;

        REG_DMA1SAD = (uint32)(input);
        REG_DMA1DAD = (uint32)REG_FIFO_A;
        REG_DMA1CNT = ENABLE_DMA | START_ON_FIFO_EMPTY | WORD_DMA | DMA_REPEAT;
        inLoop = true;
}