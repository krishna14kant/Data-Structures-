class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        int i=0,n=nums.size();
        for(i=0;i<n;i++){
            if(mp.find(nums[i])==mp.end()){
               mp[nums[i]]=1;
            }else{
                 mp[nums[i]]++;
            }
            
        }
        unordered_map<int,int>::iterator itr;
        for(itr=mp.begin();itr!=mp.end();itr++){
            if(itr->second!=3) return itr->first;
        }
        return -1;
    }
};
