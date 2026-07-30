class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_Alt=0;
        int cur_Alt=0;
        for(int i=0;i<int(gain.size());i++){
            cur_Alt+=gain[i];
            max_Alt=max(max_Alt,cur_Alt);
        }return max_Alt;
    }
};
