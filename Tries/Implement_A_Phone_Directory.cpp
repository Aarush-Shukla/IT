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
    int index=word[0]-'a';
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
void insertWord(string word) { 
    insertUtil(root, word); 
}





//T.C-O(M*(N*M)), S,C-O(M*N)
//Avg. word length=M, No.of strings given in contact list-N

void printSuggestions(TrieNode* curr,vector<string> &temp,string prefix){

  if (curr->isTerminal) {
    temp.push_back(prefix);
    // return;

    // yahan pe return iss liye nahi likhe kyuki we are not adding return
    // statement in base of recursion because we have to print all strings but
    // like you dry run the case where our 1 string is "cod" and other is
    // "coding" so when we reached at 'd' as its isTerminal is true because of
    // "cod" so we only print cod and return from there we never reached
    // "coding"
  }

  // saare charachter traverse kar lete hai
  for (char ch = 'a'; ch <= 'z'; ch++) {
    TrieNode* next = curr->children[ch - 'a'];

    if (next != NULL) { // iska matlab curr ka child exist karta hai
      prefix.push_back(ch);
      // aur aage call maar do recursion ke liye
      printSuggestions(next, temp, prefix);
      // wapas aaoge toh backtrack karke hata lena
      prefix.pop_back();
    }
  }
}
   vector<vector<string>> getSuggestions(string queryStr){
        TrieNode*prev=root;
        vector<vector<string>>output;
        string prefix="";

for (int i = 0; i < queryStr.length(); i++) {
  char lastChar = queryStr[i];
  prefix.push_back(lastChar);

  // check for lastChar if it exists or not
  TrieNode *curr = prev->children[lastChar - 'a'];

  // if not found
  if (curr == NULL) {
    break;
  }
  // aur agar mil gaya toh saare suggestion print karne hai
  vector<string> temp; // temporary storage
  printSuggestions(curr, temp, prefix);

  output.push_back(temp);
  temp.clear();

  // ab previous ko aage badha do
  prev = curr;

    }
    return output;
}

};


vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    
    //creation of Trie
    Trie*t=new Trie();

    //insert all contact in trie
    for(int i=0;i<contactList.size();i++){
        string str=contactList[i];
        t->insertWord(str);
    }

    //return ans
    return t->getSuggestions(queryStr);
}