// TIme complexity :- O(n)
// Space complexity :- O(n)
class Solution {
public:
    string toGoatLatin(string S) {
        
        stringstream ss(S);
        vector<string>words;
        string str="";
        
        while(getline(ss, str, ' '))
        {
            words.push_back(str);
        }
        
        int id = 1;
        str = "";
        for(auto &word: words)
        {
            if(word[0] == 'a' || word[0] == 'A' ||
               word[0] == 'e' || word[0] == 'E' ||
               word[0] == 'i' || word[0] == 'I' ||
               word[0] == 'o' || word[0] == 'O' ||
               word[0] == 'u' || word[0] == 'U')
            {
                str += word + "ma";
            }
            else
            {
                str += word.substr(1) + word[0] + "ma";
            }
            for(int i=1;i<=id;i++)  str += "a";
            id++;
            str += " ";
        }
        str.pop_back();
        
        return str;
    }
};