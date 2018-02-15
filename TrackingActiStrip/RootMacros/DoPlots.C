
#include <TH2F.h>
#include <TH2.h>
#include <TH1F.h>
#include <TH1I.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TString.h>
#include "TMatrixD.h"
#include "TRandom.h"
#include "TRandom2.h"
#include "TStyle.h"

#include "THStack.h"
#include "TLegend.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TEfficiency.h"
#include "TGraphAsymmErrors.h"
#include "TF1.h"
#include "TPaveStats.h"
#include "TGraphErrors.h"
#include <iostream>
#include <vector>
#include <map>


void DoPlots(TString histname1, TString histname2 , TString drawopt){

  // For the statistics box:
  gStyle->SetOptFile(0);
  gStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  gStyle->SetStatColor(0); // kWhite
  gStyle->SetStatFont(42);
  //ROOT . gStyle . SetStatFontSize(0.025);
  gStyle->SetStatFontSize(0.04);
  gStyle->SetStatTextColor(1);
  gStyle->SetStatFormat("6.4g");
  gStyle->SetStatBorderSize(1);
 // gStyle->SetStatH(0.1);
  //gStyle->SetStatW(0.15);

  gStyle->SetOptTitle(1);
  gStyle->SetTitleFont(42);
  gStyle->SetTitleColor(1);
  gStyle->SetTitleTextColor(1);
  gStyle->SetTitleFillColor(10);
  gStyle->SetTitleFontSize(0.05);


  TCanvas *c1 = new TCanvas("c1","c1", 1000, 800);

  c1->SetBottomMargin(0.15);
  c1->SetLeftMargin(0.15);

  c1->cd();

  TFile * filechannel = new TFile("output.root");
  cout << __LINE__ << endl;
  TH2F * theHisto = (TH2F*)filechannel->Get( histname1.Data() )->Clone();
  cout << __LINE__ << endl;
  TH2F * theHisto2 = (TH2F*)filechannel->Get( histname2.Data() )->Clone();
  cout << __LINE__ << endl;
  
  theHisto->SetMarkerColor(2);
  theHisto2->SetMarkerColor(4);
  theHisto->Draw(drawopt.Data());
  theHisto2->Draw((drawopt+"same").Data());
  
  cout << __LINE__ << endl;
  c1->SaveAs( ("plots/"+histname1+"_"+histname2+".png").Data());
  cout << __LINE__ << endl;
  
}
void DoPlots(TString histname, TString drawopt){

  // For the statistics box:
  gStyle->SetOptFile(0);
  gStyle->SetOptStat(0); // To display the mean and RMS:   SetOptStat("mr");
  gStyle->SetStatColor(0); // kWhite
  gStyle->SetStatFont(42);
  //ROOT . gStyle . SetStatFontSize(0.025);
  gStyle->SetStatFontSize(0.04);
  gStyle->SetStatTextColor(1);
  gStyle->SetStatFormat("6.4g");
  gStyle->SetStatBorderSize(1);
 // gStyle->SetStatH(0.1);
  //gStyle->SetStatW(0.15);

  gStyle->SetOptTitle(1);
  gStyle->SetTitleFont(42);
  gStyle->SetTitleColor(1);
  gStyle->SetTitleTextColor(1);
  gStyle->SetTitleFillColor(10);
  gStyle->SetTitleFontSize(0.05);


  TCanvas *c1 = new TCanvas("c1","c1", 1000, 800);

  c1->SetBottomMargin(0.15);
  c1->SetLeftMargin(0.15);

  c1->cd();
  
  TFile * filechannel = new TFile("output.root");
  
  
  TH2F * theHisto = (TH2F*)filechannel->Get( histname.Data() )->Clone();
  
  
  theHisto->Draw(drawopt.Data());
  c1->SaveAs( ("plots/"+histname+".png").Data());

}



void DoPlots(){

  //DoPlots("", "colz");	
  DoPlots("trackPt", "colz");		
  DoPlots("trackEta", "colz");		
  DoPlots("trackNHit", "colz");		
  DoPlots("trackChi2", "colz");		
  DoPlots("trackPt_vs_SoverN", "colz");		 
  DoPlots("SoverN", "colz");		 
  DoPlots("SoverN_TIB", "colz");	   
  DoPlots("SoverN_TOB", "colz");	   
  DoPlots("SoverN_TIDm", "colz");	  
  DoPlots("SoverN_TIDp", "colz");	  
  DoPlots("SoverN_TECm", "colz");	  
  DoPlots("SoverN_TECp", "colz");	  
  DoPlots("globalPosition_X_Y_TIB", "colz");		  
  DoPlots("globalPosition_X_Y_TOB", "colz");		  
  DoPlots("globalPosition_X_Y_TIDm", "colz");		  
  DoPlots("globalPosition_X_Y_TIDp", "colz");		  
  DoPlots("globalPosition_X_Y_TECm", "colz");		  
  DoPlots("globalPosition_X_Y_TECp", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TIB", "colz");	  
  DoPlots("globalPosition_X_Y_noise_TOB", "colz");	  
  DoPlots("tsosglobalPosition_X_Y_TIB", "colz");	    
  DoPlots("tsosglobalPosition_X_Y_TOB", "colz");	    
  DoPlots("tsosglobalPosition_X_Y_TIDm", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_TIDp", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_TECm", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_TECp", "colz");	   
  DoPlots("globalPosition_X_Y_TIDm_w1", "colz");	    
  DoPlots("globalPosition_X_Y_TIDp_w1", "colz");	    
  DoPlots("tsosglobalPosition_X_Y_TIDm_w1", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_TIDp_w1", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TIDm_w1", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TIDp_w1", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TIDm_w1", "colz");	  
  DoPlots("tsosglobalPosition_X_Y_noise_TIDp_w1", "colz");	  
  DoPlots("globalPosition_X_Y_TIDm_w2", "colz");	    
  DoPlots("globalPosition_X_Y_TIDp_w2", "colz");	    
  DoPlots("tsosglobalPosition_X_Y_TIDm_w2", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_TIDp_w2", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TIDm_w2", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TIDp_w2", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TIDm_w2", "colz");	  
  DoPlots("tsosglobalPosition_X_Y_noise_TIDp_w2", "colz");	  
  DoPlots("globalPosition_X_Y_TIDm_w3", "colz");	    
  DoPlots("globalPosition_X_Y_TIDp_w3", "colz");	    
  DoPlots("tsosglobalPosition_X_Y_TIDm_w3", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_TIDp_w3", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TIDm_w3", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TIDp_w3", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TIDm_w3", "colz");	  
  DoPlots("tsosglobalPosition_X_Y_noise_TIDp_w3", "colz");	  
  DoPlots("globalPosition_X_Y_TECm_w1", "colz");	    
  DoPlots("globalPosition_X_Y_TECp_w1", "colz");	    
  DoPlots("tsosglobalPosition_X_Y_TECm_w1", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_TECp_w1", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECm_w1", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w1", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w1", "colz");	  
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w1", "colz");	  
  DoPlots("globalPosition_X_Y_noise_TECm_w1_petalf", "colz");		 
  DoPlots("globalPosition_X_Y_noise_TECp_w1_petalf", "colz");		 
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w1_petalf", "colz");	  
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w1_petalf", "colz");	  
  DoPlots("globalPosition_X_Y_noise_TECm_w1_petalb", "colz");		 
  DoPlots("globalPosition_X_Y_noise_TECp_w1_petalb", "colz");		 
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w1_petalb", "colz");	  
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w1_petalb", "colz");	  
  DoPlots("globalPosition_X_Y_TECm_w2", "colz");	   
  DoPlots("globalPosition_X_Y_TECp_w2", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_TECm_w2", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_TECp_w2", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECm_w2", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w2", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w2", "colz");	  
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w2", "colz");	  
  DoPlots("globalPosition_X_Y_noise_TECm_w2_petalf", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w2_petalf", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w2_petalf", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w2_petalf", "colz");	   
  DoPlots("globalPosition_X_Y_noise_TECm_w2_petalb", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w2_petalb", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w2_petalb", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w2_petalb", "colz");	   
  DoPlots("globalPosition_X_Y_TECm_w3", "colz");	    
  DoPlots("globalPosition_X_Y_TECp_w3", "colz");	    
  DoPlots("tsosglobalPosition_X_Y_TECm_w3", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_TECp_w3", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECm_w3", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w3", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w3", "colz");	  
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w3", "colz");	  
  DoPlots("globalPosition_X_Y_noise_TECm_w3_petalf", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w3_petalf", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w3_petalf", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w3_petalf", "colz");	   
  DoPlots("globalPosition_X_Y_noise_TECm_w3_petalb", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w3_petalb", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w3_petalb", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w3_petalb", "colz");	   
  DoPlots("globalPosition_X_Y_TECm_w4", "colz");	    
  DoPlots("globalPosition_X_Y_TECp_w4", "colz");	    
  DoPlots("tsosglobalPosition_X_Y_TECm_w4", "colz");		 
  DoPlots("tsosglobalPosition_X_Y_TECp_w4", "colz");		 
  DoPlots("globalPosition_X_Y_noise_TECm_w4", "colz");		 
  DoPlots("globalPosition_X_Y_noise_TECp_w4", "colz");		 
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w4", "colz");	 
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w4", "colz");	 
  DoPlots("globalPosition_X_Y_noise_TECm_w4_petalf", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w4_petalf", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w4_petalf", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w4_petalf", "colz");	   
  DoPlots("globalPosition_X_Y_noise_TECm_w4_petalb", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w4_petalb", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w4_petalb", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w4_petalb", "colz");	   
  DoPlots("globalPosition_X_Y_TECm_w5", "colz");	    
  DoPlots("globalPosition_X_Y_TECp_w5", "colz");	    
  DoPlots("tsosglobalPosition_X_Y_TECm_w5", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_TECp_w5", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECm_w5", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w5", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w5", "colz");	  
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w5", "colz");	  
  DoPlots("globalPosition_X_Y_noise_TECm_w5_petalf", "colz");		 
  DoPlots("globalPosition_X_Y_noise_TECp_w5_petalf", "colz");		 
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w5_petalf", "colz");	  
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w5_petalf", "colz");	  
  DoPlots("globalPosition_X_Y_noise_TECm_w5_petalb", "colz");		 
  DoPlots("globalPosition_X_Y_noise_TECp_w5_petalb", "colz");		 
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w5_petalb", "colz");	  
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w5_petalb", "colz");	  
  DoPlots("globalPosition_X_Y_TECm_w6", "colz");	   
  DoPlots("globalPosition_X_Y_TECp_w6", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_TECm_w6", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_TECp_w6", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECm_w6", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w6", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w6", "colz");	  
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w6", "colz");	  
  DoPlots("globalPosition_X_Y_noise_TECm_w6_petalf", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w6_petalf", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w6_petalf", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w6_petalf", "colz");	   
  DoPlots("globalPosition_X_Y_noise_TECm_w6_petalb", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w6_petalb", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w6_petalb", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w6_petalb", "colz");	   
  DoPlots("globalPosition_X_Y_TECm_w7", "colz");	   
  DoPlots("globalPosition_X_Y_TECp_w7", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_TECm_w7", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_TECp_w7", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECm_w7", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w7", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w7", "colz");	  
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w7", "colz");	  
  DoPlots("globalPosition_X_Y_noise_TECm_w7_petalf", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w7_petalf", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w7_petalf", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w7_petalf", "colz");	   
  DoPlots("globalPosition_X_Y_noise_TECm_w7_petalb", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w7_petalb", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w7_petalb", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w7_petalb", "colz");	   
  DoPlots("globalPosition_X_Y_TECm_w8", "colz");	    
  DoPlots("globalPosition_X_Y_TECp_w8", "colz");	    
  DoPlots("tsosglobalPosition_X_Y_TECm_w8", "colz");		 
  DoPlots("tsosglobalPosition_X_Y_TECp_w8", "colz");		 
  DoPlots("globalPosition_X_Y_noise_TECm_w8", "colz");		 
  DoPlots("globalPosition_X_Y_noise_TECp_w8", "colz");		 
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w8", "colz");	 
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w8", "colz");	 
  DoPlots("globalPosition_X_Y_noise_TECm_w8_petalf", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w8_petalf", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w8_petalf", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w8_petalf", "colz");	   
  DoPlots("globalPosition_X_Y_noise_TECm_w8_petalb", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w8_petalb", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w8_petalb", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w8_petalb", "colz");	  
  DoPlots("globalPosition_X_Y_TECm_w9", "colz");	   
  DoPlots("globalPosition_X_Y_TECp_w9", "colz");	   
  DoPlots("tsosglobalPosition_X_Y_TECm_w9", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_TECp_w9", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECm_w9", "colz");		  
  DoPlots("globalPosition_X_Y_noise_TECp_w9", "colz");		  
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w9", "colz");	  
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w9", "colz");	  
  DoPlots("globalPosition_X_Y_noise_TECm_w9_petalf", "colz");		 
  DoPlots("globalPosition_X_Y_noise_TECp_w9_petalf", "colz");		 
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w9_petalf", "colz");	  
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w9_petalf", "colz");	  
  DoPlots("globalPosition_X_Y_noise_TECm_w9_petalb", "colz");		 
  DoPlots("globalPosition_X_Y_noise_TECp_w9_petalb", "colz");		 
  DoPlots("tsosglobalPosition_X_Y_noise_TECm_w9_petalb", "colz");	  
  DoPlots("tsosglobalPosition_X_Y_noise_TECp_w9_petalb", "colz");	  
  
  
   //DoPlots("", "", "");
   DoPlots("globalPosition_X_Y_noise_TECm_w1_petalf", "globalPosition_X_Y_noise_TECm_w1_petalb", "");
   DoPlots("globalPosition_X_Y_noise_TECm_w2_petalf", "globalPosition_X_Y_noise_TECm_w2_petalb", "");
   DoPlots("globalPosition_X_Y_noise_TECm_w3_petalf", "globalPosition_X_Y_noise_TECm_w3_petalb", "");
   DoPlots("globalPosition_X_Y_noise_TECm_w4_petalf", "globalPosition_X_Y_noise_TECm_w4_petalb", "");
   DoPlots("globalPosition_X_Y_noise_TECm_w5_petalf", "globalPosition_X_Y_noise_TECm_w5_petalb", "");
   DoPlots("globalPosition_X_Y_noise_TECm_w6_petalf", "globalPosition_X_Y_noise_TECm_w6_petalb", "");
   DoPlots("globalPosition_X_Y_noise_TECm_w7_petalf", "globalPosition_X_Y_noise_TECm_w7_petalb", "");
   DoPlots("globalPosition_X_Y_noise_TECm_w8_petalf", "globalPosition_X_Y_noise_TECm_w8_petalb", "");
   DoPlots("globalPosition_X_Y_noise_TECm_w9_petalf", "globalPosition_X_Y_noise_TECm_w9_petalb", "");
   
   DoPlots("tsosglobalPosition_X_Y_noise_TECm_w1_petalf", "tsosglobalPosition_X_Y_noise_TECm_w1_petalb", "");
   DoPlots("tsosglobalPosition_X_Y_noise_TECm_w2_petalf", "tsosglobalPosition_X_Y_noise_TECm_w2_petalb", "");
   DoPlots("tsosglobalPosition_X_Y_noise_TECm_w3_petalf", "tsosglobalPosition_X_Y_noise_TECm_w3_petalb", "");
   DoPlots("tsosglobalPosition_X_Y_noise_TECm_w4_petalf", "tsosglobalPosition_X_Y_noise_TECm_w4_petalb", "");
   DoPlots("tsosglobalPosition_X_Y_noise_TECm_w5_petalf", "tsosglobalPosition_X_Y_noise_TECm_w5_petalb", "");
   DoPlots("tsosglobalPosition_X_Y_noise_TECm_w6_petalf", "tsosglobalPosition_X_Y_noise_TECm_w6_petalb", "");
   DoPlots("tsosglobalPosition_X_Y_noise_TECm_w7_petalf", "tsosglobalPosition_X_Y_noise_TECm_w7_petalb", "");
   DoPlots("tsosglobalPosition_X_Y_noise_TECm_w8_petalf", "tsosglobalPosition_X_Y_noise_TECm_w8_petalb", "");
   DoPlots("tsosglobalPosition_X_Y_noise_TECm_w9_petalf", "tsosglobalPosition_X_Y_noise_TECm_w9_petalb", ""); 
   
   DoPlots("globalPosition_X_Y_noise_TECp_w1_petalf", "globalPosition_X_Y_noise_TECp_w1_petalb", "");
   DoPlots("globalPosition_X_Y_noise_TECp_w2_petalf", "globalPosition_X_Y_noise_TECp_w2_petalb", "");
   DoPlots("globalPosition_X_Y_noise_TECp_w3_petalf", "globalPosition_X_Y_noise_TECp_w3_petalb", "");
   DoPlots("globalPosition_X_Y_noise_TECp_w4_petalf", "globalPosition_X_Y_noise_TECp_w4_petalb", "");
   DoPlots("globalPosition_X_Y_noise_TECp_w5_petalf", "globalPosition_X_Y_noise_TECp_w5_petalb", "");
   DoPlots("globalPosition_X_Y_noise_TECp_w6_petalf", "globalPosition_X_Y_noise_TECp_w6_petalb", "");
   DoPlots("globalPosition_X_Y_noise_TECp_w7_petalf", "globalPosition_X_Y_noise_TECp_w7_petalb", "");
   DoPlots("globalPosition_X_Y_noise_TECp_w8_petalf", "globalPosition_X_Y_noise_TECp_w8_petalb", "");
   DoPlots("globalPosition_X_Y_noise_TECp_w9_petalf", "globalPosition_X_Y_noise_TECp_w9_petalb", "");
   
   DoPlots("tsosglobalPosition_X_Y_noise_TECp_w1_petalf", "tsosglobalPosition_X_Y_noise_TECp_w1_petalb", "");
   DoPlots("tsosglobalPosition_X_Y_noise_TECp_w2_petalf", "tsosglobalPosition_X_Y_noise_TECp_w2_petalb", "");
   DoPlots("tsosglobalPosition_X_Y_noise_TECp_w3_petalf", "tsosglobalPosition_X_Y_noise_TECp_w3_petalb", "");
   DoPlots("tsosglobalPosition_X_Y_noise_TECp_w4_petalf", "tsosglobalPosition_X_Y_noise_TECp_w4_petalb", "");
   DoPlots("tsosglobalPosition_X_Y_noise_TECp_w5_petalf", "tsosglobalPosition_X_Y_noise_TECp_w5_petalb", "");
   DoPlots("tsosglobalPosition_X_Y_noise_TECp_w6_petalf", "tsosglobalPosition_X_Y_noise_TECp_w6_petalb", "");
   DoPlots("tsosglobalPosition_X_Y_noise_TECp_w7_petalf", "tsosglobalPosition_X_Y_noise_TECp_w7_petalb", "");
   DoPlots("tsosglobalPosition_X_Y_noise_TECp_w8_petalf", "tsosglobalPosition_X_Y_noise_TECp_w8_petalb", "");
   DoPlots("tsosglobalPosition_X_Y_noise_TECp_w9_petalf", "tsosglobalPosition_X_Y_noise_TECp_w9_petalb", ""); 
  
  
  
  
}

