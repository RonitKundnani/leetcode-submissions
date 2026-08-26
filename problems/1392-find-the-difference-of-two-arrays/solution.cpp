class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1(nums1.begin(), nums1.end());
        unordered_set<int> n2(nums2.begin(), nums2.end());
        vector<int> a, b;
        for (int x:n1){
            if(!n2.count(x)) a.push_back(x);
        }
        for (int x:n2){
            if(!n1.count(x)) b.push_back(x);
        }
        return {a, b};
    }
};
