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
def sortalgrthm(arraya, n, testcase):
    arr = np.array(arraya)
    np.sort(arr)

with open("10testcase.txt", "r") as file:
    for i in range(10):
        testcase = file.readline().strip()
        print(f'test {testcase}')
        n = file.readline().strip()
        arraya = list(map(float, file.readline().strip().split(" ")))
        sortalgrthm(arraya, n, testcase)
