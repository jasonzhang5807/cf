#include <cstdio>
#include <map>
using namespace std;
map<char,int> mp;
int main(){
	char ipt;
	while(1){
		ipt=getchar();
		if(ipt=='\0'||ipt=='\n')break;
		++mp[ipt];
	}
	for(auto x:mp)printf("%c %d\n",x.first,x.second);
	return 0;
}
