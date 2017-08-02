def descending(l):
    for i in range(1,len(l)):
        if l[i] > l[i-1]:
            return(False)
    return(True)

def alternating(l):
    
    for i in range(1,len(l)):
        if i % 2 == 0:
            if l[i] > l[i-1]:
                return(False)
        else:
            if l[i] < l[i-1]:
                return(False)
    return(True)

def matmult(l1,l2):
    l3 = []
    l4 = []
    sum = 0
    for i in range(0,len(l1)):
        for j in range(0,len(l1[i])): 
            for k in range(0,len(l1[i])):
                sum += l1[i][k] * l2[k][j]

            l3 = l3+[sum]
            sum = 0
    l4 = l4+l3
    l3 = []
    print(l4)
    



