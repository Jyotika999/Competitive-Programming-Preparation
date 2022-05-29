#include<bits/stdc++.h>
using namespace std;

class Stack{
	
	public:
	int ct=0;
	priority_queue<pair<int,int>>pq;
	
	Stack()
	{
		ct=0;
	}
	void push(int ele)
	{
		ct++;
		pq.push({ct, ele});
		
	}
	void pop()
	{
		pq.pop();
		ct--;
	}
	int top()
	{
		return pq.top().second;
	}
	int empty()
	{
		return pq.empty();
	}
	int size()
	{
		return pq.size();
	}
};
int main()
{
	int n;
	cin>>n;
	Stack * ob = new Stack();
	while(n--)
	{
		int val;
		cin>>val;
		ob->push(val);
	}
	
	while(!ob->empty())
	{
	cout<<ob->top()<<" ";
	ob->pop();
	}
	
	
}