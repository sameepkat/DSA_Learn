#include <iostream>

struct Node{
  int data;
  Node* left;
  Node* right;
};

Node* createNode(int data){
  Node* newNode = new Node();
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void preOrder(Node* root){
  if(root != NULL){
    std::cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
  }
}

void inOrder(Node* root){
  if(root != NULL){
    inOrder(root->left);
    std::cout << root->data << " ";
    inOrder(root->right);
  }
}

void postOrder(Node* root){
  if(root != NULL){
    postOrder(root->left);
    postOrder(root->right);
    std::cout << root->data << " ";
  }
}

int main () {
  Node* root = NULL;
  root = createNode(11);
  root->left = createNode(22);
  root->right = createNode(33);

  root->left->left = createNode(44);
  root->left->right = createNode(55);

  root->right->left = createNode(66);
  root->right->right = createNode(77);

  std::cout << "\nPreorder: ";
  preOrder(root);

  std::cout << "\nInorder: ";
  inOrder(root);

  std::cout << "\nPostorder: " << std::endl;
  postOrder(root);

  return 0;
}
