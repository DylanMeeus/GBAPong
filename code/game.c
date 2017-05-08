#include "game.h"



Paddle bot; // the bot-player
Paddle player;

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
        paddleBotMove(&bot);
        paddleBotMove(&player);
    } else {
        initGame();
        started = true;
    }

}

/*
* Setup of the game
*/
void initGame(){
    createPaddle(&bot,200,10,25,10);
    createPaddle(&player,10,120,25,10);
}

void draw(){
    renderPaddle(&bot);
    renderPaddle(&player);
}