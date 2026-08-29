class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for(long long n:nums){
            string s="";
            for(int i=25;i>=0;i--){
                long long val=pow(2,i);
                if(n>=val){
                    if(i==25){
                        s.append(n/val,'z');
                        n%=val;
                    }
                    else{
                        s+=char('a'+i);
                        n-=val;
                    }
                }
            }ans.push_back(s);
        }return ans;
    }
};










