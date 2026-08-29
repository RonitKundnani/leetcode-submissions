class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        if(((source[0]+source[1])%2)!=((target[0]+target[1])%2)) return -1;
        else{
            if(abs(target[0]-source[0])==abs(target[1]-source[1])) return 1;
            else return 2;
        }
    }
};
