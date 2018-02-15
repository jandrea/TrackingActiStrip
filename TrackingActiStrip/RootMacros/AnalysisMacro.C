#define AnalysisMacro_cxx
#include "AnalysisMacro.h"
#include <TH2.h>
#include <TH2F.h>
#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>
#include <iostream>

void AnalysisMacro::Loop()
{
	
  TFile * output = new TFile("output.root", "recreate");
  
  TH1F * trackPt    = new TH1F("trackPt",    "trackPt",    100, 0, 30);
  TH1F * trackEta   = new TH1F("trackEta",   "trackEta",   20, -2.5, 2.5);
  TH1F * trackNHit  = new TH1F("trackNHit",  "trackNHit",  20, 0, 20);
  TH1F * trackChi2  = new TH1F("trackChi2",  "trackChi2",  100, 0, 20);
  
  TH2F* trackPt_vs_SoverN = new TH2F("trackPt_vs_SoverN", "trackPt_vs_SoverN",  100, 0, 30, 100, 0, 100);
  
  TH1F * SoverN      = new TH1F("SoverN",      "SoverN",      100, 0, 100);
  TH1F * SoverN_TIB  = new TH1F("SoverN_TIB",  "SoverN_TIB",  100, 0, 100);
  TH1F * SoverN_TOB  = new TH1F("SoverN_TOB",  "SoverN_TOB",  100, 0, 100);
  TH1F * SoverN_TIDm = new TH1F("SoverN_TIDm", "SoverN_TIDm", 100, 0, 100);
  TH1F * SoverN_TIDp = new TH1F("SoverN_TIDp", "SoverN_TIDp", 100, 0, 100);
  TH1F * SoverN_TECm = new TH1F("SoverN_TECm", "SoverN_TECm", 100, 0, 100);
  TH1F * SoverN_TECp = new TH1F("SoverN_TECp", "SoverN_TECp", 100, 0, 100);
  
  
  //**********************************************
  //global position for all clusters and all tracks
  std::vector<TH2F * > vect_globalPosition_X_Y_TIDm;
  std::vector<TH2F * > vect_globalPosition_X_Y_TIDp;
  
  std::vector<TH2F * > vect_globalPosition_X_Y_TECm;
  std::vector<TH2F * > vect_globalPosition_X_Y_TECp;
  
  std::vector<TH2F * > vect_tsosglobalPosition_X_Y_TIDm;
  std::vector<TH2F * > vect_tsosglobalPosition_X_Y_TIDp;
  
  std::vector<TH2F * > vect_tsosglobalPosition_X_Y_TECm;
  std::vector<TH2F * > vect_tsosglobalPosition_X_Y_TECp;
  
  
  //**********************************************
  //global position for noisy clusters and low pt tracks
  std::vector<TH2F * > vect_globalPosition_X_Y_noise_TIDm;
  std::vector<TH2F * > vect_globalPosition_X_Y_noise_TIDp;
  
  std::vector<TH2F * > vect_globalPosition_X_Y_noise_TECm;
  std::vector<TH2F * > vect_globalPosition_X_Y_noise_TECp;
  
  std::vector<TH2F * > vect_tsosglobalPosition_X_Y_noise_TIDm;
  std::vector<TH2F * > vect_tsosglobalPosition_X_Y_noise_TIDp;
  
  std::vector<TH2F * > vect_tsosglobalPosition_X_Y_noise_TECm;
  std::vector<TH2F * > vect_tsosglobalPosition_X_Y_noise_TECp;
  
  
  //****************************************************
  //global position for noisy clusters and low pt tracks
  //per petal side 
  
  std::vector<TH2F * > vect_globalPosition_X_Y_noise_TECm_petalf;
  std::vector<TH2F * > vect_globalPosition_X_Y_noise_TECp_petalf;
  
  std::vector<TH2F * > vect_tsosglobalPosition_X_Y_noise_TECm_petalf;
  std::vector<TH2F * > vect_tsosglobalPosition_X_Y_noise_TECp_petalf;
  
  
  std::vector<TH2F * > vect_globalPosition_X_Y_noise_TECm_petalb;
  std::vector<TH2F * > vect_globalPosition_X_Y_noise_TECp_petalb;
  
  
  std::vector<TH2F * > vect_tsosglobalPosition_X_Y_noise_TECm_petalb;
  std::vector<TH2F * > vect_tsosglobalPosition_X_Y_noise_TECp_petalb;
  
  
  std::vector<TString> TIDwheel;
  std::vector<TString> TECwheel;
  
  TIDwheel.push_back("w1");
  TIDwheel.push_back("w2");
  TIDwheel.push_back("w3");

  TECwheel.push_back("w1");
  TECwheel.push_back("w2");
  TECwheel.push_back("w3");
  TECwheel.push_back("w4");
  TECwheel.push_back("w5");
  TECwheel.push_back("w6");
  TECwheel.push_back("w7");
  TECwheel.push_back("w8");
  TECwheel.push_back("w9");
  
  
  
  
  TH2F * globalPosition_X_Y_TIB  = new TH2F("globalPosition_X_Y_TIB", "globalPosition_X_Y_TIB", 120, -60, 60, 120, -60, 60);
  TH2F * globalPosition_X_Y_TOB  = new TH2F("globalPosition_X_Y_TOB", "globalPosition_X_Y_TOB", 300, -130, 130, 300, -130, 130);
  TH2F * globalPosition_X_Y_TIDm = new TH2F("globalPosition_X_Y_TIDm", "globalPosition_X_Y_TIDm", 120, -60, 60, 120, -60, 60);
  TH2F * globalPosition_X_Y_TIDp = new TH2F("globalPosition_X_Y_TIDp", "globalPosition_X_Y_TIDp", 120, -60, 60, 120, -60, 60);
  TH2F * globalPosition_X_Y_TECm = new TH2F("globalPosition_X_Y_TECm", "globalPosition_X_Y_TECm", 300, -130, 130, 300, -130, 130);
  TH2F * globalPosition_X_Y_TECp = new TH2F("globalPosition_X_Y_TECp", "globalPosition_X_Y_TECp", 300, -130, 130, 300, -130, 130);
  
  TH2F * globalPosition_X_Y_noise_TIB  = new TH2F("globalPosition_X_Y_noise_TIB", "globalPosition_X_Y_noise_TIB", 120, -60, 60, 120, -60, 60);
  TH2F * globalPosition_X_Y_noise_TOB  = new TH2F("globalPosition_X_Y_noise_TOB", "globalPosition_X_Y_noise_TOB", 300, -130, 130, 300, -130, 130);
  
  
  TH2F * tsosglobalPosition_X_Y_TIB  = new TH2F("tsosglobalPosition_X_Y_TIB", "tsosglobalPosition_X_Y_TIB", 120, -60, 60, 120, -60, 60);
  TH2F * tsosglobalPosition_X_Y_TOB  = new TH2F("tsosglobalPosition_X_Y_TOB", "tsosglobalPosition_X_Y_TOB", 300, -130, 130, 300, -130, 130);
  TH2F * tsosglobalPosition_X_Y_TIDm = new TH2F("tsosglobalPosition_X_Y_TIDm", "tsosglobalPosition_X_Y_TIDm", 120, -60, 60, 120, -60, 60);
  TH2F * tsosglobalPosition_X_Y_TIDp = new TH2F("tsosglobalPosition_X_Y_TIDp", "tsosglobalPosition_X_Y_TIDp", 120, -60, 60, 120, -60, 60);
  TH2F * tsosglobalPosition_X_Y_TECm = new TH2F("tsosglobalPosition_X_Y_TECm", "tsosglobalPosition_X_Y_TECm", 300, -130, 130, 300, -130, 130);
  TH2F * tsosglobalPosition_X_Y_TECp = new TH2F("tsosglobalPosition_X_Y_TECp", "tsosglobalPosition_X_Y_TECp", 300, -130, 130, 300, -130, 130);
  TH2F * tsosglobalPosition_Z_Y_noise_TECp_petalb =  new TH2F( "tsosglobalPosition_Z_Y_noise_TECm_petalb", "tsosglobalPosition_Z_Y_noise_TECm_petalb" ,500, -1000, 1000, 1000, -1000, 1000);
   
  for(unsigned int i=0; i<TIDwheel.size(); i++){
    
    vect_globalPosition_X_Y_TIDm.push_back( new TH2F( ("globalPosition_X_Y_TIDm_"+TIDwheel[i]).Data(), ("globalPosition_X_Y_TIDm_"+TIDwheel[i]).Data() , 120, -60, 60, 120, -60, 60));
    vect_globalPosition_X_Y_TIDp.push_back( new TH2F( ("globalPosition_X_Y_TIDp_"+TIDwheel[i]).Data(), ("globalPosition_X_Y_TIDp_"+TIDwheel[i]).Data() , 120, -60, 60, 120, -60, 60));
    
    vect_tsosglobalPosition_X_Y_TIDm.push_back( new TH2F( ("tsosglobalPosition_X_Y_TIDm_"+TIDwheel[i]).Data(), ("tsosglobalPosition_X_Y_TIDm_"+TIDwheel[i]).Data() , 120, -60, 60, 120, -60, 60));;
    vect_tsosglobalPosition_X_Y_TIDp.push_back( new TH2F( ("tsosglobalPosition_X_Y_TIDp_"+TIDwheel[i]).Data(), ("tsosglobalPosition_X_Y_TIDp_"+TIDwheel[i]).Data() , 120, -60, 60, 120, -60, 60));;
    
    vect_globalPosition_X_Y_noise_TIDm.push_back( new TH2F( ("globalPosition_X_Y_noise_TIDm_"+TIDwheel[i]).Data(), ("globalPosition_X_Y_noise_TIDm_"+TIDwheel[i]).Data() , 120, -60, 60, 120, -60, 60));
    vect_globalPosition_X_Y_noise_TIDp.push_back( new TH2F( ("globalPosition_X_Y_noise_TIDp_"+TIDwheel[i]).Data(), ("globalPosition_X_Y_noise_TIDp_"+TIDwheel[i]).Data() , 120, -60, 60, 120, -60, 60));
    
    vect_tsosglobalPosition_X_Y_noise_TIDm.push_back( new TH2F( ("tsosglobalPosition_X_Y_noise_TIDm_"+TIDwheel[i]).Data(), ("tsosglobalPosition_X_Y_noise_TIDm_"+TIDwheel[i]).Data() , 120, -60, 60, 120, -60, 60));
    vect_tsosglobalPosition_X_Y_noise_TIDp.push_back( new TH2F( ("tsosglobalPosition_X_Y_noise_TIDp_"+TIDwheel[i]).Data(), ("tsosglobalPosition_X_Y_noise_TIDp_"+TIDwheel[i]).Data() , 120, -60, 60, 120, -60, 60));
   
    
  }
  
  for(unsigned int i=0; i<TECwheel.size(); i++){
    
    vect_globalPosition_X_Y_TECm.push_back( new TH2F( ("globalPosition_X_Y_TECm_"+TECwheel[i]).Data(), ("globalPosition_X_Y_TECm_"+TECwheel[i]).Data() ,500, -130, 130, 1000, -130, 130));
    vect_globalPosition_X_Y_TECp.push_back( new TH2F( ("globalPosition_X_Y_TECp_"+TECwheel[i]).Data(), ("globalPosition_X_Y_TECp_"+TECwheel[i]).Data() ,500, -130, 130, 1000, -130, 130));
    
    vect_tsosglobalPosition_X_Y_TECm.push_back( new TH2F( ("tsosglobalPosition_X_Y_TECm_"+TECwheel[i]).Data(), ("tsosglobalPosition_X_Y_TECm_"+TECwheel[i]).Data() ,500, -130, 130, 1000, -130, 130));;
    vect_tsosglobalPosition_X_Y_TECp.push_back( new TH2F( ("tsosglobalPosition_X_Y_TECp_"+TECwheel[i]).Data(), ("tsosglobalPosition_X_Y_TECp_"+TECwheel[i]).Data() ,500, -130, 130, 1000, -130, 130));;
    
    vect_globalPosition_X_Y_noise_TECm.push_back( new TH2F( ("globalPosition_X_Y_noise_TECm_"+TECwheel[i]).Data(), ("globalPosition_X_Y_noise_TECm_"+TECwheel[i]).Data() ,500, -130, 130, 1000, -130, 130));
    vect_globalPosition_X_Y_noise_TECp.push_back( new TH2F( ("globalPosition_X_Y_noise_TECp_"+TECwheel[i]).Data(), ("globalPosition_X_Y_noise_TECp_"+TECwheel[i]).Data() ,500, -130, 130, 1000, -130, 130));
    
    vect_tsosglobalPosition_X_Y_noise_TECm.push_back( new TH2F( ("tsosglobalPosition_X_Y_noise_TECm_"+TECwheel[i]).Data(), ("tsosglobalPosition_X_Y_noise_TECm_"+TECwheel[i]).Data() ,500, -130, 130, 1000, -130, 130));
    vect_tsosglobalPosition_X_Y_noise_TECp.push_back( new TH2F( ("tsosglobalPosition_X_Y_noise_TECp_"+TECwheel[i]).Data(), ("tsosglobalPosition_X_Y_noise_TECp_"+TECwheel[i]).Data() ,500, -130, 130, 1000, -130, 130));
  
    
    vect_globalPosition_X_Y_noise_TECm_petalf.push_back( new TH2F( ("globalPosition_X_Y_noise_TECm_"+TECwheel[i]+"_petalf").Data(), ("globalPosition_X_Y_noise_TECm_"+TECwheel[i]+"_petalf").Data() ,500, -130, 130, 1000, -130, 130));
    vect_globalPosition_X_Y_noise_TECp_petalf.push_back( new TH2F( ("globalPosition_X_Y_noise_TECp_"+TECwheel[i]+"_petalf").Data(), ("globalPosition_X_Y_noise_TECp_"+TECwheel[i]+"_petalf").Data() ,500, -130, 130, 1000, -130, 130));
 
 
    vect_tsosglobalPosition_X_Y_noise_TECm_petalf.push_back( new TH2F( ("tsosglobalPosition_X_Y_noise_TECm_"+TECwheel[i]+"_petalf").Data(), ("tsosglobalPosition_X_Y_noise_TECm_"+TECwheel[i]+"_petalf").Data() ,500, -130, 130, 1000, -130, 130));;
    vect_tsosglobalPosition_X_Y_noise_TECp_petalf.push_back( new TH2F( ("tsosglobalPosition_X_Y_noise_TECp_"+TECwheel[i]+"_petalf").Data(), ("tsosglobalPosition_X_Y_noise_TECp_"+TECwheel[i]+"_petalf").Data() ,500, -130, 130, 1000, -130, 130));
 
    vect_globalPosition_X_Y_noise_TECm_petalb.push_back( new TH2F( ("globalPosition_X_Y_noise_TECm_"+TECwheel[i]+"_petalb").Data(), ("globalPosition_X_Y_noise_TECm_"+TECwheel[i]+"_petalb").Data() ,500, -130, 130, 1000, -130, 130));
    vect_globalPosition_X_Y_noise_TECp_petalb.push_back( new TH2F( ("globalPosition_X_Y_noise_TECp_"+TECwheel[i]+"_petalb").Data(), ("globalPosition_X_Y_noise_TECp_"+TECwheel[i]+"_petalb").Data() ,500, -130, 130, 1000, -130, 130));
 
 
    vect_tsosglobalPosition_X_Y_noise_TECm_petalb.push_back( new TH2F( ("tsosglobalPosition_X_Y_noise_TECm_"+TECwheel[i]+"_petalb").Data(), ("tsosglobalPosition_X_Y_noise_TECm_"+TECwheel[i]+"_petalb").Data() ,500, -130, 130, 1000, -130, 130));
    vect_tsosglobalPosition_X_Y_noise_TECp_petalb.push_back( new TH2F( ("tsosglobalPosition_X_Y_noise_TECp_"+TECwheel[i]+"_petalb").Data(), ("tsosglobalPosition_X_Y_noise_TECp_"+TECwheel[i]+"_petalb").Data() ,500, -130, 130, 1000, -130, 130));
    
     
  }
  
  
  
  
  
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      
      trackPt->Fill(tree_track_pt);
      trackEta->Fill(tree_track_eta);
      trackNHit->Fill(tree_track_nhits);
      trackChi2->Fill(tree_track_NChi2);
      
      for(int i=0; i<tree_track_nclusters; i++){
        
	
	SoverN->Fill(tree_Cluster_SoverN[i]);
	trackPt_vs_SoverN->Fill(tree_track_pt, tree_Cluster_SoverN[i]);
	//for TIB
	if(tree_Cluster_subDet[i] == 0){
	  globalPosition_X_Y_TIB->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
          tsosglobalPosition_X_Y_TIB->Fill(tree_Cluster_tsosglobX[i], tree_Cluster_tsosglobY[i]);
	  SoverN_TIB->Fill(tree_Cluster_SoverN[i]);
	  
	  if(tree_track_pt<4 && tree_Cluster_SoverN[i] < 15) globalPosition_X_Y_noise_TIB->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
	  
	}
	//for TOB
	if(tree_Cluster_subDet[i] == 1){
	  globalPosition_X_Y_TOB->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
          tsosglobalPosition_X_Y_TOB->Fill(tree_Cluster_tsosglobX[i], tree_Cluster_tsosglobY[i]);
	  
	  SoverN_TOB->Fill(tree_Cluster_SoverN[i]);
	  
	  if(tree_track_pt<4 && tree_Cluster_SoverN[i] < 15) globalPosition_X_Y_noise_TOB->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);

	  
	}
	//for TID
	if(tree_Cluster_subDet[i] == 2){
	
		  
	  if(tree_Cluster_WheelSide[i] == 1 ){
	    globalPosition_X_Y_TIDm->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
            tsosglobalPosition_X_Y_TIDm->Fill(tree_Cluster_tsosglobX[i], tree_Cluster_tsosglobY[i]);
	    
	    vect_globalPosition_X_Y_TIDm[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
	    vect_tsosglobalPosition_X_Y_TIDm[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_tsosglobX[i], tree_Cluster_tsosglobY[i]);
	    
	    SoverN_TIDm->Fill(tree_Cluster_SoverN[i]);
	  }  
	  if(tree_Cluster_WheelSide[i] == 2 ){
	    globalPosition_X_Y_TIDp->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
            tsosglobalPosition_X_Y_TIDp->Fill(tree_Cluster_tsosglobX[i], tree_Cluster_tsosglobY[i]);
	    
	    vect_globalPosition_X_Y_TIDp[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
	    vect_tsosglobalPosition_X_Y_TIDp[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_tsosglobX[i], tree_Cluster_tsosglobY[i]);
	    
	    SoverN_TIDp->Fill(tree_Cluster_SoverN[i]);
	  }
	  
	  
	  if(tree_track_pt<4 && tree_Cluster_SoverN[i] < 15){
	    
	    //cout << __LINE__ << endl;
	    if(tree_Cluster_WheelSide[i] == 1 ){
	      //cout << __LINE__ << endl;
	      vect_globalPosition_X_Y_noise_TIDm[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
	      vect_tsosglobalPosition_X_Y_noise_TIDm[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_tsosglobX[i], tree_Cluster_tsosglobY[i]);
	      
	    }  
	    if(tree_Cluster_WheelSide[i] == 2 ){
	      vect_globalPosition_X_Y_noise_TIDp[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
	      vect_tsosglobalPosition_X_Y_noise_TIDp[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_tsosglobX[i], tree_Cluster_tsosglobY[i]);
	    }
	        
	  } 
	  
	}
	//for TEC
	if(tree_Cluster_subDet[i] == 3){
	
		  
	  if(tree_Cluster_WheelSide[i] == 1 ){
	    globalPosition_X_Y_TECm->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
            tsosglobalPosition_X_Y_TECm->Fill(tree_Cluster_tsosglobX[i], tree_Cluster_tsosglobY[i]);
	    
	    vect_globalPosition_X_Y_TECm[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
	    vect_tsosglobalPosition_X_Y_TECm[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_tsosglobX[i], tree_Cluster_tsosglobY[i]);
	    
	    SoverN_TECm->Fill(tree_Cluster_SoverN[i]);
	  }  
	  if(tree_Cluster_WheelSide[i] == 2 ){
	    globalPosition_X_Y_TECp->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
            tsosglobalPosition_X_Y_TECp->Fill(tree_Cluster_tsosglobX[i], tree_Cluster_tsosglobY[i]);
	    
	    vect_globalPosition_X_Y_TECp[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
	    vect_tsosglobalPosition_X_Y_TECp[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_tsosglobX[i], tree_Cluster_tsosglobY[i]);
	    
	    SoverN_TECp->Fill(tree_Cluster_SoverN[i]);
	  }
	  
	  
	  if(tree_track_pt<4 && tree_Cluster_SoverN[i] < 15){
            tsosglobalPosition_Z_Y_noise_TECp_petalb->Fill(tree_Cluster_tsosglobZ[i], tree_Cluster_tsosglobY[i]);
	    
	    //cout << "nstrip  " << tree_Strips_idLast[i] - tree_Strips_idFirst[i]<< endl;
	    //if( (tree_Strips_idLast[i] - tree_Strips_idFirst[i]) < 2) continue;
	    //if( (tree_Strips_idLast[i] - tree_Strips_idFirst[i]) !=1 ) continue;
	    //cout << __LINE__ << endl;
	    if(tree_Cluster_WheelSide[i] == 1 ){
	      //cout << __LINE__ << endl;
	      vect_globalPosition_X_Y_noise_TECm[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
	      vect_tsosglobalPosition_X_Y_noise_TECm[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_tsosglobX[i], tree_Cluster_tsosglobY[i]);
	      
	      if(tree_Cluster_PetalSide[i] == 1){
                 vect_globalPosition_X_Y_noise_TECm_petalf[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
                 vect_tsosglobalPosition_X_Y_noise_TECm_petalf[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_tsosglobX[i], tree_Cluster_tsosglobY[i]);
	      }
	      if(tree_Cluster_PetalSide[i] == -1){
                 vect_globalPosition_X_Y_noise_TECm_petalb[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
                 vect_tsosglobalPosition_X_Y_noise_TECm_petalb[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_tsosglobX[i], tree_Cluster_tsosglobY[i]);
	      }
	      
	    }  
	    if(tree_Cluster_WheelSide[i] == 2 ){
	      vect_globalPosition_X_Y_noise_TECp[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
	      vect_tsosglobalPosition_X_Y_noise_TECp[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_tsosglobX[i], tree_Cluster_tsosglobY[i]);
	      
	      if(tree_Cluster_PetalSide[i] == 1){
                 vect_globalPosition_X_Y_noise_TECp_petalf[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
                 vect_tsosglobalPosition_X_Y_noise_TECp_petalf[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_tsosglobX[i], tree_Cluster_tsosglobY[i]);
	      }
	      if(tree_Cluster_PetalSide[i] == -1){
                 vect_globalPosition_X_Y_noise_TECp_petalb[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_globX[i], tree_Cluster_globY[i]);
                 vect_tsosglobalPosition_X_Y_noise_TECp_petalb[tree_Cluster_LayerNbr[i]-1]->Fill(tree_Cluster_tsosglobX[i], tree_Cluster_tsosglobY[i]);
	      }
	    }
	        
	  } 
	  
	}
	
	
	
	
	//*************
	
	
	
      }
      
      
   }
   
   
   output->Write();
}
