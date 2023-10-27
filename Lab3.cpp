#include<iostream>
#include<vector>
#include<fstream>


using namespace std;

bool check(vector< vector<char> >& matrix, char* word, int x, int y)
{
    char *p = word;
    while (*p != '\0')
    {
        p++;
    }
    int length=p-word;

    if(word[0] != matrix[x][y])
    {
        return false;
    }
    else
    {
        //cout<<"hello";
        int count = 1;
        int pos = 1;
        //right
        for(int i = y+1; i<matrix.size()-1; i++)
        {
            
            
            if(word[pos] == matrix[x][i] && count<length)
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
            return true;
        }
        
        count = 1;
        pos=1;
        
        //left
        for(int i = y-1; i>=0; i--)
        {
            
            
            if((word[pos] == matrix[x][i]) && (count<length))
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
            return true;
        }
        
        count = 1;
        pos=1;
        
        //up
        for(int i = x-1; i>=0; i--)
        {
            
            if(word[pos] == matrix[i][y])
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
            return true;
        }
        
        count = 1;
        pos=1;
        
        //down
        //why does <= work?
        for(int i = x+1; i<=matrix[x].size()-1; i++)
        {
            
            if(word[pos] == matrix[i][y])
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
            return true;
        }
        
        count = 1;
        pos=1;
        
        //diagonalURight
        int TempX = x-1;
        int TempY = y+1;
        while(TempX>=0 && TempY<matrix.size()-1)
        {
            
            if(word[pos] == matrix[TempX][TempY])
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
            return true;
        }
        
        count = 1;
        pos=1;
        
        //diagonalULeft
        TempX = x-1;
        TempY = y-1;
        while(TempX>=0 && TempY>=0)
        {
            
            if(word[pos] == matrix[TempX][TempY])
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
            return true;
        }
        
        count = 1;
        pos=1;
        
        //diagonalLRight
        TempX = x+1;
        TempY = y+1;
        while(TempX<=matrix[x].size()-1 && TempY<matrix.size())
        {
            
            if(word[pos] == matrix[TempX][TempY])
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
            return true;
        }
        
        count = 1;
        pos=1;
        
        //diagonalLLeft
        TempX = x+1;
        TempY = y-1;
        while(TempX<=matrix[x].size()-1 && TempY>=0)
        {
            
            if(word[pos] == matrix[TempX][TempY])
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
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    //fstream input;
    //input.open("0505matrix");
    
    
    //for(int i = 0; i<r; i++)
    //{
        //for(int b = 0; b<c; b++)
        //{
            //cout<<matrix[i][b]<<" ";
        //}
        //cout<<endl;
    //}
    //input.close();
  // open the file to read from
  fstream input;
  input.open(argv[4]);
    int r;
    int c;
    input >> r;
    input >> c;
    vector< vector<char> > matrix;
    char val;
    while (!input.eof())
    {
        vector<char> temp;
        for(int i = 0; i<r; i++)
        {
            
            input>>val;
            temp.push_back( val);
        }
        matrix.push_back(temp);
    }
  
  //starting index
  int x = atoi(argv[2]);
  int y = atoi(argv[3]);
    
    if(check( matrix, argv[1], x, y))
    {
        cout<<"true"<<endl;
    }
    else {
        cout<<"false"<<endl;
    }
    //cout<< check( matrix, argv[1], x, y);
    


   return 0;
}
