inherit pkgconfig

require openssl.inc

PR = "${INC_PR}.0"

SRC_URI += "file://debian.patch \
            file://armeb.patch;striplevel=0 \
            file://gnueabi-arm.patch \
            file://gnueabi-armeb.patch \
            file://uclibcgnueabi.patch \
            file://avr32.patch;striplevel=0"

SRC_URI[src.md5sum] = "74a4d1b87e1e6e1ec95dbe58cb4c5b9a"
SRC_URI[src.sha256sum] = "c98b9703887e2dda6217b91405d0d94883f7c67e205fc4d7a81bb690d2e10572"