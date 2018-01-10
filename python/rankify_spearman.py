from math import sqrt

def rankify(A):
    ''' Computes the rank vector of A
    Complexity O(n+k), where k = max
    element of A
    '''
    
    # Get maximum element in A
    max_el = max(A)
    N = len(A)

    # Two Arrays C and D from 0 to max_el
    C = [ 0 for x in range(max_el+1)]
    D = [ 0 for x in range(max_el+1)]
    # Array for storing ranks
    R = [0 for x in range(N)]

    #Set up C vector. C[i] stores frequency
    # of A[i]
    for i in range(N):
        C[A[i]] += 1

    #Set up D vector. D[i] stores number
    # of elements less than or equal to
    # A[i]
    for i in range(1, max_el+1):
        D[i] = D[i-1] + C[i]

    # Using Formula
    for  i in range(N):
        R[i] = D[A[i]] + (1-C[A[i]])/2


    return(R)

def correlation_coefficient(X,Y):
    n = len(X)
    sigma_x = sigma_y = 0
    sigma_xy = sigma_xsq = sigma_ysq = 0

    for i in range(n):
        sigma_x += X[i]
        sigma_y += Y[i]
        sigma_xy += X[i]*Y[i]
        sigma_xsq += X[i]*X[i]
        sigma_ysq += Y[i]*Y[i]

    num = n*sigma_xy - sigma_x*sigma_y
    den = sqrt((n*sigma_xsq - sigma_x*sigma_x)
               *(n*sigma_ysq - sigma_y*sigma_y))

    return(num/den)

def spearman(X,Y):
    rank_X = rankify(X)
    rank_Y = rankify(Y)

    return(correlation_coefficient(rank_X, rank_Y))

