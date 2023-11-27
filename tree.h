#include "treeNode.h"
#include <iomanip>

template <class V>
class tree {
    TreeNode<V> * root;
    int size;
    
    public:
    // default constructor
    // by default, the tree is empty
    tree(){
        root = nullptr;
        size = 0;
    }

    // binary search value x in tree rooted at node t
    bool treeBSearch(V x, TreeNode<V>* t)
    {
        if(t == nullptr)
        {
            return false;
        }
        else if(x == t->getDatum())
        {
            return true;
        }
        else
        {
            if(x < t->getDatum())
            {
                return treeBSearch(x, t->getLeft());
            }
            else
            {
                return treeBSearch(x,t->getRight());
            }
        }
        return false;
    }
        
      
      
    
    
    // binary search value x in tree
    bool treeBSearch(V x){
        return treeBSearch(x, root);
    }
    
    // check node t is leaf
    bool isLeaf(TreeNode<V>* t){
      if(t->getRight() == nullptr && t->getLeft() == nullptr)
      {
          return true;
      }
      return false;
    }
    
    // find the height of the tree rooted at node t
    int height(TreeNode<V>* t){
      if(t == nullptr)
      {
          return 0;
      }
      else
      {
            if(t->getLeft() != nullptr)
            {
                return 1+height(t->getLeft());
            }
          else if(t->getRight()!= nullptr)
          {
              return 1+height(t->getRight());
          }
           else
           {
               return 0;
          }
        }
    }
    
    int height(){
        return height(root);
    }
    
    // find the number of nodes of tree rooted at t
    int nNodes(TreeNode<V>* t){
      if(t == nullptr)
      {
          return 0;
      }
      else
      {
          return  1 + nNodes(t->getLeft()) + nNodes(t->getRight());
      }
    }
    
    int nNodes(){
        return nNodes(root);
    }

    // insert value x to the current tree object
    void insert(V x)
    {
        TreeNode<V>* temp = new TreeNode<V>(x);
        TreeNode<V>* t = root;
        //TreeNode<V> initialRoot;
        if(root == nullptr)
        {
            root = temp;
        }
        else {
            
            
            while(t != nullptr)
            {
                //initialRoot = t;
                if(temp->getDatum()<t->getDatum())
                {
                    if(t->getLeft() == nullptr)
                    {
                        t->setLeft(temp);
                        size++;
                        break;
                    }
                    t = t->getLeft();
                }
                else
                {
                    if(t->getRight() == nullptr)
                    {
                        t->setRight(temp);
                        size++;
                        break;
                    }
                    t = t->getRight();
                }
            }
        }
        
        
    }
    
    void traverseInorder(TreeNode<V> *x)
    {
        if (x == nullptr)
            return;
        traverseInorder(x->getLeft());
        cout << x->getDatum() << " ";
        traverseInorder(x->getRight());
    }
    void traverseInorder()
    {
        traverseInorder(root);
        cout<<endl;
    }

    void traversePreorder(TreeNode<V> *x){
        if (x == nullptr)
            return;
        cout << x->getDatum() << " ";
        traversePreorder(x->getLeft());
        traversePreorder(x->getRight());
    }
    void traversePreorder(){
        traversePreorder(root);
        cout<<endl;
    }

    void traversePostorder(TreeNode<V> *x){
        if (x == nullptr)
            return;
        
        traversePostorder(x->getLeft());
        traversePostorder(x->getRight());
        cout << x->getDatum() << " ";
    }
    void traversePostorder(){
        traversePostorder(root);
        cout<<endl;
    } 
    
};
