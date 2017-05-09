#include "game.h"



Paddle bot; // the bot-player
Player player;
Ball ball;

bool started = false;

/*
* One tick in the game.
* Progress game state, and draw
*/
void tick(){
    updateState();
    draw();
}


void updateState(){

    if(started){
        key_poll();
        handleGameInput();

        paddleBotMove(&bot);
        moveBall(&ball);
        checkBallCollision(&ball,&bot,&player);
    } else {
        initGame();
        started = true;
    }

}

/*
* Setup of the game
*/
void initGame(){
    createPaddle(&bot,200,10,0,25,10);
    createPlayer(&player, 20,10,25,10);
    createBall(&ball,50,50,10,10);
}

void draw(){
    renderPaddle(&bot);
    renderPlayer(&player);
    renderBall(&ball);
}

void handleGameInput()
{
    if (key_is_down(KEY_UP))
    {
        paddleUp(player.paddle);
    }
    else if (key_is_down(KEY_DOWN))
    {
        paddleDown(player.paddle);
    }
}
