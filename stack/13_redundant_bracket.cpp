#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// redundant brackey means extra bracket== like =   ((a+b)) bahar wala faltu bracket h;
int braces(string A) {
    int n=A.size();
    stack<char>st;
    for(int i=0;i<n;i++){
        char ch=A[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            st.push(ch);
        }
        else{
            if(ch==')'){
                bool isredundant=true;
                while(st.top()!='('){
                    char topo=st.top();
                    if(topo=='+'|| topo=='-' || topo=='*' || topo=='/'){
                        isredundant=false;
                    }
                    st.pop();
                }
                if(isredundant==true){
                    return true;
                }
                 st.pop();
            
            }
           // st.pop();
        }
    }
    return false;
}
