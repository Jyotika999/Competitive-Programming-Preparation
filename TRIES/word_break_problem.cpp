class Node{
    public:
    char data ;
    map<char, Node*>mp;
    bool terminal ;
    Node(char d)
    {
        data = d;
        terminal = false;
    }
};

class Trie{
    public:
    Node * root ;
    Trie()
    {
        root = new Node('\0');
    }
    void insert(string t)
    {
        Node * temp = root;
        int len = t.length();
        for(int i=0;i<len;i++)
        {
            char cur = t[i];
            if(temp->mp.count(cur)==0)
            {
                temp->mp[cur]= new Node(cur);
            }
            temp = temp->mp[cur];
        }
        temp->terminal = true;
    }
    
    
    bool search(string s)
    {
        Node * temp = root;
        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];
            if(temp->mp[ch])
            {
                temp = temp->mp[ch];
            }
            else
                return false;
        }
        return temp->terminal;
    }
   
};


class Solution {
public:
    
     bool check(string s,  Trie &t, map<string,bool>&mp )
    {
        
        
        int n = s.length();
        if(n==0)
            return true;
         
         if(mp.count(s))
             return mp[s];
        
        for(int k=0;k<=n;k++)
        {
            string str1 = s.substr(0, k);
            string str2 = s.substr(k, n);
            if(t.search(str1) and check(str2, t, mp))
            {
                return mp[s]=true;
            }
        }
        return mp[s]=false;
    }
    bool wordBreak(string s, vector<string>& word) {
        
        map<string,bool>mp;
        Trie t ;
        int n = word.size();
        for(int i=0;i<n;i++)
        {
            t.insert(word[i]);
        }
        // return true;
        
        return check(s, t, mp);
        
        
    }
};