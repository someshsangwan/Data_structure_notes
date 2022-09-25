#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/* problem is simple you have an array of n size that is fille dwith 1 to n number, every number appears exactly one time except one(appear two times) find that 
repeat number and missing number*/
// Input:[3 1 2 5 3] 

// Output:[3, 4] 

// A = 3, B = 4
//approach 1- using map;
int main(){
    int n=5;
    int arr[]={3,1,2,5,3};
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;

    }
    int a; //repeated number
    int b; //missing number
    int i=1;
    for(auto it:mp){
        if(it.second==2){
            a=it.first;
        }
        if(it.first!=i){ //map sorted array me store hota h iska fayda uthaya ja rha h ;
            b=i;
        }
        i++;
        //cout<<it.first<<endl;
    }
    cout<<a<<" "<<b<<endl;
}



// but interviewer aapse o(1) space me krwagea 

// optimised Approach 
vector<int>function (const vector<int> &arr) {
 int xor1;
    int set_bit_no;

    int i;
    int x = 0; // missing
    int y = 0; // repeated
    int n = arr.size();

    xor1 = arr[0];
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];
        
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;
        
    set_bit_no = xor1 & ~(xor1 - 1);
    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            x = x ^ arr[i];

        else
            y = y ^ arr[i];
    }

    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            x = x ^ i;

        else
            y = y ^ i;
    }
    vector<int>ans;
    
    int x_count = 0;
    for (int i=0; i<n; i++) {
        if (arr[i]==x)
            x_count++;
    }
    
    if (x_count==0){
           ans.push_back(y);
          ans.push_back(x);
        return ans;
}
    ans.push_back(x);
    ans.push_back(y);
    return ans;
   
}

