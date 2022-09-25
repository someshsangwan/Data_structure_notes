/*
here also we play with rounds
in every ith round we place ith largest element its right position;
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bubble(int arr[],int n){
    for(int i=1;i<n;i++){ //n-1 rounds  if we start 0 to n-1 than in second loop j<n-i-1; hoga
        for(int j=0;j<n-i;j++){//last wale ko place krte ja rhe h // bda element las me chla gya
            if(arr[j+1]<arr[j]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main(){ 
    int arr[]={64,25,12,22,11};
    bubble(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<"  ";
    }cout<<endl;
}

/*time complexity
 time - o(n^2);
 space-o(1);
 best case- already sorted -o(n) phle looop ke bahar ek boop swaped =false;
 or andar wale loop me koi swap nhi hua to mtlb array already sorted h to break and return --- 
 worst case- reverse sorted array - o(n^2);



*/