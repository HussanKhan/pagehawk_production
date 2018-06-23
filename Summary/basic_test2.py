from Lean_Parsev2 import LeanParse
import keyinfo
import time
lp = LeanParse('https://www.theatlantic.com/magazine/archive/2017/06/lolas-story/524490/')
# test = input('URL: ')
# lp = LeanParse(test)
page_content = lp.content()
print('Running Test in C...')
def runtest():
    text = keyinfo.wordense(page_content)

    # text2 = text.decode()
    # print('------------')
    # print(text)
    # print('------------')
    return text;

# runtest()
