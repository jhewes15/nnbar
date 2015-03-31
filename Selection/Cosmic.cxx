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

    std::vector<int> mothers;
    
    int p = 0;
    
    auto ev_mcs = storage->get_data<event_mcshower>("mcreco");
    auto ev_mct = storage->get_data<event_mctrack>("mcreco");
    
    if(!ev_mcs){
      std::cout << "MCShower pointer invalid! Exiting..." << std::endl;
      exit(1);
    }
    else if(!ev_mct){
      std::cout << "MCTrack pointer invalid! Exiting..." << std::endl;
      exit(1);
    }
    
    for(auto const& mcs : *ev_mcs){
      if(mcs.PdgCode() == 22 && mcs.MotherPdgCode() == 111){
        int seen = 0;
        for(auto const& mother: mothers){
          if(mcs.MotherTrackID() == mother) seen = 1;
        }
        if(seen == 0){
          mothers.push_back(mcs.MotherTrackID());
          p++;
        }
      }
    }
    
    for(auto const& mct: *ev_mct){
      int pdg = mct.PdgCode();
      if(pdg == 211||pdg == -211) p++;
    }
    
    if(p > 2) std::cout << "We have a winner!" << std::endl;
    
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
