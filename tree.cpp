#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
    Node(int x )
    {
      key = x;
      left = right = NULL;
    }
};

void inorder(Node* root)
{
  if(root!=NULL)
  {
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
  }
}

void preorder(Node* root)
{
  if(root!=NULL)
  {
    cout<<root->key<<" ";
    inorder(root->left);
    inorder(root->right);
  }
}

void postorder(Node* root)
{
  if(root!=NULL)
  {
    inorder(root->left);
    inorder(root->right);
    cout<<root->key<<" ";
  }
}

int height(Node *root)
{
    if(root==NULL) return 0;
    else return max(height(root->left),height(root->right))+1;
}

int getSize(Node *root)
{
  if(root == NULL) return 0;
  else return (1+getSize(root->left)+getSize(root->right));
}

int getMax(Node *root)
{
  if(root == NULL) return -1;
  else return max(root->key,max(getMax(root->left),getMax(root->right)));
}

void levelorder(Node *root){
    if(root==NULL)return;
    queue<Node *>q;
    q.push(root);
    q.push(NULL);
    while(q.empty()==false){
        Node *curr=q.front();
        q.pop();
        // cout<<q.size()<<"----";
        if(curr==NULL && q.size()!=0)
        { // This additional portions prints the node in each level at different lines

          cout<<"\n";
          q.push(NULL);
        }
        else{
        cout<<curr->key<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
          }
    }

    /*
    Alternatively this approach can also be used to print nodes on different lines
    while(q.empty()==false){
        int count = q.size();
        for(int i =0; i<count;i++)
        {
        Node *curr=q.front();
        q.pop();
        else{
        cout<<curr->key<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
        }
      }
    }
    */

}

void printLeft(Node *root){
    if(root==NULL)
        return;
        queue<Node *> q;
        q.push(root);
    while(q.empty()==false){
        int count=q.size();
        for(int i=0;i<count;i++){
            Node *curr=q.front();
            q.pop();
            if(i==0)
            // Thjs prints the node immediately after going to the next level as i=0 only when we move to the next level
                cout<<curr->key<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
}

int isBalanced(Node *root){
    if(root==NULL)
        return 0;
    int lh=isBalanced(root->left);
    if(lh==-1)return -1;
    int rh=isBalanced(root->right);
    if(rh==-1)return -1;

    if(abs(lh-rh)>1)
        return -1;
    else
        return max(lh,rh)+1;
}

Node *BTToDLL(Node *root){
    if(root==NULL)return root; // base condition
    static Node* prev = NULL; // prev var needs to be common to all the function calls
                              // which is how we make sure the the DLL is in inorder traversal of the tree.
    Node *head=BTToDLL(root->left);
    /* Recurrsivley find the leftmost node which will be the head of the doubly linked list */
    if(prev==NULL){head=root;} // this condition is true only for the first function calls
    // prev is set for every other function call
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    /* root is the current node being processed and after processing we change the current node to its prev */
    BTToDLL(root->right);
    // Recurrsively call the function on the right subtree.
    return head;
}

int preIndex=0;
Node *cTree(int in[],int pre[],int is,int ie){
    if(is>ie)return NULL;
    Node *root=new Node(pre[preIndex++]);

    int inIndex;
    for(int i=is;i<=ie;i++){
        if(in[i]==root->key){
            inIndex=i;
            break;
        }
    }
    root->left=cTree(in, pre, is, inIndex-1);
    root->right=cTree(in, pre, inIndex+1, ie);
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
