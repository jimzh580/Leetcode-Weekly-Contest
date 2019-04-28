const int LIMIT = 20000;

class Solution {
public:
    using pii = pair<int, int>;
    using ll = long long;
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& S, vector<int>& T) {
        unordered_set<ll> a;
        for (auto p : blocked)
            a.insert(p[0]*1000000LL+p[1]);
        
        auto check = [&](vector<int> S, vector<int> T){
            unordered_set<ll> u;
            u.insert(S[0]*1000000LL+S[1]);
            int tot = 0;
            queue<pii> Q;
            Q.push(pii(S[0], S[1]));
            while (!Q.empty()){
                int x = Q.front().first;
                int y = Q.front().second;
                Q.pop();
                ++ tot;
                if (tot >= LIMIT) return true;
                if (x == T[0] && y == T[1]) return true;
                int dx[] = {-1, 1, 0, 0};
                int dy[] = {0, 0, -1, 1};
                for (int k = 0; k < 4; ++ k){
                    int tx = x+dx[k], ty = y+dy[k];
                    if (0 <= tx && tx < 1000000 && 0 <= ty && ty < 1000000 && 
                        !a.count(tx*1000000LL+ty) && !u.count(tx*1000000LL+ty)){
                        u.insert(tx*1000000LL+ty);
                        Q.push(pii(tx, ty));
                    }
                }
            }
            return false;
        };
        
        return check(S, T) && check(T, S);
    }
};