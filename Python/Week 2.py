'''
1.A positive integer m can be expresseed as the sum of three squares if it is of the form p + q + r where p, q, r ≥ 0, and p, q, r are all perfect squares. For instance, 2 can be written as 0+1+1 but 7 cannot be expressed as the sum of three squares. The first numbers that cannot be expressed as the sum of three squares are 7, 15, 23, 28, 31, 39, 47, 55, 60, 63, 71, … (see Legendre's three-square theorem).
Write a Python function threesquares(m) that takes an integer m as input and returns True if m can be expressed as the sum of three squares and False otherwise. (If m is not positive, your function should return False.)
2.Write a function repfree(s) that takes as input a string s and checks whether any character appears more than once. The function should return True if there are no repetitions and False otherwise.
3.A list of numbers is said to be a hill if it consists of an ascending sequence followed by a descending sequence, where each of the sequences is of length at least two. Similarly, a list of numbers is said to be a valley if it consists of an descending sequence followed by an ascending sequence. You can assume that consecutive numbers in the input sequence are always different from each other.
Write a Python function hillvalley(l) that takes a list l of integers and returns True if it is a hill or a valley, and False otherwise.
'''

def threesquares(m):
  if(m<0):
    return False
  else:
      i=0
      while(4**i<=m):
          for n in range(m//(4**i)):
              if(4**i)*(8*n+7)==m:
                  return False
          i=i+1 
      return True      
          
def repfree(s):
  for i in range(len(s)-1):
    if(s[i] in s[i+1:]):
      return False
  return True 

def hillvalley(l):
    if(len(l)==0):
      return False
    if(l[0]==max(l)):
        i=0
        while(i<len(l)-1 and l[i]>l[i+1]):
            i=i+1
        if(i==len(l)-1):
          return False
        while(i<len(l)-1):
            if(l[i]>l[i+1]):
                return False
            else:
                i=i+1
        return True
    else:
        i=0
        while(i<len(l)-1 and l[i]<l[i+1]):
            i=i+1
        if(i==len(l)-1):
          return False    
        while(i<len(l)-1):
            if(l[i]<l[i+1]):
                return False
            else:
                i=i+1
        return True
import ast

def tolist(inp):
  inp = "["+inp+"]"
  inp = ast.literal_eval(inp)
  return (inp[0],inp[1])

def parse(inp):
  inp = ast.literal_eval(inp)
  return (inp)

fncall = input()
lparen = fncall.find("(")
rparen = fncall.rfind(")")
fname = fncall[:lparen]
farg = fncall[lparen+1:rparen]

if fname == "threesquares":
   arg = parse(farg)
   print(threesquares(arg))
elif fname == "repfree":
   arg = parse(farg)
   print(repfree(arg))
elif fname == "hillvalley":
   arg = parse(farg)
   print(hillvalley(arg))
else:
   print("Function", fname, "unknown")