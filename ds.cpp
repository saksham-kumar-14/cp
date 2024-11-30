#include<bits/stdc++.h>
using namespace std;


class ListNode{
	int val;
	Node* next;
	
	public:
	ListNode(int v, Node* n){
		val = v;
		next = n;
	}
};

class TreeNode{
	int val;
	Node* left;
	Node* right;
	
	public:
	TreeNode(int v,Node* l, Node* r){
		val = v;
		right = r;
		left = l;
	}
}
