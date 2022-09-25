#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// given an array and a target value return indices whose  sum value is target;

//Approach_1 ->brute force o(n^2);
//Approach_2 -> sort and 2 pointer o(nlogn)
// Approach_3 -> using 

int mapping_pair_sum(int arr[], int sum, int n)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int rem = sum - arr[i];
        if (m.find(rem) != m.end())
        {
            // int count = m[rem];
            /*for (int j = 0; j < count; j++)
                cout << "(" << rem << ", "
                     << arr[i] << ")" << endl;*/
            return 1;
        }
        m[arr[i]]++;
    }
    return 0;
}