/**
 * \file Cosmic.h
 *
 * \ingroup Selection
 * 
 * \brief Class def header for a class Cosmic
 *
 * @author jhewes15
 */

/** \addtogroup Selection

    @{*/

#ifndef LARLITE_COSMIC_H
#define LARLITE_COSMIC_H

#include "Analysis/ana_base.h"
#include "DataFormat/mctruth.h"

namespace larlite {
  /**
     \class Cosmic
     User custom analysis class made by SHELL_USER_NAME
   */
  class Cosmic : public ana_base{
  
  public:

    /// Default constructor
    Cosmic(){ _name="Cosmic"; _fout=0;}

    /// Default destructor
    virtual ~Cosmic(){}

    /** IMPLEMENT in Cosmic.cc!
        Initialization method to be called before the analysis event loop.
    */ 
    virtual bool initialize();

    /** IMPLEMENT in Cosmic.cc! 
        Analyze a data event-by-event  
    */
    virtual bool analyze(storage_manager* storage);

    /** IMPLEMENT in Cosmic.cc! 
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
