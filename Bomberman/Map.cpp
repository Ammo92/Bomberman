//
//  Map.cpp
//  Bomberman
//
//  Created by Mohamed Gasmi on 23/05/2018.
//  Copyright © 2018 Mohamed Gasmi. All rights reserved.
//

#include "Map.hpp"

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

char Map::GetElem (const int row, const int col)
{
    CheckCol (col);
    CheckRow (row);
    
    return m_Fields[row][col];
}

void Map::SetElem (const int row, const int col, const char elem)
{
    CheckCol (col);
    CheckRow (row);
    
    m_Fields[row][col] = elem;
    
}

char Map::GetObjet (const int row, const int col)
{
    CheckCol (col);
    CheckRow (row);
    
    return objets[row][col];
}

void Map::SetObjet (const int row, const int col, const char elem)
{
    CheckCol (col);
    CheckRow (row);
    
    objets[row][col] = elem;
    
}


void Map::Load (const char *filename)
{
    ifstream src (filename);
    if (!src)
        throw runtime_error ("Unable to load file");
    
    int line = 0;
    string input;
    
    while (src && line < m_RowCount - 1)
    {
         getline (src, input);
         if (input.size () > m_ColCount)
          throw runtime_error ("Line > 20 chars ");
        
        for (int i = 0; i < input.size (); i++)
        {
           SetElem (line, i, input[i]);
           
        }
        line++;
    }
}

void Map::Display ()
{
    
    for (int i = 0; i < 20; i++) {
        
        for (int j = 0; j < 20; j++) {
            cout << m_Fields[i][j];
        }
        cout << "\n";
    }

}

// Génération aléatoire de la carte
void Map::Generate(char * arg[]){
    
    int nb_bombes = atoi(arg[1]);
    int posX,posY,nb_murs = 30;
    srand(time(NULL));

    // Positionnement des murs extérieurs
    
    for (int i = 0; i < 19; i++)
    {
      for (int j = 0; j < 19; j++)
      {
      
        if(i == 0 || i == 18 || j == 0 || j == 18)  SetElem (i,j,'#');
       
      }
        
    }
    
    // Positionnement des cases vides
    
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            
            if(!(i == 0 || i == 18 || j == 0 || j == 18)) SetElem (i,j,'_');
            
        }
        
    }
    
    // Positionnement des joueurs
    
        posX = rand() % 17 + 1;
        posY = rand() % 17 + 1;
    
        SetElem (posX,posY,'1');
    
        posX = rand() % 17 + 1;
        posY = rand() % 17 + 1;
    
    if (m_Fields[posX][posY] !='1')  SetElem (posX,posY,'2');
    
    // Positionnement des bombes
    
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            
            if(m_Fields[i][j] !='1' && m_Fields[i][j] !='2' &&  m_Fields[i][j] !='#')
            {
//                posX = rand() % 17 + 1;
                posY = rand() % 17 + 1;
                if(nb_bombes>0)
                {
                    if(m_Fields[posX][posY] !='1' && m_Fields[posX][posY] !='2' &&  m_Fields[posX][posY] !='#'){
                        SetElem (posX,posY,'o');
                        nb_bombes--;
                    }
                }
            }
        }
        
    }
    
    // Positionnement des murs intra map
    
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            
            if(m_Fields[i][j] !='1' && m_Fields[i][j] !='2' &&  m_Fields[i][j] !='#' &&  m_Fields[i][j] !='o')
            {
                posX = rand() % 17 + 1;
                posY = rand() % 17 + 1;
                if(nb_murs>0)
                {
                    if(m_Fields[posX][posY] !='1' && m_Fields[posX][posY] !='2' &&  m_Fields[posX][posY] !='#' &&  m_Fields[i][j] !='o'){
                        SetElem (posX,posY,'#');
                        nb_murs--;
                    }
                }
            }
        }
        
    }
}

void Map::CheckRow (const int row)
{
    if (row < 0 || row > m_RowCount - 1)
        throw out_of_range ("Row out of range");
}
void Map::CheckCol (const int col)
{
    if (col < 0 || col > m_ColCount - 1)
        throw out_of_range ("Row out of range");
}
