from Lean_Parsev2 import LeanParse
from summerizer import Summerizer
from ContentStats import ContentParse
import time


lp = LeanParse('https://www.theatlantic.com/magazine/archive/2017/06/lolas-story/524490/')
page_content = lp.content()
print('Running Test in Python...')
def runtest():
 
    sm = Summerizer(page_content)

    summery = sm.summary(4)

    # print(summery)
    return summery;
# end = time.time()
# print(end - start)

# start = time.time()
# runtest()
# end = time.time()
# print(end - start)