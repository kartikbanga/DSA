class Solution {
public:
    void rever(vector<int>& nums, int s)
    {
        int j=nums.size()-1;
        while(s<j)
        {
            swap(nums.at(s),nums.at(j));
            s++;
            j--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int firstindex=-1,secondint=INT_MAX,secondindex=0;
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums.at(i)>nums.at(i-1))
            {
                firstindex=i-1;
                break;
            }
        }
        if(firstindex==-1)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        for(int i=firstindex+1;i<nums.size();i++)
        {
            if(nums.at(i)>nums.at(firstindex))
            {
                secondint=min(secondint,nums.at(i));
                if(secondint!=INT_MAX)
                    secondindex=i;
            }
        }
        int temp=nums.at(firstindex);
        nums.at(firstindex)=nums.at(secondindex);
        nums.at(secondindex)=temp;
        rever(nums,firstindex+1);
    }
};
