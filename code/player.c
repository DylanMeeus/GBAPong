#include "player.h"


Paddle playerPaddle;

void createPlayer(Player* player, int x, int y, int h, int w){
    createPaddle(&playerPaddle,x,y,h,w);
    player->paddle = &playerPaddle;
}

void renderPlayer(Player* player){
    renderPaddle(player->paddle);
}
