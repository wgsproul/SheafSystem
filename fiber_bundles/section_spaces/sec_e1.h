


//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

/// @file
/// Interface for class sec_e1.

#ifndef SEC_E1_H
#define SEC_E1_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef E1_H
#include "e1.h"
#endif

#ifndef SEC_ED_H
#include "sec_ed.h"
#endif

namespace fiber_bundle
{

//==============================================================================
// CLASS SEC_E1
//==============================================================================

///
/// A section of a fiber bundle with a 1-dimensional Euclidean
/// vector space fiber.
///
class SHEAF_DLL_SPEC sec_e1 : public sec_ed
{

  //============================================================================
  /// @name E1 FACET OF CLASS SEC_E1
  //============================================================================
  //@{

public:

  ///
  /// The fiber type.
  ///
  typedef e1 fiber_type;

  ///
  /// Type of underlying vector space.
  ///
  typedef sec_e1 vector_space_type;

  ///
  /// default constructor
  ///
  sec_e1();

  ///
  /// Creates a new sec_e1 handle attached to the member state with hub id
  /// xhub_id in* xhost.
  ///
  sec_e1(const sec_rep_space* xhost, pod_index_type xhub_id);

  ///
  /// Creates a new sec_e1 handle attached to the member state with id xid
  /// in* xhost.
  ///
  sec_e1(const sec_rep_space* xhost, const scoped_index& xid);

  ///
  /// Creates a new sec_e1 handle attached to the member state with name xname
  /// in* xhost.
  ///
  sec_e1(const sec_rep_space* xhost, const string& xname);

  ///
  /// Creates a new handle attached to the member state
  /// with path xpath in namespace xnamespace.
  ///
  sec_e1(const namespace_poset* xnamespace,
         const poset_path& xpath,
         bool xauto_access = true);

  ///
  /// Creates a new sec_e1 handle attached to the same state as xother.
  ///
  explicit sec_e1(const sec_rep_space_member* xother);

  ///
  /// Creates a new handle attached to a new jim state in host xhost.
  ///
  sec_e1(sec_rep_space* xhost,
         section_dof_map* xdof_map = 0,
         bool xauto_access = true);

  ///
  /// Creates a new handle attached to a new jim state
  /// which is a partial section defined only on the base space
  /// member with index xbase_mbr_index and version xbase_version.
  ///
  sec_e1(sec_rep_space* xhost,
         abstract_poset_member& xbase_mbr,
         int xbase_version = CURRENT_HOST_VERSION,
         bool xauto_access = true);

  ///
  /// Creates a new handle attached to a new jrm state which is
  /// a multi-section with a branch for each member of the base space
  /// contained in xbase_parts.
  ///
  sec_e1(sec_rep_space* xhost, const subposet& xbase_parts, bool xauto_sccess);

  ///
  /// Assignment operator; synonym for attach_to_state(&xother).
  ///
  virtual sec_e1& operator=(const abstract_poset_member& xother);

  ///
  /// Assignment operator; synonym for attach_to_state(&xother).
  ///
  sec_e1& operator=(const sec_e1& xother);

  ///
  /// Assignment operator.
  ///
  sec_e1& operator=(const e1& xfiber);

  ///
  /// Assignment operator.
  ///
  sec_e1& operator=(const e1_lite& xfiber);

  ///
  /// Destructor.
  ///
  ~sec_e1();

  ///
  /// Virtual constructor for the associated fiber type.
  ///
  virtual const fiber_type& fiber_prototype() const;

protected:

private:

  //@}


  //============================================================================
  /// @name ED FACET OF CLASS SEC_E1
  //============================================================================
  //@{

public:

protected:

private:

  //@}


  //============================================================================
  /// @name AT1 FACET OF CLASS SEC_E1
  //============================================================================
  //@{

public:

protected:

private:

  //@}


  //============================================================================
  /// @name ATP FACET OF CLASS SEC_E1
  //============================================================================
  //@{

public:

protected:

private:

  //@}


  //============================================================================
  /// @name TP FACET OF CLASS SEC_E1
  //============================================================================
  //@{

public:

protected:

private:

  //@}


  //============================================================================
  /// @name VD FACET OF CLASS SEC_E1
  //============================================================================
  //@{

public:

protected:

private:

  //@}


  //============================================================================
  /// @name TUPLE FACET OF CLASS SEC_E1
  //============================================================================
  //@{

public:

protected:

private:

  //@}


  //============================================================================
  /// @name ABSTRACT POSET MEMBER FACET OF CLASS SEC_E1
  //============================================================================
  //@{

public:

  ///
  /// The name of this class.
  ///
  virtual const string& class_name() const;

  ///
  /// The name of this class.
  ///
  static const string& static_class_name();

  ///
  /// make a new handle, no state instance of current
  ///
  virtual sec_e1* clone() const;

  ///
  /// make a new handle instance of current.  Attach the new instance to
  /// a new state if xnew_state is true.  Otherwise, attach the new instance
  /// to the current state.
  ///
  inline sec_e1* clone(bool xnew_state, bool xauto_access = true) const
  {
    return static_cast<sec_e1*>(sec_ed::clone(xnew_state, xauto_access));
  }

protected:

private:

  //@}


  //============================================================================
  /// @name ANY FACET OF CLASS SEC_E1
  //============================================================================
  //@{

public:

  ///
  /// True if xother conforms to an instance of the fiber of current.
  ///
  bool fiber_is_ancestor_of(const any* xother) const;

  ///
  /// true if other conforms to current
  ///
  bool is_ancestor_of(const any* other) const;

  ///
  /// class invariant
  ///
  bool invariant() const;

protected:

private:

  //@}

};

} // namespace fiber_bundle

#endif // ifndef SEC_E1_H

