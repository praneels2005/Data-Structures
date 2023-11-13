#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node
{
    string ssn;
    string name;
    Node* next;
    Node* prev;
};

void insert(Node*& head, string SSN, string Name)
{
    Node *NewNode = new Node;
    NewNode->ssn =SSN;
    NewNode->name = Name;
    NewNode->next = NULL;
    NewNode->prev = NULL;
    
    Node *temp = head;
    if(head == NULL)
    {
        head = NewNode;
    }
    else if((NewNode->ssn).compare(temp->ssn) < 0)
    {
        NewNode->next = temp;
        temp->prev = NewNode;
        head = NewNode;
    }
    else
    {
        Node *temp1 = temp->next;
        while(temp1 !=NULL)
        {
            if((NewNode->ssn).compare(temp1->ssn) < 0)
            {
                NewNode->prev = temp;
                NewNode->next = temp1;
                temp->next = NewNode;
                temp1->prev = NewNode;
                break;
            }
                temp = temp1;
                temp1 = temp1->next;
        }

        if((NewNode->ssn).compare(temp->ssn) > 0)
        {
            temp->next = NewNode;
            NewNode->prev = temp;
            
        }
    }
}

void print(Node* head) 
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<< temp->ssn<<": "<<temp->name<<endl;
        temp = temp->next;
    }

}

void search (Node* head, string SSN)
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

int main (int argc, char* argv[])
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
        
        insert(head,SSN, Full);
    }
    
    cout<<"Input a SSN: "<<endl;
    string inputSSN;
    cin>>inputSSN;
    search(head, inputSSN);
    cout<<endl;
    cout<<"List contents:"<<endl;
    
    print(head);
}
