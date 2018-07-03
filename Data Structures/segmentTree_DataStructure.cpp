#include<bits/stdc++.h>
using namespace std ;

void build  (int data[] , int tree[] , int node , int start , int end );
void update (int data[] , int tree[] , int node , int start , int end , int index , int val); // val = new - old
int  query  (int data[] , int tree[] , int node , int start , int end , int left , int right );

int main(){
	
	// Size of the array to be processed : n 
	int n , a[n] , tree[100000]; 
	cin >> n ;
	
	for(int i=0;i<n;i++)
	   cin >> a[i] ;
	
	// building the segment tree 
	build(a,tree,1,0,n-1) ;
	
	cout << query(a,tree,1,0,n-1,2,5) << endl ; // for this to be valid n > 5 (dummy testing)
	
	update(a,tree,1,0,n-1,3,10-a[3]);  // testing update function
	
	cout << query(a,tree,1,0,n-1,2,5) ;
	
	return 0 ;
}

void build(int data[] , int tree[] , int node , int start , int end ){
	
	if ( start == end ) {
	   // leaf
	   tree[node] = data[start] ;
    }
    else {
        
		int mid = (start+end)/2  ;
    
	    build(data,tree,2*node,start,mid);
        build(data,tree,2*node+1,mid+1,end);
    
	    tree[node] = tree[2*node] + tree[2*node+1] ;
    }

}

void update(int data[] , int tree[] , int node , int start , int end , int index , int val){
	
	if (start == end){
	    // leaf	
		data[start] += val ;
		tree[node]  += val ;
	}
	else {
		int mid = (start+end)/2 ;
		
		if( index >= start && index <= mid )
		  update(data,tree,2*node,start,mid,index,val);  
		else {
		  update(data,tree,2*node+1,mid+1,end,index,val);	
		}
		
		tree[node] = tree[2*node] + tree[2*node+1] ;
	}
}

int  query(int data[] , int tree[] , int node , int start , int end , int left , int right ){
	
	if ( right < start || left > end ){
	 	// outside the range of current node .........
	 	return 0 ; 
	}
	     
	if ( left <= start && right >= end ){
	 	// node range in competely inside ...........
	 	return tree[node] ;
	}
	
	// node range is partially inside ...........
	int mid = (start+end)/2 ;
	int p1 = query(data,tree,2*node,start,mid,left,right)  ;
	int p2 = query(data,tree,2*node+1,mid+1,end,left,right);
	
	return p1+p2 ;
}

