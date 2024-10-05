#!/bin/bash

# I'm doing this in a bash script because I don't understand Makefiles enough

# turn these into raw files
# first two are BGR packing, no alpha
convert artwork/about.png BGR:about
convert artwork/background.png BGR:background

# second two are BGRA packing
convert artwork/aboutButtonNormal.png BGRA:aboutButtonNormal
convert artwork/aboutButtonHover.png BGRA:aboutButtonHover

# link them into an object
ld -r -b binary -o images.o about background aboutButtonNormal aboutButtonHover

# this will have symbols in like _binary_about_start, _binary_about_end, and
# _binary_about_length, that we use in DistrhoArtworkNekobi.cpp

# clean up
rm about background aboutButtonNormal aboutButtonHover





