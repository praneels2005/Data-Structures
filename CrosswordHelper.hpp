//
//  CrosswordHelper.hpp
//  Project1
//
//  Created by Praneel Pothukanuri on 10/3/23.
//

#ifndef CrosswordHelper_hpp
#define CrosswordHelper_hpp
#include <vector>
#include <fstream>
#include <stdio.h>

#endif /* CrosswordHelper_hpp */
using namespace std;
class CrosswordHelper
{
public:
    bool Find(vector< vector<char> >&WordSearch, char* word);
    void Place(int x, int y, int direction, char* word, vector< vector<char> >&asteriks);
    //void Print();
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
    void setDirection(int direction);
    int getDirection();
    CrosswordHelper();

private:
    //vector< vector<char> >WordSearch;
    //vector< vector<char> >asterik;
    int Xpos;
    int Ypos;
    int direction;
    

};


