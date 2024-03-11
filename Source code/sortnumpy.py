import numpy as np
import time

def tictoc(func):
    def wrapper(*args):
        t1 = time.time()
        result = func(*args)
        t2 = time.time()-t1
        print(f'{func.__name__} ran in {t2*1000} ms')
        return result
    return wrapper

@tictoc
def sortalgrthm(arraya, n):
    arr = np.array(arraya)
    np.sort(arr)

for i in range(1, 11):
    filename = "Test" + str(i) + ".txt"
    with open(filename, "r") as file:
        print(f'test{i}')
        n = file.readline().strip()
        arraya = list(map(float, file.readline().strip().split(" ")))
        sortalgrthm(arraya, n)
