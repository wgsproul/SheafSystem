

//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

// Explicit_instantiations for class e4.

#include "e4.impl.h"

using namespace fiber_bundle; // Workaround for MS C++ bug.

//==============================================================================
// EXPLICIT INSTANTIATIONS
//==============================================================================

//==============================================================================
// e4
//==============================================================================

template class
SHEAF_DLL_SPEC
fiber_bundle::e4_row_dofs_type<double>;

#ifndef DOXYGEN_SKIP_INSTANTIATIONS

template
SHEAF_DLL_SPEC
ostream& fiber_bundle::operator<< <double>(
    ostream&, const fiber_bundle::e4_row_dofs_type<double>&);

#endif // ifndef DOXYGEN_SKIP_INSTANTIATIONS

//template class
//SHEAF_DLL_SPEC
//fiber_bundle::e4_row_dofs_type<float>;

//template
//SHEAF_DLL_SPEC
//ostream& fiber_bundle::operator<<(
//    ostream&, const fiber_bundle::e4_row_dofs_type<float>&);

