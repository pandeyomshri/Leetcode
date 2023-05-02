class Solution {
public:
    int arraySign(vector<int>& nums) {
        int prd=1,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0)
                prd*=(-1);
            if(nums[i]>0)
                prd*=1;
            if(nums[i]==0)
                return 0;
        }
        return prd;
    }
};