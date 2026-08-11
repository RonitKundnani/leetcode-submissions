class Solution {
public:
    bool isvowel(char c){
        return c=='a' or c=='e' or c=='i' or c=='o' or c=='u';
    }
    int maxVowels(string s, int k) {
        int left=0;
        int maxVowel=0;
        int vowel=0;
        for(int right=0;right<s.size();right++){
            if(isvowel(s[right])) vowel++;
            if((right-left+1) == k){
                maxVowel=max(maxVowel,vowel);
                if(isvowel(s[left]))vowel--;
                left++;
            }
        }return maxVowel;
    }
};
