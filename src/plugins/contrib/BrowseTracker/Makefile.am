AM_CPPFLAGS = $(WX_CXXFLAGS) \
			-I$(top_srcdir)/src/include \
			-I$(top_srcdir)/src/sdk/wxscintilla/include

pluginlibdir = $(pkglibdir)/plugins

pluginlib_LTLIBRARIES = libBrowseTracker.la

libBrowseTracker_la_LDFLAGS = @MODULE_SHARED_LDFLAGS@ -version-info 0:1:0 -no-undefined -avoid-version

libBrowseTracker_la_LIBADD = ../../../sdk/libcodeblocks.la \
			$(WX_LIBS)

libBrowseTracker_la_SOURCES = BrowseTracker.cpp \
			Version.cpp \
			BrowseMarks.cpp \
			BrowseTrackerConfPanel.cpp \
			BrowseTrackerLayout.cpp \
			ConfigPanel.cpp \
			ProjectData.cpp \
			JumpTracker.cpp \
			JumpTrackerView.cpp \
			JumpData.cpp \
			btswitcherdlg.cpp \
			helpers.cpp

noinst_HEADERS =  	BrowseTracker.h \
			Version.h \
			BrowseMarks.h \
			BrowseTrackerDefs.h \
			BrowseTrackerConfPanel.h \
			BrowseTrackerLayout.h \
			ConfigPanel.h \
			ProjectData.h \
			JumpTracker.h \
			JumpTrackerView.h \
			JumpData.h \
			btswitcherdlg.h \
			helpers.h

resources_forZIP = \
	BrowseTrackerToolbar.xrc \
	manifest.xml \
	images/16x16/mark_clear.png \
	images/16x16/mark_next.png \
	images/16x16/mark.png \
	images/16x16/mark_prev.png \
	images/16x16/next.png \
	images/16x16/prev.png \
	images/16x16/signpost.png \
	images/20x20/mark_clear.png \
	images/20x20/mark_next.png \
	images/20x20/mark.png \
	images/20x20/mark_prev.png \
	images/20x20/next.png \
	images/20x20/prev.png \
	images/20x20/signpost.png \
	images/24x24/mark_clear.png \
	images/24x24/mark_next.png \
	images/24x24/mark.png \
	images/24x24/mark_prev.png \
	images/24x24/next.png \
	images/24x24/prev.png \
	images/24x24/signpost.png \
	images/28x28/mark_clear.png \
	images/28x28/mark_next.png \
	images/28x28/mark.png \
	images/28x28/mark_prev.png \
	images/28x28/next.png \
	images/28x28/prev.png \
	images/28x28/signpost.png \
	images/32x32/mark_clear.png \
	images/32x32/mark_next.png \
	images/32x32/mark.png \
	images/32x32/mark_prev.png \
	images/32x32/next.png \
	images/32x32/prev.png \
	images/32x32/signpost.png \
	images/40x40/mark_clear.png \
	images/40x40/mark_next.png \
	images/40x40/mark.png \
	images/40x40/mark_prev.png \
	images/40x40/next.png \
	images/40x40/prev.png \
	images/40x40/signpost.png \
	images/48x48/mark_clear.png \
	images/48x48/mark_next.png \
	images/48x48/mark.png \
	images/48x48/mark_prev.png \
	images/48x48/next.png \
	images/48x48/prev.png \
	images/48x48/signpost.png \
	images/56x56/mark_clear.png \
	images/56x56/mark_next.png \
	images/56x56/mark.png \
	images/56x56/mark_prev.png \
	images/56x56/next.png \
	images/56x56/prev.png \
	images/56x56/signpost.png \
	images/64x64/mark_clear.png \
	images/64x64/mark_next.png \
	images/64x64/mark.png \
	images/64x64/mark_prev.png \
	images/64x64/next.png \
	images/64x64/prev.png \
	images/64x64/signpost.png \
	images/svg/mark_clear.svg \
	images/svg/mark_next.svg \
	images/svg/mark.svg \
	images/svg/mark_prev.svg \
	images/svg/next.svg \
	images/svg/prev.svg \
	images/svg/signpost.svg

EXTRA_DIST = \
	$(srcdir)/*.cbp \
	$(resources_forZIP)

pkgdata_DATA = BrowseTracker.zip
CLEANFILES = $(pkgdata_DATA)

BrowseTracker.zip: $(resources_forZIP)
	PWD=`pwd` cd $(srcdir) && zip $(PWD)/BrowseTracker.zip $(resources_forZIP) > /dev/null
