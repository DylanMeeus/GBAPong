#define REG_DISPLAYCONTROL *((volatile uint32*) (0x04000000))
#define VIDEO_MODE  0x0003
#define BG_MODE  0x0400
#define SCREEN_BUFFER ((volatile uint16*)0x06000000)
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160
#define REG_VCOUNT      (* (volatile uint16*) 0x04000006) // current row being drawn by hardware


// colours

#define CYAN 0x339c8
#define BLACK 0x00000


// type defintions
typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned int       uint32;



/*
 * Create a colour: http://www.coranac.com/tonc/text/
 */
inline uint16 MakeCol(uint8 red, uint8 green, uint8 blue)
{
    return red | green << 5 | blue << 10;
}

void drawRectangle(int left, int top, int width, int height, uint16 clr)
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
    	   SCREEN_BUFFER[(top + y) * SCREEN_WIDTH + left + x] = clr;
        }
    }
}


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

    for(int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; ++i){
        // void
    }


    int x = 0;
    while(1)
	{
        vsync();
        if ( x > SCREEN_WIDTH * (SCREEN_HEIGHT/10)) {
         x = 0;
        }
        if (x != 0)
        {
            int last = x - 10;
            drawRectangle(last % SCREEN_WIDTH, (last / SCREEN_WIDTH) * 10, 10, 10,MakeCol(0,0,0));
        }

        drawRectangle(x % SCREEN_WIDTH, (x / SCREEN_WIDTH) * 10, 10, 10,CYAN);
        x += 10;
	}

    return 0;
}

