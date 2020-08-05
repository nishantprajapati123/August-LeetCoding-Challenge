// Time complexity :- O(n)
// Space complexity :- O(n)
class WordDictionary {
private:
    struct Node {
        bool endsHere; 
        vector<Node*> chars; 
        
        Node() { // Node Constructor
            endsHere = false;
            chars = vector<Node*>(26, nullptr);
        }
    };
    Node *root;
    
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *cur = root;
        for (char x: word) {
            int c = x - 'a'; // convert to 0-index

            if (cur->chars[c] == nullptr) { // If no node exists at this char
                cur->chars[c] = new Node(); // create one
            }
            
            cur = cur->chars[c]; // go to the next node
        }
        // set endsHere to true to indicate end of word on this node
        cur->endsHere = true;
    }
    
    bool search(string word) {
        return searchHelper(0, root, word);
    }
    
    bool searchHelper(int i, Node *cur, string word) {
        if (cur == nullptr || i>word.size()) return false; // invalid call
        
        while (i < word.size()) {
            int c = word[i] - 'a'; // convert to 0-index
            
            if (c == '.' - 'a') { // '.' to 0-index
                bool found = false;
                for (int j=0; j<26; j++) { // recurse on all available chars at this node
                    if (cur->chars[j] == nullptr) continue;
                    found = searchHelper(i+1, cur->chars[j], word);
                    if (found == true) break;
                }
                return found;
            }
            
            if (cur->chars[c] == nullptr) return false;
            cur = cur->chars[c];
            i++;
        }
        
        if (i == word.size()) return cur->endsHere;
        return false;
    }
};