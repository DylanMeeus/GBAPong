#include "gba.h"
#include "colour.h"
#include "drawing.h"
#include "game.h"

// type defintions
typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned int       uint32;



/*
* Do nothing when in VBlank / HBlank
*/
inline void vsync()
{
  while (REG_VCOUNT >= 160);
  while (REG_VCOUNT < 160);
}

int main()
{
    REG_DISPLAYCONTROL = VIDEO_MODE | BG_MODE; //mode 3 graphics, we aren't actually using bg2 right now


    int x = 0;

    int y = 0;
    // game loop
    while(1)
	{
        vsync();
        tick();

	}

    return 0;
}

