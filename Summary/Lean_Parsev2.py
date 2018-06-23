from urllib.request import Request, urlopen
from lxml import html
from lxml.html.clean import clean_html

class LeanParse():
    """This class takes a url, and returns the content in <p> tags"""

    def __init__(self, url):
        self.url = url

    def content(self):
        header = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/60.0.3112.113 Safari/537.36'}

        req = Request(self.url, headers=header)

        openlink = urlopen(req)
        parsed_page = html.parse(openlink)
        openlink.close()
        extracted_paragraphs = parsed_page.xpath('//p')

        paragraphs = []

        # Convert HTML elements to text
        for i in extracted_paragraphs:
            paragraphs.append(str(i.text_content()))

        all_text = ' '.join(paragraphs[4:])
      
        return all_text
