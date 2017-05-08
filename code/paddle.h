#ifndef PADDLE_H
#define PADDLE_H

#include <stdbool.h>
#include "gba.h"
#include "colour.h"

typedef struct Paddle Paddle;

struct Paddle{

    int x;
    int y;
    int height;
    int width;

    // for painting purposes
    int oldY;

    bool botUp;

};


void createPaddle(Paddle* paddle, int x, int y, int h, int w);
void renderPaddle(Paddle* paddle);
void paddleUp(Paddle* paddle);
void paddleDown(Paddle* paddle);
void paddleBotMove(Paddle* paddle);

#endif PADDLE_H