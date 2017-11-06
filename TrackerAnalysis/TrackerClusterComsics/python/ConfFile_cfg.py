import FWCore.ParameterSet.Config as cms

from RecoLocalTracker.Configuration.RecoLocalTracker_Cosmics_cff import *
from RecoTracker.MeasurementDet.MeasurementTrackerEventProducer_cfi import *
from RecoTracker.Configuration.RecoTrackerP5_cff import *

process = cms.Process("Demo")






process.load("FWCore.MessageService.MessageLogger_cfi")


process.MessageLogger.cout = cms.untracked.PSet(INFO = cms.untracked.PSet(
    reportEvery = cms.untracked.int32(10000), # every 100th only
    limit = cms.untracked.int32(10)	    # or limit to 10 printouts...
))

 # Conditions (Global Tag is used here):
process.load('Configuration/StandardSequences/FrontierConditions_GlobalTag_cff')
process.GlobalTag.globaltag = '92X_upgrade2017_realistic_v7'

process.load('Configuration.StandardSequences.Services_cff')

#Geometry and field
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load("Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff")

process.load("RecoTracker.TrackProducer.TrackRefitters_cff")
process.load("TrackingTools/TransientTrack/TransientTrackBuilder_cfi")


process.TFileService = cms.Service("TFileService", fileName = cms.string("histo.root") )
 


process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
  
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/444/00000/780D7DB1-50BC-E711-8495-02163E019DCE.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/444/00000/289D8718-4FBC-E711-8B82-02163E0137EA.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/444/00000/780D7DB1-50BC-E711-8495-02163E019DCE.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/444/00000/A4A281A5-50BC-E711-9D59-02163E011BB9.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/446/00000/02FB9C9A-52BC-E711-AC93-02163E019DB9.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/446/00000/1CFC4543-4FBC-E711-AAE1-02163E0140E1.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/446/00000/2674B85D-4FBC-E711-8289-02163E014116.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/446/00000/3C9A4EF8-50BC-E711-8AD9-02163E019E58.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/446/00000/749FF1EF-50BC-E711-B4EA-02163E01A1E5.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/446/00000/98ACAB9B-50BC-E711-AB5F-02163E019CCA.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/446/00000/D2487719-4FBC-E711-BB75-02163E012857.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/449/00000/14B72850-52BC-E711-B5DD-02163E019CAD.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/759/00000/FE36A760-4CBF-E711-A23A-02163E014135.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/815/00000/5CBFAA7E-6BC0-E711-9D02-02163E01A6CA.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/815/00000/7E8613A3-68C0-E711-A35A-02163E01282E.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/816/00000/380CC6D7-69C0-E711-A9EA-02163E0137EE.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017E/Cosmics/RECO/PromptReco-v1/000/304/665/00000/0438FD64-23AF-E711-B7F1-02163E0142B0.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017E/Cosmics/RECO/PromptReco-v1/000/304/665/00000/32278CBE-27AF-E711-9CF3-02163E019E87.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017E/Cosmics/RECO/PromptReco-v1/000/304/665/00000/88792559-23AF-E711-A2DF-02163E01A4B9.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017E/Cosmics/RECO/PromptReco-v1/000/304/665/00000/982AEAA1-22AF-E711-9B7E-02163E01A4AB.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017E/Cosmics/RECO/PromptReco-v1/000/304/665/00000/BA3ADD9F-22AF-E711-8D0D-02163E019C68.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017E/Cosmics/RECO/PromptReco-v1/000/304/665/00000/CA1BC283-22AF-E711-BBAC-02163E014148.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017E/Cosmics/RECO/PromptReco-v1/000/304/665/00000/CADAD048-21AF-E711-964B-02163E0141CD.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017E/Cosmics/RECO/PromptReco-v1/000/304/665/00000/FC39F78A-22AF-E711-A3A8-02163E019DCE.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017E/Cosmics/RECO/PromptReco-v1/000/304/665/00000/FE1E824C-21AF-E711-AD08-02163E0142C4.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017E/Cosmics/RECO/PromptReco-v1/000/304/686/00000/C6772FB8-82AF-E711-BED0-02163E01A6AD.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/360/00000/02C6C17B-A2B9-E711-90D0-02163E01180F.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/360/00000/12B91BD5-A5B9-E711-ADD2-02163E019C85.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/360/00000/145F0DD7-AFB9-E711-8F1E-02163E019B29.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/360/00000/1A422A5F-A4B9-E711-BB74-02163E01350D.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/360/00000/241C21C7-B6B9-E711-9F93-02163E019CA3.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/360/00000/2C46CB6D-ACB9-E711-B9CC-02163E019B4F.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/360/00000/52DF2EDE-AAB9-E711-BB62-02163E011D13.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/360/00000/62485CA7-A9B9-E711-9A2C-02163E01373F.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/360/00000/7213561E-A4B9-E711-A818-02163E019B89.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/360/00000/729B4436-A7B9-E711-B09E-02163E0134AE.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/360/00000/78F6E4C7-AAB9-E711-8191-02163E014416.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/360/00000/867CFE88-A5B9-E711-9910-02163E0142E4.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/360/00000/9A17DFBA-ACB9-E711-BF70-02163E01A56F.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/360/00000/A25743B1-A5B9-E711-AF95-02163E019C3E.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/360/00000/EC839F8C-ACB9-E711-944A-02163E019B4E.root',
 'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/360/00000/ECC9B1DC-AEB9-E711-B448-02163E011FA3.root'
 
 
 
 
 
 
 
 
 
 
 
        #'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/018/00000/B49E4FA9-C3B1-E711-81F4-02163E01A1E2.root',
	#'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/020/00000/32BCB2D7-C3B1-E711-A487-02163E01A4E3.root',
	#'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/021/00000/EC0C9D92-C3B1-E711-A84F-02163E01A690.root',
	#'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/038/00000/2E347F44-DFB1-E711-A390-02163E0144D1.root',
	#'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/047/00000/0632C6EC-73B2-E711-97C3-02163E0133B5.root',
	#'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/047/00000/6826B02C-76B2-E711-BF9F-02163E019E22.root',
	#'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/055/00000/1465BDB3-74B2-E711-AD8B-02163E01A516.root',
	#'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RECO/PromptReco-v1/000/305/058/00000/4E18D323-75B2-E711-8635-02163E011BF1.root'
        #'root://cms-xrd-global.cern.ch//store/data/Run2017F/Cosmics/RAW-RECO/CosmicSP-PromptReco-v1/000/305/018/00000/F48B1D07-C5B1-E711-8A77-02163E012222.root'
    )
)


process.load("RecoTracker.MeasurementDet.MeasurementTrackerEventProducer_cfi")


process.demo = cms.EDAnalyzer('TrackerClusterComsics', 
    trackLabel         = cms.InputTag("ctfWithMaterialTracksP5"),
    tkTraj             = cms.InputTag('TrackRefitterP5'),
    labelTrajToTrack   = cms.InputTag('TrackRefitterP5'),
    siStripClusters    = cms.InputTag('TrackRefitterP5'),
    TTRHBuilder        = cms.string('WithTrackAngle')
)

#process.TrackRefitteP5r.src = 'ctfWithMaterialTracksP5'


process.p = cms.Path(process.MeasurementTrackerEvent*process.TrackRefitterP5*process.demo)
