from math import *

class Point :
    # Constructor 
    def __init__(self,a=0,b=0):
        self.x = a
        self.y = b

    def translate(self,deltax,deltay):
        self.x += deltax
        self.y += deltay

    def odistance(self):
        return(sqrt(self.x^2 + self.y^2))

    def __str__(self):
        return('('+str(self.x)+','+str(self.y)+')')

    def __add__(self,p):
        p2 = Point( (p.x+self.x),(p.y+self.y) )
        return(p2)

    def __mult__(self,p):
        p2 = Point((p.x*self.x),(p.y*self.y))
        return(p2)






        

    

    
