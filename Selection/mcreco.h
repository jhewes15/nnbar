/**
 * \file mcreco.h
 *
 * \ingroup Selection
 * 
 * \brief Class def header for a class mcreco
 *
 * @author jhewes15
 */

/** \addtogroup Selection

    @{*/

#ifndef LARLITE_MCRECO_H
#define LARLITE_MCRECO_H

#include "Analysis/ana_base.h"
#include "DataFormat/mcshower.h"
#include "DataFormat/mctrack.h"

namespace larlite {
  /**
     \class mcreco
     User custom analysis class made by SHELL_USER_NAME
   */
  class mcreco : public ana_base{
  
  public:

    /// Default constructor
    mcreco(){ _name="mcreco"; _fout=0;}

    /// Default destructor
    virtual ~mcreco(){}

    /** IMPLEMENT in mcreco.cc!
        Initialization method to be called before the analysis event loop.
    */ 
    virtual bool initialize();

    /** IMPLEMENT in mcreco.cc! 
        Analyze a data event-by-event  
    */
    virtual bool analyze(storage_manager* storage);

    /** IMPLEMENT in mcreco.cc! 
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
