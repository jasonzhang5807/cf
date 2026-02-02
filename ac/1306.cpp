#include <string>
#include <iostream>
using namespace std;
int main(){
        string s1,s2,s3;
        getline(cin,s1);
        cin>>s2>>s3;
        string s22=" "+s2+" ";
        s1=" "+s1+" ";
        while(s1.find(s22)!=string::npos)
                s1.replace(s1.find(s22)+1,s2.length(),s3);
        cout<<s1.substr(1,s1.size()-2);
        return 0;
}
