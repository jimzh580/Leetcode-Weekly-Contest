class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> v[N];
        for (auto e : paths){
            v[e[0]-1].push_back(e[1]-1);
            v[e[1]-1].push_back(e[0]-1);
        }
        vector<int> u(N);
        for (int i = 0; i < N; ++ i){
            if (u[i]) continue;
            queue<int> Q;
            Q.push(i);
            u[i] = 1;
            while (!Q.empty()){
                int x = Q.front();
                Q.pop();
                for (auto y : v[x]){
                    if (u[y]) continue;
                    for (int c = 1; c <= 4; ++ c){
                        int flag = 0;
                        for (auto z : v[y])
                            if (u[z] == c) flag = 1;
                        if (!flag){
                            u[y] = c;
                            break;
                        }
                    }
                    Q.push(y);
                }
            }
        }
        return u;
    }
};