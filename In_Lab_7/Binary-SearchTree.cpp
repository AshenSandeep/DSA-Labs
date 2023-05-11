#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};
struct node *insertNode(struct node *root, int key);
struct node *deleteNode(struct node *root, int key) ;
int rightReplacer(node* root);
int leftReplacer(node* root);

// Inorder traversal
void traverseInOrder(struct node *root) {
    if(root != NULL){
      traverseInOrder(root->left);
      cout<<root->key<<" ";
      traverseInOrder(root->right);
    }

}

// Insert a node
struct node *insertNode(struct node *root, int key) {
  if(root==NULL){
    struct node* keyNode = new node;
    keyNode->key = key;
    keyNode->left = keyNode->right = NULL;
    root = keyNode;
  }else if(root->key> key){
    root->left = insertNode(root->left,key) ;
  }else{
    root->right = insertNode(root->right,key);
  }
  return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
     if(root == NULL){
        return root;
    }else if(key < root->key){
        root->left = deleteNode(root->left,key);
    }else if(key > root->key){
        root->right = deleteNode(root->right,key);
    }
    else{
        if(root->left == NULL && root->right == NULL){      // check the node's left and right NULL
            root = NULL;
        }else if(root->right != NULL){
            root->key = rightReplacer(root);
            root->right = deleteNode(root->right,root->key);
        }else{
            root->key = leftReplacer(root);
            root->left = deleteNode(root->left,root->key);
        }
    }
    return root;
}

int rightReplacer(node* root){
    root = root->right;
    while(root->left != NULL){
         root = root->left;
    }
    return root->key;
        }
int leftReplacer(node* root){
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->key;
} 

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
