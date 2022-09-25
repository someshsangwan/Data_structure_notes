#include<iostream>
using namespace std;
/* probelm is very easy we have given two string check whether  a sting is a subsequence of another string
example - str 1="sms" str2="somesh" here sms is present in str2 in order so str1 is subsequence of str2;
*/
#include<bits/stdc++.h>
bool check(string s1,string s2){
    int n1=s1.size();
    int n2=s2.size();
    int i=0;
    int j=0;
    while(i<n1 && j<n2){
        if(s1[i]==s2[j]){
            i++;
        }
        j++;
    }
    if(n1==i){  //it means we have traversal all character in str 1;
        return true;
    }
    else{
        return false;
    }

}
int main(){
    string s1;
    cout<<"enter the string 1"<<endl;
    cin>>s1;
    string s2;
    cout<<"enter the string 2"<<endl;
    cin>>s2;
    cout<<check(s1,s2)<<endl;
}