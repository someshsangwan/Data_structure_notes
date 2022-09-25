#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// /Given two words A and B, and a dictionary, C, find the length of shortest transformation sequence from A to B, such that:

// You must change exactly one character in every transformation.
// Each intermediate word must exist in the dictionary.
// Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>s;
        for(int i=0;i<wordList.size();i++){
            s.insert(wordList[i]);
        }
        if(s.find(endWord)==s.end()){
            return 0;
        }
        unordered_map<string,bool>vis;
        queue<pair<string,int>>q;
        q.push({beginWord,0});
        while(!q.empty()){
            string node=q.front().first;
            int dist=q.front().second;
            q.pop();
            if(node==endWord){
                return dist+1;
            }
            for(int i=0;i<beginWord.size();i++){
                for(char j='a';j<='z';j++){
                    string check=node;
                    check[i]=j;
                    if(s.find(check)!=s.end() && !vis[check]){
                        q.push({check,dist+1});
                        vis[check]=1;
                    }
                }
            }
        }
        return 0;
    }