# detect cycle in undirected graph using DSU

class DSU:
    def __init__(self, n):
        self.parent = [0] * (n + 1)
        self.rank = [1] * (n + 1)
        for i in range(n + 1):
            self.parent[i] = i
        
    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])
        return self.parent[u]
    
    def union(self, u, v):
        up = self.find(u)
        vp = self.find(v)
        if up == vp:
            return
        if self.rank[up] > self.rank[vp]:
            self.parent[vp] = up
        elif self.rank[vp] > self.rank[up]:
            self.parent[up] = vp
        else:
            self.parent[vp] = up
            self.rank[up] += 1
    
class Solution:
    def detectCycle(self, v, adj):
        obj = DSU(v)
        for i in range(len(adj)):
            g1 = obj.find(adj[i][0])
            g2 = obj.find(adj[i][1])

            if g1 == g2:
                return True

            obj.union(adj[i][0], adj[i][1])
        
        return False

if __name__ == '__main__':
    sol = Solution()
    v = 5
    adj = [[0, 2], [0, 3], [0, 4], [1, 3], [2, 4]]
    ans = sol.detectCycle(v, adj)
    print(ans)
