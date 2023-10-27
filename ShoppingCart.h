/* Type your code here */
#include <string>
#include <iostream>
#include <vector>
using namespace std;

#include "ItemToPurchase.h"
//#include "ItemToPurchase.cpp"


/*
 Private data members
 vector < ItemToPurchase > cartItems
 Public member functions
 AddItem()
 Adds an item to cartItems vector. Has a parameter of type ItemToPurchase. Does not return anything.
 GetNumItemsInCart() (2 pts)
 Returns quantity of all items in cart. Has no parameters.
 GetCostOfCart() (2 pts)
 Determines and returns the total cost of items in cart. Has no parameters.
 PrintTotal()
 Outputs total of objects in cart.
 If cart is empty, output this message: SHOPPING CART IS EMPTY
 PrintDescriptions()
 Outputs each item's description.
 */
class ShoppingCart
{
public:
    ShoppingCart();
    void AddItem(ItemToPurchase i);
    int GetNumItemsInCart();
    int GetCostOfCart();
    void PrintTotal();
    void PrintDescriptions();
    
    
private:
    vector < ItemToPurchase > cartItems;
    
    
};
