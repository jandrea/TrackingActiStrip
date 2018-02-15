import FWCore.ParameterSet.Config as cms
from RecoLocalTracker.Configuration.RecoLocalTracker_Cosmics_cff import *
from RecoTracker.MeasurementDet.MeasurementTrackerEventProducer_cfi import *
from RecoTracker.Configuration.RecoTrackerP5_cff import *

process = cms.Process("Demo")
process.load("FWCore.MessageService.MessageLogger_cfi")


process.MessageLogger.cout = cms.untracked.PSet(INFO = cms.untracked.PSet(
    reportEvery = cms.untracked.int32(10000), # every 100th only
    limit = cms.untracked.int32(10)         # or limit to 10 printouts...
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
process.load("RecoTracker.MeasurementDet.MeasurementTrackerEventProducer_cfi")

process.demo = cms.EDAnalyzer('TrackerClusterComsics',
    trackLabel         = cms.InputTag("ctfWithMaterialTracksP5"),
    tkTraj             = cms.InputTag('TrackRefitterP5'),
    labelTrajToTrack   = cms.InputTag('TrackRefitterP5'),
    siStripClusters    = cms.InputTag('TrackRefitterP5'),
    TTRHBuilder        = cms.string('WithTrackAngle')
)

process.p = cms.Path(process.MeasurementTrackerEvent*process.TrackRefitterP5*process.demo)
