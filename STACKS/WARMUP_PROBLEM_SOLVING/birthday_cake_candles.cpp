
// Problem: Birthday Cake Candles
// Contest: HackerRank - Algorithms - Warmup
// URL: https://www.hackerrank.com/challenges/birthday-cake-candles/problem
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

int birthdayCakeCandles(vector<int> candles) {

    int n = candles.size();
    int maxi=0;
    
    for(int i=0;i<n;i++)
    {
        maxi = max(maxi, candles[i]);
    }
    
    int c=0;
    
    for(int i=0;i<n;i++)
    {
        if(candles[i]==maxi)
        c++;
    }

    return c;
}
