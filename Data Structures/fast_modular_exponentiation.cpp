#include<bits/stdc++.h>
using namespace std ;

typedef long long int64;

int64  fastModularExpoV1(int64  base , int64   expo , int64  module );
int64  fastModularExpoV2(int64  base , int64   expo , int64  module );


int main(){
	
	int64  base , expo , module ;
	cout << "Enter base , expo , module : " ;
	cin >> base >> expo >> module ;
	

	cout << fastModularExpoV1(base,expo,module) << endl ;
	cout << fastModularExpoV2(base,expo,module) << endl ;
	
	
	return 0 ;
}

//  version 1 ................. ( Recursive ) 

int64  fastModularExpoV1(int64  base , int64   expo , int64  module ){
	
	if (expo == 0 )
	    return 1 ;
	    
	if (expo == 1 )
	    return base%module ;
	
	int64   p = fastModularExpoV1(base,expo/2,module);
	p = (p*p)%module ;
	
	if (expo % 2 == 0)
	   return p ;
	   
	return ((base%module)*p)%module ;
	   	    
}


// version 2 .................( Iterative )

int64  fastModularExpoV2(int64  base , int64   expo , int64  module ){
     
	int64  t = 1 ;
	    
    while(expo>0) {
    	
    	if (expo % 2 != 0 )
    	   t = (t*base)%module  ;
    	
    	base = (base*base)%module ;
    	expo >>= 1  ;
	}
  
    return t%module ;
}



