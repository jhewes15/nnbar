import sys

from ROOT import gSystem
from ROOT import larlite as fmwk
from ROOT import ertool
ertool.Manager

# Create ana_processor instance
my_proc = fmwk.ana_processor()

# Set input root file

for x in xrange(193):
  if x != 36:
    fname = '/uboone/data/users/uboonepro/mcc5.2_iit/v03_04_06/larlite_main/prodcosmics_uboone/528813_{}/larlite_mcinfo.root'.format(x)
    my_proc.add_input_file(fname)

# Specify IO mode
my_proc.set_io_mode(fmwk.storage_manager.kREAD)

# Specify output root file name
my_proc.set_ana_output_file("event_info.root");

# Attach an analysis unit ... here we use a base class which does nothing.
# Replace with your analysis unit if you wish.

first_ana = fmwk.EvInfo_mctruth()
my_proc.add_process(first_ana)

print
print  "Finished configuring ana_processor. Start event loop!"
print

# Let's run it.
my_proc.run();

# done!
print
print "Finished running ana_processor event loop!"
print

sys.exit(0)
