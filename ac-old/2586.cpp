#include <iostream>
using namespace std;
int ans;
int main(){
	int n,x;
	int mkt[100];
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>mkt[i];
	}
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				if(3*mkt[i]+3*mkt[j]+3*mkt[k]>=2*x&&mkt[i]+mkt[j]+mkt[k]<=x){
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
