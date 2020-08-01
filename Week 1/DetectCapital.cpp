// Time complexity :- O(n)
// Space complexity :- O(1)
class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int capital = 0;
        for(auto ch: word)
            capital += (ch>='A' && ch<='Z');
     
        if(capital == word.length() || capital == 0 || (capital == 1 && (word[0] >='A' && word[0] <= 'Z')))
            return true;
        else
            return false;
    }
};