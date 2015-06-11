/**
 * \file EvSel_mctruth.h
 *
 * \ingroup Selection
 * 
 * \brief Class def header for a class EvSel_mctruth
 *
 * @author jhewes15
 */

/** \addtogroup Selection

    @{*/

#ifndef LARLITE_EVSEL_MCTRUTH_H
#define LARLITE_EVSEL_MCTRUTH_H

#include "Analysis/ana_base.h"
#include "DataFormat/mcshower.h"
#include "DataFormat/mctrack.h"

namespace larlite {
  /**
     \class EvSel_mctruth
     User custom analysis class made by SHELL_USER_NAME
   */

  class EvSel_mctruth : public ana_base{
  
  public:
    
    EvSel_mctruth(){ _name="EvSel_mctruth"; _fout=0;}
    virtual ~EvSel_mctruth(){}

    virtual bool initialize();
    virtual bool analyze(storage_manager* storage);
    virtual bool finalize();

    int loop_number;
    int candidates;
    
    bool proximity(mcstep first,mcstep second){
      
      double x = first.X() - second.X();
      double y = first.Y() - second.Y();
      double z = first.Z() - second.Z();
      double distance = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
      if(distance < 5) return 1;
      else return 0;
    }
    
    double energy(std::vector<mcshower> showers,std::vector<mctrack> tracks){

      double e = 0;
      for(auto const& shower : showers) e = e + shower.MotherStart().E();
      for(auto const& track : tracks) e = e + track.Start().E();
      return e;
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
      return p;
    }
    
    void select(std::vector<mcshower> showers,std::vector<mctrack> tracks,int* n_o_c){
      
      for(auto const& shower : showers){
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
        if(cut(selected_showers,selected_tracks, n_o_c)==true) return;
      }
    
      for(auto const& track : tracks){
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
        cut(selected_showers,selected_tracks, n_o_c);
      }
    }
    
    bool cut(std::vector<mcshower> showers,std::vector<mctrack> tracks,int* n_o_c){
      bool is_nnbar = 1;
      double e, p;
      unsigned int pi_plus = 0;
      unsigned int pi_minus = 0;
      unsigned int pi_zero = showers.size();
      for(auto const& pion : tracks){
        if(pion.PdgCode() == 211) pi_plus++;
        else if(pion.PdgCode() == -211) pi_minus++;
        else std::cout << "Weird, a selected track is not a charged pion :/" << std::endl;
      }
      unsigned int pions = showers.size() + tracks.size();
      if(pions > 1){
        e = energy(showers,tracks);
        p = momentum(showers,tracks);
        if (!(pi_plus == pi_minus || pi_plus - 1 == pi_minus) || e < 1000 || e > 2000 || p > 300) is_nnbar = 0;
        if(is_nnbar == 1){
          std::cout << "WE HAVE A WINNER!" << std::endl;
          std::cout << pions << " pions - " << pi_plus << " pi+, " << pi_minus << " pi-, " << pi_zero << "pi0" << std::endl;
          std::cout << e << "MeV energy, " << p << "MeV momentum" << std::endl;
          std::cout << "Event vertex: " << showers[0].MotherStart().X() << "x, " << showers[0].MotherStart().Y() << "y, " << showers[0].MotherStart().Z() << "z" << std::endl;
          (*n_o_c)++;
          return true;
        }
      }
      return false;
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
