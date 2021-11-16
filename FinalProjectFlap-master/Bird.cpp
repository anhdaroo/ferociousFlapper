//
//  Bird.cpp
//  glutapp
//
//  Created by Kyle Stephan on 4/25/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#include "Bird.h"

Bird::Bird(const char* map_filename, int rows, int cols, int rate, bool visible=false, bool animated=false, float x=0, float y=0, float w=0.5, float h=0.5): AnimatedRect(map_filename, rows, cols, rate, visible, animated, x, y, w, h) {
}


void Loop(int x) {
    //    this->setY(this->getY() + 0.001);
   // std::cout << "Beingcalled" << std::endl;;
    
}
void Bird::flapWings() {
    // flap
    // AKA set the y value to be higher
    // this->setY(this->getY() + 0.3); // progressively
    for (int i = 0; i < 10; i++) {
        this->setY(this->getY() + 0.015);
        // action();
    }
}
//
//void Bird::action() {
//    std::cout << "action" << std::endl;
//    
//}

float Bird::getJumpHeight() const {
    return jumpHeight;
}

void Bird::setMinHeight(float minHeight) {
    this->minHeight = minHeight;
}

void Bird::setMaxHeight(float maxHeight) {
    this->maxHeight = maxHeight;
}
