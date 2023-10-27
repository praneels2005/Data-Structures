//
//  main.cpp
//  Project1
//
//  Created by Praneel Pothukanuri on 10/3/23.
//

#include <iostream>
#include "CrosswordHelper.hpp"
#include <vector>
#include <fstream>

using namespace std;

int main(int argc,  char * argv[]) {

    
    CrosswordHelper CW;
    //Input all values of file into 2D vector wordSearch()
    fstream input;
    input.open(argv[argc-1]);
      int r;
      int c;
      input >> r;
      //cout<<r<<endl;
      input >> c;
    //cout<<c<<endl;
      vector< vector<char> > matrix;
      char val;
      
      //cout<<matrix.size();
      while (!input.eof())
      {
        
          vector<char> temp;
          for(int i = 0; i<c; i++)
          {
              input>>val;
              temp.push_back( val);
              
          }
          if(matrix.size() != r)
          {
            matrix.push_back(temp);
          }
          
      }

      //cout<<matrix.size()<<endl;
      ///cout<<matrix[0].size();




/*
for(int i=0 ; i<matrix.size(); i++)
    {
        for(int a= 0; a<matrix[0].size(); a++)
        {
          cout<<matrix[i][a];
          //cout<<asteriks[i][a];
        }
        cout<<endl;
    }
*/



      

    
    //char* string1 = 'tcnj';
    
    //cout<<CW.Find(matrix, argv[1]);

    //Using dimensions of WordSearch, load asteriks with strictly asteriks in each position
    vector< vector<char> > asteriks;
    
    int row = 0;
    while (row<r)
      {
          vector<char> temp1;
          for(int i = 0; i<c; i++)
          {
              
              temp1.push_back( '*');
              
          }
          if(asteriks.size() != r)
          {
          asteriks.push_back(temp1);
          row++;
          }
          else
          {
            break;
          }
      }
    
   


    //Loop through each argument starting with 1 until argv-1(int i = 1 because zero represents the file name)
for(int count = 1; count<argc-1; count++)
    {
        //cout<<argv[count]<<endl;
        if(CW.Find(matrix, argv[count]))
        {
            //cout<<CW.getX()<<endl;
            //cout<< CW.getY()<<endl;
            CW.Place(CW.getX(), CW.getY(), CW.getDirection(), argv[count], asteriks);
        }
    }

    for(int i=0 ; i<asteriks.size(); i++)
    {
        for(int a= 0; a<asteriks[0].size(); a++)
        {
          
          cout<<asteriks[i][a];
          
        }
        cout<<endl;
    }

    return 0;
}
