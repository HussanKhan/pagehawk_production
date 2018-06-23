import timeit
from Lean_Parsev2 import LeanParse

num_test = input("Number of Runs: ")
cy = timeit.timeit('basic_test2.runtest()', setup='import basic_test2', number=int(num_test))
py = timeit.timeit('basic_testing.runtest()', setup='import basic_testing', number=int(num_test))

print("\n{} Runs Complete!\n".format(num_test))
print(cy, py)
print("C is {}x faster".format(py/cy))