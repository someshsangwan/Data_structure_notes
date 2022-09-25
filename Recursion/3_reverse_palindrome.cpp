#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// problem 1 - reverse an array using recursion 
 // first we will write a simple code to reverse array
void reverse_arr(int arr[],int n){
    int i=0;
    int j=n-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}
void rec_reverse(int arr[], int i, int j){    // hello kids  i just change while conditon into base conditomn     
    if(i>j){                                 // recursion is very easy if you know iterative soluion  of that probelm;   
        return;
    }
    swap(arr[i],arr[j]);
    rec_reverse(arr,i+1,j-1);
}

// now we will check its palindrom array or not ;
// first is iterative solution its easy 
bool check(int arr[],int n){
    int i=0;
    int j=n-1;
    while(i<j){
        if(arr[i]!=arr[j]){
            return false;
        }
    }
    return true ;
}
// now we will write recursive function to check whether it is palindrome or not ;
bool check_re(int arr[],int i,int j){
    if(i>j){
        return true;
    }
    if(arr[i]!=arr[j]){
        return false;
    }
     return check_re(arr,i+1,j-1);
     
}


int main(){
    int arr[]={1,2,3,3,2,1}; 
    //reverse_arr(arr,6);
    rec_reverse(arr,0,6-1);
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<check_re(arr,0,5)<<endl;

}

