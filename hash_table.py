from random import*

class Node:
    def __init__(self, k, v): #key, x
        self.k = k
        self.v = v

class Set(object):
    def __init__(self):
        self.M = 10000
        self.size = 0
        self.table = [None] * self.M
        self.ripCnt = 0
        
    def put(self, k, v):
        M = self.M
        i = self._hash(k)
        while not(self.table[i] is None):
            i = (i + i) % M
        self.table[i] = Node(k, v)
        self.size += 1
        
    def get(self, k):
        M = self.M
        i = self._hash(k)
        while not(self.table[i] is None):
            if self.table[i].k == k:
                return self.table[i].v
            i = (i + i) % M
        return None
    
    def delete(self, k):
        M = self.M
        i = self._hash(k)
        while not(self.table[i] is None):
            if self.table[i].k == k:
                self.table[i] = Node('rip', 'rip')
                self.ripCnt += 1
                self.size -= 1
                break
            i = (i + i) % M
        if self.ripCnt + self.size > M / 2:
            dodoRehashing()
        
    def doRehashing(): #для сета вроде не понадобился 
        pass
    
    def _hash(self, key):
        M = self.M
        h = 0
        A = 40
        a = 1
        for c in key:
            x = ord(c) - ord('a')  + 1
            a = a * A % M;
            h = (a * x + h) % M
        return h
            

s = Set()
s.put('k1', 'r')
s.put('k2', 't')
assert s.get('k1') == 'r'
assert s.get('k2') == 't'
s.delete('k1')
s.put('k1', 'a')
assert s.get('k1') == 'a'

s.put('k1', 'b') #пробуем добавить элемент с уже существующим ключом
assert s.get('k1') == 'a' #возвращает значение, которое ранее с этим ключом уже было
assert(s.size == 3) #но новый элемент добавлен в список. но мы до него не дойдем, пока не удалим первый
s.delete('k1')
assert s.size == 2
assert s.get('k1') == 'b'

