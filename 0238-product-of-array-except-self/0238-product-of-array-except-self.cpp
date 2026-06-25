class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answers(nums.size());
        answers[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            answers[i]=answers[i-1]*nums[i-1];
        }
        int temp=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            answers[i]=answers[i]*temp;
            temp*=nums[i];
        }
        return answers;
    }
};
