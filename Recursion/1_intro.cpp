// we will learn basic recursion and backtracking in this lesson 
// lest start bois


// print first n number using recursion ;
// its very easy to print first n number using for loop;
#include<iostream>
using namespace std;
void func(int i,int n){
    if(i>n){
        return;
    }
    cout<<i<<" ";
    func(i+1,n);


}
 

// q2- same question print n reverse number like this 5 4 3 2 1
// its also very easy we will pass func(n,n) ans reduce first n every time base condition is if(i<1){return ;}
// but we can solve this by passing (1,n) by using back tracking 
// in backtraking we write our content just down the function call   /* sorry for my poor english*/
void func1(int i,int n){
    if(i>n){
        return;
    }
    func1(i+1,n);
    cout<<i<<" ";
     


}
int main(){
    int n;
    cout<<"enter the number "<<endl;
    cin>>n;
    func(1,n);
    cout<<endl;
    func1(1,n);

}
