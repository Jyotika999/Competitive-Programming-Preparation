
// Problem: Staircase
// Contest: HackerRank - Algorithms - Warmup
// URL: https://www.hackerrank.com/challenges/staircase/problem
// Memory Limit: 512 MB
// Time Limit: 4000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)


void staircase(int n) {

// for(i=1 to n)
// {
//     // print(n-i) spaces 
//     // print(i) #
// }

for(int i=1;i<=n;i++)
{
    for(int j=1;j<=(n-i);j++)
    {
        cout<<" ";
    }
    for(int j=1;j<=i;j++)
    {
        cout<<"#";
    }
    
    cout<<"\n";
}





}