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

// binary tree
class TreeNode{
	int val;
	Node* left;
	Node* right;
	
	public:
	TreeNode(int v){
		val = v;
	}
};


void add_node(TreeNode* n, TreeNode* head){
	if(n->val> head->val){
		if(head->right==NULL){
			head->right = n;
		}else{
			add_node(n, head->right);
		}
	}else{
		if(head->left==NULL){
			head->left = n;
		}else{
			add_node(n, head->left);
		}
	}
}

void inorder(TreeNode* head){

	if(head == NULL){
		return;
	}
	inorder(head->left);
	cout << head->val << endl;
	inorder(head->right);
}

void preorder(TreeNode* head){

	if(head == NULL){
		return;
	}
	cout << head->val << endl;
	preorder(head->left);
	preorder(head->right);
}

void iterative_preorder(TreeNode* root) {
	stack<TreeNode*> s;
	if (root == NULL) return;
	s.push(root);

	while(!s.empty()) {
		TreeNode* n = s.top();
		s.pop();
		if (n->right != NULL) s.push(n->right);
		if (n->left != NULL) s.push(n->left);

		cout << n->val << endl;
	}
}

vector<vector<int> > levelOrderTraversal(TreeNode* head) {
	vector<vector<int> > ans;
	if (!head) return ans;

	queue<TreeNode*> q;
	q.push(head);
	 while(!q.empty()){
		vector<int> temp;
		TreeNode* n = q.front();

		q.pop();
		if (n != NULL) {
			if(n->left != NULL) q.push(n->left);
			else q.push(NULL);
			if(n->right != NULL) q.push(n->right);
			else q.push(NULL);
			temp.push_back(n->val);
		}else{
			temp.push_back(0);
		}
		
		ans.push_back(temp);
		
	}

	return ans;

}

int max_depth(TreeNode* root, int ch){
	if (root == NULL) return ch;

	ch++;
	int r1 = max_depth(root->left, ch);
	int r2 = max_depth(root->right, ch);

	return r1 > r2 ? r1 : r2;
}

int diameter(TreeNode* root){

	if (root == NULL) return 0;
	int r1 = max_depth(root->left, 0) + max_depth(root->right, 0);
	int r2 = diameter(root->left);
	int r3 = diameter(root->right);

	cout << "r1: " << r1 << endl;
	cout << "r2: " << r2 << endl;
	cout << "r3: " << r3 << endl;

	if (r1 >= r2 && r1 >= r3) return r1;
	if (r2 >= r1 && r2 >= r3) return r2;
	return r3;
}

int sum (vector<int> arr){
    int s = 0;
    for(int i = 0;i < arr.size(); i++) {
        s += arr[i];
    }
    return s;
}

vector<vector<int>> pathSumHelper(TreeNode* root, vector<int> c) {
    c.push_back(root->val);
    vector<vector<int>> t1, t2;
    if (!root->left && !root->right) {
        t1.push_back(c);
    }
    else if (!root->left){
        t1 = pathSumHelper(root->right, c);   
    }else if(!root->right){
        t2 = pathSumHelper(root->left, c);
    }else{
        t1 = pathSumHelper(root->right, c);
        t2 = pathSumHelper(root->left, c);
    }

    for(int i = 0; i < t2.size(); ++i){
        t1.push_back(t2[i]);
    }

    return t1;
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> all;
    vector<int> t;

    if (root){
        all = pathSumHelper(root, t);
    }

    vector<vector<int>> ans;
    for (int i = 0; i < all.size(); i++) {
        if (sum(all[i]) == targetSum) ans.push_back(all[i]);
    }

    return ans;
}


int main(){
}