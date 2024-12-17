#include<bits/stdc++.h>
using namespace std;

class TreeNode{
  public:
    int val;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int v) {
      val = v;
    }
};

TreeNode* nodeByVal(TreeNode* head, int val){
  if(!head) return NULL;
  if(head->val == val){
    return head;
  }

  TreeNode* a = NULL;
  TreeNode* b = NULL;
  if(head->left) a = nodeByVal(head->left, val);
  if(head->right) b = nodeByVal(head->right, val);

  if(a) return a;
  return b;
}
void inorder(TreeNode* head){
  if(!head) return;

  inorder(head->left);
  cout << head->val << endl;
  inorder(head->right);
}

int maxDepth(TreeNode* head){
  if(!head) return 0;
  return max(maxDepth(head->left)+1, maxDepth(head->right)+1);
}

int diameter(TreeNode* head){
  if(!head) return 0;
  int a = maxDepth(head->left) + maxDepth(head->right);
  int b = diameter(head->left);
  int c = diameter(head->right);

  int ans = a;
  if(b > ans) ans = b;
  if(c > ans) ans = c;
  return ans;
}

int main(){
  int n; cin>>n;

  vector<TreeNode* > links;
  for(int i = 0; i < n-1; ++i){
    int a, b; cin>>a>>b;

    TreeNode* acomp; TreeNode* bcomp;
    for(int j = 0; j < links.size(); ++j){
      if(links[j]->val == a) {
        acomp = links[j];
        break;
      }if(links[j]->val == b){
        bcomp = links[j];
        break;
      }
    }

    if(acomp){
      TreeNode* temp = new TreeNode(b);
      if(!acomp->left) acomp->left = temp;
      else if(!acomp->right) bcomp->right = temp;
    }else if(bcomp){
      TreeNode* temp = new TreeNode(a);
      if(!bcomp->left) bcomp->left = temp;
      else if(!bcomp->right) bcomp->right = temp;
    }


  }

  cout << diameter(head) << endl;

}

