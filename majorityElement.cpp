// Moore voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majority;
        for(auto num : nums) {
            if(!count) {
                majority = num;
                count++;
            } else {
                count += (majority == num) ? 1 : -1;
            }
        }
        return (count > 0) ? majority : -1;
    }
};
