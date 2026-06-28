class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        else{
        long long int rev=0;
        long long int rem;
        int og=x;
        while(x!=0){
            rem=x%10;
            rev=rev*10 +rem;
            x/=10;
        }
        
         if(rev==og){
            return true;
        }
        else{
            return false;
        }
        }
        
    }
};