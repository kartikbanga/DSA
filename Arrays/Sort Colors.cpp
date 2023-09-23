class Solution {
public:
    void sortColors(vector<int>& nums) {
      // o=> pointer for ones, 
      // z=> pointer for zeroes
      // t=> pointer for two's
        int o=0,z=0,t=nums.size()-1;

      // we traverse with three pointers, we need to put 2, at the end
      //  so the pointer of two is at end.
      
        while(o<=t)
        {
          // if the number found at the starting is 2
            if(nums[o]==2)
            {
              // swap it with the last element and decrease two's pointer by 1
                swap(nums[o],nums[t]);
                t--;
            }
              // if number found at the current position(let's say any position) is zero,
              // then just swap it with zero's pointer which will always  point to the next position after the starting 0's
            else if(nums[o]==0)
            {
                swap(nums[o],nums[z]);
                z++;
                o++;
            }
              // if number found is 1, then go on.
            else
                o++;
        }
    }
};
