// class Solution {
// public:
//     unordered_set<string> st; // Using an unordered set for O(1) lookup.

//     bool solve(int idx, string &s) {
//         int n = s.length();
//         if (idx >= n) {
//             return true;  // Base case: If the index reaches the end of the string, return true.
//         }

//         for (int l = 1; l <= n - idx; l++) {  // Check for every substring from current index.
//             string temp = s.substr(idx, l);  // Create substring starting from idx with length l.

//             // If the substring is in the set and we can solve the remaining part recursively.
//             if (st.find(temp) != st.end() && solve(idx + l, s)) {
//                 return true;
//             }
//         }

//         return false;  // If no valid break point is found, return false.
//     }

//     bool wordBreak(string s, vector<string>& wordDict) {
//         for (auto &word : wordDict) {
//             st.insert(word);  // Store all words from wordDict in an unordered set for O(1) lookups.
//         }

//         return solve(0, s);  // Start the recursive solution from the beginning of the string.
//     }
// };
class Solution {
public:
    unordered_set<string> st; // Using an unordered set for O(1) lookup.

    bool solve(int idx, string &s,vector<int>&memo) {
        int n = s.length();
        if (idx >= n) {
            return true;  // Basically yha pe we are starting from 0 >=n so first character match will start, this comes in picture when we have explored all character and now nothing is left
        }
        if(memo[idx]!=-1) return memo[idx];
        for (int l = 1; l <= n; l++) {  // Check for every substring from current index.
            string temp = s.substr(idx, l);  // Create substring starting from idx with length l.

            // If the substring is in the set and we can solve the remaining part recursively.
            if (st.find(temp) != st.end() && solve(idx + l, s, memo)) {
                return memo[idx]= true;
            }
        }

        return memo[idx] = false;  // If no valid break point is found, return false.
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto &word : wordDict) {
            st.insert(word);  // Store all words from wordDict in an unordered set for O(1) lookups.
        }
        vector<int>memo(301,-1);
        return solve(0, s,memo);  // Start the recursive solution from the beginning of the string.
    }
};
