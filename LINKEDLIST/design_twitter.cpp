class Twitter {
public:
    
    // map to store the follower 
    unordered_map<int, set<int>>follower;
    
    // map to store the tweetid and userid
    unordered_map<int,int>mp;
    
    // list of pair of tweets , which will be helpful in getnewsfeed
    list<pair<int,int>>newsfeed;
    
    Twitter() {
        
        follower.clear();
        mp.clear();
        newsfeed.clear();
        
    }
    
    void postTweet(int userId, int tweetId) {
        newsfeed.push_front({userId, tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
        
        // if the post is done by usedId
        // or if the post is done by the follower of userId
        // then that will be present in the newsfeed of the userId
        int count=0;
        vector<int>news;
        for(auto it : newsfeed)
        {
            if(count==10)
            {
                break;
            }
            // count++;
            int ff=it.first; // userid
            int ss=it.second; // tweetid
            
            if(ff==userId or (follower[userId].find(ff)!=follower[userId].end()))
            {
                news.push_back(ss);
                count++;
            }
           
        }
         return news;
    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */