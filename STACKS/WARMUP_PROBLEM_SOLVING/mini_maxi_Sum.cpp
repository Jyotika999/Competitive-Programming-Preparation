
// Problem: Mini-Max Sum
// Contest: HackerRank - Algorithms - Warmup
// URL: https://www.hackerrank.com/challenges/mini-max-sum/problem
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


void miniMaxSum(vector<int> arr) {

    sort(arr.begin(), arr.end());
    
    long long int mini=0;
    long long int maxi=0;
    
    for(int i=0;i<4;i++)
    {
        mini+= arr[i];
    }
    
    for(int i=1;i<5;i++)
    {
        maxi+= arr[i];
    }
    
    cout<<mini<<" "<<maxi<<"\n";
}
