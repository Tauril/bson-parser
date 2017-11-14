AC_PREREQ([2.64])

# Package set up.
AC_INIT([bson-parser], [1.0], [], [bson-parser])

# Auxiliary files.
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([build-aux/m4])

# Automake.
AM_INIT_AUTOMAKE([foreign -Wall -Werror silent-rules])

AM_SILENT_RULES([yes])


## --------------------- ##
## C++ Compiler Set up.  ##
## --------------------- ##

# Look for a C++ compiler.
AC_LANG([C++])
AC_PROG_CXX

# Enable C++ 2014 support.
AC_CANONICAL_HOST

## ----------- ##
## Libraries.  ##
## ----------- ##

BOOST_REQUIRE([1.61])
BOOST_VARIANT

## --------------- ##
## Configuration.  ##
## --------------- ##

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
