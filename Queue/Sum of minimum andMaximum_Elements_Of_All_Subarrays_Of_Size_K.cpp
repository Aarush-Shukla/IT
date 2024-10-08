#include <bits/stdc++.h> 
using namespace std;

int solve(int *arr, int n, int k) {

    deque<int> maxi(k);
    deque<int> mini(k);

    //Addition of first k size window

    for(int i=0; i<k; i++) {

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])// Jab array ka element bada hai queue se toh queue ke element ko pop karke uski jagah vo element push kardo
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])// Jab array ka element chota hai queue se toh queue ke element ko pop karke uski jagah vo element push kardo
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }
    int ans = 0;

    ans += arr[maxi.front()] + arr[mini.front()];

    //remaining windows ko process karlo
    for(int i=k; i<n; i++) {

        

        //next window

        //removal
        while(!maxi.empty() && i - maxi.front() >=k) {
            maxi.pop_front();// sliding window ke front se hatana
        }

        while(!mini.empty() && i - mini.front() >=k) {
            mini.pop_front();
        }

        //addition

        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();//sliding window ke back se hatana agar naya element array ka already existing element se bada hai

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);//jo array ka element bada tha usko deque mai push karna
        mini.push_back(i);    

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}

int main() {


    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;


    return 0;
}