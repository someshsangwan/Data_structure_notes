#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//problem statement :- find the majority elements from array whose frequency more than n/3;
// tric-> if we   n/3 freq 3 element then n/3+n/3+n/3 =n but we have to take more than n/3 
// so there are max 2 majority element can be in array;
vector<int> majorityElement(vector<int>& nums) {
        int m1 = nums[0];
        int c1 = 1;
        int m2 = nums[0];
        int c2 = 0;
        for(int i =1;i < nums.size() ;i++)
        {
            if(m1 == nums[i])
            {
                c1++;
            }
            else if(m2 == nums[i])
            {
                c2++;
            }
            else
            {
                if(c1 == 0)
                {
                    m1 = nums[i];
                    c1 = 1;
                }
                else if(c2==0)
                {
                    
                    m2 = nums[i];
                    c2 = 1;
                }else{
                     c1--;c2--;
                }
                   
            }
        }
        c1 = 0; c2 = 0;
        for(int i = 0; i < nums.size(); i++)
        {
                if(m1 == nums[i])
                {
                    c1++;
                }
                else if(m2 == nums[i])
                {
                    c2++;
                }
        }
        int n = nums.size()/3;
        vector<int> x;
        if(c1 > n)
        {
            x.push_back(m1);
        }
        
        if(c2 > n && m1!=m2)
        {
            x.push_back(m2);
        }
        
        
        return x;
        
    }