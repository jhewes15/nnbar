#ifndef LARLITE_EVINFO_MCTRUTH_CXX
#define LARLITE_EVINFO_MCTRUTH_CXX

#include "EvInfo_mctruth.h"

namespace larlite {

  bool EvInfo_mctruth::initialize() {

    InitHist();
    return true;
  }
  
  bool EvInfo_mctruth::analyze(storage_manager* storage) {

    std::vector<unsigned int> particles;
    
    auto ev_mcs = storage->get_data<event_mcshower>("mcreco");
    auto ev_mct = storage->get_data<event_mctrack>("mcreco");

    if( !ev_mcs || !ev_mct) {
      std::cout << "Shower/track object is empty :/" << std::endl;
      exit(1);
    }

    for (auto const & mcs : *ev_mcs) {
      std::cout << "SHOWER FOUND!" << std::endl;
      if (CheckParticle(mcs.TrackID(),&particles)) AddToHist(mcs.PdgCode());
      if (CheckParticle(mcs.MotherTrackID(),&particles)) AddToHist(mcs.MotherPdgCode());
      if (CheckParticle(mcs.AncestorTrackID(),&particles)) AddToHist(mcs.AncestorPdgCode());
    }
    for (auto const & mct : *ev_mct) {
      std::cout <<  "TRACK FOUND!" << std::endl;
      if (CheckParticle(mct.TrackID(),&particles)) AddToHist(mct.PdgCode());
      if (CheckParticle(mct.MotherTrackID(),&particles)) AddToHist(mct.MotherPdgCode());
      if (CheckParticle(mct.AncestorTrackID(),&particles)) AddToHist(mct.AncestorPdgCode());
    }
  
    return true;
  }

  bool EvInfo_mctruth::finalize() {

    SaveHist(_fout);
    return true;
  }

}
#endif
