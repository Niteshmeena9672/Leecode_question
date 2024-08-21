class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        int max_mem_allowed = 10; // this is maximum allowed space in ram
        int max_element = 1001; // this can also be the max element from one of the arrays

        for(int j=0;j<max_element;j+=max_mem_allowed){
            // vector<int> freq(max_mem_allowed,0);
            map<int,int> freq;
            for(int i=0;i<a.size();i++){
                if(a[i]>=j and a[i]<j+max_mem_allowed){
                    freq[a[i]]++;
                }
            }

            for(int i=0;i<b.size();i++){
                if(b[i]>=j and b[i]<j+max_mem_allowed){
                    if(freq[b[i]]>0){
                        ans.push_back(b[i]);
                        freq[b[i]]--;
                    }
                }
            }
        }

        return ans;
    }
};