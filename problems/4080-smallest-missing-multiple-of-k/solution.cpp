// class Solution {
// public:
//     int missingMultiple(vector<int>& nums, int k) {
//         unordered_set<int> s;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]%k==0){
//                 int x=nums[i]/k;
//                 s.insert(x);
//             }
//         }
//         int cnt=1;
//         for(const int i:s){
//             if(!s.count(cnt)) return cnt*k;
//             cnt++;
//         }
//         return cnt*k;
//     }
// };
//better
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());

        int x = k;

        while(s.count(x)) {
            x += k;
        }

        return x;
    }
};
