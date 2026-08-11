class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total_pts=0;
        int pts=0;
        int left=0;
        for(int i=0;i<cardPoints.size();i++){
            if(i<(int(cardPoints.size())-k))
                pts+=cardPoints[i];
            total_pts+=cardPoints[i];
        }
        int ans=total_pts-pts;
        for(int right=int(cardPoints.size())-k;right<cardPoints.size();right++){
            pts+=cardPoints[right];
            pts-=cardPoints[left];
            left++;
            ans=max(ans,total_pts-pts);
        }return ans;
    }
};
