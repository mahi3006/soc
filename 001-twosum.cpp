class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
           int n;
           n = nums.size();
           for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if (nums[i]+nums[j] == target){
                    vector<int> result = {i,j};
                    return result;
                }
            }
           } 
           return {};
        }
    
    };
    