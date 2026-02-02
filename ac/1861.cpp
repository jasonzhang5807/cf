#include <map>
#include <iostream>
#include <string>
using namespace std;
map<string,int> mp;
int main(){
	int n,ans=0;
	cin>>n;
	string s;
	while(n--){
		cin>>s;
		mp[s]++;
		if(mp[s]>2)ans++,mp[s]-=2;
	}
	cout<<mp.size()+ans;
	return 0;
}
