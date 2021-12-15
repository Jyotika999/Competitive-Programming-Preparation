class MyHashSet {
public:
    // creating a hashset , using a vector, but it has a limitation because the size of the vector can only be created till (1e6), but incase the elements are greater than 1e6, then how will we create it?
    
    vector<int>m;
    MyHashSet() {
        int sz=1e6+5;
        m.resize(sz);
    }
    
    void add(int key) {
        m[key]=1;
    }
    
    void remove(int key) {
        m[key]=0;
    }
    
    bool contains(int key) {
        return m[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */