class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map;
        for(int i=0;i<s.size();i++){
            if(map.count(s[i])){
                if(map[s[i]]==t[i]) continue;
                else return false;
            }else{
                for(auto& val:map){
                    if(val.second==t[i]) return false;
                }
                map[s[i]]=t[i];
            }
        }return true;
    }
};
