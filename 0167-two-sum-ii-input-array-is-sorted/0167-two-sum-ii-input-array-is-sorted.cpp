class Solution {
public:
    vector<int> twoSum(vector<int>arr, int target) {
        int st=0,end=arr.size()-1;
        int currsum=0;
        vector<int>ans;
        while(st<end){
            currsum=arr[st]+arr[end];
            if(currsum==target){
                ans.push_back(st+1);
                ans.push_back(end+1);
                return ans;
            }
            else if(currsum>target){
                end--;
            }
            else{
                st++;
            }
        }
        return ans;
    }
    
};
