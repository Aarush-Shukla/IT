 int compress(vector<char>& chars) {
        int i=0;
        int ansIndex=0;  //Original vector mai store karne ke liye
        int n=chars.size();
        while(i<n){
            int j=i+1;
            while(j<n && chars[j]==chars[i]){
                j++;
            }
            //Yaha Kab Aaoge?
            //Ya toh poora Vector traverse kar liya ho
            //Ya phir Different Charchter aa gaya ho
            
            chars[ansIndex++]=chars[i];// Old Charachter ko Store karne ke liye
            
            int count=j-i;
            
            if(count>1){
                string cnt= to_string(count);//Converting integer to String, to store no. greater than 9
                for(char ch:cnt){
                    chars[ansIndex++]=ch;//Count Store Karne ke liye
                }
            }
            i=j;//Naye Charachter pe jaane ke liye

        }
        return ansIndex;// ansIndex hi return kar rahe instead of ansIndex+1 ke bajaye kyuki hamne chars[ansIndex++] liya tha toh jab ansIndex pe pahuchega toh ansIndex+1 hoke hi pahuchega.
    }