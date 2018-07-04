//
//  Map.hpp
//  Bomberman
//
//  Created by Mohamed Gasmi on 23/05/2018.
//  Copyright © 2018 Mohamed Gasmi. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp


class Map
{
    
public:
    Map (){};
    int GetRowCount () {return m_RowCount;}
    int GetColCount () {return m_ColCount;}
    char GetElem (const int row, const int col);
    void SetElem (const int row, const int col, const char elem);
    
    char GetObjet (const int row, const int col);
    void SetObjet (const int row, const int col, const char elem);
    
    void CheckRow (const int row);
    void CheckCol (const int col);
    
    void Load (const char *filename);
    void Display();
    void Generate(char * arg[]);
private:
    static const int m_RowCount = 20;
    static const int m_ColCount = 20;
    char m_Fields[m_RowCount][m_ColCount];
    char objets[20][20];
    
    
};

#endif 
