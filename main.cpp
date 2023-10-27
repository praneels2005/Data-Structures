#include<iostream>
#include<cstring>
using namespace std;

void recSwap(char *first, char *second, int pos)
{
    char temp;
  if(first[pos] == '\0')
  {
      return;
  }
    else
    {
        //pos++;
        recSwap(first, second, pos+1);
        temp = first[pos];
        first[pos] = second[pos];
        second[pos] = temp;
        //cout<<pos;
    }
}

void iterSwap(char *first, char *second)
{
    char temp;
    
    int pos = 0;
    while(first[pos] != '\0')
    {
        temp = first[pos];
        first[pos] = second[pos];
        second[pos] = temp;
        pos++;
    }
}

int main(int agrc, char *argv[])
{
  cout << "Input parameters" << endl;
  cout << argv[1] << endl;
  cout << argv[2] << endl;

  cout << "After iterative swap" << endl;

  iterSwap(argv[1], argv[2]);

  cout << argv[1] << endl;
  cout << argv[2] << endl;

  cout << "After recursive swap" << endl;

  recSwap(argv[1], argv[2], 0);

  cout << argv[1] << endl;
  cout << argv[2] << endl;

  return 0;
}
