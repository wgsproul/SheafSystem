
//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

// Interface for class subposet_names_record

#ifndef SUBPOSET_NAMES_RECORD_H
#define SUBPOSET_NAMES_RECORD_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef ATTRIBUTES_RECORD_H
#include "attributes_record.h"
#endif

namespace sheaf
{
  
///
/// A wrapper/adapter for the subposet names record.
/// Intended for transferring subposet name data
/// between the kernel and the i/o subsystem.
///
///
class SHEAF_DLL_SPEC subposet_names_record : public attributes_record
{
public:

  // =============================================================================
  // ANY FACET
  // =============================================================================

  ///
  /// Virtual constructor;
  /// makes a new instance of
  /// the same type as this
  ///
  virtual subposet_names_record* clone() const;

  ///
  /// Class invariant.
  ///
  virtual bool invariant() const;

  ///
  /// Conformance test; true if other conforms to this
  ///
  virtual bool is_ancestor_of(const any* other) const;

  // =============================================================================
  // SUBPOSET_NAMES_RECORD FACET
  // =============================================================================

  ///
  /// Creates an instance with type map xtype_map
  ///
  subposet_names_record(poset_scaffold& xscaffold);

  ///
  /// Copy constructor
  ///
  ///
  subposet_names_record(const subposet_names_record& xother);

  ///
  /// Destructor
  ///
  virtual ~subposet_names_record();

protected:

  ///
  /// Initializes member with index xmbr_id from the internal buffer.
  ///
  virtual void transfer_internal_buffer_to_poset();

  ///
  /// Initializes the internal buffer from the member with index xmbr_id.
  ///
  virtual void transfer_poset_to_internal_buffer();
};

} // namespace sheaf

#endif // ifndef SUBPOSET_NAMES_RECORD_H






