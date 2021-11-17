
// Problem: Plus Minus
// Contest: HackerRank - Algorithms - Warmup
// URL: https://www.hackerrank.com/challenges/plus-minus/problem
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


void plusMinus(vector<int> arr) {

    int n = arr.size();
    double neg=0;
    double pos=0;
    double zero=0;
    
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        neg++;
        
        if(arr[i]>0)
        pos++;
        
        if(arr[i]==0)
        zero++;
    }
    
    double ans = 0.0001;
    
    printf("%0.6f\n", pos/n);
    printf("%0.6f\n", neg/n);
    printf("%0.6f\n", zero/n);
    //cout<<(pos*ans/n)<<" "<<(neg*ans/n)<<" "<<(zero*ans/n)<<"\n";
    

}