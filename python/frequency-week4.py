
freqlist ={}

def mycmp(i, j):
    if freqlist[i] == freqlist[j]:
        return(i -j)
    return(freqlist[i] - freqlist[j])

def cmp_to_key(mycmp):
    'Convert a cmp= function into a key= function'
    class K:
        def __init__(self, obj, *args):
            self.obj = obj
        def __lt__(self, other):
            return mycmp(self.obj, other.obj) < 0
        def __gt__(self, other):
            return mycmp(self.obj, other.obj) > 0
        def __eq__(self, other):
            return mycmp(self.obj, other.obj) == 0
        def __le__(self, other):
            return mycmp(self.obj, other.obj) <= 0
        def __ge__(self, other):
            return mycmp(self.obj, other.obj) >= 0
        def __ne__(self, other):
            return mycmp(self.obj, other.obj) != 0
    return K


def frequency(l):
    max = 0
    N = len(l)
    
    a = []
    b = []
    

    for i in l:
        try:
            freqlist[i] += 1
        except KeyError:
            freqlist[i] = 1

          
    l.sort(key=cmp_to_key(mycmp))
    

    
    a.append(l[0])
    b.append(l[-1])

    i = 1
    j = N-2

    
    while i < N-1 and freqlist[l[i]] == freqlist[l[i-1]]:       
        
        if l[i] != l[i-1]:
            a.append(l[i])
        i = i+1
        
        

    while j > 0 and freqlist[l[j]] == freqlist[l[j+1]]:
        if l[j] != l[j+1]:
            b.append(l[j])
        j = j - 1
        

    return(a, sorted(b))
    


