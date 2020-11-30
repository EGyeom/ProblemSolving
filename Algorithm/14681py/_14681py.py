
a, b = input().split()
a = int(a)
b = int(b)

if(b-45 < 0):
    b= 60 - 45 + b
    a= a-1
    if a < 0:
        a = 24 + a
else:
    b = b - 45

print(f'{a} {b}')