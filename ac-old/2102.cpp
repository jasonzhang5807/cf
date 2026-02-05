#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main(){
	freopen("title.in","r",stdin);
	freopen("title.out","w",stdout);
	string s;
	getline(cin,s);
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!=' ') ans++;
	}
	cout<<ans;
	return 0;
}
