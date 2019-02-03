/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        vector<Interval> res;
        if(A.empty()||B.empty()) return res;
        int la=A.size(),lb=B.size();
        int a=0,b=0;
        int lmax=0,rmin=0;
        while(a<la&&b<lb){
            lmax=max(A[a].start,B[b].start);
            rmin=min(A[a].end,B[b].end);
            if(lmax<=rmin) res.emplace_back(lmax,rmin);
            if(A[a].end<=B[b].end) a++;
            else b++;
        }
        return res;
    }
};
