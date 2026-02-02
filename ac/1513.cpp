#include <cstdio>
int len,del,poi;
struct Node{
	int dat,nxt;
} s[200010];
int main(){
	scanf("%d",&len);
	s[0].nxt=1;
	for(int i=1;i<=len;i++){
		scanf("%d",&s[i].dat);
		s[i].nxt=i+1;
	}
	scanf("%d",&del);
	s[len+1].nxt=-1;
	for(int i=1;i<=len;i++){
		if(s[i].dat==del) s[poi].nxt++;
		else poi=i;
	}
	
	poi=0;
	while(1){
		poi=s[poi].nxt;
		if(s[poi].nxt==-1) break;
		printf("%d ",s[poi].dat);
	}
	return 0;
}
