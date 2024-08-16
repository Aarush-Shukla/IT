class Solution {

private:
char toLowerCase(char ch){
     if ((ch>='a'&& ch<='z')|| (ch>='0'&& ch<='9') ){
         return ch;
     }else{
         char temp=ch+'a'-'A';
         return temp;
     }
}
private:
bool isValid(char ch){
    if ((ch>='a'&& ch<='z')|| (ch>='A'&& ch<='Z')||(ch>='0'&& ch<='9') ){
        return 1;
    }else{
        return 0;
    }
}
private:
bool CheckPalindrome(string a){
       int start=0;
       int end=a.length()-1;
   while(start<=end){
   if(a[start]!=a[end]){
       return 0;
   }else{
       start++;
       end--;
        }
   }
   return 1;
}

public:
    bool isPalindrome(string s) {
        string temp="";
        // Remove all the phaltu ke elements
        for(int j=0;j<s.length();j++){
            if(isValid(s[j])){
                temp.push_back(s[j]);
            }
        }
        //Convert into LowerCase
        for(int i=0;i<temp.length();i++){
            temp[i]=toLowerCase(temp[i]);
        }

        return CheckPalindrome(temp);

    }
};