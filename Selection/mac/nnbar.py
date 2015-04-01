import sys

#if len(sys.argv) < 2:
#    msg  = '\n'
#    msg += "Usage 1: %s $INPUT_ROOT_FILE(s)\n" % sys.argv[0]
#    msg += '\n'
#    sys.stderr.write(msg)
#    sys.exit(1)

from larlite import larlite as fmwk

# Create ana_processor instance
my_proc = fmwk.ana_processor()

# Set input root file
for x in xrange(193):
#for x in xrange(1):
  fname = '/uboone/data/users/uboonepro/mcc5.2_iit/v03_04_06/larlite_main/prodcosmics_uboone/528813_{}/larlite_mcinfo.root'.format(x)
  if x != 36:
    my_proc.add_input_file(fname)

# Specify IO mode
my_proc.set_io_mode(fmwk.storage_manager.kREAD)

# Specify output root file name
my_proc.set_ana_output_file("output/event_selection.root");

# Attach an analysis unit ... here we use a base class which does nothing.
# Replace with your analysis unit if you wish.
my_proc.add_process(fmwk.Cosmic())

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
