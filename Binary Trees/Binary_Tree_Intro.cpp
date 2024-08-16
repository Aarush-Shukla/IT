#include <bits/stdc++.h> 
using namespace std;

class node{
    public:
     int data;
     node* left;
     node* right;

     node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
     }
};

node* buildTree (node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left: "<< data << endl;
    root->left=buildTree(root->left);
     cout<<"Enter data for inserting in right: "<< data << endl;
    root->right=buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
    node* temp=q.front();
    q.pop();

    if(temp==NULL){
        //pura level traverse ho chuka hai
        cout<<endl;
        
        if(!q.empty()){
            //agar queue empty nahi hai toh null push karna padega queue mai kyuki next level jaane se pehle bhi ek bar cout<<endl(enter) dena hai
            q.push(NULL);
            }
        }
        
        else{
        
        cout<<temp->data<<" ";
        if(temp->left){
        q.push(temp->left);
        }

        if(temp->right){
        q.push(temp->right);
            }
        }
    }
}


void revreselevelordertraversal(node* root){
    queue<node*> q1;
    q1.push(root);
    q1.push(NULL);
    stack<int> s; 
    node* temp = NULL;
    while(!q1.empty()){
        temp = q1.front();
        q1.pop();

        if( temp== NULL){   // // purana level complete traverse ho chuka hai
            s.push(0); // because s.push(temp -> data ) will give error as temp is null
            if(!q1.empty()){
                q1.push(NULL); 
            }
        }
        else{
            s.push(temp -> data); // as stack uses FIRST IN LAST OUT method so the first node entered in stack that is root node will be at the last and so on
            if(temp -> left){ 
                q1.push(temp -> left);
            }
            if(temp -> right){
                q1.push(temp -> right);
            }
        }
    }
    while(!s.empty()){
        if(s.top() == 0){
            s.pop();
            cout<<endl;
        }
        else{
            cout<< s.top() << " ";
            s.pop();
        }
    }
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
 }

int main() {

    node* root = NULL;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

  
    // //creating a Tree
    // root = buildTree(root);
    // //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    // //level order
    // cout << "Printing the level order tracersal output " << endl;
    // levelOrderTraversal(root);

    // cout << "inorder traversal is:  ";
    // inorder(root); 

    // cout << endl << "preorder traversal is:  ";
    // preorder(root); 

    // cout << endl << "postorder traversal is:  ";
    // postorder(root); 
    


    return 0;
}