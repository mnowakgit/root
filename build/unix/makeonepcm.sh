#!/bin/sh
#
# Build a single large pcm for the entire basic set of ROOT libraries.
# Script takes as optional argument the source directory path.
#
# Copyright (c) 2013 Rene Brun and Fons Rademakers
# Author: Fons Rademakers, 19/2/2013

srcdir=.
if [ $# -eq 1 ]; then
   srcdir=$1
   modules=./*/
fi
if [ $# -eq 2 ]; then
   srcdir=$1
   modules=$2
fi

rm -f include/allHeaders.h include/allHeaders.h.pch include/allLinkDef.h all.h cppflags.txt include/allLinkDef.h

for dict in `find $modules -name 'G__*.cxx' | grep -v /G__Cling.cxx | grep -v core/metautils/src/G__std_`; do
    dirname=`dirname $dict` # to get foo/inc
    dirname=`dirname $dirname` # to get foo
    awk 'BEGIN{START=-1} /includePaths\[\] = {/, /^0$/ { if (START==-1) START=NR; else if ($0 != "0") { sub(/",/,"",$0); sub(/^"/,"-I",$0); print $0 } }' $dict >> cppflags.txt
    echo "// $dict" >> all.h
    awk 'BEGIN{START=-1} /payloadCode =/, /^;$/ { if (START==-1) START=NR; else if ($1 != ";") { code=substr($0,2); sub(/\\n"/,"",code); print code } }' $dict >> all.h
    awk 'BEGIN{START=-1} /headers\[\] = {/, /^0$/ { if (START==-1) START=NR; else if ($0 != "0") { sub(/,/,"",$0); print "#include",$0 } }' $dict >> all.h

    if ! test "$dirname" = "`echo $dirname| sed 's,/qt,,'`"; then
        # something qt; undef emit afterwards
        cat <<EOF >> all.h
#ifdef emit
# undef emit
#endif
EOF
    elif ! test "$dirname" = "`echo $dirname| sed 's,net/ldap,,'`"; then
        # ldap; undef Debug afterwards
        cat <<EOF >> all.h
#ifdef Debug
# undef Debug
#endif
EOF
    fi


    find $srcdir/$dirname/inc/ -name '*LinkDef*.h' | \
        sed -e 's|^|#include "|' -e 's|$|"|' >> alldefs.h
done

mv all.h include/allHeaders.h
mv alldefs.h include/allLinkDef.h

cxxflags="-D_LIBCPP_EXTERN_TEMPLATE(...)= -D__CLING__ -D__STDC_LIMIT_MACROS -D__STDC_CONSTANT_MACROS -Iinclude -Ietc -Ietc/cling `cat cppflags.txt | sort | uniq`"
#rm cppflags.txt

# generate one large pcm
rm -f allDict.* lib/allDict_rdict.pc*
touch etc/allDict.cxx.h
core/utils/src/rootcling_tmp -1 -f etc/allDict.cxx -c $cxxflags -I$srcdir include/allHeaders.h include/allLinkDef.h
res=$?
if [ $res -eq 0 ] ; then
  mv etc/allDict_rdict.pch etc/allDict.cxx.pch
  res=$?

  # actually we won't need the allDict.[h,cxx] files
  #rm -f allDict.*
fi

exit $res
