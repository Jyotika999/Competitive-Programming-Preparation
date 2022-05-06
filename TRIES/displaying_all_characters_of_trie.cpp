// displaying the content of a trie 

#include<bits/stdc++.h>
using namespace std;

class Node{
	
	public:
	char data;
	map<char, Node*>mp;
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
	void insert(string word)
	{
		Node * temp = root;
		
		int len = word.size();
		
		for(int i=0;i<len;i++)
		{
			char cur = word[i];
			if(temp->mp.count(cur)==0)
			{
				// create new node 
				Node * newnode = new Node(cur);
				temp->mp[cur]=newnode;
			}
			temp = temp->mp[cur];
		}
		temp->terminal = true;
	}
	
	void display_all(Node * temp, string str)
	{
		if(temp->terminal == true)
		{
			cout<<str<<"\n";
		}
		
		for(auto it : temp->mp)
		{
			if(temp->mp[it.first])
			{
				// str+=it.first;
				display_all(temp->mp[it.first], str+it.first);
			}
		}
	}
	void display()
	{
		// to display all the content of the trie 
		Node * temp = root;
		string str="";
		display_all(temp, str);
	}
	
	
};
int main()
{
	int n ;
	cin>>n;
	Trie t ;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		t.insert(s);
	}
	
	t.display();
}