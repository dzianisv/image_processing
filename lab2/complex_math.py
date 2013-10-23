import math


def abs(X):
  result = []
  for x in X:
    result.append( x )
  return result

def ajoint(X):
  result= []
  for x in X:
    result.append( x.real - x.imag*1j)
    
  return result