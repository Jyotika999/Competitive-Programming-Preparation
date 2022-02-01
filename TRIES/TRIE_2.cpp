// TRIE IMPLEMENTATION
// COUNTWORDS EQUAL TO 
// COUNTWORDS STARTING WITH
// ERASE A WORD 

#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		char data;
		unordered_map<char, Node*>mp;
		int ends_with ;
		int count_pre ; 
		Node(char d)
		{
			data = d;
			ends_with =0;
			count_pre =0;
		}
		
};

class Trie{
	public:
		Node * root;
		Trie()
		{
			root = new Node('\0');
		}
		
		void insert(string s)
		{
			Node * temp = root;
			
			for(int i=0;i<s.length();i++)
			{
				if(temp->mp.count(s[i])==0)
				{
					Node * n = new Node(s[i]);
					temp->mp[s[i]] = n;
				}
				temp->count_pre = temp->count_pre + 1;
			
				temp= temp->mp[s[i]];
			}
			temp->count_pre = temp->count_pre + 1;
			temp->ends_with =  temp->ends_with +1 ;
			
		}
		
		int count_words_equal_to(string s)
		{
			Node * temp = root;
			
			for(int i=0;i<s.length();i++)
			{
				if(temp->mp.count(s[i])==0)
				return 0;
				
				temp = temp->mp[s[i]];
			}
			return temp->ends_with;
			
		}
		
		int count_prefixes(string s)
		{
			Node * temp = root;
			for(int i=0;i<s.length();i++)
			{
				if(temp->mp.count(s[i])==0)
				return 0;
				// cout<<temp->data<<" "<<temp->count_pre<<"\n";
				temp = temp->mp[s[i]];
			}
			// cout<<temp->data<<"\n";
			return temp->count_pre;
		}
		void erase(string s)
		{
			Node * temp = root;
			for(int i=0;i<s.length();i++)
			{
				if(temp->mp.count(s[i])==0)
				return ;
				
				temp->count_pre = temp->count_pre -1;
				temp = temp->mp[s[i]];
			}
			temp->count_pre = temp->count_pre -1 ;
			temp->ends_with = temp->ends_with -1;
			return;
		}
	
};

int main()
{
	int n;
	cin>>n;
	Trie t;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		t.insert(s);
	}
	
	int q3, q1, q2;
	// endwith queries
	cin>>q3;
	while(q3--)
	{
		string s;
		cin>>s;
		t.erase(s);
	}
	
	cin>>q1;
	while(q1--)
	{
		string s;
		cin>>s;
		cout<<t.count_words_equal_to(s)<<"\n";
	}
	
	cin>>q2;
	while(q2--)
	{
		string s;
		cin>>s;
		cout<<t.count_prefixes(s)<<"\n";
	}
	
	
}