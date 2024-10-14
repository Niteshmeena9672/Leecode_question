class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for (auto num :nums){
            st.insert(num);
        }
        int longest_sequence = 0;

        for(auto num : st){
            if(st.find(num-1)== st.end()){
                int curr_sequence = 0;
                while(st.find(num)!= st.end()){
                    num+=1;
                    curr_sequence+=1;
                }
                longest_sequence = max(curr_sequence,longest_sequence);
            }
        }
        return longest_sequence;
    }
};