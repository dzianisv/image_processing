#!/usr/bin/python
# -*- coding: utf-8 -*- 


import numpy
import function
import math

iteration_count=0

def _compute(Y, k):
  global iteration_count
  N=len(Y)
  result=0
  W=math.e**( -2*1j*math.pi/N )
 
  m=0
  for y in Y:
    iteration_count+=1
    result+=y*W**(k*m)
    m+=1

  return result/N

def _reverse_compute(C, m):
  N=len(C)
  result=0
  W=math.e**( -2*1j*math.pi/N )

  k=0
  for c in C:
    result+=c*W**(-1*k*m)
    k+=1
    
  return result

def compute(Y):
  result=[]

  for k in range(0, len(Y)):
    result.append( _compute(Y, k) )
    k+=1
    
  return result

def reverse_compute(C):
  result=[]
  
  
  for m in range(0, len(C)):
    result.append( _reverse_compute(C, m))
  return result