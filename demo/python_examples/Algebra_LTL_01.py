from chasecorebnd import *

x1 = Variable(Integer(), Name('x1'), generic)
x2 = Variable(Integer(), Name('x2'), generic)
y2 = Variable(Integer(), Name('y2'), generic)
y1 = Variable(Integer(), Name('y1'), generic)

zero = IntegerValue(0)

A1 = Always(Prop(GE(Id(x1), zero)))
G1 = Always(Prop(GE(Id(y1), zero)))
A2 = Always(Prop(GE(Id(x2), zero)))
G2 = Always(Prop(GE(Id(y2), zero)))

C1 = Contract('C1')
C1.addDeclaration(x1)
C1.addDeclaration(y1)

C2 = Contract('C2')
C2.addDeclaration(x2)
C2.addDeclaration(y2)

C1.addAssumptions(semantic_domain.logic, A1)
C2.addAssumptions(semantic_domain.logic, A2)
C1.addGuarantees(semantic_domain.logic, G1)
C2.addGuarantees(semantic_domain.logic, G2)

Contract.saturate(C1)
print(C1.getString())

Contract.saturate(C2)
print(C2.getString())

map = {'y1': 'x2'}
C = Contract.composition(C1, C2, map)
print(C.getString())
