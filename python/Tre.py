class Tree:
    def __init__(self,initval=None):
        self.value = initval
        if self.value :
            self.left = Tree()
            self.right = Tree()
        else:
            self.left = None
            self.right = None
        return(None)

    def isempty(self):
        return(self.value == None)

    def inorder(self):
        if self.value == None:
            return([])
        else:
            return(self.left.inorder() +
                    self.value +
                    self.right.inorder()
                    )

    def __str__(self):
        return(str(self.inorder()))

    def search(v):
        if self.value == None:
            return(False)
        if self.value == v:
            return(True)
        elif v > self.value:
            return(self.right.search(v))
        else:
            return(self.left.search(v))


