class Solution {
public:
    int compress(vector<char>& chars) {
        // Get the size of the input vector
        int n = chars.size();
        
        // Initialize an index to track the position in the array where we write the compressed result
        int index = 0;
        
        // Iterate over the input vector
        int i = 0;
        while (i < n) {
            // Store the current character
            char curr_char = chars[i];
            
            // Initialize a counter to count occurrences of the current character
            int count = 0;

            // Count the number of times the current character repeats
            while (i < n && chars[i] == curr_char) {
                count++;
                i++;
            }

            // Write the current character to the result at the index position
            chars[index] = curr_char;
            index++;

            // If the character repeats more than once, write the count to the result
            if (count > 1) {
                // Convert the count to a string
                string count_str = to_string(count);

                // Write each character of the count string to the result
                for (char &ch : count_str) {
                    chars[index] = ch;
                    index++;
                }
            }
        }

        // The index now represents the length of the compressed vector
        return index;
    }
};
