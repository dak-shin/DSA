#include<iostream>
#include<algorithm>
using namespace std;

struct Node
{
  int key;
  struct Node *left;
  struct Node *right;
  Node(int k){
      key=k;
      left=right=NULL;
  }
};


// Naive approach to finding the LCA of two nodes with time complexity O(n^2)
bool findPath(Node *root, vector<Node *> &p, int n){
  // Builds a path for the node n if it is present or else returns false
    if(root==NULL)return false;
    p.push_back(root);
    if(root->key==n)return true;

    if(findPath(root->left,p,n)||findPath(root->right,p,n))return true;

    p.pop_back();
    return false;
}

Node *lca(Node *root, int n1, int n2){
    vector <Node *> path1, path2;
    if(findPath(root,path1,n1)==false||findPath(root,path2,n2)==false)
        return NULL;
    /* Iterates through the path array for the nodes and finds the
    last same nodes in their path which would be
        their last common ancestor */
    for(int i=0;i<path1.size()-1 && i<path2.size()-1;i++)
        if(path1[i+1]!=path2[i+1])
            return path1[i];
    return NULL;
}


// Effecient approach with O(n) time complexity
Node *lca(Node *root, int n1, int n2)
{
    if(root==NULL)return NULL;
    if(root->key==n1||root->key==n2)
        return root;

    Node *lca1=lca(root->left,n1,n2);
    Node *lca2=lca(root->right,n1,n2);

    if(lca1!=NULL && lca2!=NULL)
        return root;
    if(lca1!=NULL)
        return lca1;
    else
        return lca2;
}

int res=0;
int burnTime(Node *root, int leaf, int &dist){
    if(root==NULL)return 0;
    if(root->key==leaf){dist=0;return 1;}
    int ldist=-1,rdist=-1;
    int lh=burnTime(root->left,leaf,ldist);
    int rh=burnTime(root->right,leaf,rdist);

    if(ldist!=-1){
       dist=ldist+1;
       res=max(res,dist+rh);
    }
    else if(rdist!=-1){
        dist=rdist+1;
        res=max(res,dist+lh);
    }
    return max(lh,rh)+1;
}

// Effecient code for counting number of nodes in a complete binray tree
int countNode(Node *root){
    int lh=0,rh=0;
    Node *curr=root;
    while(curr!=NULL){
        lh++;
        curr=curr->left;
    }
    curr=root;
    while(curr!=NULL){
        rh++;
        curr=curr->right;
    }
    if(lh==rh){
        return pow(2,lh)-1;
    }else{
        return 1+countNode(root->left)+countNode(root->right);
    }
}

const int EMPTY=-1;
void serialize(Node *root, vector<int> &arr){
   if(root==NULL){
       arr.push_back(EMPTY);
       return;
   }
    arr.push_back(root->key);
    serialize(root->left,arr);
    serialize(root->right,arr);
}

Node *deSerialize(vector<int> &arr, int &index){
    if(index==arr.size())
        return NULL;
    int val=arr[index];
    index++;
    if(val==EMPTY)return NULL;
    Node *root=new Node(val);
    root->left=deSerialize(arr,index);
    root->right=deSerialize(arr,index);
    return root;
}

int main()
{
  Node *root=new Node(10);
root->left=new Node(20);
root->right=new Node(30);
root->left->left=new Node(40);
root->left->right=new Node(50);
root->right->left=new Node(60);
root->right->right=new Node(70);
levelorder(root);
cout<<"\n"<<getMax(root)<<" "<<getSize(root)<<"\n";
printLeft(root);
}
