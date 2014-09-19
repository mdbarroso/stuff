import unittest
from os import listdir

class TestMonkeySong(unittest.TestCase):
	testsToRun = []

	def setUp(self):
		testsToRun = listdir('inputs/')
		print testsToRun

	def TestMusic(self):
		for testCase in testsToRun:
			

if __name__ == '__main__':
    unittest.main()
