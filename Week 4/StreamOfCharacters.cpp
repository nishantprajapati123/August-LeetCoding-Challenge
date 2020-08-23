// Time complexity :- O(n*m) and O(m)
// SPace complexity :- O(n*m)
class Trie
{
    public:
        vector<Trie*>child;
        bool leaf;
        Trie()
        {
            child.resize(26, NULL);
            leaf = false;
        }
};
class StreamChecker {
    Trie *root;
    string s;
public:
    StreamChecker(vector<string>& words) {
        
        root = new Trie();
        s = "";
        for(auto word: words)
        {
            Trie *curr = root;
            reverse(word.begin(), word.end());
            for(char c: word)
            {
                if(curr->child[c-'a'] == NULL)
                    curr->child[c-'a'] = new Trie();
                
                curr = curr->child[c-'a'];
            }
            curr->leaf = true;
        }
    }
    
    bool query(char letter) {
        s += letter;
        
        Trie *curr = root;
        int i=s.length()-1;
        while(i>=0 && curr->child[s[i] - 'a'] != NULL)
        {
            curr = curr->child[s[i] - 'a'];
            if(curr->leaf)  return true;
            i--;
        }
        
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */