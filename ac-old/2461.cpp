#include <cstdio>
#include <unordered_set>
std::unordered_set<int> vis;
int s[20],n;
void dfs(int dep){
        if(dep>n){
                for(int i=1;i<=n;i++) printf("%d ",s[i]);
                putchar('\n');
                return;
        }
        for(int i=1;i<=n;i++){
                s[dep]=i;
                if(dep!=i&&vis.find(i)==vis.end()) vis.insert(i),dfs(dep+1),vis.erase(i);
        }
}
int main(){
        scanf("%d",&n);
        dfs(1);
        return 0;
}
