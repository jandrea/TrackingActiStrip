from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName 	= 'cosmicnoise_Run2016A_6_12_2017_test_2'
config.General.workArea 	= 'crab_projects'
config.General.transferOutputs 	= True
config.General.transferLogs	= True

config.JobType.pluginName 	= 'Analysis'
config.JobType.psetName 	= 'runCosmics.py'

config.Data.inputDataset 	= '/Cosmics/Run2016A-v1/RAW'#/Cosmics/Run2016A-PromptReco-v1/RECO'
config.Data.inputDBS 		= 'global'
config.Data.splitting 		= 'FileBased'
config.Data.unitsPerJob 	= 1
config.Data.lumiMask 		= '/afs/cern.ch/user/o/ocolegro/CMSSW_9_2_13/src/TrackerAnalysis/TrackerClusterComsics/python/noisyruns.txt'
config.Data.outLFNDirBase 	= '/store/user/%s/' % (getUsernameFromSiteDB())
config.Data.publication 	= False
config.Data.outputDatasetTag 	= 'cosmicnoise_Run2016A_6_12_2017_2'
config.Site.storageSite 	= 'T2_US_UCSD'
config.Site.blacklist = ['T2_IT_Legnaro','T2_US_UCSD']
