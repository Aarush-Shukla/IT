#include <bits/stdc++.h> 
using namespace std;



// int GetMaxPoints(vector<int>& markers) {
//     // Sort the markers in descending order
//     // sort(markers.rbegin(), markers.rend());

//     // // Initialize variables
//     // int james_points = 0;
//     // int bob_points = 0;

//     // // Determine the maximum number of points for James
//     // for (int i = 0; i < markers.size(); i++) {
//     //     if (i % 2 == 0) {
//     //         james_points += markers[i];
//     //     }
//     // }

//     // return james_points;
// int james_points = 0;
//     int bob_points = 0;
//     int length=markers.size();
//     while(length>0){
//          if (length==1){
//             james_points+=markers[0];
//             break;
//          }
//          if(markers[0]>markers[-1])
//     }
// }


// int main() {
//     int num_markers;
//     cin >> num_markers; // Read the number of markers

//     vector<int> markers(num_markers);
//     for (int i = 0; i < num_markers; i++) {
//         cin >> markers[i]; // Read the marker values
//     }

//     int max_points = GetMaxPoints(markers);
//     cout << max_points << endl;

//     return 0;
// }



#include <iostream>
using namespace std;

int getNumberOfDroppedPackets(vector<pair<int, int>> requests, int maxPackets, int rate) {
  int time = 0;
  int packetsLeft = 0;
  int packetsSent = 0;
  int dropped = 0;

  for (pair<int, int> req : requests) {
    int reqTime = req.first;
    int reqPackets = req.second;

    if (time < reqTime) {
      time = reqTime;
    }

    int packetsToSend = min(reqPackets, packetsLeft + rate - packetsSent);

    if (packetsToSend > maxPackets) {
      dropped += packetsToSend - maxPackets;
    }

    packetsLeft = max(0, packetsLeft + rate - packetsSent - packetsToSend);
    packetsSent += packetsToSend;
    time += packetsToSend / rate;
  }

  return dropped;
}

int main() {
  vector<pair<int, int>> requests = {{1, 10}, {2, 5}, {3, 15}};
  int maxPackets = 10;
  int rate = 5;

  int droppedPackets = getNumberOfDroppedPackets(requests, maxPackets, rate);

  cout << "Number of dropped packets: " << droppedPackets << endl;

  return 0;
}


//   int solve(vector<int>& nums, int i, int j){
//         if(i > j)
//         return 0;
        
//         if(i == j)
//         return nums[j];

//         int p1 = nums[i] + min(solve(nums, i+2, j), solve(nums, i+1, j-1));
//         int p2 = nums[j] + min(solve(nums, i+1, j-1), solve(nums, i, j-2));

//         return max(p1, p2);
//     }
//     int PredictTheWinner(vector<int>& nums) {
//         int i = 0;
//         int temp = 0;
//         int j = nums.size()-1;

//         for(auto it:nums){
//             temp += it;
//         }

//         int p1 = solve(nums, i, j);
//         int p2 = temp-p1;

//         return p1 ;
        
//     }