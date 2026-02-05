#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<string> s;
	string tmp;
	while(cin>>tmp)s.push_back(tmp);
	sort(s.begin(),s.end());
	s.resize(distance(s.begin(),unique(s.begin(),s.end())));
	for(string x:s)cout<<x<<endl;
	return 0;
}
