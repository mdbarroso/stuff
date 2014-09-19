class A(object):
	att1 = 1
	def __init__(self):
		self.att2 = 10
	def foo(self):
		return self.__class__.__name__, 'foo'
	def __repr__(self):
		return 'att1:%d att2:%d' % (self.att1, self.att2)

class B(A):
	def __init__(self):
		super(B, self).__init__()
	def foo(self):
		return B.__name__, 'foo'

class C(A):
	def __init__(self):
		super(C, self).__init__()

class D(B, C):
	def __init__(self):
		super(D, self).__init__()

class E(C, B):
	def __init__(self):
		super(E, self).__init__()

class F(C, B):
	def __init__(self):

		B.__init__(self)
		C.__init__(self)

print A().foo() # prints ?
print B().foo() # prints ?
print C().foo() # prints ?
print D().foo() # prints ?
print E().foo() # prints ?
print F().foo() # prints ?


a1=A()
a2=A()
print a1 # prints ?
print a2 # prints ?
A.att1 += 1
a1.att1 += 1
a1.att2 += 10
print a1 # prints ?
print a2 # prints ?
