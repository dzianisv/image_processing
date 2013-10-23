import fastft
import function
import numpy
import cmath
import complex_math

def single_regular(X, m):
  sum=0
  arg=0
  for x in X:
    if  m+x >= len(X):
      arg=m+x-len(X)
    else:
      arg=m+x
    sum+=numpy.multiply( function.function1(x), function.function2(arg) )
  return sum/len(X)

def range_regular(X, M):
  result = []
  for m in M:
    result.append( single_regular(X, m) )  
  return result

def range_fast(X):
  f1 = function.function1(X)
  f2 = function.function2(X)
  F1 = fastft.compute(f1)
  F2 = fastft.compute(f2)
  F1 = complex_math.ajoint(F1)
  MUL = numpy.multiply(F1, F2)
  return fastft.reverse_compute(MUL)