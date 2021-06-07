#ifndef MAP_SCOPES_IN_TOKEN_STREAM_AND_AST
#define MAP_SCOPES_IN_TOKEN_STREAM_AND_AST

#include <functional>
#include "linearizeAST.h"
#include <vector>
#include <boost/tuple/tuple.hpp>

struct separator
   {
     int begin_pos;
     int end_pos;

  // DQ (11/1/2016): Fixup to allow compilation with the --enable-advanced-warnings option.
#ifndef _GLIBCXX_CONCEPT_CHECKS
     std::vector<separator> sub_separators;
#endif

     separator(int bp, int ep, std::vector<separator> ss );
     separator(int bp, int ep);

#ifndef ROSE_SKIP_COMPILATION_OF_WAVE
// #ifndef USE_ROSE
  // If we are using ROSE to compile ROSE source code then the Wave support is not present.
     void outputValues(token_container& tokenStream, int counter = 0);
// #endif
#endif

     void outputValues(std::vector<SgNode*>& linearizedAST, int counter = 0 );
   };

separator* mapSeparatorsAST(std::vector<SgNode*>& linearizedAST);

#ifndef ROSE_SKIP_COMPILATION_OF_WAVE
// #ifndef USE_ROSE
  // If we are using ROSE to compile ROSE source code then the Wave support is not present.
separator* mapSeparatorsTokenStream(token_container& tokenStream);
// #endif
#endif

#endif
