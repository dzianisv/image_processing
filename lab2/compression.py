import fastft
import numpy
import function


def single_regular(X, m):
  sum=0
  for x in X:
    arg=0
    if  m-x > 0:
      arg=m-x
    else:
      arg=m-x+len(X)
      
    sum+=numpy.multiply( function.function1(x), function.function2( arg ) )
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
  MUL = numpy.multiply(F1, F2)
  return fastft.reverse_compute(MUL)