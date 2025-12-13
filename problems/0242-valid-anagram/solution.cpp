class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map;
        if(s.length()==t.length()){
            for(char x:s){
                if(map.contains(x))map[x]++;
                else map[x]=1;
            }
            for(char x:t){
                if(map.contains(x))map[x]--;
                else return false; 
            }
            for(auto x:map) if(x.second!=0) return false;
                       
            return true;
        }
        else return false;
    }
};
