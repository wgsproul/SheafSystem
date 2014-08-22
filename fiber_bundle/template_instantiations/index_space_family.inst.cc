
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

// Explicit instantiations for class index_space_family.

#include "ComLimitPoint/sheaf/index_space_family.impl.h"

#include "ComLimitPoint/fiber_bundle/section_space_schema_jims_index_space_handle.h"

using namespace std;

//============================================================
// EXPLICIT INSTANTIATIONS
//============================================================

//==============================================================================
// section_space_schema_jims_index_space_handle
//==============================================================================

template
SHEAF_DLL_SPEC
bool
sheaf::index_space_family::
handle_conforms_to_state<fiber_bundle::section_space_schema_jims_index_space_handle>(const string& xname) const;

template
SHEAF_DLL_SPEC
fiber_bundle::section_space_schema_jims_index_space_handle&
sheaf::index_space_family::
get_id_space<fiber_bundle::section_space_schema_jims_index_space_handle>(const string& xname) const;

template
SHEAF_DLL_SPEC
bool
sheaf::index_space_family::
handle_conforms_to_state<fiber_bundle::section_space_schema_jims_index_space_handle>(pod_type xid) const;

template
SHEAF_DLL_SPEC
fiber_bundle::section_space_schema_jims_index_space_handle&
sheaf::index_space_family::
get_id_space<fiber_bundle::section_space_schema_jims_index_space_handle>(pod_type xid) const;
