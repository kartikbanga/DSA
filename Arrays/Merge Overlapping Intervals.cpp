class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      // first sort the interval array/vector, so they are in increasing sequence of starting time
        sort(intervals.begin(),intervals.end());
      // take a result 2-D vector to store the result
        vector<vector<int>> res;

      // take another vector to push into the result vector
        vector<int> ans;
      // the first interval will always be pushed into the ans vector as it has the first starting time
        ans.push_back(intervals[0][0]);
      // store the end time of the first interval
        int end=intervals[0][1];

      // traverse the intervals array
        for(int i=1;i<intervals.size();i++)
        {
          // check if the starting time of the current element is overlapping with the end time time of the previous element or not
            if(intervals[i][0]<=end) //if yes then replace the end time with the greater value
            {
                end=max(intervals[i][1],end);
            }
              // if not then the previous interval is completed and the new interval starts
            else{
                ans.push_back(end);    // push the end time of the previous interval
                res.push_back(ans);    // push the ans into the result vector
                ans.clear();           // clear the ans vector for the new interval
                end=intervals[i][1];   // re-initialize the end variable with the end time of the current interval
                ans.push_back(intervals[i][0]);  //push the current interval starting time
            }
        }
      // after getting out of the loop we have to push the end time of the completed interval and then push it into the result vector
        ans.push_back(end);
        res.push_back(ans);
        return res;
    }
};
