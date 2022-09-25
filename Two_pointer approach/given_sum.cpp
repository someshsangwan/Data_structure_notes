using namespace std;
#include <bits/stdc++.h>
#include <iostream>
/* given an array and a sum if there is any possible two index whose sum is equal to this target sum then return 1*/
/* brute force approach is very simple use two loop and try to find the pair*/
/* brute force approach contains o(n^2) time complexity so to reduce complexity we use here two method- first one is two pointer approach and
second one is mapping both have o(n) time complexity but mapping have o(n) space complexity ;
*/
int pair_sum_two_pointer(int arr[], int n, int sum)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == sum)
        {
            return 1;
        }
        else if (arr[i] + arr[j] < sum)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}

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