// GIVEN AN ARRAY OF STRINGS
// FIND THE LONGEST LENGTH OF STRING 
// WHICH IS HAVING ALL ITS PREFIXES IN THE GIVEN ARRAY

#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	char data;
	unordered_map<char, Node*>mp;
	bool terminal;
	
	Node(char d)
	{
		data = d;
		terminal = false;
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
			temp = temp->mp[s[i]];
		}
		temp->terminal = true;
	}
	
	bool search(string s)
	{
		Node * temp = root;
		for(int i=0;i<s.length();i++)
		{
			if(temp->mp.count(s[i])==0)
			return false;
			temp = temp->mp[s[i]];
		}
		if(temp->terminal)
		return true;
		else
		return false;
	}
};

int main()
{
	int n;
	cin>>n;
	string ar[n];
	Trie t;
	
	for(int i=0;i<n;i++)
	{
		cin>>ar[i];
		t.insert(ar[i]);
	}
	string ans="";
	for(int i=0;i<n;i++)
	{
		string s = ar[i];
		bool flag= 1;
		// cout<<s<<"\n";
		for(int j=0;j<s.length();j++)
		{
			string str = s.substr(0, j+1);
			
			flag = flag && (t.search(str));
			
		}
		// cout<<s<<" "<<flag<<"\n";
		if(flag)
		{
			// if(ans.length()==s)
			// {
				// // lexicographically smallest 
			// }
			// else
			{
				ans = s;
			}
		}
	}
	
	cout<<ans<<"\n";
}