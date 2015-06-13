/**
 * \file EvSel_mcreco.h
 *
 * \ingroup Selection
 * 
 * \brief Class def header for a class EvSel_mcreco
 *
 * @author jhewes15
 */

/** \addtogroup Selection

    @{*/

#ifndef LARLITE_EVSEL_MCRECO_H
#define LARLITE_EVSEL_MCRECO_H

#include "Analysis/ana_base.h"

namespace larlite {
  /**
     \class EvSel_mcreco
     User custom analysis class made by SHELL_USER_NAME
   */
  class EvSel_mcreco : public ana_base{
  
  public:

    /// Default constructor
    EvSel_mcreco(){ _name="EvSel_mcreco"; _fout=0;}

    /// Default destructor
    virtual ~EvSel_mcreco(){}

    /** IMPLEMENT in EvSel_mcreco.cc!
        Initialization method to be called before the analysis event loop.
    */ 
    virtual bool initialize();

    /** IMPLEMENT in EvSel_mcreco.cc! 
        Analyze a data event-by-event  
    */
    virtual bool analyze(storage_manager* storage);

    /** IMPLEMENT in EvSel_mcreco.cc! 
        Finalize method to be called after all events processed.
    */
    virtual bool finalize();

  protected:
    
  };
}
#endif

//**************************************************************************
// 
// For Analysis framework documentation, read Manual.pdf here:
//
// http://microboone-docdb.fnal.gov:8080/cgi-bin/ShowDocument?docid=3183
//
//**************************************************************************

/** @} */ // end of doxygen group 
