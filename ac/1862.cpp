#include <set>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
set<string> a;
int main(){
	int n;
	cin>>n;
	string s;
	while(n--){
		getchar();
		char opt=getchar();
		switch(opt){
			case '+':
				cin>>s;
				a.insert(s);
				break;
			case '-':
				cin>>s;
				a.erase(s);
				break;
			case 'Q':
				cout<<a.size()<<endl;
				for(string x : a)cout<<x<<" ";
				cout<<endl;
				break;
			default:
				break;
		}
	}
}
