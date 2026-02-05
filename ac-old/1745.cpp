#include <bits/stdc++.h>
using namespace std;
int cntr[1010];
int cntc[1010];
int main(){
	priority_queue<pair<int,int>> row;
	priority_queue<pair<int,int>> col;
	int m,n,k,l,d;
	cin>>m>>n>>k>>l>>d;
	while(d--){
		int x,y,p,q;
		scanf("%d%d%d%d",&x,&y,&p,&q);
		if(x==p)cntc[min(y,q)]++;
		else cntr[min(x,p)]++;
	}
	for(int i=0;i<m;i++)row.push({cntr[i],i});
	for(int i=0;i<n;i++)col.push({cntc[i],i});
	priority_queue<int,vector<int>,greater<int>> tmp;
	while(k--)tmp.push(row.top().second),row.pop();
	while(!tmp.empty())printf("%d ",tmp.top()),tmp.pop();
	cout<<endl;
	while(l--)tmp.push(col.top().second),col.pop();
	while(!tmp.empty())printf("%d ",tmp.top()),tmp.pop();
	return 0;
}
