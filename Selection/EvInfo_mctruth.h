/**
 * \file EvInfo_mctruth.h
 *
 * \ingroup Selection
 * 
 * \brief Class def header for a class EvInfo_mctruth
 *
 * @author jhewes15
 */

/** \addtogroup Selection

    @{*/

#ifndef LARLITE_EVINFO_MCTRUTH_H
#define LARLITE_EVINFO_MCTRUTH_H

#include "Analysis/ana_base.h"
#include "DataFormat/mcshower.h"
#include "DataFormat/mctrack.h"
#include <TH1.h>

namespace larlite {
  /**
     \class EvInfo_mctruth
     User custom analysis class made by SHELL_USER_NAME
   */
  class EvInfo_mctruth : public ana_base{
  
  public:
    
    TH1I* PdgBreakdown;

    EvInfo_mctruth(){ _name="EvInfo_mctruth"; _fout=0;}
    virtual ~EvInfo_mctruth(){}

    virtual bool initialize();
    virtual bool analyze(storage_manager* storage);
    virtual bool finalize();
    
    bool CheckParticle(unsigned int track_id, std::vector<unsigned int> particles) {
      bool seen = false;
      for (auto const & particle : particles) {
        if (particle == track_id) {
          seen = true;
          break;
        }
      }
      if (seen == false) {
        particles.push_back(track_id);
        return true;
      }
      else {
        return false;
      }
    }
    
    void InitHist() {
      PdgBreakdown = new TH1I("PdgBreakdown","PDG breakdown",12,0,12);
      PdgBreakdown->SetStats(0);
      PdgBreakdown->GetXaxis()->SetLabelSize(0.1);
      PdgBreakdown->GetYaxis()->SetLabelSize(0.07);
      PdgBreakdown->GetXaxis()->SetBinLabel(1,"#pi^{0}");
      PdgBreakdown->GetXaxis()->SetBinLabel(2,"#pi^{+}");
      PdgBreakdown->GetXaxis()->SetBinLabel(3,"#pi^{-}");
      PdgBreakdown->GetXaxis()->SetBinLabel(4,"#gamma");
      PdgBreakdown->GetXaxis()->SetBinLabel(5,"p");
      PdgBreakdown->GetXaxis()->SetBinLabel(6,"n");
      PdgBreakdown->GetXaxis()->SetBinLabel(7,"e^{-}");
      PdgBreakdown->GetXaxis()->SetBinLabel(8,"e^{+}");
      PdgBreakdown->GetXaxis()->SetBinLabel(9,"#mu^{-}");
      PdgBreakdown->GetXaxis()->SetBinLabel(10,"#mu^{+}");
      PdgBreakdown->GetXaxis()->SetBinLabel(11,"K^{+}");
      PdgBreakdown->GetXaxis()->SetBinLabel(12,"#omega");
    }
    
    void AddToHist(int i) {
      switch(i) {
        case 111: // pi0
          PdgBreakdown->AddBinContent(1);
          break;
        case 211: // pi+
          PdgBreakdown->AddBinContent(2);
          break;
        case -211: // pi-
          PdgBreakdown->AddBinContent(3);
          break;
        case 22: // gamma
          PdgBreakdown->AddBinContent(4);
          break;
        case 2212: // proton
          PdgBreakdown->AddBinContent(5);
          break;
        case 2112: // neutron
          PdgBreakdown->AddBinContent(6);
          break;
        case 11: // electron
          PdgBreakdown->AddBinContent(7);
          break;
        case -11: // positron
          PdgBreakdown->AddBinContent(8);
          break;
        case 13: // muon
          PdgBreakdown->AddBinContent(9);
          break;
        case -13: // antimuon
          PdgBreakdown->AddBinContent(10);
          break;
        case 321: // k+
          PdgBreakdown->AddBinContent(11);
          break;
        case 223: // omega
          PdgBreakdown->AddBinContent(12);
          break;
        default:
          std::cout << "PDG code not recognised: " << i << std::endl;
          break;
      }
    }
    
    void SaveHist(TFile* f) {
      if(f && PdgBreakdown) {
        f->cd();
        PdgBreakdown->Write();
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
