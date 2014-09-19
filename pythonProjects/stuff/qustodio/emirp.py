import math
import re
import sys

def is_prime(n):
    if n % 2 == 0 and n > 2: 
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True	

def invertNumber(n):
	strFormat = str(n)
	strFormat = strFormat[::-1]
	return int(strFormat)

def calculateEmirp(n):
	emirp = 0
	for i in range(1, n):
		if is_prime(i):
			reversedNumber = invertNumber(i)
			if is_prime(reversedNumber) and not isPalindromic(i):
				emirp += i
		else:
			pass
	return emirp

def isPalindromic(n):
	strFormat = str(n)
	reversedStr = strFormat[::-1]
	if strFormat == reversedStr:
		return True
	return False

def iterateEmirp():
	if len(sys.argv) < 2:
		print "Usage: python emirp.py <inputDataPath>+"
		return
	for fileName in sys.argv[1:]:
		print fileName
		f = open(fileName, 'r')
		for line in f:
			if line == '\n':
				continue
			readCeilingNumber = re.sub('\n$', '', line)
			print calculateEmirp(int(readCeilingNumber)) 
		f.close()

iterateEmirp()	
