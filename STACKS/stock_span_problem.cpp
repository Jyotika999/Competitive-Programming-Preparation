class StockSpanner {
public:
    
    
    // nearest smallest to left wala index find krna h
    // that will be the span of the current day 
    // as the stream of integers are added more
    
    vector<int>daily;
    int ct=0;
    stack<pair<int,int>>s;
    
    StockSpanner() {
        daily.clear();
        ct=0;
    }
    
    int next(int price) {
        
        ct++;
        daily.push_back(price);
        // finding nearest smaller to left;
        // jab tk conseuctive smaller ya equal aarha h pop pkrwate jayo 
        while(!s.empty()  and ((s.top().first)<=price))
            s.pop();
        
        int ans = 1;
        if(!s.empty())
            ans=ct-s.top().second;
        else
            ans= ct; // mtlb peeche k sare elements chote hain 
        if(!s.empty())
        cout<<price<<" "<<s.top().second<<" "<<s.top().first<<"\n";
        s.push({price, ct});
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */