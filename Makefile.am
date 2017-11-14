AUTOMAKE_OPTIONS = subdir-objects

AM_DEFAULT_SOURCE_EXT = .cc

AM_CXXFLAGS  = -std=c++14 -O3 -Wall -Wextra -Werror -pedantic
AM_CPPFLAGS  = -I$(top_srcdir)/src

EXTRA_DIST = bootstrap ChallengeCpp3.md

bin_PROGRAMS = src/tauril-bson-parser

# ast
src_tauril_bson_parser_SOURCES =
	src/ast/fwd.hh
	src/ast/binary.hh src/ast/binary.cc src/ast/binary.hxx
	src/ast/binary-data.hh src/ast/binary-data.cc src/ast/binary-data.hxx
	src/ast/document.hh src/ast/document.cc src/ast/document.hxx
	src/ast/element.hh
	src/ast/e-list.hh
	src/ast/e-name.hh

# parser
src_tauril_bson_parser_SOURCES +=
	src/parser/bson-parser.hh src/parser/bson-parser.cc

# main
src_tauril_bson_parser_SOURCES += src/tauril-bson-parser.cc
