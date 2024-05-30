class Solution {
public:
    int jump(vector<int>& nums) {
        int pos = 0;
        int max_jump_pos = 0;
        int window = nums[0];
        int jumps = 0;
        int dest = nums.size() - 1;
        
        for(int i = 1; i < dest+1; i++) {
            if(dest == pos) return jumps;
            if(dest <= pos + window) return jumps+1;
            if(i <= pos + window) {
                if(max_jump_pos + nums[max_jump_pos] < nums[i] + i) {
                    max_jump_pos = i;
                }
            } else {
                pos = max_jump_pos;
                max_jump_pos = 0;
                window = nums[pos];
                jumps++;
                i--;
            }
        }
        return jumps;
    }
};