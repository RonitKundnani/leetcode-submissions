class Solution {
public:
    string defangIPaddr(string address) {
        string str;
        for(char c : address){
            if(c=='.'){str=str+'['+c+']';}
            else str+=c;
        }
        return str;
    }
};
