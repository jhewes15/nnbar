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
    
    bool proximity(mcstep first,mcstep second){
      
      double x = first.X() - second.X();
      double y = first.Y() - second.Y();
      double z = first.Z() - second.Z();
      double distance = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
      if(distance < 5) return 1;
      else return 0;
    }
    
    bool energy(std::vector<mcshower> showers,std::vector<mctrack> tracks){
      
      double e = 0;
      for(auto const& shower : showers) e = e + shower.MotherStart().E();
      for(auto const& track : tracks) e = e + track.Start().E();
      if(e > 2 || e < 1) return 0;
      else return 1;
    }
    
    bool momentum(std::vector<mcshower> showers,std::vector<mctrack> tracks){
      
      double p_x = 0;
      double p_y = 0;
      double p_z = 0;
      for(auto const& shower : showers){
        p_x = p_x + shower.MotherStart().Px();
        p_y = p_y + shower.MotherStart().Py();
        p_z = p_z + shower.MotherStart().Pz();
      }
      for(auto const& track : tracks){
        p_x = p_x + track.Start().Px();
        p_y = p_y + track.Start().Py();
        p_z = p_z + track.Start().Pz();
      }
      double p = sqrt(pow(p_x,2) + pow(p_y,2) + pow(p_z,2));
      if(p < 0.1) return 0;
      else return 1;
    }
    
    void select(std::vector<mcshower> showers,std::vector<mctrack> tracks){
      
      for(auto const& shower : showers){
        int is_nnbar = 1;
        bool test;
        std::vector<mcshower> selected_showers;
        std::vector<mctrack> selected_tracks;
        for(auto const& test_shower : showers){
          test = proximity(shower.MotherStart(),test_shower.MotherStart());
          if(test) selected_showers.push_back(test_shower);
        }
        for(auto const& test_track : tracks){
          test = proximity(shower.MotherStart(),test_track.Start());
          if(test) selected_tracks.push_back(test_track);
        }
        unsigned int pi_plus = 0;
        unsigned int pi_minus = 0;
        for(auto const& pion : selected_tracks){
          if(pion.PdgCode() == 211) pi_plus++;
          else if(pion.PdgCode() == -211) pi_minus++;
          else std::cout << "Weird, a selected track is not a charged pion :/" << std::endl;
        }
        if(pi_plus != pi_minus) is_nnbar = 0;
        test = energy(selected_showers,selected_tracks);
        if(!test) is_nnbar = 0;
        test = momentum(selected_showers,selected_tracks);
        if(!test) is_nnbar = 0;
        if(is_nnbar == 1) std::cout << "WE HAVE A WINNER!" << std::endl;
      }
    
      for(auto const& track : tracks){
        int is_nnbar = 1;
        bool test;
        std::vector<mcshower> selected_showers;
        std::vector<mctrack> selected_tracks;
        for(auto const& test_shower : showers){
          test = proximity(track.Start(),test_shower.MotherStart());
          if(test) selected_showers.push_back(test_shower);
        }
        for(auto const& test_track : tracks){
          test = proximity(track.Start(),test_track.Start());
          if(test) selected_tracks.push_back(test_track);
        }
        unsigned int pi_plus = 0;
        unsigned int pi_minus = 0;
        for(auto const& pion : selected_tracks){
          if(pion.PdgCode() == 211) pi_plus++;
          else if(pion.PdgCode() == -211) pi_minus++;
          else std::cout << "Weird, a selected track is not a charged pion :/" << std::endl;
        }
        if(pi_plus != pi_minus) is_nnbar = 0;
        test = energy(selected_showers,selected_tracks);
        if(!test) is_nnbar = 0;
        test = momentum(selected_showers,selected_tracks);
        if(!test) is_nnbar = 0;
        if(is_nnbar == 1) std::cout << "WE HAVE A WINNER!" << std::endl;
      }
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
