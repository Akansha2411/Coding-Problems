def extraElement(x,y): 
  
    # To store the result 
    ans = 0; 
  
    # Find the XOR of all the element 
    # of array x[] and array y[] 
    
    for i in range(len(x)): 
        ans ^= x[i]; 
    for i in range(len(y)): 
        ans ^= y[i]; 
  
    return ans; 
  

  
