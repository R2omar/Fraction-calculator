#include<iostream>
#include<string>
#include<regex>
using namespace std;
int main(){
string a;
float x;
getline(cin,a);
regex b("[+-]?\\d+/\\d+ [+\\-*/] [+-]?\\d+/\\d+");
if(regex_match(a,b)){
    cout << "Yes";
    }
else{
cout << "no";
}
return 0;
}
