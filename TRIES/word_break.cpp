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

class Trie{
public:
    Node * root;
    Trie()
    {
        root = new Node('\0');
    }
    
    void insert(string s)
    {
        int n = s.length();
        Node * temp = root;
        for(int i=0;i<n;i++)
        {
            if(temp->mp.count(s[i])==0)
            {
                Node * n = new Node(s[i]);
                temp->mp[s[i]] = n;
            }
            temp = temp->mp[s[i]];
        }
        temp->terminal = true;
        
    }
    bool search(string s)
    {
        int n = s.length();
        Node * temp = root;
        for(int i=0;i<n;i++)
        {
            if(temp->mp.count(s[i])==0)
            {
               return false;
            }
            temp = temp->mp[s[i]];
        }
        
        return temp->terminal;
        
    }
    
};


class Solution {
public:
    Trie t ;
    unordered_map<string, int>mp;
    
    bool word_break_util(string s)
    {
        int n = s.length();
        if(n==0)
            return true;
        
        if(mp.find(s)!=mp.end())
            return mp[s];
        
        for(int i=1;i<=n;i++)
        {
            string substr1 = s.substr(0, i);
            string substr2 = s.substr(i, n);
            cout<<substr1<<" "<<substr2<<"\n";
            if(t.search(substr1) && word_break_util(substr2))
            {
                return mp[s] = true;
            }
        }
        return mp[s] = false;
    }
    
    bool wordBreak(string s, vector<string>& worddict) {
        
        int n = worddict.size();
        // Trie t ; 
        
        for(int i=0;i<n;i++)
        {
            t.insert(worddict[i]);
        }
        
        return word_break_util(s);
          
    }
};