#!/usr/bin/python3.3
# -*- coding: utf-8 -*- 
import sys
import math
import numpy
from matplotlib import pyplot
import difft
import fastft
import function 

def reverse_dft(x, k):
  return 0
  
  
def dft(X, Y):
  pyplot.subplot(2, 4, 1)
  pyplot.plot(X, Y, "b-o")
  pyplot.title("Timing scope")

  #computing dft
  K=numpy.arange(0, function.N, 1)
  C=difft.compute(Y)

  pyplot.subplot(2, 4, 2)
  pyplot.plot(K, function.array_abs( C ), "g-s")
  pyplot.title("Amplitude scope")

  pyplot.subplot(2, 4, 3)
  pyplot.plot(K, function.array_phase(C), "r-s")
  pyplot.title("Phase scope")

  X_t=difft.reverse_compute(C)
  pyplot.subplot(2, 4, 4)
  pyplot.plot(X, X_t, "m-s")
  pyplot.title("Reverse")
  print("Diff Furie transform done. %d iteration count. Theoritical iteration count: %d" % ( difft.iteration_count, function.N**2 ) )

  
def fft(X, Y):
  pyplot.subplot(2, 4, 5)
  pyplot.plot(X, Y, "b-o")
  pyplot.title("Timing scope")

  #computing dft
  K=numpy.arange(0, function.N, 1)
  C=fastft.compute(Y)
  
  pyplot.subplot(2, 4, 6)
  pyplot.plot(K, function.array_abs(C), "g-s")
  pyplot.title("Amplitude scope")

  pyplot.subplot(2, 4, 7)
  pyplot.plot(K, function.array_phase(C), "r-s")
  pyplot.title("Phase scope")

  X_t=fastft.reverse_compute(C)
  pyplot.subplot(2, 4, 8)
  pyplot.plot(X, X_t, "c-s")
  pyplot.title("Reverse")
  
  N=len(X)
  print("Fast Furie transform done.  %d iteration count. Theoritical count is %d"  % (  fastft.iteration_count, (N)*math.log(N,2 ) ) )

#preparing Real part of complex numbers
X = numpy.arange(0, 2*math.pi, function.GAP)
Y = function.myfunction(X)

print( "Source data: " )
print( X )
print( Y )
#compute and plot by DFT alg
dft(X, Y)
#compute and plot by FFT alg
fft(X, Y)
#show plots
pyplot.show()
