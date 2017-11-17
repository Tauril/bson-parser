AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = -I build-aux/m4

AM_DEFAULT_SOURCE_EXT = .cc

AM_CXXFLAGS  = -std=c++14 -Wall -Wextra -Werror -pedantic
AM_CPPFLAGS  = -I$(top_srcdir)/src -I$(top_builddir)/src -I$(top_builddir)
AM_CPPFLAGS += $(BOOST_CPPFLAGS)

EXTRA_DIST = bootstrap ChallengeCpp3.md

bin_PROGRAMS = src/tauril-bson-parser

# ast
src_tauril_bson_parser_SOURCES = \
	src/ast/fwd.hh \
	src/ast/types.hh \
	src/ast/binary.hh src/ast/binary.cc src/ast/binary.hxx \
	src/ast/boolean.hh src/ast/boolean.cc src/ast/boolean.hxx \
	src/ast/code-ws.hh src/ast/code-ws.cc src/ast/code-ws.hxx \
	src/ast/db-pointer.hh src/ast/db-pointer.cc src/ast/db-pointer.hxx \
	src/ast/object-id.hh src/ast/object-id.cc src/ast/object-id.hxx \
	src/ast/regex.hh src/ast/regex.cc src/ast/regex.hxx \
	src/ast/string.hh src/ast/string.cc src/ast/string.hxx \
	src/ast/element.hh src/ast/element.hxx \
	src/ast/document.hh src/ast/document.cc src/ast/document.hxx

# parser
src_tauril_bson_parser_SOURCES += \
	src/parser/bson-parser.hh src/parser/bson-parser.cc

# main
src_tauril_bson_parser_SOURCES += src/tauril-bson-parser.cc
