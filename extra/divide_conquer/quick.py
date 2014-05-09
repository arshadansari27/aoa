

import random
from time import *
from pylab import *
import time
from merg import *
from selection import *;
from pylab import *	
import random
import time
import matplotlib.pyplot as plt

def quicksort(a, l, u):
	if l >= u:
		return
	r=random.randrange(l,u+1)	
	swap(a,l,r)
	m = l	 
	for j in range(l+1,u+1):
		if a[j] < a[l]:
			m +=1
			swap(a,j,m)
	swap(a,l,m)
	quicksort(a,l, m-1) 		
	quicksort(a, m+1, u)	

def swap(a,x,y):
	temp  = a[x]
	a[x] = a[y]
	a[y] = temp

def call_quick():
    n=1000;
    y = []
    while n <= 10001:
        s =time.clock();
        b=range(0,n+1,1);
        shuffle(b);
        quicksort(b,0,n);
        t= time.clock() - s
        y.append(t)
        n = n+250;
    return y

'''
since merge and quick require very small amount of time as compare to selection sort ,so their graphs are merged you can comment the selection call 
and check the difference in more cleaner way.
'''
y2 = call_merg();
y1 = call_quick();
y3 = call_selection();
x = range(1000,10001,250)
plt.subplot()
plt.xlabel('Inputs',fontsize = 20,color = 'red')
plt.ylabel('Time',fontsize =20,color = 'red')
plt.title('Merge | Quick | Selection')
plt.plot(x,y1,'ro-',x,y3,'bo-',x,y2,'g^-');

plt.subplot()
plt.plot(x,y2,'ro-',x,y2,'bo-')
plt.show();




