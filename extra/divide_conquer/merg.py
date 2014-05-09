
import random
from time import *
from pylab import *
import time
import numpy as np

def merge_sort(m):
    if len(m) <= 1:
        return m

    middle = len(m) / 2
    left = m[:middle]
    right = m[middle:]

    left = merge_sort(left)
    right = merge_sort(right)
    return list(merge(left, right))

def merge(left, right):
    result = []
    left_idx, right_idx = 0, 0
    while left_idx < len(left) and right_idx < len(right):
        # change the direction of this comparison to change the direction of the sort
        if left[left_idx] <= right[right_idx]:
            result.append(left[left_idx])
            left_idx += 1
        else:
            result.append(right[right_idx])
            right_idx += 1

    if left:
        result.extend(left[left_idx:])
    if right:
        result.extend(right[right_idx:])
    return result




def call_merg():
    n=1000;
    y = []
    while n <= 10001:
        s =time.clock();
        b=range(0,n+1,1);
        shuffle(b);
        merge_sort(b);
        t= time.clock() - s
        y.append(t)
        n = n+250;
    return y


if __name__ == '__main__':
	x = range(1000,10001,250)
	z = call_merg()
	plot(x,z,'ro-')
	show();
