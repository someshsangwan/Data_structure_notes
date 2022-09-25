#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
problem -  ({[]}) this is a valid parathesis 
if there is an open bracket so to be a valid parathesis there should be also a closing bracket;
*/
bool check(string s){
    int n=s.size();
    stack<char>st;
    for(int i=0;i<n;i++){
        char ch=s[i];
        if(ch =='(' || ch=='{' || ch=='['){
            st.push(ch);
        }
        else{
            if(!st.empty()){
                char top=st.top();
                if((ch==')' && top=='(') || (ch==']' && top=='[') || (ch=='}' && top=='{') ){
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    string s ="{([])}";
    cout<<check(s)<<endl;

}