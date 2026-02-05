#include <cstdio>
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[8];
	scanf("%s",s);
	int cnt=0;
	for(int i=0;i<8;i++){
		if(s[i]=='1'){
			cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}
