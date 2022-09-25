#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/*
A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string start to a gene string end where one mutation is 
defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings start and end and the gene bank bank, 
return the minimum number of mutations needed to mutate from start to end. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

*/
// Input: start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
// Output: 2

int minMutation(string start, string end, vector<string>& bank) {
        set<string>s;
        for(int i=0;i<bank.size();i++){
            s.insert(bank[i]);
        }
        unordered_map<string,bool>vis;
        queue<pair<string,int>>q;
        if(s.find(end)==s.end()){
            return -1;
        }
        string  fill="ACGT";
        q.push({start,0});
        while(!q.empty()){
            string node=q.front().first;
            int dist=q.front().second;
            q.pop();
            if(node==end){
                return dist;
            }
            for(int i=0;i<8;i++){
                for(int j=0;j<4;j++){
                    string check=node;
                    check[i]=fill[j];
                    if(s.find(check)!=s.end() && !vis[check]){
                        q.push({check,dist+1});
                        vis[check]=1;
                    }
                }
            }
        }
        return -1;   
    }