class Solution {
public:
    int minKBitFlips(vector<int>& a, int k) {
        int n=a.size(),flip=0,ans=0;
        bool hint[30010];
        memset(hint,0,sizeof(hint));
        // When we flip a subarray like A[i], A[i+1], ..., A[i+K-1]
        // we can instead flip our current writing state, and put a hint at
        // position i+K to flip back our writing state.
        for (int i=0;i<n;i++){
            flip ^= hint[i];//��ȡ��ǰλ�õ�״̬
            if (a[i] == flip) {  // If we must flip the subarray starting here...
                ans++;// We're flipping the subarray from A[i] to A[i+K-1]
                if (i+k>n) return -1;//If we can't flip the entire subarray, its impossible
                flip ^= 1;//��ת�ˣ���Ҫ����״̬
                hint[i+k]^=1;//��λ״̬
            }
        }
        return ans;
    }
};
