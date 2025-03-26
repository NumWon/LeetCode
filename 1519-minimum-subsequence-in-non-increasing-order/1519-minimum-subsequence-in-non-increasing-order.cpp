class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ret;
        int ret_sum = 0;
        
        for(int i = nums.size()-1; i >= 0; i--) {
            // if ret_sum + nums[i] is greater than rest of elements
            if(sum - ret_sum - nums[i] < ret_sum + nums[i]) {
                ret.push_back(nums[i]);
                ret_sum += nums[i];
                break;
            } else {
                ret_sum += nums[i];
                ret.push_back(nums[i]);
            }
        }

        nums = ret;
        return nums;
    }
};