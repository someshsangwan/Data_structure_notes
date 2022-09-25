//problem statement -- every element appears twice except one element , find that element ---
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int search(int A[], int N){
	int x=0;
	for(int i=0;i<N;i++){
	    x=x^A[i];
	}
    return x;
}