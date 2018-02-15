//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Nov  3 21:40:20 2017 by ROOT version 6.04/10
// from TTree ttree/ttree
// found on file: histo.root
//////////////////////////////////////////////////////////

#ifndef AnalysisMacro_h
#define AnalysisMacro_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class AnalysisMacro {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           tree_track_nclusters;
   Double_t        tree_track_pt;
   Double_t        tree_track_eta;
   Double_t        tree_track_phi;
   Int_t           tree_track_nhits;
   Double_t        tree_track_NChi2;
   Int_t           tree_Cluster_subDet[22];   //[tree_track_nclusters]
   Int_t           tree_Cluster_PetalSide[22];   //[tree_track_nclusters]
   Int_t           tree_Cluster_LayerNbr[22];   //[tree_track_nclusters]
   Int_t           tree_Cluster_WheelSide[22];   //[tree_track_nclusters]
   Double_t        tree_Cluster_charge[22];   //[tree_track_nclusters]
   Double_t        tree_Cluster_tsosx[22];   //[tree_track_nclusters]
   Double_t        tree_Cluster_tsosy[22];   //[tree_track_nclusters]
   Double_t        tree_Cluster_SoverN[22];   //[tree_track_nclusters]
   Double_t        tree_Cluster_noise[22];   //[tree_track_nclusters]
   Int_t           tree_Cluster_width[22];   //[tree_track_nclusters]
   Int_t           tree_Cluster_detID[22];   //[tree_track_nclusters]
   Double_t        tree_Cluster_barycenter[22];   //[tree_track_nclusters]
   Float_t         tree_Cluster_locX[22];   //[tree_track_nclusters]
   Float_t         tree_Cluster_locY[22];   //[tree_track_nclusters]
   Float_t         tree_Cluster_globX[22];   //[tree_track_nclusters]
   Float_t         tree_Cluster_globY[22];   //[tree_track_nclusters]
   Float_t         tree_Cluster_globZ[22];   //[tree_track_nclusters]
   Float_t         tree_Cluster_tsosglobX[22];   //[tree_track_nclusters]
   Float_t         tree_Cluster_tsosglobY[22];   //[tree_track_nclusters]
   Float_t         tree_Cluster_tsosglobZ[22];   //[tree_track_nclusters]
   Int_t           tree_Strips_nstrip;
   Int_t           tree_Strips_idFirst[22];   //[tree_track_nclusters]
   Int_t           tree_Strips_idLast[22];   //[tree_track_nclusters]
   Int_t           tree_Strips_stripCharges[171];   //[tree_Strips_nstrip]
   Float_t         tree_Strips_stripGains[171];   //[tree_Strips_nstrip]
   Float_t         tree_Strips_stripNoises[171];   //[tree_Strips_nstrip]
   Bool_t          tree_Strips_stripQualitiesBad[171];   //[tree_Strips_nstrip]

   // List of branches
   TBranch        *b_tree_track_nclusters;   //!
   TBranch        *b_tree_track_pt;   //!
   TBranch        *b_tree_track_eta;   //!
   TBranch        *b_tree_track_phi;   //!
   TBranch        *b_tree_track_nhits;   //!
   TBranch        *b_tree_track_NChi2;   //!
   TBranch        *b_tree_Cluster_subDet;   //!
   TBranch        *b_tree_Cluster_PetalSide;   //!
   TBranch        *b_tree_Cluster_LayerNbr;   //!
   TBranch        *b_tree_Cluster_WheelSide;   //!
   TBranch        *b_tree_Cluster_charge;   //!
   TBranch        *b_tree_Cluster_tsosx;   //!
   TBranch        *b_tree_Cluster_tsosy;   //!
   TBranch        *b_tree_Cluster_SoverN;   //!
   TBranch        *b_tree_Cluster_noise;   //!
   TBranch        *b_tree_Cluster_width;   //!
   TBranch        *b_tree_Cluster_detID;   //!
   TBranch        *b_tree_Cluster_barycenter;   //!
   TBranch        *b_tree_Cluster_locX;   //!
   TBranch        *b_tree_Cluster_locY;   //!
   TBranch        *b_tree_Cluster_globX;   //!
   TBranch        *b_tree_Cluster_globY;   //!
   TBranch        *b_tree_Cluster_globZ;   //!
   TBranch        *b_tree_Cluster_tsosglobX;   //!
   TBranch        *b_tree_Cluster_tsosglobY;   //!
   TBranch        *b_tree_Cluster_tsosglobZ;   //!
   TBranch        *b_tree_Strips_nstrip;   //!
   TBranch        *b_tree_Strips_idFirst;   //!
   TBranch        *b_tree_Strips_idLast;   //!
   TBranch        *b_tree_Strips_stripCharges;   //!
   TBranch        *b_tree_Strips_stripGains;   //!
   TBranch        *b_tree_Strips_stripNoises;   //!
   TBranch        *b_tree_Strips_stripQualitiesBad;   //!

   AnalysisMacro(TTree *tree=0);
   virtual ~AnalysisMacro();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef AnalysisMacro_cxx
AnalysisMacro::AnalysisMacro(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("histo.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("histo.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("histo.root:/demo");
      dir->GetObject("ttree",tree);

   }
   Init(tree);
}

AnalysisMacro::~AnalysisMacro()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t AnalysisMacro::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t AnalysisMacro::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void AnalysisMacro::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("tree_track_nclusters", &tree_track_nclusters, &b_tree_track_nclusters);
   fChain->SetBranchAddress("tree_track_pt", &tree_track_pt, &b_tree_track_pt);
   fChain->SetBranchAddress("tree_track_eta", &tree_track_eta, &b_tree_track_eta);
   fChain->SetBranchAddress("tree_track_phi", &tree_track_phi, &b_tree_track_phi);
   fChain->SetBranchAddress("tree_track_nhits", &tree_track_nhits, &b_tree_track_nhits);
   fChain->SetBranchAddress("tree_track_NChi2", &tree_track_NChi2, &b_tree_track_NChi2);
   fChain->SetBranchAddress("tree_Cluster_subDet", tree_Cluster_subDet, &b_tree_Cluster_subDet);
   fChain->SetBranchAddress("tree_Cluster_PetalSide", tree_Cluster_PetalSide, &b_tree_Cluster_PetalSide);
   fChain->SetBranchAddress("tree_Cluster_LayerNbr", tree_Cluster_LayerNbr, &b_tree_Cluster_LayerNbr);
   fChain->SetBranchAddress("tree_Cluster_WheelSide", tree_Cluster_WheelSide, &b_tree_Cluster_WheelSide);
   fChain->SetBranchAddress("tree_Cluster_charge", tree_Cluster_charge, &b_tree_Cluster_charge);
   fChain->SetBranchAddress("tree_Cluster_tsosx", tree_Cluster_tsosx, &b_tree_Cluster_tsosx);
   fChain->SetBranchAddress("tree_Cluster_tsosy", tree_Cluster_tsosy, &b_tree_Cluster_tsosy);
   fChain->SetBranchAddress("tree_Cluster_SoverN", tree_Cluster_SoverN, &b_tree_Cluster_SoverN);
   fChain->SetBranchAddress("tree_Cluster_noise", tree_Cluster_noise, &b_tree_Cluster_noise);
   fChain->SetBranchAddress("tree_Cluster_width", tree_Cluster_width, &b_tree_Cluster_width);
   fChain->SetBranchAddress("tree_Cluster_detID", tree_Cluster_detID, &b_tree_Cluster_detID);
   fChain->SetBranchAddress("tree_Cluster_barycenter", tree_Cluster_barycenter, &b_tree_Cluster_barycenter);
   fChain->SetBranchAddress("tree_Cluster_locX", tree_Cluster_locX, &b_tree_Cluster_locX);
   fChain->SetBranchAddress("tree_Cluster_locY", tree_Cluster_locY, &b_tree_Cluster_locY);
   fChain->SetBranchAddress("tree_Cluster_globX", tree_Cluster_globX, &b_tree_Cluster_globX);
   fChain->SetBranchAddress("tree_Cluster_globY", tree_Cluster_globY, &b_tree_Cluster_globY);
   fChain->SetBranchAddress("tree_Cluster_globZ", tree_Cluster_globZ, &b_tree_Cluster_globZ);
   fChain->SetBranchAddress("tree_Cluster_tsosglobX", tree_Cluster_tsosglobX, &b_tree_Cluster_tsosglobX);
   fChain->SetBranchAddress("tree_Cluster_tsosglobY", tree_Cluster_tsosglobY, &b_tree_Cluster_tsosglobY);
   fChain->SetBranchAddress("tree_Cluster_tsosglobZ", tree_Cluster_tsosglobZ, &b_tree_Cluster_tsosglobZ);
   fChain->SetBranchAddress("tree_Strips_nstrip", &tree_Strips_nstrip, &b_tree_Strips_nstrip);
   fChain->SetBranchAddress("tree_Strips_idFirst", tree_Strips_idFirst, &b_tree_Strips_idFirst);
   fChain->SetBranchAddress("tree_Strips_idLast", tree_Strips_idLast, &b_tree_Strips_idLast);
   fChain->SetBranchAddress("tree_Strips_stripCharges", tree_Strips_stripCharges, &b_tree_Strips_stripCharges);
   fChain->SetBranchAddress("tree_Strips_stripGains", tree_Strips_stripGains, &b_tree_Strips_stripGains);
   fChain->SetBranchAddress("tree_Strips_stripNoises", tree_Strips_stripNoises, &b_tree_Strips_stripNoises);
   fChain->SetBranchAddress("tree_Strips_stripQualitiesBad", tree_Strips_stripQualitiesBad, &b_tree_Strips_stripQualitiesBad);
   Notify();
}

Bool_t AnalysisMacro::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void AnalysisMacro::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t AnalysisMacro::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef AnalysisMacro_cxx
