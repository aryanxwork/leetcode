#include<iostream>
#include<vector>
using namespace std;

vector<int>pairsum (vector<int>arr,int target){
    int st=0, end=arr.size()-1;
    int currentsum=0;
    vector<int>ans;

    while(st<end){
        currentsum=arr[st]+arr[end];
        if (currentsum==target)
        {
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        }
        else if (currentsum>target)
        {
            end--;
        }
        else{
            st++;
        }
        
        }
        return ans;
    }

int main(){
    vector<int>arr={2,7,9,11};
    int targetsum=9;
    vector<int>ans=pairsum(arr,targetsum);
    cout<<"required indices are "<<ans[0]<<","<<ans[1]<<endl;
}