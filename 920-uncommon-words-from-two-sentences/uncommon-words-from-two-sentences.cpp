class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string temp ="";
        string s = s1 + " " + s2;
        unordered_map<string,int> mpp;
        for(auto val : s){
            if(val==' '){
                mpp[temp]++;
                temp = "";
            }
            else{
                temp+=val;
            }
        }
        if(temp!=""){
            mpp[temp]++;
            temp="";
        }
        vector<string>ans;
        for(auto val : mpp){
            if(val.second ==1){
                ans.push_back(val.first);
            }
        }
        return ans;
    }
};