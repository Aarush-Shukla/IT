#include <bits/stdc++.h> 
using namespace std;

struct node{
    public:
     int data;
     node* left;
     node* right;
};

 struct node* newNode(int d){
         struct node* temp
        = (struct node*)malloc(sizeof(struct node));
        temp->data=d;
        temp->left=NULL;
        temp->right=NULL;
         return temp;
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

node* insertIntoBST(node* root,int d){
    //base case
     if (root == NULL){
        return newNode(d);
        }
    if(d>root->data){
        root->right=insertIntoBST(root->right,d);
    }else if(d<root->data){
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}

void takeInput(node* &root){
int data;
cin>>data;
while(data!=-1){
insertIntoBST(root,data);
cin>>data;
    }
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


node* miniVal(node* root){
    node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

node* maxVal(node* root){
    node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}


node* deleteFromBST(node* root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        //0 Child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        //1 Child
        //left subtree
         if(root->left!=NULL && root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
         //right subtree
         if(root->left==NULL && root->right!=NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }

        //2 Child
        if(root->left!=NULL && root->right!=NULL){
            int mini=miniVal(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }
}


    if(root->data>val){
        node* temp=root;
        root->left=deleteFromBST(root->left,val);
        return root;
    }else{
        node* temp=root;
        root->right=deleteFromBST(root->right,val);
        return root;
    }
}



int main(){
    node* root= NULL;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);
    
// // 10 8 21 7 27 5 4 3 -1

    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);

//     cout<<"Printing the BST"<<endl;
//     inorder(root);

//     cout<<"Printing the BST"<<endl;
//     preorder(root);

//     cout<<"Printing the BST"<<endl;
//     postorder(root);
    
//     return 0;

// struct node* root = NULL;

//   cout<<"Enter data to create BST"<<endl;
//     takeInput(root);
    
// // 10 8 21 7 27 5 4 3 -1

//     cout<<"Printing the BST"<<endl;
    // levelOrderTraversal(root);

//     root = insertIntoBST(root, 50);
//    insertIntoBST(root, 30);
//     insertIntoBST(root, 20);
//     insertIntoBST(root, 40);
//     insertIntoBST(root, 70);
//     insertIntoBST(root, 60);
//     insertIntoBST(root, 80);
 
    // Print inorder traversal of the BST
    // inorder(root);
 
    return 0;
}