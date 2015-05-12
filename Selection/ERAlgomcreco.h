/**
 * \file ERAlgomcreco.h
 *
 * \ingroup Selection
 * 
 * \brief Class def header for a class ERAlgomcreco
 *
 * @author jhewes15
 */

/** \addtogroup Selection

    @{*/

#ifndef ERTOOL_ERALGOMCRECO_H
#define ERTOOL_ERALGOMCRECO_H

#include "ERTool/Base/AlgoBase.h"

namespace ertool {

  /**
     \class ERAlgomcreco
     User custom Algorithm class made by kazuhiro
   */
  class ERAlgomcreco : public AlgoBase {
  
  public:

    /// Default constructor
    ERAlgomcreco();

    /// Default destructor
    virtual ~ERAlgomcreco(){};

    /// Reset function
    virtual void Reset();

    /// Function to evaluate input showers and determine a score
    virtual ParticleSet Reconstruct(const EventData &data);

  };
}
#endif

/** @} */ // end of doxygen group 
