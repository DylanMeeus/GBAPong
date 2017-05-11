#ifndef GBA_H
#define GBA_H

#define REG_DISPLAYCONTROL *((volatile uint32*) (0x04000000))
#define VIDEO_MODE  0x0003
#define BG_MODE  0x0400
#define SCREEN_BUFFER ((volatile uint16*)0x06000000)
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160
#define REG_VCOUNT      (* (volatile uint16*) 0x04000006) // current row being drawn by hardware

// locate vram
#define MEM_VRAM        0x06000000
#define vid_mem         ((uint16*)MEM_VRAM)

// sound configuration
#define REG_SOUNDCNT_X *(uint32*)0x04000084
#define SND_ENABLED           0x00000080



#define DSA_OUTPUT_RATIO_100  0x0004
#define SND_OUTPUT_RATIO_100  0x0002
#define DSA_OUTPUT_TO_BOTH    0x0300
#define DSA_TIMER0            0x0000
#define DSA_FIFO_RESET        0x0800
#define REG_SOUNDCNT_H  (*(uint16*)0x04000082)



// enable and reset Direct Sound channel A, at full volume, using
// Timer 0 to determine frequency




#endif