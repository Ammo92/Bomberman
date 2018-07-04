//
//  main.cpp
//  Bomberman
//
//  Created by Mohamed Gasmi on 23/05/2018.
//  Copyright © 2018 Mohamed Gasmi. All rights reserved.
//

#include <iostream>
#include <string>
#include "Map.hpp"



int main(int argc, char ** argv)
{
    Map map;
  
    map.Generate(argv);
    map.Display ();
    
    return 0;
}


