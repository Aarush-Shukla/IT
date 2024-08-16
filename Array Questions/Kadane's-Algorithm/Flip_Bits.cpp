#include <bits/stdc++.h> 
using namespace std;

// In this explanation, we'll explore a concise algorithm that cleverly draws inspiration from Kadane's algorithm to tackle this problem efficiently in Time Complexity of O(n) and Space Complexity of O(1).

 

// Relating to Kadane's Algorithm:


// Kadane's algorithm is a renowned approach used to find the maximum subarray sum in a given array. Interestingly, our "flip bits" solution takes inspiration from this powerful concept. Here's how:

// We basically try to find a subarray which gives us the most profit (means the num of ones after flipping it), if we encounter a 0, we increase the profit and if we encounter a 1 we decrease it (as it, when flipped will turn to 0 reducing the total number of ones). We keep on taking the element in our potential subarray till we have a profit >= 0, and reset the window as soon as it gets negative:

    int maxOnes(int a[], int n)
    {
         int maxprof = 0;  // Maximum profit (maximum count of ones)
    int cp = 0;       // Current profit (count of flipped bits)
    int num1 = 0;     // Total count of ones in the array

    // Loop through each element in the array
    for(int i = 0; i < n; i++) {
        if(a[i]) {
            num1++;      // Increment total count of ones
            cp--;        // Decrement current profit (flip 1 to 0)
        } else {
            cp++;        // Increment current profit (flip 0 to 1)
        }

        cp = max(0, cp); // Ensure non-negative current profit

        // Connection to Kadane's algorithm: Update maxprof using maximum subarray sum logic
        maxprof = max(maxprof, cp);
    }

    // Result: Maximized count of ones after flips
    return maxprof + num1;
    }

// Explanation:

// 1. We initialize `maxprof`, `cp`, and `num1`, akin to the initial variables in Kadane's algorithm.

// 2. As we traverse the array, the logic for flipping bits resembles Kadane's approach of finding the maximum subarray sum:
//    - When encountering a 1, we increment `num1` (total ones) and decrement `cp` (current profit) to account for the flip.
//    - When encountering a 0, we increment `cp` to track potential profit gained from flipping.

// 3. Just like Kadane's algorithm ensures a non-negative subarray sum, we make sure `cp` stays non-negative by setting it to the maximum of 0 and its current value.

// Important Note:

// And this resets the probable profit as here it gets negative, instead we wont want to flip that subarray as it would potentially decrease our answer even more. It's best to start over and search for a better space for a subarray to convert.

// 4. The crucial connection comes when updating `maxprof`. Similar to Kadane's algorithm updating the maximum subarray sum, we update `maxprof` to hold the maximum profit achievable by flipping bits.

// 5. Finally, we obtain the result by summing `maxprof` and `num1`, providing us with the count of ones maximized through flips.