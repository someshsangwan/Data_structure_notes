#include<iostream>
using namespace std;
#include<bits/stdc++.h>

//now given a range xor between 3 to 7 then how to find in o(1);
//  now to find xor 3 to 7 first we find xor 1 to 3-1 then find xor of 1 to 7 then xor of all
//     1^2^(1^2^3^4^5^6^7) same will become 0 and remaing will be ans of our question.
