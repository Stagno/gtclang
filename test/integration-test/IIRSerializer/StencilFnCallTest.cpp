//===--------------------------------------------------------------------------------*- C++ -*-===//
//                         _       _
//                        | |     | |
//                    __ _| |_ ___| | __ _ _ __   __ _
//                   / _` | __/ __| |/ _` | '_ \ / _` |
//                  | (_| | || (__| | (_| | | | | (_| |
//                   \__, |\__\___|_|\__,_|_| |_|\__, | - GridTools Clang DSL
//                    __/ |                       __/ |
//                   |___/                       |___/
//
//
//  This file is distributed under the MIT License (MIT).
//  See LICENSE.txt for details.
//
//===------------------------------------------------------------------------------------------===//

// RUN: %gtclang% %file% -fwrite-iir -fno-codegen -o %filename%_gen.cpp
// EXPECTED_FILE: OUTPUT:%filename%.iir REFERENCE:%filename%_ref.iir IGNORE:filename

#include "gridtools/clang_dsl.hpp"

using namespace gridtools::clang;

stencil_function fn {
  storage a;
  Do { return a; }
};

stencil Test {
  storage a, b;

  Do { vertical_region(k_start, k_end) b = fn(a); }
};
