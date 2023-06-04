num = [192, 211, 391, 458, 606, 775, 892, 954, 989, 998]

def bsearch(n, data):
    low = 0
    high = len(data) - 1
    while low <= high:
        middle = (low + high) / 2
        if n == data[middle]:
            return True
        elif n > data[middle]:
            low = middle + 1
        else:
            high = middle - 1
    return False

def hsearch(n,data):
    h = n%10
    if not hash_table.has_key(h):
        return False
    return lsearch(n, hash_table[h])

hash_table = {}
def make_hash(num):
    for n in num:
        h = n%10
        if not hash_table.has_key(h):
            hash_table[h] = []
        hash_table[h].append(n)
make_hash(num)
