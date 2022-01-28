// Problem: L. Divide The Students
// Contest: Codeforces - 2019-2020 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/problemset/problem/1250/L
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool funct(ll mid, ll a, ll b, ll c)
{
	// a in 1 , 2 
	// c in 3
	// {
		// ll box1  = min(a,x);
		// ll box2 = min(a-box1, x);
		// a = a-box1-box2;
// 		
		// ll box3 = min(x, c);
		// c = c - box3;
		// if(a==0 and c==0 and (x-box1 + x-box2 + x-box3)>=b)
		// {
			// return true;
		// }
	// }
// 	
// 	
	// // a in 1
	// // c in 2,3
	// {
		// ll box1 = min(x, a);
		// ll box2 = min(x, c);
		// ll box3 = min(x, c-box2);
		// c = c-box2-box3;
		// a = a-box1;
		// if(a==0 and c==0 and (x-box1 + x-box2 + x-box3)>=b)
		// {
			// return true;
		// }
	// }
// 	
// 	
	// // a in 1
	// // c in 3
	// {
		// ll box1 = min(x,a);
		// ll box2 = 0;
		// ll box3 = min(x,c);
		// a=a-box1;
		// c=c-box3;
		// if(a==0 and c==0 and (x-box1+x-box2+x)>=b)
		// {
			// return true;
		// }
	// }
	// return false;
// 	

 bool pos = false;
        // Imagine there are 3 boxes of size mid, with B out of picture
        // [S1] A can be in box 1,2 and C in box 3
        // OR
        // [S2] C in box 2,3 and A in 1
        // OR
        // [S3] A in 1 and C in 3
        // Then we see space left and fill them with B
        // [S4] A in 1 and 2 and B in 2 and 3 and C in 3
        // Then we see space left and fill them with B
        // [S5] A in 1 and B in 1 and 2 and C in 2 and 3
        // Then we see space left and fill them with B
        
        // Case S1 (a > mid and a <= 2*mid and c <= mid)
        {
            if(a > mid && a <= 2*mid && c <= mid){
                int box2 = 2*mid - a;
                int box3 = mid - c;
                if(box2 + box3 >= b){
                    pos = true;
                }
            }
        }
        
        // Case S2 (a <= mid and c > mid and c <= 2*mid)
        {
            if(c > mid && c <= 2*mid && a <= mid){
                int box2 = 2*mid - c;
                int box1 = mid - a;
                if(box2 + box1 >= b){
                    pos = true;
                }
            }
        }
        
        // Case S3 (a <= mid and c <= mid)
        {
            if(c <= mid && a <= mid){
                int box2 = mid;
                int box1 = mid - a;
                int box3 = mid - c;
                if(box2 + box1 + box3 >= b){
                    pos = true;
                }
            }
        }
        // Case S4 (c < mid)
        {
            if(c < mid){
                int box3 = mid - c;
                int new_b = b-box3;
                int box2 = mid - new_b;
                int box1 = mid;
                if(new_b >= 0 && box2+box1 >= a){
                    pos = true;
                }
            }
        }
        
        // Case S5 (a < mid)
        {
            if(a < mid){
                int box1 = mid - a;
                int new_b = b-box1;
                int box2 = mid - new_b;
                int box3 = mid;
                if(new_b >= 0 && box2+box3 >= c){
                    pos = true;
                }
            }
        }
        
        return pos;
}
void solve()
{
	ll a,b,c;
	cin>>a>>b>>c;
	ll high = max(a, max(b,c));
	ll ans=0;
	ll low=0;
	
	while(low<=high)
	{
		int mid = (low+high)/2;
		
		if(funct(mid, a, b, c))
		{
			ans = mid;
			high = mid-1;
		}
		else
		{
			low = mid+1;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ll tc=1;
	cin>>tc;
	for(ll i=1;i<=tc;i++)
	{
		// cout<<"Case "<<"#"<<i<<": ";
		solve();
	}
}