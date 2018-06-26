#!/usr/bin/python3.5
import sys
sys.path.insert(0,"/var/www/PageHawk/pagehawk")
import nltk
from nltk.corpus import stopwords
from Stop_Word_Remover import RemoveStopWords
from nltk.tokenize import word_tokenize, sent_tokenize
import c_wordcount
import c_sentcount
import keyinfo

class Text_Anna():
	"""This class takes in text, and returns common text analytics"""

	def __init__(self, text):
		self.text = text
		self.wordsFound = 0
		self.total_sylb = 0
		self.total_sentences = 0

	def word_count(self):
		# Returns wordcount of text
		self.wordsFound = c_wordcount.wordcounter(self.text)
		return self.wordsFound

	def sentence_count(self):
		# Returns sentence count of text
		self.total_sentences = c_sentcount.sentcounter(self.text)
		return self.total_sentences

	def keyword_density(self):
		# Returns array of top 10 most used words (Excludes stop word)
		filtered_example = RemoveStopWords(self.text).cleaned_list()
		word_freq = nltk.FreqDist(filtered_example)
		most_common = []
		for words in word_freq.most_common(15):
			punc = [".", ",", "’", '"', "(", ")", "``", "''", ":", '“', '”']
			if words[0] not in punc:
				most_common.append((str(words[0]) + ", " + str(words[1])))
		return most_common

	def read_time(self):
    	# Read time based on 200 words per minute 
		if (self.wordsFound != 0):
			return str(int((self.wordsFound/200) + 0.5)) + " min"
		else:
			self.word_count()
			if self.wordsFound == 0:
				return str("< 0 min")
			else:
				return str(int((self.wordsFound)/200) + 0.5) + " min"
			

	def summary(self):
		return keyinfo.wordense(self.text)

	def sylb_counter(self, word):
		counter = 0
		vowel = ['a', 'e', 'i', 'o', 'u', 'y']
		word_letters = list(word)
		for letter in word_letters:
			if letter in vowel:
				counter += 1
			else:
				pass

		return counter

	def reading_ease(self):
		if self.total_sylb == 0:
			for word in self.text:
				self.total_sylb = self.total_sylb + self.sylb_counter(word)

		if (self.wordsFound == 0):
			self.word_count()
		if (self.total_sentences == 0):
			self.sentence_count()

		if self.wordsFound != 0 and self.total_sentences != 0:
			# Flesch equation
			self.total_sylb = int((self.total_sylb/10)*8.3)
			wordosents = float((self.wordsFound)/(self.total_sentences))
			syboword = float((self.total_sylb)/(self.wordsFound))

			score = int(float(206.835) - (float(1.015)*wordosents) - (float(84.6)*(syboword)))

			if score in range(0, 31):
				return "College graduate - {}".format(score)
			elif score in range(30, 51):
				return "College - {}".format(score)
			elif score in range(50, 61):
				return "10th to 12th grade - {}".format(score)
			elif score in range(60, 71):
				return "8th & 9th grade - {}".format(score)
			elif score in range(70, 81):
				return "7th grade - {}".format(score)
			elif score in range(80, 91):
				return "6th grade - {}".format(score)
			elif score in range(90, 101):
				return "5th grade - {}".format(score)
		else:
			return "No Score"


