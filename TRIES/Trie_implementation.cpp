
#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

//this is how every node of the trie will look like 
class Node{
	
	public:
		char data;
		unordered_map<char, Node*>mp;
		bool is_terminal;
		Node(char d)
		{
			data = d;
			is_terminal = false;
		}
};

// making of class trie 
class Trie{
	public:
		Node * root;
		Trie()
		{
			root = new Node('\0');// NULL CHARACTER IS THE ROOT IF TRIE
		}
		
		void insert(string word)
		{
			// root created using new keyword 
			// created in heap memory
			// hence it needs to be accessed using -> arrow
			
			Node * temp = root;
			for(char ch : word)
			{
				if(temp->mp.count(ch)==0)
				{
					Node * n = new Node(ch);
					temp->mp[ch] = n;
				}
				temp = temp->mp[ch];
			}
			temp->is_terminal = true;
		}
		
		bool search(string word)
		{
			Node * temp = root;
			for(char ch : word)
			{
				if(temp->mp.count(ch)==0)
				return false;
				
				temp = temp->mp[ch];
			}
			return temp->is_terminal;
			
		}
	
};

int main()
{
	
	ll n;
	cin>>n;
	
	string ar[n];
	for(ll i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	
	// trie object created in stack , hence 
	// accesssed by "." dot operator 
	
	Trie t ;
	for(ll i=0;i<n;i++)
	{
		t.insert(ar[i]);
	}
	
	ll q;
	cin>>q;
	
	while(q--)
	{
		string c;
		cin>>c;
		if(t.search(c))
		cout<<"YES";
		else
		cout<<"NO";
		
		cout<<"\n";
	}
	
	
}