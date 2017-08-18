import math

def perfect(n):
  sum = 0;
  for i in range(1,n):
      if n % i == 0:
        sum += i
  
  return(sum == n)


def depth(s):
  (count, max) = (0,0)
  
  for i in s:
    
    if i == "(" :
      count += 1
    elif i == ")" :
      count -= 1
      
    if count > max:
      max = count
   
  return(max)


def sumsquares(l):
  sum = 0
  for i in l:
    if ( (math.sqrt(i) - int(math.sqrt(i)) ) == 0):
      sum += i
    
  return(sum)



  