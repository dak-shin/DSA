#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int key;
  struct Node *left;
  struct Node *right;
  int lCount;
  Node(int k){
      key=k;
      left=right=NULL;
      lCount=0; // stores number of nodes in the left subtree.
  }
};

Node* insert(Node* root, int x)
{
    if (root == NULL)
        return new Node(x);

    if (x < root->key) {
        root->left = insert(root->left, x);
        // Recurrsively insert the node and update left count for all ancestor nodes
        root->lCount++;
    }

    else if (x > root->key)
        root->right = insert(root->right, x);
    return root;
}

Node* kthSmallest(Node* root, int k)
{
    if (root == NULL)
        return NULL;

    int count = root->lCount + 1; // +1 includes the root node as well. which gives the position of node in the ordered list

    if (count == k)
        return root;

    if (count > k)
        return kthSmallest(root->left, k);

    return kthSmallest(root->right, k - count);
}

bool isBST(Node* root,int min, int max)
{
  if (root == NULL)
    return true;

  return ( root->key>min && root->key<max &&
            isBST(root->left,min,root->key) && isBST(root->right,root->key,max));
}


void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

Node *prevv=NULL,*first=NULL,*second=NULL;
// This sets the first and second pointers to the nodes that need to be swapped
void fixBST(Node* root)
{
    if (root == NULL)
        return;
    fixBST(root->left);
    if(prevv!=NULL && root->key<prevv->key){
        if(first==NULL)
            first=prevv;
        second=root;
    }
    prevv=root;

    fixBST(root->right);
}

// Checks whether sum of a pair of nodes in the BST or BT is equal to sum parameter
bool isPairSum(Node *root, int sum, unordered_set<int> &s)
    {
        if(root==NULL)return false;

        if(isPairSum(root->left,sum,s)==true)
            return true;

        if(s.find(sum-root->key)!=s.end())
            return true;
        else
            s.insert(root->key);
        return isPairSum(root->right,sum,s);
      }

//vertical traversal
void vTraversal(Node *root){
    map<int,vector<int>> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(q.empty()==false){
        auto p=q.front();
        Node *curr=p.first;
        int hd=p.second;
        mp[hd].push_back(curr->key);
        q.pop();
        if(curr->left!=NULL)
            q.push({curr->left,hd-1});
        if(curr->right!=NULL)
            q.push({curr->right,hd+1});
    }
    for(auto x:mp){
        for(int y:x.second)
            cout<<y<<" ";
        cout<<endl;
    }
}

void topView(Node *root){
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(q.empty()==false){
        auto p=q.front();
        Node *curr=p.first;
        int hd=p.second;
        if(mp.find(hd)==mp.end())
            mp[hd]=(curr->key);
        q.pop();
        if(curr->left!=NULL)
            q.push({curr->left,hd-1});
        if(curr->right!=NULL)
            q.push({curr->right,hd+1});
    }
    for(auto x:mp){
        cout<<x.second<<" ";
    }
}

void bottomView(Node *root){
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(q.empty()==false){
        auto p=q.front();
        Node *curr=p.first;
        int hd=p.second;
        mp[hd]=(curr->key);
        q.pop();
        if(curr->left!=NULL)
            q.push({curr->left,hd-1});
        if(curr->right!=NULL)
            q.push({curr->right,hd+1});
    }
    for(auto x:mp){
        cout<<x.second<<" ";
    }
}


int main() {

	Node* root = NULL;
    int keys[] = { 20, 8, 22, 4, 12, 10, 14 };

    for (int x : keys)
        root = insert(root, x);

    int k = 4;
    Node* res = kthSmallest(root, k);
    if (res == NULL)
        cout << "There are less than k nodes in the BST";
    else
        cout << "K-th Smallest Element is " << res->key;
    return 0;

}
