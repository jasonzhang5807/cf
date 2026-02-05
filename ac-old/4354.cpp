#include <cstdio>
int main(){
        int n;
        char s[110];
        scanf("%d%s",&n,s);
        for(int zclen=1;zclen<=n;zclen++){
                char zc[110][110];
                bool rep=false;
                for(int i=0;i<=n-zclen;i++) for(int j=i;j<i+zclen;j++) zc[i][j-i]=s[j];
                //for(int i=0;i<=n-zclen;i++) printf("%s\n",zc[i]);
                for(int i=0;i<n-zclen;i++){
                        for(int j=i+1;j<=n-zclen;j++){
                                //check zc[i]!=zc[j];
                                bool diff=false;
                                for(int k=0;k<zclen;k++){
                                        if(zc[i][k]!=zc[j][k]){
                                                //printf("%s and %s are diff\n",zc[i],zc[j]);
                                                diff=true;
                                                break;
                                        }
                                }
                                if(diff==false){
                                        rep=true;
                                        //printf("%s and %s are same\n",zc[i],zc[j]);
                                        break;
                                }
                        }
                        if(rep==true) break;
                }
                if(rep==false){
                        printf("%d",zclen);
                        return 0;
                }
        }
        return 0;
}
