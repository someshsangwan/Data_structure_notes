/*
 problem -
 sometime we have given a direct string of integer-
 now we have given array 
 Input: nums = [3,30,34,5,9]
Output: "9534330"
push every index value in a string vector by changing int to string than sort them --- by using a comparator-
*/



#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 static bool compare(string a, string b){
        return a+b>b+a;
}
string largestNumber(vector<int>& nums) {
    vector<string>temp;
    for(int i=0;i<nums.size();i++){
        temp.push_back(to_string(nums[i]));
    }
    sort(temp.begin(),temp.end(),compare);
    string ans="";
    for(int i=0;i<temp.size();i++){
        ans=ans+temp[i];
    }
    if(ans[0]=='0'){// it means if our array contains only zero then we return only one zero "0";
        return "0";
    }
    return ans;
}
 