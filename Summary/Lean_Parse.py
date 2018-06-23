import bs4 as bs
from urllib.request import Request, urlopen

class LeanParse():
    """This class takes a url, and returns the content in <p> tags"""

    def __init__(self, url):
        self.url = url

    def content(self):
        header = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/60.0.3112.113 Safari/537.36'}
        req = Request(self.url, headers=header)
        page = urlopen(req)
        content = page.read()
        page.close()
        parsed = bs.BeautifulSoup(content, 'html.parser')
        paragraphs = parsed.findAll('p')

        text_list = []
        for p in paragraphs:
            text_list.append(p.getText())

        content = ' '.join(text_list)

        return content
