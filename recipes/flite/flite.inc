DESCRIPTION = "flite - the festival light speech synthesizer"
PRIORITY = "optional"
HOMEPAGE = "http://www.speech.cs.cmu.edu/flite/"
SECTION = "console/utils"
LICENSE = "flite"
DEPENDS = "alsa-oss"

PARALLEL_MAKE = ""

S = "${WORKDIR}/flite-${PV}-release"

CFLAGS += " -lasound "

inherit autotools

PACKAGES += "lib${PN} lib${PN}-vox8 lib${PN}-vox16"

FILES_${PN} = "${bindir}"

FILES_lib${PN} ="${libdir}/libflite.so.* \
                 ${libdir}/libflite_cmu_time_awb.so.* \
		 ${libdir}/libflite_cmulex.so.* \
		 ${libdir}/libflite_usenglish.so.*"

FILES_lib${PN}-vox8 = "${libdir}/libflite_cmu_us_kal.so.*"

FILES_lib${PN}-vox16 = "${libdir}/libflite_cmu_us_kal16.so.*"

LEAD_SONAME = "libflite.so"

do_install() {
        oe_runmake INSTALLBINDIR="${D}${bindir}" INSTALLLIBDIR="${D}${libdir}" INSTALLINCDIR="${D}${includedir}" install
}

do_stage () {
        install -d ${STAGING_INCDIR}/flite
        install -m 0644 ${S}/include/*.h ${STAGING_INCDIR}/flite/

        oe_libinstall -C lib -a -so libflite ${STAGING_LIBDIR}
        oe_libinstall -C lib -a -so libflite_cmu_time_awb ${STAGING_LIBDIR}
        oe_libinstall -C lib -a -so libflite_cmulex ${STAGING_LIBDIR}
        oe_libinstall -C lib -a -so libflite_usenglish ${STAGING_LIBDIR}
        oe_libinstall -C lib -a -so libflite_cmu_us_kal ${STAGING_LIBDIR}
        oe_libinstall -C lib -a -so libflite_cmu_us_kal16 ${STAGING_LIBDIR}
}
