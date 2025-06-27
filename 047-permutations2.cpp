class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answer;
        vector<int> temp;
        vector<bool> taken(nums.size(), false);
        generate(nums, temp, taken, answer);
        return answer;
    }

    void generate(vector<int>& nums, vector<int>& temp, vector<bool>& taken, vector<vector<int>>& answer) {
        if (temp.size() == nums.size()) {
            answer.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (taken[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !taken[i - 1]) continue;

            taken[i] = true;
            temp.push_back(nums[i]);
            generate(nums, temp, taken, answer);
            temp.pop_back();
            taken[i] = false;
        }
    }
};
