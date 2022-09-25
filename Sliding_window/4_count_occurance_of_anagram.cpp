#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//problem
// Input:
// txt = forxxorfxdofr
// pat = for
// Output: 3
// Explanation: for, orf and ofr appears
// in the txt, hence answer is 3.
// isme window size to pta chl gya hoga kitna rakhna h =>pat.size();
	int search(string pat, string txt) {
	    int m=txt.size();
	    int n=pat.size();
	    if(n>m){
	        return 0;
	    }
	    int res=0;
	    int j=0;
	    int i=0;
	    map<char,int>mp;
	    //map<char,int>mp2;
	    for(auto i:pat){
	        mp[i]++;
	    }
	    int ct=mp.size();
	    while(j<m){
	        if(mp.find(txt[j])!=mp.end()){
	            mp[txt[j]]--;
	            if(mp[txt[j]]==0){
	                ct--;
	            }
	        }
	        //mp1[txt[j]]++;
	        if(j-i+1<n){
	            j++;
	        }
	        else{
	            
	            if(ct==0){
	                res++;
	            }
                
                if(mp.find(txt[i])!=mp.end()){
                mp[txt[i]]++;
                if(mp[txt[i]]==1){
                    ct=ct+1;
                }
                }
	            i++;
	            j++;
	            
	        }
	        
	    }
	    return res;
	}