import nltk
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize, sent_tokenize
from Stop_Word_Remover import RemoveStopWords
import time

class Summerizer():
    """This class takes in text, and calling the summery method provides a summery"""

    def __init__(self, text):
        self.text = text

    def summary(self, length):
        # start_time = time.time()
        sentences = sent_tokenize(self.text)

        # First index sometimes has author name and date information
        sentences = sentences[1:]

        filtered_example = RemoveStopWords(self.text).cleaned_list()

        word_freq = nltk.FreqDist(filtered_example)
        most_common = {}
        count = 15
        for words in word_freq.most_common(15):
            punc = [".", ",", "’", '”']
            if words[0] not in punc:
                most_common[str(words[0]).lower()] = count
                count = count - 1

        relevent_sent = []
        sent_value = {}
        # Sentence scoring system
        scores = []
        for sent in sentences:
            value = 0
            word_list = sent.split(' ')
            for word in word_list:
                if most_common.get(word.lower()):
                    value += most_common[word.lower()]
            if value > 0:
                sent_value[str(sent)] = value
                scores.append(value)

        summary = []

        scores.sort()

        low = 3*(len(scores)/10)

        for key, value in sent_value.items():
            if len(summary) == length:
                break
            elif int(value) in scores[int(low):] and key not in summary:
                summary.append(key)

        ordered = []
        for sent in summary:
            ordered.append(sentences.index(sent))
        ordered.sort()
        ordered_summary = []
        for n in ordered:
            ordered_summary.append(sentences[n])

        final_summery = ' '.join(ordered_summary)
        # print('\n')
        # print("Sum --- %s seconds ---" % (time.time() - start_time))
        # print('\n')
        return final_summery
