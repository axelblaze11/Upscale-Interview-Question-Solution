#include <iostream> 
using namespace std; 
  
class node 
{ 
   public:
    int data; 
    node *left, *right; 
}; 

void kdistance(node *root, int k) 
{ 
    if (root == NULL || k < 0)  return; 

    if (k==0) 
    { 
        cout << root->data << " "; 
        return; 
    } 

    kdistance(root->left, k-1); 
    kdistance(root->right, k-1); 
} 

int kdistanceNode(node* root, node* target , int k) 
{ 

    if (root == NULL) return -1; 

    if (root == target) 
    { 
        kdistance(root, k); 
        return 0; 
    } 
  
    int dl = kdistanceNode(root->left, target, k); 

    if (dl != -1) 
    { 

         if (dl + 1 == k) 
            cout << root->data << " "; 
         else
            kdistance(root->right, k-dl-2); 

         return 1 + dl; 
    } 

    int dr = kdistanceNode(root->right, target, k); 
    if (dr != -1) 
    { 
         if (dr + 1 == k) 
            cout << root->data << endl; 
         else
            kdistance(root->left, k-dr-2); 
         return 1 + dr; 
    } 

    return -1; 
} 

node *newnode(int data) 
{ 
    node *temp = new node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
int main() 
{ 
  
    node * root = newnode(20); 
    root->left = newnode(8); 
    root->right = newnode(22); 
    root->left->left = newnode(4); 
    root->left->right = newnode(12); 
    root->left->right->left = newnode(10); 
    root->left->right->right = newnode(14); 
    node * target = root->left; 
    cout<<"when target = "<<target->data<<"\nand root = "<<root->data<<"\nk = 2\nOutput: ";
    kdistanceNode(root, target, 2);
	target=root->left->right->right; 
    cout<<"\n\nwhen target = "<<target->data<<"\nand root = "<<root->data<<"\nk = 3\nOutput: ";
    kdistanceNode(root, target, 3); 
    target=root->left->right;
    cout<<"\n\nwhen target = "<<target->data<<"\nand root = "<<root->data<<"\nk = 2\nOutput: ";
    kdistanceNode(root, target, 2); 
    
    return 0; 
}
