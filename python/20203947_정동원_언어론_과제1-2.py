class sort_gen:
    def __init__(self, data):
        self.data = data
    
    def __next__(self):
        head, less, greater = self.makeHead()
        while less:
            self.data = less + [head] + greater
            head, less, greater = self.makeHead()
        self.data = less + greater
        return head
    def __iter__(self):
        return self
    
    def makeHead(self):
        head, tail = self.data[0], self.data[1:]
        less = [v for v in tail if v < head]
        greater = [v for v in tail if v >= head]
        return head, less, greater

data = [3,1,-5,7,-4,2,6,200,9, -2, 4,3,0,-2] + [100]*100000
sum = 0
for val in sort_gen(data):
    sum += val*val
    if sum > 50:
        print('sum =', sum)
        break
