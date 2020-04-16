/* https://leetcode.com/problems/first-bad-version/
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. */
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution 
{
public:
    int firstBadVersion(int n) 
    {
        long long int lo = 1,hi = n;  //n versions hence lo = 1 and hi = n;
        long long int mid = lo + (hi - lo)/2;
         while(lo<=hi)
        {
            if(isBadVersion(mid)) hi = mid-1; //if mid is bad, there is a possibility that items bfore mid is also bad, hence we reduce the search space to thr first half, ie from 1 to mid-1;
            else  lo=mid+1; //if mid is good, this means 2nd half has a bad element.
            
            mid = (hi+lo)/2;
        }
        return lo; //since we are returning the first bad element.
    }
};
