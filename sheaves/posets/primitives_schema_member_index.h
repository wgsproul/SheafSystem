
//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

// Declarations for primitives_schema_member_index facet of namespace sheaf.

#ifndef PRIMITIVES_SCHEMA_MEMBER_INDEX_H
#define PRIMITIVES_SCHEMA_MEMBER_INDEX_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef STD_CLIMITS_H
#include "std_climits.h"
#endif

#ifndef POD_TYPES_H
#include "pod_types.h"
#endif

namespace sheaf
{

///
/// Ids for standard poset members.
///
enum primitives_schema_member_index
{
  PRIMITIVES_SCHEMA_MEMBER_INDEX_BEGIN = 2, // Must be same as first std id.
  SIZE_INDEX = 2,
  ALIGNMENT_INDEX, // 3
  INDEX_INDEX, // 4
  PRIMITIVES_SCHEMA_MEMBER_INDEX_END, // Must be one more than last std id.
  NOT_A_PRIMITIVES_SCHEMA_MEMBER_INDEX = INT_MAX
};

///
/// Number of dofs defined by primitives schema
///
const int PRIMITIVES_SCHEMA_DOF_CT =
  PRIMITIVES_SCHEMA_MEMBER_INDEX_END - PRIMITIVES_SCHEMA_MEMBER_INDEX_BEGIN;


///
/// Prefix increment operator for primitives_schema_member_index.
///
SHEAF_DLL_SPEC primitives_schema_member_index& operator++(primitives_schema_member_index& x);

///
/// The name of the enumerator xpt.
///
SHEAF_DLL_SPEC const string& primitives_schema_member_index_to_name(primitives_schema_member_index xpt);

///
/// The enumerator with name xname.
///
SHEAF_DLL_SPEC primitives_schema_member_index primitives_schema_member_index_from_name(const string& xname);

///
/// The enumerator corresponding to primitive index xindex.
///
SHEAF_DLL_SPEC primitives_schema_member_index primitives_schema_member_index_from_index(pod_index_type xindex);

///
/// True if xindex is a valid primitive index.
///
SHEAF_DLL_SPEC bool is_primitives_schema_member_index(pod_index_type xindex);

} // namespace sheaf

#endif // ifndef PRIMITIVES_SCHEMA_MEMBER_INDEX_H






