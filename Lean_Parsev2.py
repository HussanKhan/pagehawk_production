from urllib.request import Request, urlopen
from lxml import html
from lxml.html.clean import clean_html
import time
import socket

class LeanParse():
    """This class takes a url, and returns the content in <p> tags"""

    def __init__(self, url):
        self.url = url

    def content(self):
        header = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/60.0.3112.113 Safari/537.36'}

        s_time = time.time()
        
        try: 
            req = Request(self.url, headers=header)
        except Exception:
            return "UNABLE TO GET URL"

        try: 
            openlink = urlopen(req, timeout=3.0)
        except Exception:
            return "UNABLE TO GET URL"
            
        load_time = (time.time() - s_time)

        parsed_page = html.parse(openlink)
        openlink.close()

        paragraphs = []
        headings = []
        links = []

        extracted_paragraphs = parsed_page.xpath('//p')
        # Convert HTML elements to text
        for i in extracted_paragraphs:
            paragraphs.append(str(i.text_content()))

        extracted_h1 = parsed_page.xpath('//h1')
        for i in extracted_h1:
            headings.append(str(i.text_content()))

        extracted_h2 = parsed_page.xpath('//h2')
        for i in extracted_h2:
            headings.append(str(i.text_content()))

        extracted_h3 = parsed_page.xpath('//h3')
        for i in extracted_h3:
            headings.append(str(i.text_content()))

        extracted_links = parsed_page.xpath('//p//a')
        for i in extracted_links:
            temp = i.get("href")
            if "http" in str(temp):
                links.append(temp)

        all_text = ' '.join(paragraphs[2:])

        final_data = {"text": all_text, "links": links, "headings": headings, "load_time": load_time}
        return final_data


