#include "ball.h"


void createBall(Ball* ball, int x, int y, int h, int w){
    ball->x = x;
    ball->y = y;
    ball->height = h;
    ball->width = w;

    // initial velocity
    ball->velX = 2;
}
void renderBall(Ball* ball){

    if(ball->oldX != ball->x || ball->y != ball->oldY){
        // clear previous rectangle space
        drawRectangle(ball->oldX,ball->oldY,ball->width,ball->height,BLACK);
    }
    drawRectangle(ball->x,ball->y,ball->width,ball->height,CYAN);
    ball->oldX = ball->x;
    ball->oldY = ball->y;
}

void moveBall(Ball* ball){
    ball->x += ball->velX;
}

void checkBallCollision(Ball* ball, Paddle* bot, Player* player){
    // check for collision, update the velocity of the ball.

    if((ball->x + ball->width) >= SCREEN_WIDTH){
        ball->velX = -2;
    }
    // bot paddle check
    else if (((ball->x + ball->width) >= bot->x
            && (ball->x + ball->width) <= (bot->x + bot->width))
            && (ball->y + ball->height) >= bot->y
            && (ball->y + ball->height) <= (bot->y + bot->height)
            ){
        ball->velX = -2;
    }
    // left wall check
    else if(ball->x <= 0){
        ball->velX = 2;
    }
     // player check
    else if(
        (ball->x) <= (player->paddle->x + player->paddle->width)
          && (ball->x - ball->width) >= (player->paddle->x)
          && ball->y + ball->height >= player->paddle->y
          && (ball->y) < (player->paddle->y + player->paddle->height)
    ){
        ball-> velX = 2;
    }

}