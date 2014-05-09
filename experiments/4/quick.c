/*
This quick-sort uses partition scheme based on N.Lomuto(ref -CLRS 171) not on orignal Hoare's method as i find it nore conceptual 

Sedgewick and Bentely method helped to implement partition inside quick routine and also made code "Beautiful".
(but their production level code sucks{too math})

If we choose always choose first or middle or last element as pivot it gives 0(n^2)
therefore randomly choosing pivots make some good some bad pivot choices but on average gives 0(nlogn).

This code is also implemented in python(in "extra" folder) with some bueautiful graphs
*/
#include<stdio.h>
#include<stdlib.h>
void quick(int *a,int first,int last ){
	int i,m;
	if(first >= last ) return;
	swap(a,first,rand()%(last-first)+first); //hopefully now it works in 0(nlogn) time as partitions is are done randomly to achive average of
											// "good" and "evil"   pivots.
	m= first;	
	for (i=first+1; i<= last;i++)
		if(a[i] < a[first])
			swap(a,i,++m);
	swap(a,first,m);	
	quick(a,first,m-1);
	quick(a,m+1,last);
}

int swap(int *a, int x,int y){
	int temp = a[x]; a[x] = a[y]; a[y] = temp;
}

int main(){
	int i,j=0, a[1000000]; time_t t; srand((unsigned) time(&t));
	for(i=999999;i>=0;i--,j++)
			a[j] = i;
	quick(a,0,999999);
	return 0;	
}	
	
