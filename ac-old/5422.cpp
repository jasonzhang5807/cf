#include <bits/stdc++.h>
using namespace std;
bool cmp(const string &a,const string &b){
	return a+b>b+a;
}
int main(){
	int n;
	string a[110];
	scanf("%d",&n);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)cout<<a[i];
	return 0;
}
