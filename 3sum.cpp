class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() <= 2) return ans;
        // sort the array
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k) {
                int toFind = -nums[i];
                if(nums[j] + nums[k] > toFind) {
                    k--;
                } else if(nums[j] + nums[k] < toFind) {
                    j++;
                } else {
                    // found the triplet, add it to answer
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    // bypass duplicates if they are present
                    while(j < k && nums[j] == nums[j - 1]) j++;
                    while(j < k && k < nums.size() && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};
