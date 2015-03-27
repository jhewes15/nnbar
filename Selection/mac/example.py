import sys
from ROOT import gSystem
gSystem.Load("libnnbar_Selection")
from ROOT import sample

try:

    print "PyROOT recognized your class %s" % str(sample)

except NameError:

    print "Failed importing Selection..."

sys.exit(0)

