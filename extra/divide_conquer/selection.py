from time import *;
import time
from pylab import *

	
def selection_sort(b):
    size = len(b)
    for i in range(size):
         min = b[i];
         for j in range(i+1,size):
             if(b[i] > b[j]):
                 tmp = b[i];
                 b[i] = b[j];
                 b[j] = tmp;


def call_selection():
    n=1000;
    y = []
    while n <= 10001:
        s =time.clock();
        b=range(0,n+1,1);
        shuffle(b);
        selection_sort(b)
        t= time.clock() - s
        y.append(t)
        n = n+250;
    return y
    
if __name__ == '__main__':
	x = range(1000,10001,250)
	z = call_selection()
	plot(x,z,'ro-')
	show();
