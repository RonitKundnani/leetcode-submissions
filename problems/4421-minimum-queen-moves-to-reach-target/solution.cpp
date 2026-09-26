class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        if(source[0]==target[0] and source[1]==target[1]) return 0;
        if(source[0]==target[0] or source[1]==target[1] or abs(target[0]-source[0])==abs(target[1]-source[1])) return 1;
        else return 2;
    }
};
