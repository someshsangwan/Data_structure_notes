/* selection sort - if our array size is n than there will be n-1 round ;
in every round we find minimum value in set that value that index;
for example -
int arr[]={64,25,12,22,11};
n=5 , there will be 4 round ;
Round 1- minimum value is 11 than we swap 64 ,11 -   now array- {11,25,12,22,64}; now i=0; is fix now our i is on 1st index;
round 2- second minimum value is 12 swap 25 ,12 - now array-{11,12,25,22,64};
round 3- 3rd---------------------22  swap 25,22- now array -{11,12,22,25,64};
round 4- 4th --------------------25 swap 25,25  now array -{11,12,22,25,64};

huhuehuehueh array is sorted now ---
*/
// bhai 2 loop use krne padenge to time complexity o(n^2) hogi and space complexity o(1);
// best case(already sorted array) me bhi o(n^2) hogi or worst case  me bhi;
//phla loop n-1 times chlega bcz last wala to apne app bhi set ho jaega jb hm n-1 set kr chuke honge-

// application - jb size of array is small that time selection sort is good;
//code-
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
void sort_selection(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){// pichle wale sorted ho chuke h 
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
}
int main(){
    int arr[]={64,25,12,22,11};
    sort_selection(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<"  ";
    }cout<<endl;
}