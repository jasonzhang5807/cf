#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main(){
        freopen("edit.in","r",stdin);
        freopen("edit.out","w",stdout);
        string s;int n;
        getline(cin,s);
        cin>>n;
        while(n--){
                getchar();
                char opt,arg1,arg2;string arg3;
                opt=getchar();
                switch(opt){
                        case 'D':
                                getchar();
                                arg1=getchar();
                                if(s.find(arg1)!=string::npos)s.erase(s.find(arg1),1);
                                cout<<s<<endl;
                                break;
                        case 'I':
                                getchar();
                                arg1=getchar();
                                getchar();
                                arg2=getchar();
                                arg3=arg2;
                                if(s.find(arg1)==string::npos);
                                else if(!s.rfind(arg1))s=arg3+s;
                                else s=s.substr(0,s.rfind(arg1))+arg3+s.substr(s.rfind(arg1),s.size()-s.rfind(arg1));
                                cout<<s<<endl;
                                break;
                        case 'R':
                                getchar();
                                arg1=getchar();
                                getchar();
                                arg2=getchar();
                                if(s.find(arg1)==string::npos){
                                        cout<<"Not found"<<endl;
                                        break;
                                }
                                for(int i=0;i<s.size();i++)if(s[i]==arg1)s[i]=arg2;
                                cout<<s<<endl;
                                break;
                        default:
                                cout<<"ERROR!\n";
                                break;
                }
        }
        return 0;
}
