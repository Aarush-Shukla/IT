#include<bits/stdc++.h>
using namespace std;

struct meeting {
   int start;
   int end;
   int pos;
};


 bool static comparator(struct meeting m1, meeting m2) {
         if (m1.end < m2.end) return true;
         else if (m1.end > m2.end) return false;
         else if (m1.pos < m2.pos) return true;
         return false;
      }
      
      
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
           struct meeting meet[N];
      for (int i = 0; i < N; i++) {
         meet[i].start = S[i], meet[i].end = F[i], meet[i].pos = i + 1;
      }

      sort(meet, meet + N, comparator);

      vector < int > answer;

      int limit = meet[0].end;
      answer.push_back(meet[0].pos);

      for (int i = 1; i < N; i++) {
         if (meet[i].start > limit) {
            limit = meet[i].end;
            answer.push_back(meet[i].pos);
         }
      }
      sort(answer.begin(),answer.end());
      return answer;
    }