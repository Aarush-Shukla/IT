
 string reverseWords(string s) {
        s.push_back(' ');
        string ans, st;
        for(auto c: s) {
            if(c == ' ') {
                reverse(st.begin(), st.end());
                ans += st;
                ans += ' ';
                st.clear();
            }
            else st.push_back(c);
        }
        ans.pop_back();
        return ans;
    }