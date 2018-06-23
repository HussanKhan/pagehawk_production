class ContentParse():
    """This class returns common statistics about text"""

    def __init__(self, content):
        self.content = content

    def wordcount(self):
        return len(self.content.split(' '))

    def keyword_density(self):
        return None

    def summery(self):
        return None
