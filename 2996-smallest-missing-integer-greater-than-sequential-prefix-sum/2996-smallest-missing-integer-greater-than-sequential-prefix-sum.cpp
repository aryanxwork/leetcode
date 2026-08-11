class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int hash[51]={0};
        int currSum=0;
        int n=nums.size();
        bool propertySatisfied=true;
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
            if (propertySatisfied) {
            currSum += nums[i];

            if (i < n - 1 && nums[i + 1] != nums[i] + 1) {
                propertySatisfied = false;
            }
        }
        }
        for(int i=currSum;;i++){
            if(i>50){return i;}
            else if(hash[i]==0){
                return i;
            }
        }
    }
};