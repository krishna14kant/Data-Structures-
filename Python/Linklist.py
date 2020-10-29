class Linklist:
    """ Linklist data structure """
    class Node:
        def __init__(self, data=None):
            self.data = data
            self.next = None

        def __str__(self):
            return str(self.data)

    def __init__(self):
        self.head = self.Node()
        self.tail = self.head
        self.size = 0

    def __str__(self):
        s, it = '', self.head.next
        while it != None:
            s += str(it.data) + ' '
            it = it.next
        return s.rstrip()

    def append(self, data):
        self.tail.next = self.Node(data)
        self.tail = self.tail.next
        self.size += 1

    def __len__(self):
        return self.size

    def getIndex(self, index):
        it = self.head.next
        if it is None or index >= self.size:
            return None
        for _ in range(index):
            it = it.next
        return it.data

    def insert(self, index, data):
        if index <= self.size:
            it = self.head
            for _ in range(index):
                it = it.next
            newNode = self.Node(data)
            newNode.next = it.next
            it.next = newNode
            if index == self.size:
                self.tail = newNode
            self.size += 1

    def delete(self, index):
        if index < self.size:
            it = self.head
            for _ in range(index):
                it = it.next
            item = it.next
            it.next = it.next.next
            if index == self.size-1:
                self.tail = it
            self.size -= 1
        return item

    def clear(self):
        self.head = self.tail = self.Node()
        self.size = 0

    def isEmpty(self):
        return self.size == 0

    def popBack(self):
        return self.delete(self.size - 1)


l = Linklist()

l.append(5)
print('append 5 :', l)
l.append(4)
print('append 4 :', l)
l.insert(1, 8)
print('insert 8 at index 1 :', l)
l.insert(3, 6)
print('insert 6 at index 3 :', l)
l.append(2)
print('isEmpty check : ', l.isEmpty())
print('append 2 :', l)
l.delete(2)
print('delete index 2 :', l)
l.delete(3)
print('delete index 3 :', l)
l.append(7)
print('append 7 :', l)
l.popBack()
print('pop back :', l)
l.clear()
print('Clear :', l)
print('isEmpty check : ', l.isEmpty())
