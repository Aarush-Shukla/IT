#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};



class Trie{
public:
TrieNode* root;

Trie(){
    root=new TrieNode('\0');
}


// T.C-O(L),L-Length
void insertUtil(TrieNode* root, string word){
    //base case
    if(word.length()==0){
        root->isTerminal=true;
        return;
    }

    //assumption,word would be in CAPS
    int index=word[0]-'A';
    TrieNode* child;
    
    
    //present
    if(root->children[index]!=NULL){
        child=root->children[index];
    }

    //absent
    else{
        child=new TrieNode(word[0]);
        root->children[index]=child;
    }

    //RECURSION
    insertUtil(child,word.substr(1));
}

void insertWord(string word){
    insertUtil(root,word);
}



// T.C-O(L),L-Length
bool searchUtil(TrieNode* root, string word){
    //base case
    if(word.length()==0){
       return  root->isTerminal;
    }

    //assumption,word would be in CAPS
    int index=word[0]-'A';
    TrieNode* child;
    
    
    //present
    if(root->children[index]!=NULL){
        child=root->children[index];
    }

    //absent
    else{
       return false;
    }

    //RECURSION
    return searchUtil(child,word.substr(1));
}


bool searchWord(string word){
    return searchUtil(root,word);
}




// Code to remove/delete a word from Trie :-


    //Return True if the Trie node has no child, else false
    bool isEmpty(TrieNode* root)
    {
        for(int i=0;i<26;i++)
            if(root->children[i])
                return false;
        
        return true;
    }

    TrieNode* deleteUtil(TrieNode* root, string word)
    {
        if(root == NULL)
            return NULL;
        
        //Last character being processed
        if(word.length() == 0)
        {
            //This will not be a word after removal
            if(root->isTerminal)
                root->isTerminal = false;
            
            //If this is not a prefix of any other word. [not helping to make any other word]
            if(isEmpty(root))
            {
                delete root;
                root = NULL;
            }
            
            return root;
        }
        
        //Recursion call
        int index = word[0] - 'a';
        root->children[index] = deleteUtil(root->children[index], word.substr(1));
        
        //Backtracking
        //If root has no child (as it's only child got deleted) and it is also not end of any other word
        if(isEmpty(root) && root->isTerminal == false)
        {
            delete root;
            root = NULL;
        }
        
        return root;
    }
    
    TrieNode* deleteWord(string word)
    {
        return deleteUtil(root, word);
    }

};




int main(){
    Trie *t= new Trie();
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    cout<<"Presesnt or Not "<< t->searchWord("ABCD")<<endl;
    return 0;
}