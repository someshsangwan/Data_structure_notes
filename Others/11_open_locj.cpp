#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/*
You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. 
The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning
 one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of deadends dead ends, meaning if the lock displays any of these codes, 
the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, return the minimum
 total number of turns required to open the lock, or -1 if it is impossible.

Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation: 
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".
 
Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation: We can turn the last wheel in reverse to move from "0000" -> "0009".


Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation: We cannot reach the target without getting stuck.

*/
  int openLock(vector<string>& deadends, string target) {
        set<string>s;
        unordered_map<string,bool>vis;
        for(int i=0;i<deadends.size();i++){
            s.insert(deadends[i]);
        }
        if(s.find("0000")!=s.end()){
            return -1;
        }
        queue<pair<string,int>>q;
        q.push({"0000",0});
        while(!q.empty()){
            string node=q.front().first;
            int dist=q.front().second;
            q.pop();
            if(node==target){
                return dist;
            }
            for(int j=0;j<4;j++){
                    string check=node;
                    if(check[j]=='9'){
                        check[j]='0';
                    }
                    else{
                    check[j]= check[j]+1;
                    }
                    
                    if(s.find(check)==s.end() && !vis[check]){
                        q.push({check,dist+1});
                        vis[check]=1;
                    }
                    check=node;
                   if(check[j]=='0'){
                       check[j]='9';
                   }
                   else{
                    check[j]= check[j]-1;
                   }
                    if(s.find(check)==s.end() && !vis[check]){
                        q.push({check,dist+1});
                        vis[check]=1;
                    }
                }
            }
            
        
        return -1;
        
    }