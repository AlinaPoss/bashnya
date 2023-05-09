from random import*

class Node:
    def __init__(self, k, x): #key, x
        self.k = k
        self.x = x
        self.next = None
        self.size = 0

class Set(object):
    def __init__(self):
        self.M = 10000
        self.size = 0
        self.table = [None] * self.M
        
    def insert(self, x):
        if self.size + 1 >= M: # если скоро место кончится
            self.M *= 2

        #если индекс свободен, кладем туда значение
        #если нет, все равно кладем, просто новое
        M = self.M
        i = self._hash(x)
        while not(self.table[i] is None):
            i = (i + i) % M
        self.table[i] = x
        self.size += 1
        
    def exists(self, x):
        M = self.M
        i = self._hash(x)
        while not(self.table[i] is None):
            if self.table[i] == x:
                return True
            i = (i + i) % M
        return False
    
    def delete(self, x):
        M = self.M
        i = self._hash(x)
        while not(self.table[i] is None):
            if self.table[i] == x:
                self.table[i] = None
                self.size -= 1
                break
            i = (i + i) % M
    def doRehashing(): #для сета вроде не понадобился 
        pass
    
    def _hash(self, key):
        a = 257
        p = 600
        M = self.M
        return (a*key % p) % M

s = Set()
s.insert(3)
s.insert(5)
assert s.exists(5) == True
s.delete(5)
assert s.exists(5) == False
assert s.exists(4) == False
assert s.exists(3) == True
