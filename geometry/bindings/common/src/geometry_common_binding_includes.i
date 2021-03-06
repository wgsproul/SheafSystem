
//
// Copyright (c) 2014 Limit Point Systems, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

//
//
// Common SWIG interface to geometry cluster
//

//=============================================================================

//$$SCRIBBLE: This file contains only the part of the Swig interface which
//            is to be inserted directly into the generated code.
//            We have to break the interface into two parts because
//            of the way Swig handles "%import" versus "%include".
//            If you change this file make sure you also change
//            "geometry_common_binding.i" as well.

//=============================================================================

%{

#include "geometry.h"

#include "d_bin_coordinates.h"
#include "d_bounding_box.h"
#include "d_tree_point_locator_node.h"
#include "d_tree_point_locator_path.h"

#include "point_locator.h"
#include       "cylindrical_point_locator.h"
#include             "array_cylindrical_point_locator.h"
#include       "d_bin_point_locator.h"
#include             "d_array_point_locator.h"
#include             "d_tree_point_locator.h"
#include       "d_uniform_point_locator.h"
#include       "db0_point_locator.h"

#include "sec_ed_invertible.h"

using namespace std;
using namespace geometry;

%}
