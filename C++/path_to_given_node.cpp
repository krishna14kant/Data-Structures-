void fun(TreeNode* A,int B,vector<int> v,vector<int> &ans){
     if(A==NULL)
     return ;
     v.push_back(A->val);
     if(B==A->val)
     {
        for(int i=0;i<v.size();i++)
        ans.push_back(v[i]);
        return;
    }
    fun(A->left,B,v,ans);
    fun(A->right,B,v,ans);
 }
vector<int> Solution::solve(TreeNode* A, int B) {
   vector<int>v;
   vector<int>ans;
   fun(A,B,v,ans);
   return ans;
}
