// Longest length of the mountain array

#include<bits/stdc++.h>
using namespace std;

int mountain_length(int ar[], int n)
{
	int i=1;
	int len=0;
	int max_len=0;
	
	while(i<n-2)
	{
		// if peak element , then do some work
		if(ar[i-1]<ar[i] and ar[i]>ar[i+1])
		{
			int frnt=i;
			while(ar[frnt-1]<=ar[frnt])
			{
				frnt--;
				len++;
			}
			
			int back = i;
			while(ar[back]>= ar[back+1])
			{
				back++;
				len++;
			}
			//cout<<len<<" "<<max_len<<"\n";
			max_len = max(max_len, len);
			i++;
			
		}
		
		// else continue further
		else
		{
			i++;
			len=0;
		}
	}
	
	return max_len;
}
int main()
{
	int n;
	cin>>n;
	
	int ar[n];
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	
	int len = mountain_length(ar, n);
	cout<<len<<"\n";
	
}