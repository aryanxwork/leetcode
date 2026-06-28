class Solution {
public:
    void reverse(vector<int>& nums,int si,int ei){
    for (int i = si, j = ei; i <= j; i++, j--)
    {
        swap(nums[i], nums[j]);
    }
    }
    void rotate(vector<int>& nums, int k) {
        if(k>nums.size()){
            k=k%nums.size();
        }
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
    }
};