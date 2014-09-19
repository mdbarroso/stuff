import re
import pycurl
import cStringIO
from bs4 import BeautifulSoup
import sys

def crawler():
	if len(sys.argv) < 2:
		print "Usage: python crawler.py <inputData>+"
		return
	for fileName in sys.argv[1:]:
		f = open('inputs/testCrawler.txt')
		for line in f:
			if line == "\n":
				continue
			line = re.sub('\n$','', line)
			contents = getHTTPData(line)
			soup = BeautifulSoup(contents)
			try:
				print "\'" + line + "\' \'" + soup.title.string + "\'"
			except AttributeError as e:
				print "\'NO TITLE IN THIS HTML!\'" 
		f.close()

def getHTTPData(url):
	c = pycurl.Curl()
	buf = cStringIO.StringIO()
	c.setopt(pycurl.URL, url)
	c.setopt(c.WRITEFUNCTION, buf.write)
	c.setopt(pycurl.FOLLOWLOCATION, 1)
	c.setopt(pycurl.MAXREDIRS, 5)
	c.setopt(pycurl.SSL_VERIFYPEER, 0)
        c.setopt(pycurl.SSL_VERIFYHOST, 0)
	c.perform()
	contents = buf.getvalue()
	buf.close()
	return contents

crawler()
