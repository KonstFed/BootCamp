import time
def fib(n):
  if n == 1 or n==2:
    return 1

  return fib(n-2) + fib(n-1)

start_time = time.time()

n = int(input())
if n == 1 or n == 2:
  print(1)
  exit(0)
f1,f2 = 1,1
f = 0
for i in range(2,n):
  f = f1 + f2
  f1 = f2
  f2 = f
print('Iterative way',f)
print("--- %s seconds ---" % (time.time() - start_time))

st_time = time.time()
print("Recursive way",fib(n))
print("--- %s seconds ---" % (time.time() - st_time))
