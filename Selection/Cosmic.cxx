#ifndef LARLITE_COSMIC_CXX
#define LARLITE_COSMIC_CXX

#include "Cosmic.h"

namespace larlite {

  bool Cosmic::initialize() {

    //
    // This function is called in the beggining of event loop
    // Do all variable initialization you wish to do here.
    // If you have a histogram to fill in the event loop, for example,
    // here is a good place to create one on the heap (i.e. "new TH1D"). 
    //

    return true;
  }
  
  bool Cosmic::analyze(storage_manager* storage) {
  
    auto ev_mct = storage->get_data<event_mctruth>("generator");
    for(auto const& mct : *ev_mct) {
      int a = 0;
      int b = 0;
      for(auto const& mcp : mct.GetParticles()) {
        if ( mcp.PdgCode() == 111 || mcp.PdgCode() == -111 ) {
          a++;
        } else if ( mcp.PdgCode() == 211 || mcp.PdgCode() == -211 ) {
          b++;
        }
      }
      if ( a + b > 0 ) {
        std::cout << a << " neutral pions, " << b << " charged pions" << std::endl;
      }
    }
    
    return true;
  }

  bool Cosmic::finalize() {

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
