#include "gba.h"
#include "colour.h"
#include "drawing.h"


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
        if ( x > SCREEN_WIDTH * (SCREEN_HEIGHT/10)) {
         x = 0;
        }
        if (x != 0)
        {
            int last = x - 10;
          //  drawRectangle(last % SCREEN_WIDTH, (last / SCREEN_WIDTH) * 10, 10, 10,BLACK);
        }

        drawRectangle(10,10,10,30,WHITE);

	}

    return 0;
}

