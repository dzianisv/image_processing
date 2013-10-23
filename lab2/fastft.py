import math
import cmath
import numpy
import function

iteration_count=0

def _internal_compute(a,  dir):
  global iteration_count
  N = len(a)
  if N == 1:
    return a
  a_even = []
  a_odd = []
  
  i=0
  for element in a: 
    if i % 2  == 0:
      a_even.append(element)
    else:
      a_odd.append(element)
    i += 1

  b_even = _internal_compute(a_even,  dir)
  b_odd = _internal_compute(a_odd, dir)
  out_vector = list( range(0, N ) )
  
  #initialization
  Wn = cmath.cos( cmath.pi*2/N ) + dir*1j*cmath.sin( cmath.pi*2/N )
  W=1
  
  for m in range(0, int(N/2)):
    iteration_count+=1
    out_vector[m]= b_even[m] + W*b_odd[m]
    out_vector[m+int(N/2)] = b_even[m]-W*b_odd[m]
    W = W*Wn
    
  return out_vector

def compute(X):
  result = _internal_compute(X,  1)
  for i in range(0, len(result)):
    result[i] /= len(result)
    
  return result

def reverse_compute(C):
   return _internal_compute(C,  -1)
