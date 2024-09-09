class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int edgeLength = matrix.size(); // Get the size of the matrix (since it's square)

        int top = 0; // Pointer to the top row
        int bottom = edgeLength - 1; // Pointer to the bottom row

        // Step 1: Flip the matrix upside down (swap top and bottom rows)
        while (top < bottom) {
            for (int col = 0; col < edgeLength; col++) {
                int temp = matrix[top][col]; // Temporarily store the top row element
                matrix[top][col] = matrix[bottom][col]; // Assign bottom row element to top
                matrix[bottom][col] = temp; // Assign stored top row element to bottom
            }
            top++; // Move the top pointer down
            bottom--; // Move the bottom pointer up
        }

        // Step 2: Transpose the matrix (swap elements symmetrically along the diagonal)
        for (int row = 0; row < edgeLength; row++) {
            for (int col = row + 1; col < edgeLength; col++) {
                int temp = matrix[row][col]; // Temporarily store the element at (row, col)
                matrix[row][col] = matrix[col][row]; // Swap with the element at (col, row)
                matrix[col][row] = temp; // Assign the stored element to (col, row)
            }
        }        
    }
};
