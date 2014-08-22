
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

/// @file
/// Interface for class sec_e3.

#ifndef COM_LIMITPOINT_FIBER_BUNDLE_SEC_E3_H
#define COM_LIMITPOINT_FIBER_BUNDLE_SEC_E3_H

#ifndef COM_LIMITPOINT_SHEAF_SHEAF_DLL_SPEC_H
#include "ComLimitPoint/sheaf/sheaf_dll_spec.h"
#endif

#ifndef COM_LIMITPOINT_FIBER_BUNDLE_SEC_ED_H
#include "ComLimitPoint/fiber_bundle/sec_ed.h"
#endif

#ifndef COM_LIMITPOINT_FIBER_BUNDLE_E3_H
#include "ComLimitPoint/fiber_bundle/e3.h"
#endif

namespace fiber_bundle
{

//==============================================================================
// CLASS SEC_E3
//==============================================================================

///
/// A section of a fiber bundle with a 3-dimensional Euclidean
/// vector space fiber.
///
class SHEAF_DLL_SPEC sec_e3 : public sec_ed
{

  // ===========================================================
  /// @name HOST FACTORY FACET OF CLASS SEC_E3
  // ===========================================================
  //@{

public:

  // Typedefs:

  ///
  /// The fiber type.
  ///
  typedef e3 fiber_type;

  ///
  /// Type of underlying vector space.
  ///
  typedef sec_e3 vector_space_type;

  ///
  /// Creates a new host table for members of this type.
  /// The poset is created in namespace xns with path xhost_path, schema specified by xschema_path,
  /// and scalar section space specified by xscalar_space_path.
  ///
  static host_type& new_host(namespace_type& xns, 
                             const poset_path& xhost_path, 
                             const poset_path& xschema_path,
                             const poset_path& xscalar_space_path,
                             bool xauto_access);

  ///
  /// The standard host for sections of this type with base space xbase_path,
  /// representation xrep_path, section suffix xsection_suffix,
  /// and fiber suffix xfiber_suffix. Creates the host and its prerequisites
  /// if necessary.
  ///
  static host_type& standard_host(namespace_type& xns, 
                                  const poset_path& xbase_path,
                                  const poset_path& xrep_path,
                                  const std::string& xsection_suffix, 
                                  const std::string& xfiber_suffix, 
                                  bool xauto_access);

protected:

private:

  //@}


  //============================================================================
  /// @name E3 FACET OF CLASS SEC_E3
  //============================================================================
  //@{

public:

  ///
  /// Creates a new sec_e3 handle not attached to any state.
  ///
  sec_e3();

  ///
  /// Creates a new sec_e3 handle attached to the member state with hub id
  /// xhub_id in* xhost.
  ///
  sec_e3(const sec_rep_space* xhost, pod_index_type xhub_id);

  ///
  /// Creates a new sec_e3 handle attached to the member state with id xid
  /// in host xhost.
  ///
  sec_e3(const sec_rep_space* xhost, const scoped_index& xid);

  ///
  /// Creates a new sec_e3 handle attached to the member state with name xname
  /// in host xhost.
  ///
  sec_e3(const sec_rep_space* xhost, const std::string& xname);

  ///
  /// Creates a new handle attached to the member state
  /// with path xpath in namespace xnamespace.
  ///
  sec_e3(const namespace_poset* xnamespace,
         const poset_path& xpath,
         bool xauto_access = true);

  ///
  /// Creates a new sec_e3 handle attached to the same state as xother.
  ///
  explicit sec_e3(const sec_rep_space_member* xother);

  ///
  /// Creates a  new sec_e3 handle attached to a new jim in host xhost.
  /// If xdof_map is non-null it is used as the dof map for the new jim.
  ///
  sec_e3(sec_rep_space* xhost,
         section_dof_map* xdof_map = 0,
         bool xauto_access = true);

  ///
  /// Creates a new handle attached to a new jim state
  /// which is a partial section defined only on the base space
  /// member with index xbase_mbr_index and version xbase_version.
  ///
  sec_e3(sec_rep_space* xhost,
         abstract_poset_member& xbase_mbr,
         int xbase_version = CURRENT_HOST_VERSION,
         bool xauto_access = true);

  ///
  /// Creates a new handle attached to a new jrm state which is
  /// a multi-section with a branch for each member of the base space
  /// contained in xbase_parts.
  ///
  sec_e3(sec_rep_space* xhost, const subposet& xbase_parts, bool xauto_sccess);

  ///
  /// Assignment operator; synonym for attach_to_state(&xother).
  ///
  virtual sec_e3& operator=(const abstract_poset_member& xother);

  ///
  /// Assignment operator; synonym for attach_to_state(&xother).
  ///
  sec_e3& operator=(const sec_e3& xother);

  ///
  /// Assignment operator.
  ///
  sec_e3& operator=(const e3& xfiber);

  ///
  /// Assignment operator.
  ///
  sec_e3& operator=(const e3_lite& xfiber);

  ///
  /// Destructor.
  ///
  ~sec_e3();

  ///
  /// Virtual constructor for the associated fiber type.
  ///
  virtual const fiber_type& fiber_prototype() const;

protected:

private:

  //@}


  //============================================================================
  /// @name ED FACET OF CLASS SEC_E3
  //============================================================================
  //@{

public:

protected:

private:

  //@}


  //============================================================================
  /// @name AT1 FACET OF CLASS SEC_E3
  //============================================================================
  //@{

public:

protected:

private:

  //@}


  //============================================================================
  /// @name ATP FACET OF CLASS SEC_E3
  //============================================================================
  //@{

public:

protected:

private:

  //@}


  //============================================================================
  /// @name TP FACET OF CLASS SEC_E3
  //============================================================================
  //@{

public:

protected:

private:

  //@}


  //============================================================================
  /// @name VD FACET OF CLASS SEC_E3
  //============================================================================
  //@{

public:

protected:

private:

  //@}


  //============================================================================
  /// @name TUPLE FACET OF CLASS SEC_E3
  //============================================================================
  //@{

public:

protected:

private:

  //@}


  //============================================================================
  /// @name ABSTRACT POSET MEMBER FACET OF CLASS SEC_E3
  //============================================================================
  //@{

public:

  ///
  /// The name of this class.
  ///
  virtual const std::string& class_name() const;

  ///
  /// The name of this class.
  ///
  static const std::string& static_class_name();
  
  ///
  /// Make a new handle, no state instance of current
  ///
  virtual sec_e3* clone() const;

  ///
  /// Make a new handle instance of current.  Attach the new instance to
  /// a new state if xnew_state is true.  Otherwise, attach the new instance
  /// to the current state.
  ///
  inline sec_e3* clone(bool xnew_state, bool xauto_access = true) const
  {
    return static_cast<sec_e3*>(sec_ed::clone(xnew_state, xauto_access));
  }

protected:

private:

  //@}


  //============================================================================
  /// @name ANY FACET OF CLASS SEC_E3
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

//==============================================================================
// NON-MEMBER FUNCTIONS
//==============================================================================

#ifndef DOXYGEN_1_5_4_SKIP_UNKNOWN

///
/// Insert sec_e3& xv into ostream& xos
///
SHEAF_DLL_SPEC std::ostream& operator << (std::ostream& xos, const sec_e3& xv);

#endif // ifndef DOXYGEN_1_5_4_SKIP_UNKNOWN

//==============================================================================
// NON-MEMBER FUNCTIONS
//==============================================================================

//==============================================================================
// TP FACET
//==============================================================================

// Forward declarations needed for specialization:

class sec_at0;
class sec_t2_e3;
class sec_t3_e3;
class sec_at2_e3;
class sec_at3_e3;
class sec_st2_e3;
class sec_st3_e3;

///
/// Specialization for degree 0 tensors over sec_e3.
///
template<> class tensor_section_traits<0, sec_e3>
{
public:
  ///
  /// Type of general tensor of degree 0 over sec_e3.
  ///
  typedef sec_at0 tp_type;

  ///
  /// Type of antisymmetric tensor of degree 0 over sec_e3.
  ///
  typedef sec_at0 atp_type;

  ///
  /// Type of symmetric tensor of degree 0 over sec_e3.
  ///
  typedef sec_at0 stp_type;
};
  
///
/// Specialization for degree 1 tensors over sec_e3.
///
template<> class tensor_section_traits<1, sec_e3>
{
public:
  ///
  /// Type of general tensor of degree 1 over sec_e3.
  ///
  typedef sec_e3 tp_type;

  ///
  /// Type of antisymmetric tensor of degree 1 over sec_e3.
  ///
  typedef sec_e3 atp_type;

  ///
  /// Type of symmetric tensor of degree 1 over sec_e3.
  ///
  typedef sec_e3 stp_type;
};
  
///
/// Specialization for degree 2 tensors over sec_e3.
///
template<> class tensor_section_traits<2, sec_e3>
{
public:
  ///
  /// Type of general tensor of degree 2 over sec_e3.
  ///
  typedef sec_t2_e3 tp_type;

  ///
  /// Type of antisymmetric tensor of degree 2 over sec_e3.
  ///
  typedef sec_at2_e3 atp_type;

  ///
  /// Type of symmetric tensor of degree 2 over sec_e3.
  ///
  typedef sec_st2_e3 stp_type;
};
  
///
/// Specialization for degree 3 tensors over sec_e3.
///
template<> class tensor_section_traits<3, sec_e3>
{
public:
  ///
  /// Type of general tensor of degree 3 over sec_e3.
  ///
  typedef sec_t3_e3 tp_type;

  ///
  /// Type of antisymmetric tensor of degree 3 over sec_e3.
  ///
  typedef sec_at3_e3 atp_type;

  ///
  /// Type of symmetric tensor of degree 3 over sec_e3.
  ///
  typedef sec_st3_e3 stp_type;
};
  
//==============================================================================
// NON-MEMBER FUNCTIONS
//==============================================================================

///
/// Namespace containing the algrebra functions for a a section 
/// of a fiber bundle with a fiber type e3.
///
namespace sec_e3_algebra
{

///
/// The 3D Euclidean vector "cross" product of x0 with x1
/// (pre-allocated version).
///
SHEAF_DLL_SPEC void cross(const sec_e3& x0, const sec_e3& x1, sec_e3& xresult,
			  bool xauto_access);

///
/// The 3D Euclidean vector "cross" product of xresult with xother;
/// synonym for cross(xresult, xother, xresult, xauto_access).
///
SHEAF_DLL_SPEC void cross_equal(sec_e3& xresult, const sec_e3& xother,
				bool xauto_access);
  
} // namespace sec_e3_algebra

} // namespace fiber_bundle

#endif // ifndef COM_LIMITPOINT_FIBER_BUNDLE_SEC_E3_H

