// subsequnce -- i think it is lover of dp and recursion they have a huge crush on this topic 
// you will find a lot of questions of subsequence in recursion and dp problems.

//lets start--
 
//subsequence --  it can be can contigous or non contigous but it follow  order;
// for example string s="IITROPAR"
// here 'IIT' is a substring and subsequence
// 'IIOR' its not a substring but its is a subsequence;
// 'RAPOR' neither a substring not a subsequence;


// write a function who print all subsequences of  given string
/* approach 1 - power set ---- here we will not discuss 
approach 2- by recursion */
// input - abc  output- '','a','b','c','ab','bc','ac','abc'; 
using namespace std;
#include<iostream>
#include<bits/stdc++.h>
void solve(string str,string output,int index,vector<string>&ans){
    if(index>=str.length()){
        ans.push_back(output);
        return;
        
    }
    solve(str,output,index+1,ans); //not includeing str value;
    output=output+str[index];
    solve(str,output,index+1,ans);// here we will include 
    //hme pop krne ki jrurat nhi h bcz hm output as a refrence nhi le rhe h to call aate time apne aap hat jaega . got it ? hey tell me .
    // recrusion tree bnao ache se smjh aayega lode ;
}

// recursion tree bna lo yrr sb smjh aa jaega - base condition wgera ache se;
