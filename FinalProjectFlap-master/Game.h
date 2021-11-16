#ifndef Game_hpp
#define Game_hpp

#include "AppComponent.h"
#include "AnimatedRect.h"
#include "Timer.h"
#include "Bird.h"

class Game: public AppComponent, private Timer{
    //Background
    TexRect* bg1;
    TexRect* bg2;
    //Pipe Set 1
    TexRect* topPipe1;
    TexRect* botPipe1;
    //Pipe Set 2
    TexRect* topPipe2;
    TexRect* botPipe2;
    //Pipe Set 3
    TexRect* topPipe3;
    TexRect* botPipe3;
    //Pipe Set 4
    TexRect* topPipe4;
    TexRect* botPipe4;
    
    //Power Up
    TexRect* power;
    
    //Beginning and End Screen
    TexRect* menu;
    TexRect* over;
    
    //Explosion
    AnimatedRect* fire;
    
    //Bird
    Bird* bird;
    //Bools
    bool gameOver;
    bool gameStart;
    bool positive;
    bool negative;
    bool jump;
    bool sCover;
    bool collision;
    
    //Floats
    float num;
    float bnum;
    float pnum;
    float powerNum;
    float fireNum;
    float overNum;
    
    //Int
    int counter;
    
public:
    int iterate;
    AnimatedRect* explosion;
    Game();
    
    void draw() const ;
    void handleKeyDown(unsigned char, float, float);
    
    void action();
    
    ~Game();
    
};

#endif
