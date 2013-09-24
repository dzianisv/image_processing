# -*- coding: utf-8 -*- 
import math
import cmath
import numpy

N=int(32)
GAP=2*math.pi/N

def myfunction(x):
  return numpy.cos(2*x) + numpy.sin(3*x)


def phase(z):
  return math.atan2(z.imag, z.real)

def array_phase(Z):
  out = []
  for z in Z:
    out.append( phase(z))
  return out
  
def array_abs(Z):
  out = []
  for z in Z:
    out.append( abs(z) )
  return out