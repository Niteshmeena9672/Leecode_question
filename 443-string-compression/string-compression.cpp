class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0, j = 0;
        int count = 0;
        
        // Initialize index for the result
        int index = 0;
        
        while (j < n) {
            // Count occurrences of the current character
            while (j < n && chars[i] == chars[j]) {
                count++;
                j++;
            }
            
            // Add the character and its count to the result
            chars[index++] = chars[i];
            if (count > 1) {
                // Convert count to a string and then add each character to the result
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[index++] = c;
                }
            }
            
            // Move to the next character
            i = j;
            count = 0;
        }
        
        // Resize the vector to fit the compressed result
        
        return index;
    }
};
