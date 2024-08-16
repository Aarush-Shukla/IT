#include <bits/stdc++.h> 
using namespace std;

bool IsEqual(int arr1[26],int arr2[26]){
    for(int i=0;i<26;i++){
        if(arr1[i]!=arr2[i]){
            return 0;
        }
    }
    return 1;
}

    bool checkInclusion(string s1, string s2) {
//charachters ko unke index ke according position pe count ke hisab se rakhna 
        int count1[26]={0};
        for(int i=0;i<s1.length();i++){
            int index=s1[i]-'a';
            count1[index]++;
        }
        int i=0;
        int count2[26]={0};
        int WindowSize= s1.length();

        //Window banana
        while(i<s1.length() && i<s2.length()){
            int index=s2[i]-'a';
            count2[index]++;
            i++;
        }
        if(IsEqual(count1,count2)){
            return 1;
        }

         // Window Ko Aage Badhana

         while(i<s2.length()){
        char NewChar=s2[i];
        int index=s2[i]-'a';
        count2[index]++;

        char OldChar=s2[i-WindowSize];
        index=OldChar-'a';
        count2[index]--;
        i++;

        if(IsEqual(count1,count2)){
            return 1;
        }
    }
    return 0;
}