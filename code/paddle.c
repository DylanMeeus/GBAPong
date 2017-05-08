#include "paddle.h"


void createPaddle(Paddle* paddle, int x, int y, int h, int w){
    paddle->x = x;
    paddle->y =y;
    paddle->oldY = y;
    paddle->height = h;
    paddle->width = w;
}

void renderPaddle(Paddle* paddle){

    int oldY = paddle->oldY;
    if(oldY != 0){
        int newY = paddle->y;
        int deltaY = newY - oldY;
        if(deltaY > 0){
            drawRectangle(paddle->x, oldY, paddle->width, deltaY, BLACK);
        } else {
            drawRectangle(paddle->x, oldY+paddle->height, paddle->width, deltaY*-1, BLACK);
        }

    }
    drawRectangle(paddle->x,paddle->y,paddle->width,paddle->height,WHITE);
    paddle->oldY = paddle->y;
}

void paddleUp(Paddle* paddle){
    paddle->y -= 1;
}

void paddleDown(Paddle* paddle){
    paddle->y += 1;
}

void  paddleBotMove(Paddle* paddle){
    if(paddle->botUp){
        paddleUp(paddle);
        if(paddle->y == 0){
            paddle->botUp = false;
        }
    } else {
        paddleDown(paddle);
        if((paddle->y+paddle->height) == SCREEN_HEIGHT){
            paddle->botUp = true;
        }
    }
}