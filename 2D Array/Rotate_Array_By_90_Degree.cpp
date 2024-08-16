    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>> temp(matrix);
         int row_t=temp.size();
        int col_t=temp[0].size()-1;
        for(int i=0,k=col_t;i<row,k>=0;i++,k--){
            for(int j=0,l=0;j<col,l<row_t;j++,l++){

                temp[l][k]=matrix[i][j];

            }

        }

        for(int i=0;i<temp.size();i++){
            for(int j=0;j<temp[0].size();j++){
                matrix[i][j]=temp[i][j];
            }
        }
        
    }