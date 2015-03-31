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
#include "DataFormat/mcshower.h"
#include "DataFormat/mctrack.h"

namespace larlite {
  /**
     \class Cosmic
     User custom analysis class made by SHELL_USER_NAME
   */
  class Cosmic : public ana_base{
  
  public:
    
    Cosmic(){ _name="Cosmic"; _fout=0;}
    virtual ~Cosmic(){}

    virtual bool initialize();
    virtual bool analyze(storage_manager* storage);
    virtual bool finalize();
    
    bool proximity(mcstep first, mcstep second){
      
      double x = first.X() - second.X();
      double y = first.Y() - second.Y();
      double z = first.Z() - second.Z();
      double distance = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
      if(distance < 5) return 1;
      else return 0;
    }

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
