
//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

// Declarations for namespace_member_index facet of namespace sheaf.

#ifndef NAMESPACE_MEMBER_INDEX_H
#define NAMESPACE_MEMBER_INDEX_H

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
enum namespace_member_index
{
  NAMESPACE_MEMBER_INDEX_BEGIN = 2, // Must be same as first id.
  PRIMITIVES_SCHEMA_INDEX = 2, // 2
  NAMESPACE_SCHEMA_INDEX, // 3
  PRIMITIVES_INDEX, // 4
  SCHEMA_DEFINITIONS_INDEX, // 5
  NAMESPACE_MEMBER_INDEX_END, // Must be one more than last id.
  NOT_A_NAMESPACE_MEMBER_INDEX = INT_MAX
};

///
/// Prefix increment operator for namespace_member_index.
///
SHEAF_DLL_SPEC namespace_member_index& operator++(namespace_member_index& x);

///
/// The name of the enumerator xpt.
///
SHEAF_DLL_SPEC const string& namespace_member_index_to_name(namespace_member_index xpt);

///
/// The enumerator with name xname.
///
SHEAF_DLL_SPEC namespace_member_index namespace_member_index_from_name(const string& xname);

///
/// The enumerator corresponding to primitive index xindex.
///
SHEAF_DLL_SPEC namespace_member_index namespace_member_index_from_index(pod_index_type xindex);

///
/// True if xindex is a valid primitive index.
///
SHEAF_DLL_SPEC bool is_namespace_member_index(pod_index_type xindex);

} // namespace sheaf

#endif // ifndef NAMESPACE_MEMBER_INDEX_H






