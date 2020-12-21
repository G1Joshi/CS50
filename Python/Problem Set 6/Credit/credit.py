import cs50

m = 0
n = 0
c = 0
s = 0
t = 0
cc_number = cs50.get_int("Number: ")

while cc_number > 0:
    n = m
    m = cc_number % 10
    if c % 2 == 0:
        t += m
    else:
        multiple = 2 * m
        s += (multiple // 10) + (multiple % 10)
    cc_number //= 10
    c += 1
    
val = (t + s) % 10 == 0
fs = (m * 10) + n

if m == 4 and c >= 13 and c <= 16 and val:
    print("VISA")
elif fs >= 51 and fs <= 55 and c == 16 and val:
    print("MASTERCARD")
elif (fs == 34 or fs == 37) and c == 15 and val:
    print("AMEX")
else:
    print("INVALID")
