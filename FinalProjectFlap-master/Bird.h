//
//  Bird.hpp
//  glutapp
//
//  Created by Kyle Stephan on 4/25/19.
//  Copyright © 2019 Angelo Kyrilov. All rights reserved.
//

#ifndef Bird_h
#define Bird_h
#include "AnimatedRect.h"
#include "GlutApp.h"
#include <stdio.h>
#include "Timer.h"

class Bird : public AnimatedRect {
public:
    double jumpHeight = 0.2;
    float maxHeight = 1.05;
    float minHeight = -0.2;
    
    // Timer *thisTimer;
    
    Bird(const char*, int, int, int, bool, bool, float, float, float, float);
    void flapWings(); // listening for a left button click or space bar
    
    float getJumpHeight() const;
    
    void setMinHeight(float);
    void setMaxHeight(float);
    // void action();
};



#endif /* Bird_h */
