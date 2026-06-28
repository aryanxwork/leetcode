class Solution {
public:
    vector<string> ans;

    void helper(int n, int last, string curr) {
        if (n == 0) {
            ans.push_back(curr);
            return;
        }

        // Can always place '1'
        helper(n - 1, 1, curr + '1');

        // Can place '0' only if previous bit wasn't '0'
        if (last != 0) {
            helper(n - 1, 0, curr + '0');
        }
    }

    vector<string> validStrings(int n) {
        helper(n, 1, "");
        return ans;
    }
};