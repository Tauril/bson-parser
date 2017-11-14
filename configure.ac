AC_PREREQ([2.64])

# Package set up.
AC_INIT([bson-parser], [1.0], [], [bson-parser])

# Auxiliary files.
AC_CONFIG_AUX_DIR([build-aux])

# Automake.
AM_INIT_AUTOMAKE([foreign -Wall silent-rules])

AM_SILENT_RULES([yes])


## --------------------- ##
## C++ Compiler Set up.  ##
## --------------------- ##

# Look for a C++ compiler.
AC_LANG([C++])
AC_PROG_CXX

# Enable C++ 2014 support.
AC_CANONICAL_HOST

## -------------------- ##
## Auxiliary programs.  ##
## -------------------- ##

# We don't need shared libraries, speed the compilation up.
LT_INIT([disable-shared])


## --------------- ##
## Configuration.  ##
## --------------- ##

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
