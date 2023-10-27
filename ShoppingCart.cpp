/* Type your code here */
#include <iostream>
#include <vector>
using namespace std;

#include "ShoppingCart.h"

//#inlcude "ItemToPurchase.cpp"

ShoppingCart::ShoppingCart()
{
    
}

void ShoppingCart::AddItem(ItemToPurchase i)
{
    cartItems.push_back(i);
}

int ShoppingCart::GetNumItemsInCart()
{
    int count = 0;
    
    for(int i = 0; i<cartItems.size(); i++)
    {
        count += (cartItems.at(i)).GetQuantity();
    }
    
    return count;
}

int ShoppingCart::GetCostOfCart()
{
    int sum = 0;
    
    for(int i = 0; i<cartItems.size(); i++)
    {
        sum += (cartItems.at(i)).GetPrice() * (cartItems.at(i)).GetQuantity();
    }
    
    return sum;
}

void ShoppingCart::PrintTotal()
{
    if(GetNumItemsInCart() == 0)
    {
        cout<<"Number of Items: "<<GetNumItemsInCart()<<endl;
        
        cout<< "SHOPPING CART IS EMPTY"<<endl;
        
        cout<<"Total: $0";
    }
     else
     {
         int sum = 0;
         cout<<"Number of Items: "<<GetNumItemsInCart();
         
         for(int i = 0; i<cartItems.size(); i++)
         {
             (cartItems.at(i)).PrintItemCost();
             cout<<endl;
             sum += (cartItems.at(i)).GetPrice() * (cartItems.at(i)).GetQuantity();
         }
         
         cout<< "Total: $"<<GetCostOfCart();
    }
}

void ShoppingCart::PrintDescriptions()
{
    if(GetNumItemsInCart() == 0)
    {
        cout<< "SHOPPING CART IS EMPTY";
    }
    else
    {
        cout<<"Item Descriptions"<<endl;
        for(int i = 0; i<cartItems.size(); i++)
        {
            (cartItems.at(i)).PrintItemDescription();
            cout<<endl;
        }
    }
}
