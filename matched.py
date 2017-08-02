def matched(s):
    topofstack = -1
    for c in s:
        if c == "(":
            topofstack = topofstack + 1
        elif c == ")":
            if topofstack >= 0:
                topofstack = topofstack - 1
            else : 
                return(False)
    if topofstack == -1:
        return(True)
    return(False)




