#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"
//#include "ShoppingCart.cpp"
//#include "ItemToPurchase.cpp"

int main() {
  ShoppingCart myCart;
  
  string name;
  string descr;
  int price;
  int quantity;
  int noOfItems;
  cout << "How many items are you purchasing: ";
  cin >> noOfItems;
  for (int i = 0; i < noOfItems; i++) {
    cin.ignore();
    cout << "ADD ITEM NO " << (i+1) << " TO CART" << endl;
    cout << "Enter the item name:" << endl;
    getline(cin, name);

    cout << "Enter item description:" << endl;
    getline(cin, descr);

    cout << "Enter item price:" << endl;
    cin >> price;

    cout << "Enter item quantity:" << endl;
    cin >> quantity;

    ItemToPurchase item;
    item.SetName(name);
    item.SetDescription(descr);
    item.SetPrice(price);
    item.SetQuantity(quantity);

    myCart.AddItem(item);

    
  }
  

  // "OUTPUT ITEMS' DESCRIPTIONS and TOTAL" 
  myCart.PrintDescriptions();
  myCart.PrintTotal();


  return 0;
}
