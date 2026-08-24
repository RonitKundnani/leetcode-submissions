class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt=0,high=0;
        for(int x:gain){
            alt+=x;
            high=max(high,alt);
        }return high;
    }
};
