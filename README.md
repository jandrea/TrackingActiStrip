# TrackingActiStrip
TrackingActiStrip
//to install and run the EDAnalyzer

cmsrel CMSSW_9_2_13

cd CMSSW_9_2_13/src

git clone git://github.com/jandrea/TrackingActiStrip.git

mv TrackingActiStrip/TrackerAnalysis .

scramv1 b

cmsenv

cmsRun TrackerAnalysis/TrackerClusterComsics/python/ConfFile_cfg.py

//to run on express stream, 

cmsRun TrackerAnalysis/TrackerClusterComsics/python/ConfFileExpres_cfg.py

//once the data are process, the EDAnalyzer produced a root file, that contains a TTree
//then, root macros to read the tree can be see in the directory RootMacros
//to produce histograms

cd RootMacros

root -l

>L AnalysisMacro.C+;

> AnalysisMacro.C t;

>t.Loop();

//it produces a files containing several histograms ?
//to produce plots out of the histograms, you can :

root -l -b DoPlots.C+


 
