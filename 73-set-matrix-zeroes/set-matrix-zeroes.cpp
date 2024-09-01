class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        

        int rows = matrix.size();
        int columns = matrix[0].size();
        // Use vectors instead of arrays
        vector<int> extra_row(rows, 0);
        vector<int> extra_col(columns, 0);
        // int extra_row[rows] = {0};
        // int extra_col[columns] = {0};
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < columns; j++){
                if(matrix[i][j] == 0){
                    extra_row[i] =1;
                    extra_col[j]=1;
                }
            }
        }
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < columns; j++){
                if(extra_row[i] || extra_col[j]){
                    matrix[i][j] = 0;
                }
            }
        };

        
    }
};