const int bound = 40000;
bitset<80000> F;

class Solution {
public:
    int lastStoneWeightII(vector<int>& a) {
        int n = a.size();
        F.reset();
        F[bound] = 1;
        for (int i = 0; i < n; ++ i)
        {
            F = (F<<a[i])|(F>>a[i]);
        }
        for (int i = 0; i <= 30000; ++ i)
            if (F[bound+i]) return i;
        return -1;
    }
};