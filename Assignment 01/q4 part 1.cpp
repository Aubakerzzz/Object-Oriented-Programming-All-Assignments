bool isprimeNumber(int n, int i){
	if(n == 0 || n == 1)
		return false;			// 0 & 1 are not prime numbers
	
	
	else if(i == n)				
		return true;		 	// 2 is prime number so returning true 
	
	else if(n % i == 0)
		return false; 			// number divided my other than 0,1 & its self is not a prime number so returning false 
		
	return isprimeNumber(n, i + 1);
}

