/**
 * \file mctruth.h
 *
 * \ingroup Selection
 * 
 * \brief Class def header for a class mctruth
 *
 * @author jhewes15
 */

/** \addtogroup Selection

    @{*/

#ifndef LARLITE_MCTRUTH_H
#define LARLITE_MCTRUTH_H

#include "Analysis/ana_base.h"
#include "DataFormat/mcshower.h"
#include "DataFormat/mctrack.h"

namespace larlite {
  /**
     \class mctruth
     User custom analysis class made by SHELL_USER_NAME
   */
  class mctruth : public ana_base{
  
  public:

    /// Default constructor
    mctruth(){ _name="mctruth"; _fout=0;}

    /// Default destructor
    virtual ~mctruth(){}

    /** IMPLEMENT in mctruth.cc!
        Initialization method to be called before the analysis event loop.
    */ 
    virtual bool initialize();

    /** IMPLEMENT in mctruth.cc! 
        Analyze a data event-by-event  
    */
    virtual bool analyze(storage_manager* storage);

    /** IMPLEMENT in mctruth.cc! 
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
