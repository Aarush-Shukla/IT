bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        int rowindex=0;
        int colindex=col-1;
        while(rowindex< row && colindex>=0){         //approach is thought after seeing the last element of first row.
            int element=matrix[rowindex][colindex];
            if(element==target){
                return 1;
            }
            if(element<target){
                rowindex++;
            }else{
                colindex--;
            } 
        }
        return 0;
    }