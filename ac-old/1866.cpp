#include <string>
#include <set>
#include <iostream>
using namespace std;
set<string> a;
string ipt(){
	string s;
	char b;
	while(b!=':'){
		b=getchar();
		s+=b;
	}
	return s;
}
int main(){
	ipt();
	string gjc;
	while(getchar()==' '){
		cin>>gjc;
		a.insert(gjc);
	}
	int n;
	cin>>n;
	getchar();
	while(n--){
		cout<<ipt()<<" ";
		int cnt=0,all=0;
		while(getchar()==' '){
			cin>>gjc;
			if(a.count(gjc))cnt++;
			all++;
		}
		cout<<cnt<<"/"<<all<<endl;
	}
	return 0;
}
