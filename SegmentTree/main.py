# maximum element 
N = int(1e5 + 2)
arr = [0] * N
tree = [0] * (4 * N)

def build(node: int, start: int, end: int):
    if start==end:
        tree[node]=arr[start]
        return
    mid = (start+end)//2
    build(2*node,start,mid)
    build(2*node+1,mid+1,end)
    tree[node]=max(tree[2*node],tree[2*node+1])

def query(node:int,start:int,end:int,left:int,right:int)->int:
    if start>right or end<left:
        return float("-inf")
    if left<=start and end<=right:
        return tree[node]
    mid=(start+end)//2
    q1=query(2*node,start,mid,left,right)
    q2=query(2*node+1,mid+1,end,left,right)
    return max(q1,q2)

def update(node,start,end,idx,val):
    if start==end:
        arr[start]=val
        tree[node]=val
        return
    mid=(start+end)//2
    if idx<=mid:
        update(2*node,start,mid,idx,val)
    else:
        update(2*node+1,mid+1,end,idx,val)
    tree[node]=max(tree[2*node],tree[2*node+1])



temp = [6, 8, -1, 2, 17, 1, 3, 2, 4]
n=len(temp)
for i in range(len(temp)):
    arr[i] = temp[i]
build(1, 0, len(temp) - 1)
print("query is: ",query(1,0,n-1,2,6))
update(1,0,n-1,6,18)
print("query after update is: ",query(1,0,n-1,2,6))
print("tree is: ",tree[:20])