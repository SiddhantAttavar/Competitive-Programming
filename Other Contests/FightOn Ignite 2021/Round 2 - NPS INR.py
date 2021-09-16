# NPS INR-R2
# Q1
from math import ceil as q
_,e=input,len
w,p=_('Enter string: ').split(),int(_('Enter percentage: '))/100
print(*(c[:q(e(c)*p)]+' '+c[q(e(c)*p):] for c in w))

# Q2
l=n=u=s=0
p=[]
for w in _('Enter passwords: ').split(' , '):
    for c in w:
        l+=c.islower()
        n+=c.isnumeric()
        u+=c.isupper()
        s+=c in'!@#$%&*?'
    if (l>4)+(n>0)+(u>1)+(8<e(w)<21)+(s>0)==5:p+=[w]
print('Correct passwords: ',' , '.join(p))