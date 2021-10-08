class flatten:
    def __init__(self, data):
        self.data = data

    def __next__(self):
        item, self.data = self.data[0], self.data[1:]
        while isinstance(item, list):
            if not item:
                item, self.data = self.data[0], self.data[1:]
            else:
                item, self.data = item[0], item[1:] + self.data
        return item
        raise StopIteration

    def __iter__(self):
        return self

data = [1, [-2, [[[4]]], [0, 5], [], 3], [4], 2, 7]

sum = 0
for e in flatten(data):
    print(e)
    sum += e
    if sum > 10:
        break
print("Result:", sum)
