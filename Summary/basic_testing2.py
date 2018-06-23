from Lean_Parse import LeanParse
from summerizer import Summerizer

lp = LeanParse('https://arstechnica.com/science/2018/05/block-5-rocket-launch-marks-the-end-of-the-beginning-for-spacex/')

page_content = lp.content()

sm = Summerizer(page_content)

print(sm.summary(5))
