#ifndef ERTOOL_ERALGOMCRECO_CXX
#define ERTOOL_ERALGOMCRECO_CXX

#include "ERAlgomcreco.h"

namespace ertool {

  ERAlgomcreco::ERAlgomcreco() : AlgoBase()
  {
    _name     = "ERAlgomcreco";
  }

  void ERAlgomcreco::Reset()
  {}

  ParticleSet ERAlgomcreco::Reconstruct(const EventData &data)
  {
    //for(auto const& track : data.Particle())
    //{
    //  
    //}
    std::cout << "HEY YEAH THIS IS WORKING YO" << std::endl;
    return ParticleSet();
  }

}

#endif
