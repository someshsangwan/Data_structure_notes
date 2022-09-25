using namespace std;
#include<bits/stdc++.h>
#include<iostream>
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
// approach 1 is very simple put all the value of every node in array and check the palindrom that array 
// this is o(n) time and o(n) space complexity solution
//approach 2 o(n) time and o(1) space compexity solution  we find middle node of LL and after the middle node we reverse LL and check it
bool ispalindrome(Node* A){
if(A==NULL || A->next==NULL){
        return 1;
    }
    Node* middle=getmiddle(A);
    Node* temp=middle->next;
    middle->next=reverse_LL(temp);
    Node* head1=A;
    Node* head2=middle->next;
    //ListNode* prac=middle->next;
    while(head1 && head2){
        if(head1->val != head2->val){
            return 0;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return 1;
}


int main(){
    Node* head=new Node(3);
    Node* second=new Node(5);
    Node* third=new Node(7);
    head->next=second;
    second->next=third;

}