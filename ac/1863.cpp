#include <map>
#include <iostream>
#include <string>
using namespace std;
map<string,bool> mp;
int main(){
	mp["xiaoming"]=true;
	int n;
	cin>>n;
	string s1,s2; 
	while(n--){
		cin>>s1>>s2;
		mp[s1]=mp[s2]=mp[s1]||mp[s2];
	}
	int ans=0;
	for(auto x:mp)if(x.second)ans++;
	cout<<ans;
	return 0;
}
