def order(poly):
  """
  Returns the order of polynomial
  """
  order = 0
  for j in poly:
    if j[1] > order:
      order = j[1]
  return(order)

def combinensort(poly):
  """ Combines the terms of the polynomial which have
  same exponenet and also sorts the polynomial in decreasing
  powers
  """
  order_poly = order(poly)
  total = 0
  poly2 = []
  for exp in range(order_poly,-1,-1):
    for j in poly:
      if j[1] == exp:
        total += j[0]
    poly2.append((total,exp))
    total = 0
  return(poly2)

def cleanup(poly):
  """ Removes zero terms from the polynomia
  """
  poly2 = []
  for j in poly:
    if  j[0] != 0 :
      # Remove terms which are zero
      poly2.append( (j[0],j[1]) )
  return(poly2)

def makeproper(poly,toOrder):
  """ Poperly arranges the polynomial to a polynomial of
  nth order by add zeros to it
  """
  for exp_term in range(toOrder,-1,-1):
    poly.append( (0,exp_term) )
  poly = combinensort(poly)
  return(poly)


def addpoly(poly1,poly2):
  """ Adds to polynomials
  """
  largest_order = max(order(poly1),order(poly2))
  poly1 = makeproper(poly1,largest_order)
  poly2 = makeproper(poly2,largest_order)
  poly3 = []
  for j in range(0,largest_order+1):
    poly3.append( ((poly1[j][0]+poly2[j][0]),poly1[j][1]) )
  poly3 = cleanup(poly3)
  return(poly3)

def multpoly(poly1,poly2):
  """ Multiplies two polynomials
  """
  ( poly3,totalsum,totalpower )  = ( [],0,0 )
  for j in range(0,len(poly1)):
    for k in range(0,len(poly2)):
      totalsum += poly1[j][0] * poly2[k][0]
      totalpower = poly1[j][1] + poly2[k][1]
      poly3.append( (totalsum,totalpower) )
      (totalsum,totalpower) = (0,0)
  poly3 = combinensort(poly3)
  poly3 = cleanup(poly3)
  return(poly3)


if __name__ == "__main__" :
  print(multpoly([(1,1),(-1,0)],[(1,2),(1,1),(1,0)]))









