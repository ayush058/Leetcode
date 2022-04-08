class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 0) return ans;

        // Idea: Check the chars in first word are present in other words in the list
        for(int i = 0; i < strs[0].size(); i++) {
            for(int j = 1; j < strs.size(); j++) {
                // Check if index is getting out of bound in string to be checked.
                if( i >= strs[j].size() || strs[0][i] != strs[j][i]) {
                    return ans;
                }
            }
            ans += strs[0][i];
        }
        return ans;
    }
};
