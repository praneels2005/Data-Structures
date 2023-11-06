#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Node definition
struct Node {
  string ssn;
  string name;
  Node * next;
};

// Append node to end of linked list
void append(Node * & head, string SSN, string Name)
{
    Node *NewNode = new Node;
    NewNode->ssn = SSN;
    NewNode->name = Name;
    
    if(head == NULL)
    {
        head = NewNode;
    }
    else
    {
        Node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NewNode;
        NewNode->next = NULL;
    }
    
}

// Search linked list for given SSN and prints the location and name for that SSN
void search(Node * head, string SSN)
{
    Node *temp = head;
    int index = 0;
    while(temp != NULL)
    {
        if((temp->ssn).compare(SSN) == 0)
        {
            cout<<"Found at location "<< index<<", belongs to "<<temp->name;
        }
        index++;
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;

    fstream input;
    input.open("sample.txt");
    char i;
    string SSN;
    string First;
    string Last;
    string Full;
    
    while(!input.eof())
    {
        input>>i;
        input>>SSN;
        input>>First;
        input>>Last;
        
        Full = First + " " + Last;
        
        append(head,SSN, Full);
    }
    
    cout<<"Input a SSN: "<<endl;
    string inputSSN;
    cin>>inputSSN;
    
    search(head, inputSSN);

   return 0;
}
