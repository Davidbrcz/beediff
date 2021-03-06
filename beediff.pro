TEMPLATE =  app
CONFIG +=  qt release warn_on x11
QMAKE_CXXFLAGS_DEBUG = -O0 -g
QMAKE_CXXFLAGS_RELEASE = -O3
OBJECTS_DIR =  ./tmp
MOC_DIR =  ./tmp
QT += widgets
QT += core

SOURCES =  \
	BtStringTool.cpp \
	QBtBrowser.cpp \
	QBtColorDemo.cpp \
	QBtConfig.cpp \
	QBtConfigDialog.cpp \
	QBtConfigDiffProcess.cpp \
	QBtConfigOthers.cpp \
	QBtConfigTextViewer.cpp \
	QBtDiffInfo.cpp \
	QBtDiffProcess.cpp \
	QBtEventsController.cpp \
	QBtIndicator.cpp \
	QBtMainWindow.cpp \
	QBtNumeration.cpp \
	QBtOperator.cpp \
	QBtSaveQuestion.cpp \
	QBtSeparator.cpp \
	QBtSettings.cpp \
	QBtShared.cpp \
	QBtSyntax.cpp \
	QBtWorkspace.cpp \
	beediff.cpp
RESOURCES =  beediff.qrc
HEADERS =  \
	BtStringTool.h \
	BtToken.h \
	QBiConfigWidget.h \
	QBtBrowser.h \
	QBtColorDemo.h \
	QBtConfig.h \
	QBtConfigDialog.h \
	QBtConfigDiffProcess.h \
	QBtConfigOthers.h \
	QBtConfigTextViewer.h \
	QBtDiffInfo.h \
	QBtDiffProcess.h \
	QBtEvent.h \
	QBtEventsController.h \
	QBtIndicator.h \
	QBtLineData.h \
	QBtMainWindow.h \
	QBtMarkerInfo.h \
	QBtNumeration.h \
	QBtOperator.h \
	QBtRange.h \
	QBtSaveQuestion.h \
	QBtSeparator.h \
	QBtSettings.h \
	QBtShared.h \
	QBtSyntax.h \
	QBtWorkspace.h
