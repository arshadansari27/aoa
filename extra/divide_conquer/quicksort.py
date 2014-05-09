from pylab import *	
import random
import time

def quicksort1(a, first, last):
	if first >= last :
			return 
	q = partition1(a,first,last)
	quicksort1(a, first, q-1)
	quicksort1(a, q+1, last)

def partition1(a, first, last):
	r = random.randrange(first,last+1)
	swap(a,r,first)
	i,pivot=first,a[first]
	for j in range(i+1,last+1):
		if a[j] < pivot:
			i = i+1
			swap(a,j,i)	
	swap(a,i,first)	
	return i 		
	
def swap(a,x,y):
	temp  = a[x]
	a[x] = a[y]
	a[y] = temp



def call_quicksort():
    n=1000;
    y = []
    while n <= 10001:
        s =time.clock();
        b=range(0,n+1,1);
        shuffle(b);
        quicksort1(b,0,n);
        t= time.clock() - s
        y.append(t)
        n = n+250;
    return y
   
if __name__ == '__main__':
	x = range(1000,10001,250)
	z = call_quicksort()
	plot(x,z,'ro-')
	show();
    
    
    
    
