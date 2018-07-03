#include<bits/stdc++.h>
using namespace std ;


void build(int data[] , int tree[] , int node , int start , int end );

void updateRange(int data[] , int tree[] , int node , int start , int end, int l , int r , int val) ;

void lazyUpdateRange(int data[] , int tree[] , int lazy[] , int node , int start , int end, int l , int r , int val);

int  queryRange(int data[] , int tree[] , int lazy[] , int node , int start , int end, int l , int r ) ;


int main() {
	
	int n ,  a[100000] ; 
	int tree[100000] , lazy[100000] = {0}  ;
	
	cin >> n ;
	
	for(int i=0;i<n;i++)
	   cin >> a[i] ;   
	   
	// building the segment tree 
	build(a,tree,1,0,n-1) ; 
	
		
	cout << queryRange(a,tree,lazy,1,0,n-1,2,5) << endl ; // for this to be valid n > 5 (dummy testing)
	
	lazyUpdateRange(a,tree,lazy,1,0,n-1,3 ,5,10);  // testing update function
	
	cout << queryRange(a,tree,lazy,1,0,n-1,2,5) ;  
	
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

//  updates without laziness ................

void updateRange(int data[] , int tree[] , int node , int start , int end, int l , int r , int val){
	
	if ( start > end || start > r || end < l )   // outof range
	  return ;
	
	
	if ( start == end ) {
		// leaf 
		tree[node] = val ;
		return ;
	}
	
	int mid = (start+end)/2 ;
	updateRange(data,tree,2*node,start,mid,l,r,val);
	updateRange(data,tree,2*node+1,mid+1,end,l,r,val);
	
	tree[node] = tree[2*node] + tree[2*node+1] ;
	
}

// Lazy updates ( update only when needed ) ......

void lazyUpdateRange(int data[] , int tree[] , int lazy[] , int node , int start , int end, int l , int r , int val){

    if ( lazy[node] != 0 ){
     	// needs to be updated first .....
     	
     	tree[node] += (end - start + 1)*lazy[node] ;
     	if (start != end){
     	   	
     	    lazy[2*node]   += lazy[node] ;  // delaying the updates of childrens ...	
     		lazy[2*node+1] += lazy[node] ;
		}
		
		lazy[node] = 0 ;
    }
    
    if ( start > end || start > r || end < l )   // outof range
	    return ;
	    
    if (l<=start && r >= end)  {
    	
    	// Segment is fully within range
    	tree[node] = (end - start + 1 )*val ;
    	
		if(start != end){
            // Not leaf node
            lazy[node*2] = val;
            lazy[node*2+1] = val;
        }
        return;
    }
    
    int mid = (start+end)/2 ;
	lazyUpdateRange(data,tree,lazy,2*node,start,mid,l,r,val);
	lazyUpdateRange(data,tree,lazy,2*node+1,mid+1,end,l,r,val);
	
	tree[node] = tree[2*node] + tree[2*node+1] ;
}



int  queryRange(int data[] , int tree[] , int lazy[] , int node , int start , int end, int l , int r ){
	
	if (start > end || start > r || end < l ) // out of range 
	    return 0 ;
	    
	if ( lazy[node] != 0 ){
		
		// This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        
		if(start != end) {
            lazy[node*2]   += lazy[node];       // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        
        lazy[node] = 0;
	}
	
	if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node]; 
        
        
	int mid = (start + end) / 2;
    int p1 = queryRange(data,tree,lazy,node*2, start, mid, l, r);         // Query left child
    int p2 = queryRange(data,tree,lazy,node*2 + 1, mid + 1, end, l, r);  // Query right child

    return (p1 + p2);
	
}




