import re
from math import pow, exp
from os import listdir
import sys

def monkeySong():
	if len(sys.argv) < 2:
		print "Usage: python monkeySong.py <inputDataPath>+"
	for fileName in sys.argv[1:]:
		compiledPattern = re.compile('.*test[0-9]*.txt')
		
		if not compiledPattern.match(fileName):
			continue
		f = open(fileName, 'r')
		inputDict = getInputData(f)
		readyData = getOrderedData(inputDict)
		for i in range(0, inputDict['hits']):
			print re.sub('\n$','',readyData[i]['songInfo'][1])

def calculateMonkeyAffinity(views, theoViews):
	qi =  float(views)/theoViews
	return qi

def calculatePosition(l, val):
	for i in range(0, len(l)):
		if val > float(l[i]['affinity']):
			return i
	return len(l)

def getOrderedData(inputDict):
	orderedList = []
	songNumber = 0
	for songInfo in inputDict['songInfo']:
		if not validateRow(songInfo) or not validateViews(int(songInfo[0])):
			continue
		else:
			songMonkeyAffinity = calculateMonkeyAffinity(int(songInfo[0]), inputDict['numberOfSongs'] - songNumber)
			position = calculatePosition(orderedList,songMonkeyAffinity)
			completeSongInfo = {'songInfo': songInfo, 'affinity': songMonkeyAffinity}
			orderedList.insert(position, completeSongInfo)
		songNumber += 1
	return orderedList

def validateRow(pair):
	if len(pair) == 2:
		return True
	else:
		return False

def validateString(string):
	if len(re.search('[a-z_0-9]*', string) > 0):
		return True
	else:
		return False

def validateViews(views):
	if views < pow(10,12):
		return True
	else:
		return False

def validateConfigData(numberOfViews, hits):
	if numberOfViews < 50000 and numberOfViews > 1 and hits < numberOfViews and hits > 1:
		return True
	else:
		return False
	
def getInputData(f):
	first = True 
	data = {}
	data['songInfo'] = []
	for line in f:
		row = line.split(' ')
		if first:
			first = False
			if validateRow(row) and validateConfigData(int(line.split(' ')[0]), int(line.split(' ')[1])): 
				data['numberOfSongs'] = int(line.split(' ')[0])  
				data['hits'] = int(line.split(' ')[1])
			else:
				print "Wrong input data!!!"
				f.close()
				return data
		else:
			data['songInfo'].append(line.split(' '))
	f.close()
	return data

monkeySong()
