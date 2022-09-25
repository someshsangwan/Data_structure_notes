// vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
//     vector<vector<int>>ans;
//     if(A==NULL){
         
//         return ans;
//     }
//     if(A->left==NULL && A->right==NULL){
//         vector<int>temp;
//         temp.push_back(A->val);
//         ans.push_back(temp);
//         return ans;
//     }
//     map<int, vector<int>> mp;
//     queue<pair<TreeNode*,int>>q;
//     q.push({A,0});
//     while(!q.empty()){
//         pair<TreeNode*,int>time=q.front();
//         q.pop();
//         TreeNode* temp=time.first;
//         int hd=time.second;
//         mp[hd].push_back(temp->val);
//         if(temp->left){
//             q.push({temp->left,hd-1});
//         }
//         if(temp->right){
//             q.push({temp->right,hd+1});
//         }
//     }
//     for(auto it: mp){
//         vector<int> a = it.second;
//         ans.push_back(a);
//     }
    
    
//     return ans;
// }
