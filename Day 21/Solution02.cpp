// Leetcode: Koko Eating Bananas [https://leetcode.com/problems/koko-eating-bananas/description/]

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start=0, end=0, mid, ans, n=piles.size();
        long long sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=piles[i];
            end=max(end,piles[i]);
        }
        start=sum/h;

        if(!start)
        start=1;

        while(start<=end)
        {
            mid=start+(end-start)/2;

            int time=0;

            for(int i=0; i<n; i++)
            {
                time+=piles[i]/mid;
                if(piles[i]%mid)
                time++;
            }

            if(time>h)
            {
                start=mid+1;
            }
            else
            {
                ans=mid;
                end=mid-1;
            }
        }
        return ans;    
    }
};