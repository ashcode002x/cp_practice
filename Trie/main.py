# trie

class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.isEndofWord = 0
    def insert(self,word):
        curr=self
        for c in word:
            c=ord(c)-ord('a')
            if curr.children[c] is None:
                curr.children[c]=Trie()
                curr=curr.children[c]
            
        curr.isEndofWord+=1
    def search(self,word):
        curr=self
        for c in word:
            c=ord(c)-ord('a')
            if curr.children[c] is None:
                return False
            curr=curr.children[c]
        return curr.isEndofWord>0
    def prefixSearch(self,word):
        curr=self
        for c in word:
            c=ord(c)-ord('a')
            if curr.children[c] is None:
                return False
            curr=curr.children[c]
        return True

if __name__=="__main__":
    trie=Trie()
    trie.insert("hello")
    trie.insert("world")
    trie.insert("helth")
    print(trie.search("help"))
    print(trie.prefixSearch("he"))
    print(trie.search("hello"))
    # print(trie.children)