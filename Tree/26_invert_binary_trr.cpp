/*
Given a binary tree A, invert the binary tree and return it. 
Inverting refers to making left child as the right child and vice versa.

ezz h pr sala google puch lia kisi se kash hm se bhi gugl esa kuch puch le ;
aaj 14/7/2022 h or college me placement drive nov. starting me suru hoga but infosys aa gyi abhi pta nhi kyo apply kr dia m 
aaj 9.5 de rhi h ctc , ho gya to backup me rakh lunga isko or, phir acc to cdpc policy i can sit in company with 15+ ctc in 
placement drive . sahi to h ......haha vaise adobe ka off campus bhi apply kia hu;;;

*/
/*  input 1
      1           
    /   \
   2     3
output 1
     1
   /   \
  3     2
input 2
     1
   /   \
  2     3
 / \   / \
4   5 6   7 
output   root ke jo right me h usko phle left me laye phir usme bhi ese hi kia sb me esa krte gye through recursion
     1
   /   \
  3     2
 / \   / \
7   6 5   4


*/
//code
/*
 
TreeNode*  invertTree(TreeNode* A) {
    if(A!=NULL){
        TreeNode *temp=A->left;
        A->left=invertTree(A->right);
        A->right=invertTree(temp);
    }
    return A;   
}
*/

