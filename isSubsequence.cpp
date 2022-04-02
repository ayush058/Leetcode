class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == "") return true;
        if(t == "") return false;
        int index = 0;
        for(int i = 0; i < t.size(); ++i) {
            if(t[i] == s[index]) {
                index++;
            }
            // Check if all chars in s are seen in t; break loop
            if(index == s.size()) {
                return true;
            }
        }
        return false;
    }
};

// Recursive Solution
// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         return checkSubsequence(s, s.size(), t, t.size());
//     }
    
//     bool checkSubsequence(string s, int sz1, string t, int sz2) {
//         if(sz1 == 0) return true;
//         if(sz2 == 0) return false;
//         if(s[sz1 - 1] == t[sz2 - 1]) {
//             return checkSubsequence(s, sz1 - 1, t, sz2 - 1);
//         }
//         return checkSubsequence(s, sz1, t, sz2 - 1);
//     }
// };
