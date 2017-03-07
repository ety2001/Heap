// Node.cpp
// Implements methods for Node class
#include "Node.h"
#include <iostream>

Node::Node(int val){
	this->val = val;
	right = NULL;
  left = NULL;
};

int Node::getVal(){
  return val;
}

Node* Node::getRight(){
	return right;
};

Node* Node::getLeft(){
	return left;
};

void Node::setRight(Node* node){
	right = node;
};

void Node::setLeft(Node* node){
  left = node;
};
