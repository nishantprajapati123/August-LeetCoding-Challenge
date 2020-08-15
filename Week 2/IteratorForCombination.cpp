class CombinationIterator {
    queue<string>q;
    string s;
public:
    void comb(int start, int n, string curr)
    {
        if(n == 0)
        {
            q.push(curr);
            return;
        }
        for(int i=start;i<=(s.length()-n); i++)
        {
            comb(i+1, n-1, curr + s[i]);
        }
    }
    CombinationIterator(string characters, int combinationLength) {
        
        s = characters;
        string curr = "";
        comb(0, combinationLength, curr);
        
    }
    
    string next() {
        
        string ans = q.front();
        q.pop();
        return ans;
    }
    
    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */