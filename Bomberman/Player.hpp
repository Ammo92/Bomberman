//
//  Player.hpp
//  Bomberman
//
//  Created by Mohamed Gasmi on 23/05/2018.
//  Copyright © 2018 Mohamed Gasmi. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>

class Player {
    
private:
    
    int x,y;
    
public:
    
    int getX()const;
    int getY()const;
    int getPosition()const;
    void setPosition(int x, int y);
    
    
};
#endif 
