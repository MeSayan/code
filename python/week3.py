def check_ascending(l,left,right):
  # Base Cases 
  if left == right:
    return(False)
  elif (right - left) == 1:
    return(True)
  
  mid = (left + right) // 2;
  
  if l[mid] < l[left] or l[mid] > l[right-1] :
    return(False)
  
  return check_ascending(l,left,mid) and check_ascending(l,mid,right)

def ascending(l):
  return(check_ascending(l,0,len(l)))


def transpose(l):
  m = len(l)
  n = len(l[0])
  transposed = []
  a = []
  for i in range(m-1,-1,-1):
   for j in range(n-1,-1,-1):
      a.append(l[i][j])
   transposed.append(a)
   a = []
    
  return(transposed)



