require ${PN}.inc

PR = "r0"

SRC_URI = "http://sources.openembedded.org/opie-1.2.5-split_inputmethods_multikey.tar.bz2 \
           http://sources.openembedded.org/opie-1.2.5-split_share.tar.bz2 \
           file://fix-rpath.patch"

#           file://friendly-button-names.patch"