


//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

/// @file
/// Interface for class sec_atp_space.

#ifndef SEC_ATP_SPACE_H
#define SEC_ATP_SPACE_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef SEC_TP_SPACE_H
#include "sec_tp_space.h"
#endif

namespace sheaf
{
class arg_list;
class namespace_poset;
}

namespace fiber_bundle
{
using namespace sheaf;

class sec_atp;
class atp;

///
/// An abstract antisymmetric tensor section space of degree p.
///
class SHEAF_DLL_SPEC sec_atp_space : public sec_tp_space
{
  friend class fiber_bundles_namespace;

  // ===========================================================
  /// @name SEC_ATP_SPACE FACET
  // ===========================================================
  //@{

public:

  ///
  /// The type of member associated with this space.
  ///
  typedef sec_atp member_type;

  ///
  /// The fiber type.
  ///
  typedef atp fiber_type;

  ///
  /// The scalar type definition.
  ///
  typedef sec_atp scalar_type;

  ///
  /// Creates an arg list which conforms to the schema of this.
  ///
  static arg_list make_arg_list(int xp, const poset_path& xvector_space_path);
  
  ///
  /// True if the member with id xmbr_id is a p-form;
  /// synonym for is_covariant(xmbr_id, xauto_access).
  ///
  bool is_p_form(pod_index_type xmbr_id, bool xauto_access) const;

  ///
  /// True if the member with id xmbr_id is a p-form;
  /// synonym for is_covariant(xmbr_id, xauto_access).
  ///
  bool is_p_form(const scoped_index& xmbr_id, bool xauto_access) const;

  ///
  /// Sets is_p_form for the member with id xmbr_id to true;
  /// synonym for put_is_covariant(xmbr_id, xauto_access).
  ///
  void put_is_p_form(pod_index_type xmbr_id, bool xauto_access);

  ///
  /// Sets is_p_form for the member with id xmbr_id to true;
  /// synonym for put_is_covariant(xmbr_id, xauto_access).
  ///
  void put_is_p_form(const scoped_index& xmbr_id, bool xauto_access);

  ///
  /// True if the member with id xmbr_id is a p-vector;
  /// synonym for is_contravariant(xmbr_id, xauto_access).
  ///
  bool is_p_vector(pod_index_type xmbr_id, bool xauto_access) const;

  ///
  /// True if the member with id xmbr_id is a p-vector;
  /// synonym for is_contravariant(xmbr_id, xauto_access).
  ///
  bool is_p_vector(const scoped_index& xmbr_id, bool xauto_access) const;

  ///
  /// Sets is_p_vector for the member with id xmbr_id to true.
  /// synonym for put_is_contravariant(xmbr_id, xauto_access).
  ///
  void put_is_p_vector(pod_index_type xmbr_id, bool xauto_access);

  ///
  /// Sets is_p_vector for the member with id xmbr_id to true.
  /// synonym for put_is_contravariant(xmbr_id, xauto_access).
  ///
  void put_is_p_vector(const scoped_index& xmbr_id, bool xauto_access);

protected:

  ///
  /// Default constructor;
  /// creates a new sec_atp_space handle not attached to any state.
  ///
  sec_atp_space();

  ///
  /// Copy constructor; attaches this to the same state as xother.
  ///
  sec_atp_space(const sec_atp_space& xother);

  ///
  /// Destructor.
  ///
  virtual ~sec_atp_space();

  ///
  /// Covariant constructor
  ///
  sec_atp_space(sec_atp* xtop, sec_atp* xbottom);

  //============================================================================
  // NEW HANDLE, NEW STATE CONSTRUCTORS
  //============================================================================

  ///
  /// Creates a new poset handle attached to a new state in namespace xhost,
  /// with schema specified by xschema_path,  name xname, and
  /// table dofs initialized by xargs.
  ///
  sec_atp_space(namespace_poset& xhost,
		const string& xname,
		const arg_list& xargs,
		const poset_path& xschema_path,
		bool xauto_access);

  //============================================================================
  // NEW HANDLE, EXISTING STATE CONSTRUCTORS
  //============================================================================

  ///
  /// Creates a new handle attached to the sec_atp_space with
  /// index xindex in namespace xhost.
  ///
  sec_atp_space(const namespace_poset& xhost, pod_index_type xindex, bool xauto_access);

  ///
  /// Creates a new handle attached to the sec_atp_space with
  /// index xindex in namespace xhost.
  ///
  sec_atp_space(const namespace_poset& xhost, const scoped_index& xindex, bool xauto_access);

  ///
  /// Creates a new handle attached to the sec_atp_space with
  /// name xname in namespace xhost.
  ///
  sec_atp_space(const namespace_poset& xhost, const string& xname, bool xauto_access);

  ///
  /// Creates a new handle attached to the sec_atp_space associated
  /// with namespace member xmbr.
  ///
  sec_atp_space(const namespace_poset_member& xmbr, bool xauto_access);

private:

  //@}


  // ===========================================================
  /// @name SEC_TP_SPACE FACET
  // ===========================================================
  //@{

public:

  using sec_tp_space::d;
  
  ///
  /// Dimension d() as a function of degree xp and domain dimension xdd.
  ///
  virtual int d(int xp, int xdd) const;

  ///
  /// "Rounds" xvariance up or down to a supported value;
  /// either pure covariant or pure contravariant.
  ///
  virtual tensor_variance round_variance(const tensor_variance& xvariance) const;

protected:

  ///
  /// The number of covariant subposets.
  ///
  virtual size_type covariant_subposet_ct() const;

private:

  //@}


  // ===========================================================
  /// @name SEC_VD_SPACE FACET
  // ===========================================================
  //@{

public:

protected:

private:

  //@}


  // ===========================================================
  /// @name SEC_TUPLE_SPACE FACET
  // ===========================================================
  //@{

public:

protected:

private:

  //@}


  // ===========================================================
  /// @name SEC_REP_SPACE FACET
  // ===========================================================
  //@{

public:

protected:

private:

  ///
  /// True if prototype for this class has been entered in factory.
  /// Intended to force creation of prototype at initialization.
  ///
  static bool _has_prototype;

  ///
  /// Creates prototype for this class and enters in factory.
  ///
  static bool make_prototype();

  //@}

 
  // ===========================================================
  /// @name POSET_STATE_HANDLE FACET
  // ===========================================================
  //@{

public:

  ///
  /// Identifier for the type of this poset.
  ///
  virtual poset_type type_id() const;

  ///
  /// The name of this class.
  ///
  virtual const char* class_name() const;

  ///
  /// Assignment operator; attaches this to the same state as xother.
  /// @issue This is probably the wrong signature for operator=,
  /// see thread Misc/Language/covariance in C++/covariance and operator=
  /// in the discusion forum. But it is consistent with all the
  /// other derivatives of poset_state_handle and it will soon be refactored
  /// out of existence any way.
  ///
  sec_atp_space& operator=(const poset_state_handle& xother);

protected:

private:

  //@}

 
  // ===========================================================
  /// @name READ_WRITE_MONITOR_HANDLE FACET
  // ===========================================================
  //@{

public:

protected:

private:

  //@}
 
 
  // ===========================================================
  /// @name ANY FACET
  // ===========================================================
  //@{

public:

  ///
  /// True if other conforms to this.
  ///
  virtual bool is_ancestor_of(const any* xother) const;

  ///
  /// Virtual constructor; creates a new handle of the same
  /// actual type as this, attached to the same state as this.
  ///
  virtual sec_atp_space* clone() const;

  ///
  /// Class invariant.
  ///
  virtual bool invariant() const;

protected:

private:

  //@}
 
};


} // namespace fiber_bundle


#endif // SEC_ATP_SPACE_H
