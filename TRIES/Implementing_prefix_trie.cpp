class Node{
public:
    
    char data;
    unordered_map<char, Node*>mp;
    bool terminal;
    
    Node(char d)
    {
        data = d;
        terminal = false; 
    }
};

class Trie {
public:
    Node * root;
    Trie() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        
        Node * temp = root;
        int n = word.length();
        for(int i=0;i<n;i++)
        {
            if(temp->mp.count(word[i])==0)
            {
                Node * n = new Node(word[i]);
                temp->mp[word[i]] = n;
            }
            temp = temp->mp[word[i]];
        }
        temp->terminal = true;
    }
    
    bool search(string word) {
        
        Node * temp = root;
        int n = word.size();
        for(int i=0;i<n;i++)
        {
            if(temp->mp.count(word[i])==0)
            {
                return false;
            }
            temp = temp->mp[word[i]];
        }
        return temp->terminal;
        
    }
    
    bool startsWith(string prefix) {
        
        int n = prefix.length();
        Node * temp = root;
        for(int i=0;i<n;i++)
        {
            if(temp->mp.count(prefix[i])==0)
                return false;
            
            temp = temp->mp[prefix[i]];
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */