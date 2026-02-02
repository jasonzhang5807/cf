#include <iostream>
#include <string>
using namespace std;
int main(){
        string s;
        cin>>s;
        bool flag=true;
        while(flag){
                flag=false;
                if(s.size()>2&&s[s.size()-2]=='l'&&s[s.size()-1]=='y')s.erase(s.size()-2,2),flag=true;
                if(s.size()>2&&s[s.size()-2]=='e'&&s[s.size()-1]=='r')s.erase(s.size()-2,2),flag=true;
                if(s.size()>3&&s[s.size()-3]=='i'&&s[s.size()-2]=='n'&&s[s.size()-1]=='g')s.erase(s.size()-3,3),flag=true;
        }
        cout<<s;
        return 0;
}
