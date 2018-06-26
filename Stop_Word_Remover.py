#!/usr/bin/python3.5
import sys
sys.path.insert(0,"/var/www/PageHawk/pagehawk/")
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize

class RemoveStopWords():
    """This class removes stop words from a string of content, and returns a
        word array"""

    def __init__(self, content):
        self.content = content
        self.stopwords = set(stopwords.words('english'))

    def cleaned_list(self):
        text = word_tokenize(self.content)

        cleaned_content = []
        for w in text:
            if w.lower() not in self.stopwords:
                cleaned_content.append(w)

        return cleaned_content
