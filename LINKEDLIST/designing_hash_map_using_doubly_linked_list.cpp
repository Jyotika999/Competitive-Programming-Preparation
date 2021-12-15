class MyHashMap {
public:
    
    vector<list<pair<int,int>>>m;
    int sz;
    MyHashMap() {
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
        
        auto it = m[i].begin();
        
        while(it!=m[i].end())
        {
            if(it->first==key)
                return it;
            it++;
        }
        return it;
    }
    void put(int key, int value) {
        
        auto it = search(key);
        int i=hash(key);
        if(it==m[i].end()){
            m[i].push_back({key, value});
        }
        else
        {
            remove(key);
            m[i].push_back({key, value});
        }
        
    }
    
    int get(int key) {
        
        auto it = search(key);
        int i=hash(key);
        if(it==m[i].end())
        {
            return -1;
        }
        else
        {
            return it->second;
        }
    }
    
    void remove(int key) {
        
        auto it = search(key);
        int i=hash(key);
        if(it!=m[i].end())
            m[i].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */