class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>n;
        for(int i=0;i<nums.size();i++)
            n.emplace(nums[i]);
        if(nums.size()==0)
            return 0;
        int oldCount=1,newCount=1;
        auto it=n.begin();
        auto prev=it;
        it++;
        while(it!=n.end())
        {
            if(*it-1==*prev)
            {
                newCount++;
            }
            else
            {
                if(newCount>oldCount)
                    oldCount=newCount;
                newCount=1;
            }
            it++;
            prev++;
        }
        return (oldCount>=newCount)?oldCount:newCount;
    }
};