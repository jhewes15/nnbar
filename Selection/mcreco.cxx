#ifndef LARLITE_MCRECO_CXX
#define LARLITE_MCRECO_CXX

#include "mcreco.h"

namespace larlite {

  bool mcreco::initialize() {

    //
    // This function is called in the beggining of event loop
    // Do all variable initialization you wish to do here.
    // If you have a histogram to fill in the event loop, for example,
    // here is a good place to create one on the heap (i.e. "new TH1D"). 
    //

    return true;
  }
  
  bool mcreco::analyze(storage_manager* storage) {
  
    auto ev_mcs = storage->get_data<event_mcshower>("mcreco");
    auto ev_mct = storage->get_data<event_mctrack>("mcreco");
    
    // Loop over all showers, and grab only the gamma showers
    
    // Loop over all gamma showers, and reconstruct all pi0s
    
    // Loop over all tracks, and grab only the charged pions
    
    // Loop over all start & end points, do a location check
    
    // Construct PDFs of nnbar event??
  
    return true;
  }

  bool mcreco::finalize() {

    // This function is called at the end of event loop.
    // Do all variable finalization you wish to do here.
    // If you need, you can store your ROOT class instance in the output
    // file. You have an access to the output file through "_fout" pointer.
    //
    // Say you made a histogram pointer h1 to store. You can do this:
    //
    // if(_fout) { _fout->cd(); h1->Write(); }
    //
    // else 
    //   print(MSG::ERROR,__FUNCTION__,"Did not find an output file pointer!!! File not opened?");
    //
  
    return true;
  }

}
#endif
