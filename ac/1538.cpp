#include <cstdio>
#include <string>
#include <deque>
#include <iostream>
using namespace std;
int main(){
    deque<int> q;
    int n;
    scanf("%d", &n);
    while(n--){
        string opt;
        cin>>opt;
        if(opt == "PUSH"){
            int x;
            scanf("%d", &x);
            q.push_back(x);
        } else if(opt == "POP"){
            if(!q.empty()){
                printf("%d\n", q.front());
                q.pop_front();
            } else {
                printf("error\n");
            }
        } else if(opt == "POP-BACK"){
            if(!q.empty()){
                printf("%d\n", q.back());
                q.pop_back();
            } else {
                printf("error\n");
            }
        }
    }
    if(q.empty()){
        printf("empty\n");
    } else {
        for(auto x: q){
            printf("%d ", x);
        }
    }
    return 0;
}
