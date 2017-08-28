
def generate_adjacency_matrix(l):
    max = 0
    for i in l:
        if i[0] > max:
            max = i[0]
        if i[1] > max:
            max = i[1]

    A = [ [0 for i in range(max+1)] for j in range(max+1)]

    for i in l:
        src = i[0]
        dest = i[1]
        A[src][dest] = 1

    return(A, max)


def one_hop_path(A, i, j, N):
    if i == j:
        return(False)

    for k in range(N,0,-1):
        # print(k)
        if A[i][k] !=0 and k != i:
            intermediate = k
            # print(intermediate)
            if A[intermediate][j] == 1:
                return(True)

    return(False)


def onehop(l):
    (A, N) = generate_adjacency_matrix(l)
    l = []
    for i in range(1,N+1):
        for j in range(1,N+1):
            if one_hop_path(A, i, j, N):
                l.append((i,j))
    return(l)
