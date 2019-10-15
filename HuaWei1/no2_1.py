#!/usr/bin/env python
# -*- coding:utf-8 -*-

def main():
  while(True):
    n = int(input())
    res = {}
    strg = ""
    flag = True
    for i in range(n):
      strg = input()
      if "=" not in strg: continue
      temp = strg.split("=")
      if len(temp) < 2: continue
      left = temp[0]
      right = temp[1]
      right_l = []
      right_l = right.split("+")
      val = 0
      s = ""
      for ele in right_l:
        s = ele.replace(' ','')
        if s.isdigit(): break
        if s in res: val += res[s]
        else:
          print("NA")
          flag = False
      k = left.replace(' ','')
      if val == 0 and s.isdigit(): val = int(s)
      if i == n-1 and flag: print(val)
      res[k] = val

if __name__ == '__main__':
  main()