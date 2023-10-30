#include <iostream>
#include <fstream>
using namespace std;

struct Person
 {
    string SSN;
    string Name;
};

int main(int agrc, char* argv[])
{
    Person *People = new Person[1000];
    fstream input;
    input.open("sample.txt");
    char i;
    string SSN;
    string First;
    string Last;
    string Full;
    string ch;
    int pos = 0;
    
    
    while(!input.eof())
    {
        input>>i;
        input>>SSN;
        input>>First;
        input>>Last;
        
        Full = First + " " + Last;
        
        Person p = {SSN, Full};
        People[pos] = p;
        pos++;
    }
    
    
    string inputSSN;
    int index;
    cin>>inputSSN;
    for(int i = 0; i<pos; i++)
    {
        if((inputSSN).compare(People[i].SSN) == 0)
        {
            index = i;
            break;
        }
    }
    
    cout<<"Found at location "<<index<<", belongs to "<<People[index].Name;
    

   return 0;
}
