#include<bits/stdc++.h>
using namespace std ;

//           .......................constructing Max Heap datastructure ..................

void buildHeap(int []  , int & ) ;
void maxHeapify(int [] , int , int & ) ;
int  extractMax(int [] , int&) ;

int main() {
	
	
	int a[10000] , n , heapSize ;
	
	cout << "Enter no. of Elements :  " ;
	cin >> n ;
	
	cout << "\nEnter Data : " ;
	
	for (int i = 0 ; i < n ; i++)
	    cin >> a[i] ;
	
	heapSize = n ;
	
	buildHeap(a,heapSize) ;
	
	while( heapSize != 0 )  {
		
        cout << "\n\nHeap Data : " ;
	    for (int i = 0 ; i < heapSize ; i++)
	        cout <<  "  " << a[i] ;
	
	    cout << "\n" << extractMax(a,heapSize) ;

    }
	
	return 0 ;
}


//  ............... Build Heap Method .....................

void buildHeap(int a[] , int& heapSize ) {
	
	for (int  index = (heapSize-1)/2 ; index >= 0 ; index-- ) {
		maxHeapify(a,index,heapSize) ;
	}	
}



//        ................ Max Heapify Method ..................

void maxHeapify(int a[] , int i , int & heapSize) {
	
	
	int leftChild = 2*i+1 , rightChild = 2*i+2 , largestChild = i , temp  ;
	
	if ( leftChild <= heapSize-1 && a[leftChild] > a[largestChild] )
	   largestChild =  leftChild ;
	
	if ( rightChild <= heapSize-1 && a[rightChild] > a[largestChild] )
	   largestChild =  rightChild ; 
	 
	if (largestChild != i ) {
		
		// Swap 
		
		temp = a[largestChild] ;
		a[largestChild] = a[i] ;
		a[i] = temp ;
		
		maxHeapify(a,largestChild,heapSize) ;
	}  
}



// ............... Extract Max method ............

int extractMax(int a[] , int & heapSize ){
	
	int mx ;
	mx = a[0] ;
	a[0] =  a[heapSize-1]  ;
	heapSize-- ;
	maxHeapify(a,0,heapSize) ;
	
	return mx ;
}
