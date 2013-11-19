#!/usr/bin/python3.3
# -*- coding: utf-8 -*- 
import sys
import math
import numpy
from matplotlib import pyplot
import fastft
import function 
import correlation
import compression

def compute_plot(X):
  f1 = function.function1(X)
  f2 = function.function2(X)
  #**************************************************************
  #plot source functions
  #function 1
  pyplot.subplot(3, 2, 1)
  pyplot.plot(X, f1, "g-s")
  pyplot.title("Function 1")
  #function 2
  pyplot.subplot(3, 2, 2)
  pyplot.plot(X, f2, "r-s")
  pyplot.title("Function 2")
  #**************************************************************
  #regular algorithms
  regular_correlation_array = correlation.range_regular(X, X)
  regular_compression_array = compression.range_regular(X, X)
  #compression
  pyplot.subplot(3, 2, 3)
  pyplot.plot(X, regular_compression_array, "b-o")
  pyplot.title("Regular compression")
  #correlation
  pyplot.subplot(3, 2, 4)
  pyplot.plot(X, regular_correlation_array, "c-o")
  pyplot.title("Regular correlation")
  #**************************************************************
  #fast furie algorithms
  fast_correlation_array = correlation.range_fast(X)
  fast_compression_array = compression.range_fast(X)
  #compression
  pyplot.subplot(3, 2, 5)
  pyplot.plot(X, regular_compression_array, "b-s")
  pyplot.title("Fast compression")
  #correlation
  pyplot.subplot(3, 2, 6)
  pyplot.plot(X, regular_correlation_array, "c-s")
  pyplot.title("Fast correlation")
  
#preparing Real part of complex numbers
X = numpy.arange(0, 2*math.pi, function.GAP)
print(len(X))
compute_plot(X)
#show plots
pyplot.show()
