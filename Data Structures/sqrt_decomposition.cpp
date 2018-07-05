#include<bits/stdc++.h>
using namespace std ;

void build (int input[] , int blocks[] ,  int size  );
int  query (int input[] , int blocks[] , int size , int l , int r);

int main() {
	
	int n , t ,  a[100000] , blocks[10000] , l , r ;  // size of array 
	cin >> n >> t ;
    	
	for(int i=1;i<=n;i++)
	    cin >> a[i] ; 
	    
	build(a,blocks,n) ;
	
	cout << "Blocks :  " ;
	for(int i=1; i<=ceil(sqrt(n)) ; i++)
	   cout << blocks[i] << "  " ;
	cout << endl  << endl ;
	
	
	while(t--) {
	    cout << "Enter Query Range : " ;
	    cin >> l >> r ;
	    cout << query(a,blocks,n,l,r) << endl  ;   //   l <= r <= n 
    }
	
   
	   
	return 0 ;
}

void build(int input[] , int blocks[] ,  int size){
	
	int blk_size = ceil(sqrt(size));
	int block_no = 1 , sum = 0  ; 	
	
	for(int i=1;i<=size;i++){
		
		sum += input[i] ;
		if ( i%blk_size == 0 ) {
			blocks[block_no] = sum ;
			block_no++ ;
			sum = 0 ;
		}
	}
	
	if ( sum != 0 )
	   blocks[block_no] = sum ;
}

int query(int input[] , int blocks[] , int size , int l , int r ){
	
	int blk_size = ceil(sqrt(size)) ;
	int sum = 0 ;
	
	while( l%blk_size != 0 && l<=r ) {
		sum += input[l++] ;
	}
	
	if(l%blk_size==0 && l<=r)
	   sum += input[l] ;
	
	while(l+blk_size <= r) {
	    sum += blocks[(int) ceil((l+1)/(double)blk_size)] ;
	    l += blk_size ;    
    }
	
	while(l<r)
	    sum += input[++l] ;
	
	return sum ;
}
