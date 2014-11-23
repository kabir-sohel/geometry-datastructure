#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
#include "Node.h"

//create a doubly link list pointing to itself from both side


/*This constructure is only to test the code, child class will implement the value on their own */
/*
Node::Node(int v) : _next(this), _prev(this), _v(v){}
*/

Node::Node() : _next(this), _prev(this){}
Node::~Node(void){
	//printf("virtual destructor\n");
}
/*
int Node::value(){
	return _v;
}
*/
Node *Node::next(void){
	return _next;
}

Node *Node::prev(void){
	return _prev;
}

Node *Node::insert(Node *node){
	Node* myNext = _next;
	node->_next = myNext;
	node->_prev = this;
	_next = node;
	myNext->_prev = node;
	return node;
}

Node *Node::remove(void){
	_prev->_next = _next;
	_next->_prev = _prev;
	_prev = _next = this;
	return this;
}

void Node::splice(Node *b){
	Node *a = this;
	Node *an = a->_next;
	Node *bn = b->_next;
	a->_next = bn;
	b->_next = an;
	an->_prev = b;
	bn->_prev = a;
}

/*void printNodes(Node *node){
	Node *cur = node;
	do{
		printf("%d\n", cur->value());
		cur = cur->next();
	}while(cur != node);
}
int main(){
	Node *root = new Node(1);
	for(int i = 2; i <= 5; ++i){
		Node *a = new Node(i);
		root = root->insert(a);
	}
	Node *tem = root;
	root = root->next();
	printNodes(tem);
	printf("Removing last node\n");

	tem = tem->remove();
	printNodes(tem);
	printNodes(root);
	return 0;
}*/