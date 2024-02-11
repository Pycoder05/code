'''
1.Define a Python function remdup(l) that takes a nonempty list of integers l and removes all duplicates in l, keeping only the first occurrence of each number.
2.Write a Python function sumsquare(l) that takes a nonempty list of integers and returns a list [odd,even], where odd is the sum of squares all the odd numbers in l and even is the sum of squares of all the even numbers in l.
3.A two dimensional matrix can be represented in Python row-wise, as a list of lists: each inner list represents one row of the matrix.
'''
def transpose(m):
    return [list(row) for row in zip(*m)]
def sumsquare(l):
    odd_sum = sum(x**2 for x in l if x % 2 != 0)
    even_sum = sum(x**2 for x in l if x % 2 == 0)
    return [odd_sum, even_sum]
def remdup(l):
    return list(dict.fromkeys(l))
  