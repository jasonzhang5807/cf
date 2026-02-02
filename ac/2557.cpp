#include <cstdio>
int z,f;
int main(){
	int n,tmp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		if(tmp==5){
			f++;
		}
		else{
			z++;
		}
	}
	if(f>8&&z>0){
		for(int i=0;i<(f/9)*9;i++){
			printf("5");
		}
		for(int i=0;i<z;i++){
			printf("0");
		}
	}
	else if(z>0){
		printf("0");
	}
	else{
		printf("-1");
	}
	return 0;
}
