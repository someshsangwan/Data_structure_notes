#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// time complexity- 
// best case-o(nlogn);
// avg case- o(nlogn);
// worst case- o(n^2);
// space complexity - o(n);
/*Quicksort is a divide-and-conquer algorithm. It works by selecting a 'pivot' element from the array  and
and partitioning the  other elements into two sub-arrays, according to whether they are less than or greater than the pivot.
*/
// it is a better algorithms among all of them 
// it is also better than merge sort 
// time comolexuty is o(nlogn);
int partition_p(int arr[],int s,int e){
    int pivot=arr[s];
    int ct=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            ct++;
        }
    }
    int pivotindex=s+ct;
    swap(arr[pivotindex],arr[s]);
    int i=s;
    int j=e;
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<arr[pivotindex]){
            i++;
        }
        while(arr[j]>arr[pivotindex]){
            j--;
        }
        if(i<pivotindex && j>pivotindex){
        swap(arr[i],arr[j]);
        i++;
        j--;
        }
    }
    return pivotindex;


}
void quick_sort(int arr[],int s ,int e){
    if(s>=e){
        return;
    }
    int p=partition_p(arr,s,e);
    quick_sort(arr,s,p-1); // left part sort
    quick_sort(arr,p+1,e); // right part wala sort


}
int main(){
    int arr[]={25,11,22,65,7};
    int n=5;
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}