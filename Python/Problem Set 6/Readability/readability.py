import cs50

st = cs50.get_string("Text: ")
l = 0
w = 1
s = 0

for i in range(len(st)):
    if (st[i].isalnum()):
        l += 1
    if (st[i].isspace()):
        w += 1
    if (st[i] == '.' or st[i] == '!' or st[i] == '?'):
        s += 1
        
L = 100 * l / w
S = 100 * s / w
index = 0.0588 * L - 0.296 * S - 15.8

if (index > 16):
    print("Grade 16+")
elif (index < 1):
    print("Before Grade 1")
else:
    print("Grade "+str((round(index))))
