using namespace std;
#include <bits/stdc++.h>
#include <iostream>
/* given an array and a sum if there is any possible two index whose sum is equal to this target sum then return 1*/
/* brute force approach is very simple use two loop and try to find the pair*/
/* brute force approach contains o(n^2) time complexity so to reduce complexity we use here two method- first one is two pointer approach and
second one is mapping both have o(n) time complexity but mapping have o(n) space complexity ;
*/
int solve(vector<int> &A, int B)   //sorted array is given
{
    int size = A.size();
    sort(A.begin(), A.end());
    int i = 0, j = 1;
    while (i < size && j < size)
    {
        int diff = A[j] - A[i];
        if (diff == B && i != j)
        {
            return 1;
        }
        else if (diff < B)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return 0;
}
int solve_map(int arr[], int n, int diff)
{
    unordered_map<int, int> m;
    //int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
        if (m[arr[i]] > 1 && diff == 0)
        {
            return 1;
        }
    }
    if (diff == 0)
    {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        int rem = diff + arr[i];
        if (m.find(rem) != m.end())
        {
            return 1;
        }
        m[arr[i]]++;
    }
    return 0;
}
