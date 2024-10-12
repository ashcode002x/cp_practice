# DSU

class DSU:
    def __init__(self,n) -> None:
        self.parent = [0]*n
        self.rank = [1]*n
        for i in range(n):
            self.parent[i] = i
            self.rank[i] = 1


    def find(self,x):
        if self.parent[x]!=x:
            self.parent[x]=self.find(self.parent[x])
        return self.parent[x]
    
    def union(self,x,y):
        xp=self.find(x)
        yp=self.find(y)

        if xp==yp:
            return
        if self.rank[xp]>self.rank[yp]:
            self.parent[yp]=xp
        elif self.rank[xp]<self.rank[yp]:
            self.parent[xp]=yp
        else:
            self.parent[yp]=xp
            self.rank[xp]+=1

obj=DSU(5)
obj.union(0, 2) 
obj.union(4, 2) 
obj.union(3, 1) 
# obj.union(3,4)
print(obj.find(0))
print(obj.find(1))