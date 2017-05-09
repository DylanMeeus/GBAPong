#include "game.h"



Paddle bot; // the bot-player
Player player;
Ball ball;

bool initialised = false;

bool roundStarted = false;

/*
* One tick in the game.
* Progress game state, and draw
*/
void tick(){
    updateState();
    draw();
}


void updateState(){

    if(initialised){
        key_poll();
        handleGameInput();

        if(roundStarted){
            paddleBotMove(&bot);
            moveBall(&ball);
            checkBallCollision(&ball,&bot,&player);
        }
    } else {
        initGame();
        initialised = true;
    }

}


/*
* Check the state of the round.
*/
bool isRoundOver(){

}

/*
* Setup of the game
*/
void initGame(){
    createPaddle(&bot,200,10,2,25,10);
    createPlayer(&player, 20,10,25,10);
    // setup ball in the middle of the screen.
    createBall(&ball,SCREEN_WIDTH >> 1,SCREEN_HEIGHT >> 1,10,10);
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

    if(key_is_down(KEY_A)){
        if(!roundStarted){
            setBallVelocity(&ball, 2,2);
            roundStarted = true;
        }
    }

    if(key_is_down(KEY_START)){
        // todo: pause the game
    }
}
