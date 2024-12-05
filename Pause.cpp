#include "Pause.h"
#include <iostream>

void drawPause(SDL_Plotter &g){
    g.clear();
    
    int resumeX = 200, resumeY = 100, resumeWidth = 200, resumeHeight = 50;
    for(int x = resumeX; x < resumeX + resumeWidth; x++){
        for(int y = resumeY; y < resumeY + resumeHeight; y++){
            g.plotPixel(x, y, color(0, 255, 0));
        }
    }
    
    int quitX = 200, quitY = 200, quitWidth = 200, quitHeight = 50;
    for(int x = quitX; x < quitX + quitWidth; x++){
        for(int y = quitY; y < quitY + quitHeight; y++){
            g.plotPixel(x, y, color(255, 0, 0));
        }
    }
}

bool handlePause(SDL_Plotter &g){
    
}
