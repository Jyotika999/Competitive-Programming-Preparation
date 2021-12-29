// OOPS 

#include<bits/stdc++.h>
using namespace std;
class data{
	
	public:
	string first_name;
	string last_name;
	int age;
	int year_of_birth;
	string location;
	
};

int main()
{
		
		int testcases;
		cin>>testcases;
		
		data userdata[testcases+1];
		
		for(int i=1;i<=testcases;i++)
		{
			string first_name;
			string last_name;
			int age;
			int year_of_birth;
			string location;
			cin>>first_name>>last_name>>age>>year_of_birth>>location;
			userdata[i-1].first_name=first_name;
			userdata[i-1].last_name=last_name;
			userdata[i-1].age=age;
			userdata[i-1].year_of_birth=year_of_birth;
			userdata[i-1].location=location;
				
		}
		for(int i=0;i<testcases;i++)
		{
			cout<<"USERDATA "<<i+1<<"\n";
			cout<<"FIRSTNAME : "<<userdata[i].first_name<<"\n";
			cout<<"LASTNAME : "<<userdata[i].last_name<<"\n";
			cout<<"AGE : "<<userdata[i].age<<"\n";
			cout<<"YEAR OF BIRTH : "<<userdata[i].year_of_birth<<"\n";
			cout<<"LOCATION : "<<userdata[i].location<<"\n";
			cout<<"\n";
		}
}