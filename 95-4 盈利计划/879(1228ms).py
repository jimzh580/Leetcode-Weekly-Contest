class Solution(object):
    def profitableSchemes(self, G, P, group, profit):
        MOD = 10**9 + 7
		#[利益][人数]=方案数
        cur = [[0] * (G + 1) for _ in xrange(P + 1)]
        cur[0][0] = 1

        for p0, g0 in zip(profit, group):
            # p0, g0 : the current crime profit and group size
			#当前利益和人数
            cur2 = [row[:] for row in cur]
            for p1 in xrange(P + 1):
                # p1 : the current profit #当前利益
                # p2 : the new profit after committing this crime 新利益
                p2 = min(p1 + p0, P)
                for g1 in xrange(G - g0 + 1):
                    # g1 : the current group size
                    # g2 : the new group size after committing this crime
                    g2 = g1 + g0
                    cur2[p2][g2] += cur[p1][g1]
                    cur2[p2][g2] %= MOD
            cur = cur2

        # Sum all schemes with profit P and group size 0 <= g <= G.
        return sum(cur[-1]) % MOD