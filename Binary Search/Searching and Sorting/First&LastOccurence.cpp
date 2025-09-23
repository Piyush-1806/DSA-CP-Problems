class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size()-1;
        int first_occurence = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int last_occurence = upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        if(first_occurence<=n && nums[first_occurence]==target){
            ans.push_back(first_occurence);
            ans.push_back(last_occurence);
        }
        else{
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};