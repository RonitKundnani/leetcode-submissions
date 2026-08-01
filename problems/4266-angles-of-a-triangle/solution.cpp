class Solution {
public:
    double angle(int a,int b,int c){
        double cosA=(((double)b*b)+((double)c*c)-((double)a*a))/(2.0*b*c);
        return acos(cosA)* 180.0 / acos(-1.0);
    }
    vector<double> internalAngles(vector<int>& sides) {
        vector<double> res;
        sort(sides.begin(),sides.end());
        if(sides[0]+sides[1]<=sides[2]) return {};
        else{
            res={angle(sides[0],sides[1],sides[2]),
                angle(sides[1],sides[2],sides[0]),
                angle(sides[2],sides[0],sides[1])};
            sort(res.begin(),res.end());
            return res;
        }
    }
};
