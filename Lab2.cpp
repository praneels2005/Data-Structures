#include <iostream>
#include <string>
using namespace std;

int main() {
    string newstr;
    string rnewstr;
    
    string input;
    cin>>input;
    //char orgname = input;
    //char newname[50] =
    
    int inc;
    cin>>inc;
    
    //vector<string> list(length," ");
    for(int i = 0; i<input.size(); i++)
    {
        if(input.at(i) != 'a' && input.at(i) != 'e' && input.at(i) != 'i' && input.at(i) != 'o' && input.at(i) != 'u')
        {
            if((input.at(i) + inc)>'z')
            {
                newstr += string(1,(input.at(i) + inc)- 26);
            }
            else
            {
                //strcat(newstr,string(1,(input.at(i) + inc)));
                newstr +=  string(1,(input.at(i) + inc));
            }
        }
        else
        {
            //strcat(newstr,string(1,(input.at(i))));
            newstr +=  (string(1,input.at(i)));
        }
    }
    
    //cout<<newstr<<endl;
    
for(int i = newstr.size()-1; i>=0; i--)
{
    rnewstr += (string(1,newstr.at(i)));;
}
    cout<<rnewstr;
   return 0;
}

//input.at(i) != 'a' && input.at(i) != 'e' && input.at(i) != 'i' && input.at(i) != 'o' && input.at(i) != 'u'
