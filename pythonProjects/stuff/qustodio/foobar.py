
def foobar():
	for i in range(1, 101):
		print str(i) + ": ",
		if ( (i % 3) == 0 and (i % 5) == 0 ):
			print "foobar"
		else:
			if( i % 3 == 0 ):
				print "foo"
			elif ( i % 5 == 0 ):
				print "bar"
			else:
				print ""

foobar()
