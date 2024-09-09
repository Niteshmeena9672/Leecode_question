class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Get the size of the matrix (number of rows or columns since it's square)
        int edgeLength = matrix.size();

        // Initialize two pointers for top and bottom rows
        int top = 0;
        int bottom = edgeLength - 1;

        // First step: Flip the matrix upside down (top to bottom)
        while (top < bottom) {
            // Swap elements of the 'top' and 'bottom' rows for each column
            for (int col = 0; col < edgeLength; col++) {
                int temp = matrix[top][col];
                matrix[top][col] = matrix[bottom][col];
                matrix[bottom][col] = temp;
            }
            // Move 'top' down and 'bottom' up towards each other
            top++;
            bottom--;
        }

        // Second step: Transpose the matrix (swap elements symmetrically across the diagonal)
        for (int row = 0; row < edgeLength; row++) {
            for (int col = row + 1; col < edgeLength; col++) {
                // Swap matrix[row][col] with matrix[col][row] to transpose the matrix
                int temp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = temp;
            }
        }        
    }
};
