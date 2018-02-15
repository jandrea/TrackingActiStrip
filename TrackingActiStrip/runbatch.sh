#!/bin/sh
ulimit -s unlimited
cd /afs/cern.ch/work/j/jandrea/TrackingActiStrip/CMSSW_9_2_13/src/Express/
pwd
export X509_USER_PROXY=/afs/cern.ch/user/j/jandrea/x509up_u14793
echo "gros connard"
export SCRAM_ARCH=slc6_amd64_gcc491
eval `scramv1 runtime -sh`
cmsRun ../TrackerAnalysis/TrackerClusterComsics/python/ConfFileExpres_cfg.py

 
