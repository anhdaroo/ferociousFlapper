#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <ctime>
#include <cstdlib>


#include "Game.h"

Game::Game(){
    
    // Some cross-platform compatimility stuff
    iterate = 0;
    const char* bgFileName;
    const char* birdFileName;
    const char* topPipeFileName;
    const char* botPipeFileName;
    const char* startFileName;
    const char* endFileName;
    const char* fireball;
    const char* powerUp;
    srand(time(0));
    
    // In Windows (Visual Studio only) the image files are found in the enclosing folder in relation to the project
    // In other environments the image files are in the same folder as the project
    
#if defined WIN32
    bgFileName = "/Users/rubylaw/Desktop/FlappyBird/flap.png";
    birdFileName = "/Users/rubylaw/Desktop/FlappyBird/Bird.png";
    botPipeFileName = "/Users/rubylaw/Desktop/FlappyBird/tubeUp.png";
    topPipeFileName = "/Users/rubylaw/Desktop/FlappyBird/tubeDown.png";
    startFileName = "/Users/rubylaw/Desktop/FlappyBird/flaptcover.png";
    endFileName = "/Users/rubylaw/Desktop/CSE165/FlappyBird/flapEnd.png";
    fireball = "/Users/rubylaw/Desktop/CSE165/FlappyBird/fireball.png";
    powerUp = "/Users/rubylaw/Desktop/CSE165/FlappyBird/img.png";
#else
    bgFileName = "/Users/rubylaw/Desktop/FlappyBird/flap.png";
    birdFileName = "/Users/rubylaw/Desktop/FlappyBird/Bird.png";
    botPipeFileName = "/Users/rubylaw/Desktop/FlappyBird/tubeDown.png";
    topPipeFileName = "/Users/rubylaw/Desktop/FlappyBird/tubeUp.png";
    startFileName = "/Users/rubylaw/Desktop/FlappyBird/flapcover.png";
    endFileName = "/Users/rubylaw/Desktop/FlappyBird/flapEnd.png";
    fireball = "/Users/rubylaw/Desktop/FlappyBird/fireball.bmp";
    powerUp = "/Users/rubylaw/Desktop/FlappyBird/powerup.png";
#endif
    //Background obj
    bg1 = new TexRect(bgFileName, -2, 1, 4, 2);
    bg2 = new TexRect(bgFileName, 2, 1, 4, 2);
    
    //Bird obj
    bird = new Bird(birdFileName, 1, 3, 200, true, true, -.5, 0, .25, 0.25);
    
    //Pipe Set 1
    topPipe1 = new TexRect(topPipeFileName, 2, 1.0, 0.25, 0.6);
    botPipe1 = new TexRect(botPipeFileName, 2, 0.1, 0.25, 0.5);
    
    //Pipe Set 2
    topPipe2 = new TexRect(topPipeFileName, 3, 1.0, 0.25, 0.75);
    botPipe2 = new TexRect(botPipeFileName, 3, -0.15, 0.25, 0.25);
    
    //Pipe Set 3
    topPipe3 = new TexRect(topPipeFileName, 4, 1.0, 0.25, 0.5);
    botPipe3 = new TexRect(botPipeFileName, 4, 0.2, 0.25, 0.6);
    
    //Pipe Set 4
    topPipe4 = new TexRect(topPipeFileName, 5, 1.0, 0.25, 0.75);
    botPipe4 = new TexRect(botPipeFileName, 5, -0.15, 0.25, 0.25);
    
    //Power Up
    power = new TexRect(powerUp, 2.5, .12, .25, .25);
    
    //Beginning and End Screens
    menu = new TexRect(startFileName, -2, 1, 4, 2);
    over = new TexRect(endFileName, -1.2, 0.7, 2.5, 1.5);
    
    //Explosion
    fire = new AnimatedRect(fireball,  6, 6, 60, true, true, -2, 1, 4, 2);
    
    //float
    num = 0.001;
    bnum = 0.1;
    pnum = 0.1;
    fireNum = .2;
    overNum = .21;
    
    //Bool
    gameOver = false;
    gameStart = false;
    jump = false;
    sCover = true;
    collision = true;
    
    //Int
    counter = 0;
    
    setRate(1);
    start();
}

void Game::action() {
    
    //Background Variables
    float x1 = bg1->getX();
    float x2 = bg2->getX();
    
    //Bottom Pipes X Values
    float bx1 = botPipe1->getX();
    float bx2 = botPipe2->getX();
    float bx3 = botPipe3->getX();
    float bx4 = botPipe4->getX();
    
    //Bottom Pipes Y Vales
    float by1 = botPipe1->getY();
    
    //Top Pipes X Values
    float tx1 = topPipe1->getX();
    float tx2 = topPipe2->getX();
    float tx3 = topPipe3->getX();
    float tx4 = topPipe4->getX();
    
    //Top Pipe Y Values
    float ty1 = topPipe1->getY();
    
    //Bird Vars
    float bx = bird->getX();
    float by = bird->getY();
    
    //Power Up
    float px = power->getX();
    float py = power->getY();
    
    //Random Number
    float randomNum = rand() % 3 + (-.5);
    if (randomNum < 0) {
        negative = true;
        positive = false;
    }
    if (randomNum > 0) {
        negative = false;
        positive = true;
    }
    
    //Power reset
    if (px <= -2) {
        px = 8;
        pnum = 0.1;
    }
    
    //First Bg
    if (x1 <= -6) {
        x1 = x2 + 4;
        iterate++;
    }
    //Second Bg
    if (x2 <= -6) {
        x2 = x1 + 4;
        iterate++;
    }
//    std::cout << iterate << "ITERATE DEBUG STATEMENT OUTSIDE OF THE IF STATEMENT" << std::endl;
    if (!collision) {
        //std::cout << iterate << "ITERATE DEBUG STATEMENT" << std::endl;
        
        if (iterate >= 2) {
            collision = true;
            iterate = 0;
        }
    }
    
    if (px <= -2) {
        px = 2;
    }
    
    //Pipe Set 1
    if (bx1 <= -2) {
        bx1 = 2;
        /*
         if (positive) {
         botPipe1->setH(by1 - randomNum);
         }
         if (negative) {
         botPipe1->setH(by1 + randomNum);
         }*/
    }
    if (tx1 <= -2) {
        tx1 = 2;
        /*
         if (positive) {
         topPipe1->setH(ty1 - randomNum);
         }
         if (negative) {
         topPipe1->setH(ty1 + randomNum);
         }*/
    }
    
    //Pipe Set 2
    if (bx2 <= -2) {
        bx2 = 2;
    }
    if (tx2 <= -2) {
        tx2 = 2;
    }
    
    //Pipe Set 3
    if (bx3 <= -2) {
        bx3 = 2;
    }
    if (tx3 <= -2) {
        tx3 = 2;
    }
    //Pipe Set 4
    if (bx4 <= -2) {
        bx4 = 2;
    }
    if (tx4 <= -2) {
        tx4 = 2;
    }
    
    if (gameStart) {
        if (!gameOver) {
            //Move backgrounds
            bg1->setX(x1 - num);
            bg2->setX(x2 - num);
            
            //Move Pipe Set 1
            botPipe1->setX(bx1 - num);
            topPipe1->setX(tx1 - num);
            
            //Move Pipe Set 2
            botPipe2->setX(bx2 - num);
            topPipe2->setX(tx2 - num);
            
            //Move Pipe Set 3
            botPipe3->setX(bx3 - num);
            topPipe3->setX(tx3 - num);
            
            //Move Pipe Set 4
            botPipe4->setX(bx4 - num);
            topPipe4->setX(tx4 - num);
            
            //Power Move
            power->setX(px - num);
        }
    }
    
    if(jump) {
        bird->setY(by + 0.0001);
    }
    
    if (collision) {
        
        //Pipe Set 1 Collision
        if (botPipe1->contains(bx + 0.15, by - 0.15) || topPipe1->contains(bx + 0.15, by - 0.05)) {
            gameOver = true;
            //bird->playOnce();
            bnum = 0;
        }
        //Pipe Set 2 Collision
        if (botPipe2->contains(bx + 0.15, by + 0.05) || topPipe2->contains(bx + 0.15, by - 0.05)) {
            gameOver = true;
            //bird->playOnce();
        }
        //Pipe Set 3 Collision
        if (botPipe3->contains(bx + 0.15, by + 0.05) || topPipe3->contains(bx + 0.15, by - 0.05)) {
            gameOver = true;
            //bird->playOnce();
        }
        //Pipe Set 4 Collisoin
        if (botPipe4->contains(bx + 0.15, by + 0.05) || topPipe4->contains(bx + 0.15, by - 0.05)) {
            gameOver = true;
            //bird->playOnce();
        }
    }
    //Power Collision
    if (power->contains(bx   - 0.15, by)) {
        
        collision = false;
        pnum = 0;
        //bird>setW(1);
       // bird->setH(1);
       // bird->setMinHeight(.3);
       // bird->setMaxHeight(1.25);
    }
    
    if(gameOver) {
        bg1->setX(-2);
        bg2->setX(2);
        
        botPipe1->setX(2);
        botPipe2->setX(3);
        botPipe3->setX(4);
        botPipe4->setX(5);
        
        topPipe1->setX(2);
        topPipe2->setX(3);
        topPipe3->setX(4);
        topPipe4->setX(5);
        
        power->setX(2.5);
    }
    

    
}

void Game::draw() const {
    //Draw Cover
    if(sCover) {
        
    }
    
    //Draw Background
    bg1->draw(0);
    bg2->draw(0);
    
    //Draw Bird
    bird->draw(bnum);
    
    //Pipe Set 1 Draw
    botPipe1->draw(0.15);
    topPipe1->draw(0.15);
    
    //Pipe Set 2 Draw
    botPipe2->draw(0.15);
    topPipe2->draw(0.15);
    
    //Pipe Set 3 Draw
    botPipe3->draw(0.15);
    topPipe3->draw(0.15);
    
    //Pipe Set 4 Draw
    botPipe4->draw(0.15);
    topPipe4->draw(0.15);
    
    if (!gameStart) {
        menu->draw(0.2);
    }
    
    if (gameStart) {
        power->draw(pnum);
        
        if (!gameOver) {
            //Gravity
            if (bird->getY() >= bird->minHeight) {
                bird->setY(bird->getY() - 0.00075); // separate this
            }
        }
        if (gameOver) {
            fire->draw(fireNum);
            //fire->playOnce();
            over->draw(overNum);
        }
    }
}
//
//
//for (float i = 0.0; i < this->jumpHeight; i += 0.0001) {
//    if (this->getY() <= this->maxHeight) {
//        this->setY(this->getY() + 0.0001);
//        //glutTimerFunc(16, Loop, 1);
//    }

void Game::handleKeyDown(unsigned char key, float x, float y){
    
    if (key == ' '){
        if (!gameOver) {
        bird->flapWings();
        }
        //jumpStart();
    }
    
    if (key == 's') {
        gameOver = false;
        bnum = .14;
        
    }
    
    if (key == 13) {
        gameStart = true;
    }
    
    else if (key == 'p'){
        stop();
    }
    else if (key == 'r'){
        start();
    }
}

Game::~Game(){
    stop();
    //Delete Bird
    delete bird;
    //Delete backgrounds
    delete bg1;
    delete bg2;
    //Delete Pipe Set 1
    delete botPipe1;
    delete topPipe1;
    //Delete Pipe Set 2
    delete botPipe2;
    delete topPipe2;
    //Delete Pipe Set 3
    delete botPipe3;
    delete topPipe3;
    //Delete Pipe Set 4
    delete botPipe4;
    delete topPipe4;
}
