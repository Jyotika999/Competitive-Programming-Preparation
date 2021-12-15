class MyHashSet {
public:
    
    vector<list<int>>m;
    // use of vector of doubly linkedlist
    // use of hashfunctions
    // use of separate chaining
    int sz;
    MyHashSet() {
        sz=100;
        m.resize(sz);
    }
    
    int hash(int key)
    {
        return key%sz;
    }
    auto search(int key)
    {
        int i=hash(key);
        
       return find(m[i].begin(), m[i].end(), key);
    }
    void add(int key) {
        
        int i=hash(key);
        if(!contains(key))
        m[i].push_back(key);
        
    }
    
    void remove(int key) {
        int i=hash(key);
        if(contains(key))
        m[i].erase(search(key));
    }
    
    bool contains(int key) {
        
        int i=hash(key);
        if(search( key)!=m[i].end())
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */