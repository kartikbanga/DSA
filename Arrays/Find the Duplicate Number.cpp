// BRUTE FORCE

int findDuplicate(vector<int>& nums) {
    // Declare a map to store the frequencies of each number
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
          // if this is the first occurance
            if(m[nums[i]]==0)
                m[nums[i]]++;
              // if it occurs more than once
            else
                return nums[i];
        }
        return 1;
    }
// T.C.: O(n)
// S.C.: O(n)

//  OPTIMAL APPROACH
  int findDuplicate(vector<int>& nums) {
      int xs=0;
    // take xor sum of all the elements
      for(int i=0;i<nums.size();i++){
        xs^=nums[i];
      }
    return xs;
  }
// T.C.: O(n)
// S.C.: O(1)
