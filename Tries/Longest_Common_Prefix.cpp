#include<bits/stdc++.h>
using namespace std;


//T.C-O(M*N), M-length, N-No.of Strings,  S.C-O(N)
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans="";

   //for traversing all charachter of 1st string
   for(int i=0;i<arr[0].length();i++){
       char ch=arr[0][i];
       bool match=true;


    // for compairing ch with rest of the strings
       for(int j=1;j<n;j++){
        
           // not match
            if(arr[j].size()<i || ch!=arr[j][i]){
               match=false;
               break;
           }
        }
        if(match==false){
            break;
        }else{
            ans.push_back(ch);
        }

   }

   return ans;
}

//Approach 2
// 1 more approach :-
// sorting karke first and last string compare karenge to ans mil jayega

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
	if(n==0)return "";
	if(n==1)return arr[0];
	sort(arr.begin(),arr.end());
	string ans="";
	string a=arr[0];
	string b=arr[n-1];
	for(int i=0;i<a.size();++i){
		if(a[i]!=b[i])break;
		ans.push_back(a[i]);
	}
	return ans;
}




class TrieNode{
    public:
        char data;
        TrieNode * children[26];
        int childCount;
        bool isTerminal;

        TrieNode(char data){
            this -> data = data;
            this -> isTerminal = false;
            this -> childCount = 0;
            for(int i = 0; i < 26; i++){
                this -> children[i] = NULL;
            }
        }
};

class Trie{
public:
    TrieNode * root;
    
    void insertUtil(TrieNode * root, string word){
        if(word.size() == 0){
            root -> isTerminal = true;
            return;
        }
        
        int ind = word[0] - 'a';
        
        if(root -> children[ind] != NULL){
            insertUtil(root -> children[ind], word.substr(1));
        } else {
            root -> children[ind] = new TrieNode(word[0]);
            root -> childCount++;
            insertUtil(root -> children[ind], word.substr(1));
        }
    }
    
    Trie(){
        this -> root = new TrieNode('\0');
    }
    void insertWord(string word){
        insertUtil(root, word);
    }
    
    void lsp(string str, string &ans){
        for(auto c : str){
            if(root -> childCount == 1){
                ans.push_back(c);
                int ind = c - 'a';
                root = root -> children[ind];
            } else break;
            
            if(root -> isTerminal) break;
        }
    }
};


    string longestCommonPrefix(vector<string>& strs) {
        Trie * t = new Trie();
        for(auto word : strs) {
            //our trie doesn't support empty string so need to handle explicitly
            if(word.empty())
                return "";
            t->insertWord(word);
        }
        
        string ans = "";
        t -> lsp(strs[0], ans);
        
        return ans;
    }

