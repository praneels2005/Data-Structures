//
//  CrosswordHelper.cpp
//  Project1
//
//  Created by Praneel Pothukanuri on 10/3/23.
//

#include "CrosswordHelper.hpp"
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

CrosswordHelper::CrosswordHelper()
{
    //Xpos = -1;
    //Ypos = -1;
    //direction = -1;
}

void CrosswordHelper::setX(int NewX)
{
    Xpos = NewX;
}

void CrosswordHelper::setY(int NewY)
{
    Ypos = NewY;
}

int CrosswordHelper::getX()
{
    return Xpos;
}

int CrosswordHelper::getY()
{
    return Ypos;
}

void CrosswordHelper::setDirection(int NewDirection)
{
    direction = NewDirection;
}

int CrosswordHelper::getDirection()
{
    return direction;
}

bool CrosswordHelper::Find(vector< vector<char> > &WordSearch, char* word)
//Finds the allocated position of the inputted word(argument[n]) sets the x position, y position, and direction of the match
{
    //CrosswordHelper Chelper;
    char *p = word;
    while (*p != '\0')
    {
        p++;
    }
    int length= p-word;
    
    
    for(int row = 0; row<WordSearch.size(); row++)//Loop through rows of WordSearch
    {
        for(int col = 0; col<WordSearch[0].size(); col++)
        {
            //cout<<WordSearch[row][col]<<"--"<<word[0]<<endl;
            //Check if there is a true case in each direction(right, left, up, down, diagonalURight, diagonalULeft, diagonalLRight, diagonalLLeft) and return true if found
            if(WordSearch[row][col] == word[0])
            {
                //cout<<WordSearch[row][col]<<"--"<<word[0]<<endl;
                int count = 1;
                int pos = 1;
                int x = row;
                int y = col;
                
                //right
                for(int i = y+1; i<WordSearch[0].size(); i++)
                {
                    //cout<<WordSearch[x][i]<<"--"<<word[pos]<<endl;
                    if(word[pos] == WordSearch[x][i] && count<length)
                    {
                        count++;
                        pos++;
                        
                    }
                    else
                    {
                        break;
                    }
                }
                
                if(count == length)
                {
                    setX(x);
                    setY(y);
                    setDirection(1);
                    return true;
                }
                
                count = 1;
                pos=1;
                
                
                //left
                for(int i = y-1; i>=0; i--)
                {
                    
                    
                    if((word[pos] == WordSearch[x][i]) && (count<length))
                    {
                        count++;
                        pos++;
                    }
                    else
                    {
                        break;
                    }
                }
                
                if(count == length)
                {
                    setX(x);
                    setY(y);
                    setDirection(2);
                    return true;
                }
                
                count = 1;
                pos=1;
                
                
                //up
                for(int i = x-1; i>=0; i--)
                {
                    
                    if(word[pos] == WordSearch[i][y])
                    {
                        count++;
                        pos++;
                    }
                    else
                    {
                        break;
                    }
                }
                
                if(count == length)
                {
                    setX(x);
                    setY(y);
                    setDirection(3);
                    return true;
                }
                
                count = 1;
                pos=1;
                
                
                //down
                for(int i = x+1; i<WordSearch.size(); i++)
                {
                    
                    if(word[pos] == WordSearch[i][y])
                    {
                        count++;
                        pos++;
                    }
                    else
                    {
                        break;
                    }
                }
                
                if(count == length)
                {
                    setX(x);
                    setY(y);
                    setDirection(4);
                    return true;
                }
                
                count = 1;
                pos=1;
                
                
                //diagonalURight
                int TempX = x-1;
                int TempY = y+1;
                while(TempX>=0 && TempY<WordSearch[0].size())
                {
                    
                    if(word[pos] == WordSearch[TempX][TempY])
                    {
                        count++;
                        pos++;
                        TempX--;
                        TempY++;
                    }
                    else
                    {
                        break;
                    }
                }
                
                if(count == length)
                {
                    setX(x);
                    setY(y);
                    setDirection(5);
                    return true;
                }
                
                count = 1;
                pos=1;
                
                //diagonalULeft
                TempX = x-1;
                TempY = y-1;
                while(TempX>=0 && TempY>=0)
                {
                    
                    if(word[pos] == WordSearch[TempX][TempY])
                    {
                        count++;
                        pos++;
                        TempX--;
                        TempY--;
                    }
                    else
                    {
                        break;
                    }
                }
                
                if(count == length)
                {
                    setX(x);
                    setY(y);
                    setDirection(6);
                    return true;
                }
                
                count = 1;
                pos=1;
                
                //diagonalLRight
                TempX = x+1;
                TempY = y+1;
                while(TempX<WordSearch.size() && TempY<WordSearch[0].size())
                {
                    
                    if(word[pos] == WordSearch[TempX][TempY])
                    {
                        count++;
                        pos++;
                        TempX++;
                        TempY++;
                    }
                    else
                    {
                        break;
                    }
                }
                
                if(count == length)
                {
                    setX(x);
                    setY(y);
                    setDirection(7);
                    return true;
                }
                
                count = 1;
                pos=1;
                
                //diagonalLLeft
                TempX = x+1;
                TempY = y-1;
                while(TempX<WordSearch.size() && TempY>=0)
                {
                    
                    if(word[pos] == WordSearch[TempX][TempY])
                    {
                        count++;
                        pos++;
                        TempX++;
                        TempY--;
                    }
                    else
                    {
                        break;
                    }
                }
                
                if(count == length)
                {
                    setX(x);
                    setY(y);
                    setDirection(8);
                    return true;
                }
                
                //setX() = rows;
                //setY() = columns;
                //setDirection() = 0(not found),1(right), 2(left), 3(up), 4(down),5(diagURight), 6(diagULeft),7(diagLRight),8(diagLLeft);
            }
            
        }
    }
    return false;
}

//void CrosswordHelper::Print()
//{
    //for(int r=0 ; r<asterik.size(); i++)
    //{
        //for(int c= 0; c<asterik[0].size(); c++)
        //{
          //cout<<asterik[i][c];
        //}
    //}
//}

void CrosswordHelper::Place(int x, int y, int direction, char* word, vector< vector<char> > &asterik)
{
    int pos = 0;
    int TempX = x;
    int TempY = y;
    int count = 0;

    char *p = word;
    while (*p != '\0')
    {
        p++;
    }
    int length= p-word;

    switch(direction)
    {

        case 1:
        //Go to position asterisk[x][y] and start setting each element to the right equal to the letters of word[0],word[1], … ,word[word.length-1]
        
             pos = 0;
            //right
            for(int i = y; i<asterik[0].size(); i++)
            {
                if(pos < length)
                {
                    asterik[x][i] = word[pos];
                pos++;
                }
                else
                {
                    break;
                }
                
            }
            break;

    case 2:
    //    Go to position asterisk[x][y] and start setting each element to the left equal to the letters of word[0],word[1], … ,word[word.length-1]
    pos = 0;
            //left
            for(int i = y; i>=0; i--)
            {
                if(pos < length)
                {
                asterik[x][i] = word[pos];
                pos++;
                }
                else
                {
                    break;
                }
            }
            break;


    case 3:
    //    Go to position asterisk[x][y] and start setting each element upwards equal to the letters of word[0],word[1], … ,word[word.length-1]
    pos = 0;
            //upwards
            for(int i = x; i>=0; i--)
            {    
                if(pos < length)
                {
                asterik[i][y]=word[pos];
                pos++;
                }
                else{
                    break;
                }
            }
    break;

    case 4:
    //    Go to position asterisk[x][y] and start setting each element downwards equal to the letters of word[0],word[1], … ,word[word.length-1]
    //down
    pos = 0;
            //down
            for(int i = x; i<asterik.size(); i++)
                    {
                        if(pos < length)
                        {
                        asterik[i][y]=word[pos];
                            pos++;
                        }
                        else
                        {
                            break;
                        }
                    }
    break;

    case 5:
    //    Go to position asterisk[x][y] and start setting each element diagonally to the upper right equal to the letters of word[0],word[1], … ,word[word.length-1]
    TempX = x;
                    TempY = y;
                pos = 0;
                    //UDiagonalRight
                    while(TempX>=0 && TempY<asterik[0].size())
                    {
                        if(pos < length)
                        {
                        asterik[TempX][TempY] = word[pos];
                            pos++;
                            TempX--;
                            TempY++;
                        }
                        else
                        {
                            break;

                        }
                    }
    break;

    case 6:
    //    Go to position asterisk[x][y] and start setting each element diagonally to the upper left equal to the letters of word[0],word[1], … ,word[word.length-1]
    TempX = x;
                    TempY = y;
                    pos = 0;
                    //UDiagonalLeft
                    while(TempX>=0 && TempY>=0)
                    {
                        if(pos < length)
                        {
                        asterik[TempX][TempY] = word[pos];
                            pos++;
                            TempX--;
                            TempY--;
                        }
                        else
                        {
                            break;
                        }
                    }
    break;

    case 7:
    //    Go to position asterisk[x][y] and start setting each element diagonally to the lower right equal to the letters of word[0],word[1], … ,word[word.length-1]
                    TempX = x;
                    TempY = y;
                    pos = 0;
                    //LDiagonalRight
                    while(TempX<asterik.size() && TempY<asterik[0].size())
                    {
                        if(pos < length)
                        {
                        asterik[TempX][TempY] = word[pos];
                            pos++;
                            TempX++;
                            TempY++;
                        }
                        else
                        {
                            break;
                        }
                    }
    break;

    case 8:
    //    Go to position asterisk[x][y] and start setting each element diagonally to the lower left equal to the letters of word[0],word[1], … ,word[word.length-1]
    TempX = x;
                    TempY = y;
                    pos = 0;
                    //LDiagonalLeft
                    while(TempX<asterik.size() && TempY>=0)
                    {
                        if(pos < length)
                        {
                        asterik[TempX][TempY] = word[pos];
                            pos++;
                            TempX++;
                            TempY--;
                        }
                        else
                        {
                            break;
                        }
                    }
    break;

    default:
    {
    break;
    }
}

}


