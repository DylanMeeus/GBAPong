#include "game.h"


typedef unsigned char      uint8;

Paddle bot; // the bot-player
Player player;
Ball ball;

ballSize = 7;
paddleHeight = 20;
paddleWidth = 5;

uint8 botScore = 0;
uint8 playerScore = 0;

bool initialised = false;
bool roundStarted = false;

/*
* One tick in the game.
* Progress game state, and draw
*/
void gameTick(){
    updateState();
    draw();
}


void updateState(){

    if(initialised){
        key_poll();
        handleGameInput();

        if(roundStarted){
            paddleBotMove(&bot,&ball);
            moveBall(&ball);
            checkBallCollision(&ball,&bot,&player);
            checkRoundOver();
        }
    } else {
        initGame();
        initialised = true;
    }

}


/*
* Check the state of the round.
*/
void checkRoundOver(){
    // the game is over if there is a collision with the left / right wall.

    if(ball.x <= 0){
        botScore++;
        roundStarted = false;
        resetRound();
    }

    if(ball.x+ball.width >= SCREEN_WIDTH){
        playerScore++;
        roundStarted = false;
        resetRound();
    }
}

/*
* Set round state to the beginning.
*/
void resetRound(){
    createBall(&ball,SCREEN_WIDTH >> 1,SCREEN_HEIGHT >> 1,ballSize,ballSize);
}

/*
* Setup of the game
*/
void initGame(){
    createPaddle(&bot,SCREEN_WIDTH - paddleWidth - 10,((SCREEN_HEIGHT >> 1) - (paddleHeight>>1)),2,paddleHeight,paddleWidth);
    createPlayer(&player, 10,((SCREEN_HEIGHT >> 1) - (paddleHeight>>1)),paddleHeight,paddleWidth);
    // setup ball in the middle of the screen.
    createBall(&ball,SCREEN_WIDTH >> 1,SCREEN_HEIGHT >> 1,ballSize,ballSize);
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
