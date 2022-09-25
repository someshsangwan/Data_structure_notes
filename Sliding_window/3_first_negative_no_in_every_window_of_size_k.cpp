#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// N = 5
// A[] = {-8, 2, 3, -6, 10}
// K = 2
// Output : 
// -8 0 -6 -6
//brute force two loop one 0 to n-k and 2nd j==i to j<k;
//optimised - sliding window;
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        vector<long long>ans;
        long long i=0;
        long long  j=0;
        queue<long long>q;
        while(j<N){
            if(A[j]<0){
                q.push(A[j]);
            }
            if(j-i+1<K){
                j++;
            }
            else{
                if(q.size()==0){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(q.front());
                    if(A[i]==q.front()){
                        q.pop();
                    }
                }
                i++;
                j++;
            }
            
        }
        return ans;