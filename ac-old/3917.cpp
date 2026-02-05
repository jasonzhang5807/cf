#include <cstdio>
#include <vector>
int main(){
	freopen("c.in","r",stdin);
        freopen("c.out","w",stdout);
        char ipt;
        std::vector<char> s;
        while(1){
                ipt=getchar();
                if(ipt<'a'||ipt>'z') break;
                s.push_back(ipt);
        }
        while(!s.empty()){
                bool flag=false;
                if(s.size()>=4){
                        if(s[s.size()-1]=='k'&&s[s.size()-2]=='r'&&s[s.size()-3]=='o'&&s[s.size()-4]=='w'){
                                int i=4;
                                while(i--) s.pop_back();
                                flag=true;
                        }
                }
                if(s.size()>=5){
                        if(s[s.size()-1]=='e'&&s[s.size()-2]=='s'&&s[s.size()-3]=='a'&&s[s.size()-4]=='r'&&s[s.size()-5]=='e'){
                                int i=5;
                                while(i--) s.pop_back();
                                flag=true;
                        }
                }
                if(s.size()>=6){
                        if(s[s.size()-6]=='w'&&s[s.size()-5]=='o'&&s[s.size()-4]=='r'&&s[s.size()-3]=='k'&&s[s.size()-2]=='e'&&s[s.size()-1]=='r'){
                                int i=6;
                                while(i--) s.pop_back();
                                flag=true;
                        }
                        if(s[s.size()-6]=='e'&&s[s.size()-5]=='r'&&s[s.size()-4]=='a'&&s[s.size()-3]=='s'&&s[s.size()-2]=='e'&&s[s.size()-1]=='r'){
                                int i=6;
                                while(i--) s.pop_back();
                                flag=true;
                        }
                }
                if(!flag){
                        printf("NO");
                        return 0;
                }
        }
        printf("YES");
        return 0;
}
