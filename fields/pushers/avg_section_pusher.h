
//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

/// @file
/// Interface for class avg_section_pusher.

#ifndef AVG_SECTION_PUSHER_H
#define AVG_SECTION_PUSHER_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef SECTION_PUSHER_H
#include "section_pusher.h"
#endif

namespace fields
{

///
/// A section pusher that uses extension by averaging to
/// define the target outside the domain of the source;
/// an incomplete implementation intended mostly as an example
/// of how the section_pusher hierarchy differentiates.
///
class SHEAF_DLL_SPEC avg_section_pusher : public section_pusher
{

  // =============================================================================
  /// @name AVG_SECTION_PUSHER FACET
  // =============================================================================
  //@{

public:

  ///
  /// Creates the push-forward from xdomain to xrange
  /// induced by xdom_coord and xran_coord.
  ///
  avg_section_pusher(const sec_rep_space& xdomain,
                     const sec_rep_space& xrange,
                     const geometry::sec_ed_invertible& xdom_coord,
                     const sec_ed& xran_coord,
                     bool xauto_access);

protected:

  ///
  /// Default constructor.
  ///
  avg_section_pusher();

  ///
  /// Creates a value for the dofs at disc point xdisc_id.
  /// Intended for use when xdisc_id lies outside the domain
  /// of the source field.
  ///
  virtual void extend(sec_vd& result, const scoped_index& xdisc_id);

  /// @issue it is not clear what the extend signature should be
  /// for maximum combined generality and efficiency.

  //@}


  // =============================================================================
  /// @name ANY FACET
  // =============================================================================
  //@{

public:

  ///
  /// Copy constructor.
  ///
  avg_section_pusher(const avg_section_pusher& xother);

  ///
  /// Destructor.
  ///
  virtual ~avg_section_pusher();

  ///
  /// Class invariant.
  ///
  virtual bool invariant() const;

  //@}
};
  
} // namespace fields

#endif // ifndef AVG_SECTION_PUSHER_H
