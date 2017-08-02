def intreverse(no):
  sum=0
  while (no > 0):
    sum *= no%10
    no = no // 10
  
  return(sum)


def sumprimes(l):
  sum = 0
  for i in l:
    flag = True 
    for j in range(2,i):
      if( i % j == 0):
        flag = False
    if flag:
      sum += i
  return(sum)
