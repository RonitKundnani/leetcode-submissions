class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int base=0;
        //Already satisfied 
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0) base+=customers[i];    
        }
        //extra in window
        int gain=0;
        for(int i=0;i<minutes;i++){gain+=customers[i]*grumpy[i];}
        int maxGain=gain;
        int left=0;
        for(int i=minutes;i<customers.size();i++){
            gain-=customers[left]*grumpy[left];
            left++;
            gain+=customers[i]*grumpy[i];
            maxGain=max(maxGain,gain);
        }return maxGain+base;
    }
};
