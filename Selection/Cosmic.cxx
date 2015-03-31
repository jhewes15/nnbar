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
      int pdg = mcs.PdgCode();
      if(pdg == 22){
        pdg = mcs.MotherPdgCode();
        if(pdg == 111) p++;
      }
    }
    
    for(auto const& mct: *ev_mct){
      int pdg = mct.PdgCode();
      if(pdg == 211||pdg == -211) p++;
    }
    
    if(p > 2) std::cout << "We have a winner!" << std::endl;
    
    /*
    int select = 1;
    std::vector<mcpart> pions;

    for(auto const& mct : *ev_mct) {

      for(auto const& mcp : mct.GetParticles())
        if ( mcp.PdgCode() == 111 || mcp.PdgCode() == -111 || mcp.PdgCode() == 211 || mcp.PdgCode() == -211 )
          pions.push_back(mcp);

    }
    
    if ( pions.size() < 2 ) select = 0;
    else std::cout << pions.size() << " pions detected!" << std::endl;{
      
      for ( int i = 1; i < pions.size(); i++ ) {
        for ( int j = 0; j < i; j++ ) {
          mcstep one = pions[i].Trajectory()[0];
          mcstep two = pions[j].Trajectory()[0];
          
          double distance = sqrt(pow(one.X() - two.X(),2) + pow(one.Y() - two.Y(),2) + pow(one.Z() - two.Z(),2));
          std::cout << distance << std::endl;
          
        }
      }
      
    }*/
    
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
