#include <iostream>
using namespace std;
int ans;
int main(){
	int n,d;
	int a[2000];
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int add;
	for(int i=1;i<n;i++){
		if(a[i]<=a[i-1]){
			add=(a[i-1]-a[i])/d+1;
			ans+=add;
			a[i]+=d*add;
		}
	}
	cout<<ans;
	return 0;
}
