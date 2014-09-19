import re
import sys

def teaParty():
	if len(sys.argv) < 2:
		print "Usage: python teaParty.py <inputData>+"
		return
	for fileName in sys.argv[1:]:
		f = open(fileName, 'r')
	
		for line in f:
			if line =='\n':
				continue
			line = re.sub('\n$','',line)
			name = getName(line)
			greeting = getGreeting(line, name['pointer'])
			if not  name['ok']:
				print "Wrong name in: " + line
				continue
			print "Hello " + greeting + " " + name['data'][1]
		f.close()

def getName(line):
	res = {}
	res['ok'] = False
	separator = ' was '
	findPosition = line.find(separator)
	if findPosition == -1:
		separator = ' is a '
		findPosition = line.find(separator)
		if findPosition == -1:
			return res 
	name = line[:findPosition]
	l = name.split(' ')
	if len(l) != 2:
		return res
	res['data'] = l
	res['pointer'] = findPosition + len(separator)
	res['ok'] = True
	return res
	
def getGreeting(line, pointer):
	guestType = line[pointer:]
	return translateGreeting(guestType)

def translateGreeting(guest):
	if guest == 'man':
		return "Mr."
	elif guest == 'woman':
		return "Ms."
	elif 'knight' in guest:
		return "Sir"
	else:
		return ''

teaParty()
	
