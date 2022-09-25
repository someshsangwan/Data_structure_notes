#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// if given two string and find any string in another string if found then return 1st index of that string.
int strStr(string haystack, string needle) {
    int pos = haystack.find(needle);
    return pos;
}
