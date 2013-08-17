


//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

/// @file
/// Implementation for class sec_tp_space.

#include "sec_tp_space.h"

#include "abstract_poset_member.impl.h"
#include "assert_contract.h"
#include "binary_section_space_schema_member.h"
#include "fiber_bundles_namespace.h"
#include "namespace_poset.impl.h"
#include "namespace_poset_member.h"
#include "poset_handle_factory.h"
#include "sec_at1.h"
#include "sec_at1_space.h"
#include "sec_tp.h"
#include "section_space_schema_member.impl.h"
#include "section_space_schema_poset.h"
#include "tp.h"
#include "tp_space.h"

using namespace fiber_bundle; // Workaround for MS C++ bug.

//#define DIAGNOSTIC_OUTPUT

//==============================================================================
// SEC_TP_SPACE FACET
//==============================================================================

// PUBLIC MEMBER FUNCTIONS

sheaf::arg_list
fiber_bundle::sec_tp_space::
make_arg_list(int xp, const poset_path& xvector_space_path)
{
  // Preconditions:

  // Body:

  sheaf::arg_list result = sec_vd_space::make_arg_list("");

  result << "p" << xp
	 << "dd" << static_cast<int>(0)
	 << "vector_space_path" << xvector_space_path.path();
  
#ifdef DIAGNOSTIC_OUTPUT
  cout << "sec_tp_space::make_arg_list:result: " << result << endl;
#endif

  // Postconditions:

  ensure(unexecutable("result.conforms_to(schema of this class)"));
  ensure(result.value("p") == xp);
  ensure(result.value("vector_space_path") == xvector_space_path);
  
  // Exit:

  return result;
}



fiber_bundle::sec_tp_space&
fiber_bundle::sec_tp_space::
new_table(namespace_type& xns, const poset_path& xpath, 
          const poset_path& xschema_path,
          const poset_path& xvector_space_path, 
          bool xauto_access)
{
  // cout << endl << "Entering sec_tp_space::new_table." << endl;

  // Preconditions:


  require(!xpath.empty());
  require(!xns.contains_path(xpath, xauto_access));

  require(xschema_path.full());
  require(xns.path_is_auto_read_accessible<section_space_schema_poset>(xschema_path, xauto_access));
  require(fiber_schema_conforms(xns, xschema_path, fiber_type::standard_schema_path(), xauto_access));

  require(xns.path_is_auto_read_accessible<vector_type::host_type>(xvector_space_path, xauto_access));

  require(same_vector_fiber_space(xns, xschema_path, xvector_space_path, xauto_access));

  // Body:

  // Create the table; have to new it because namespace keeps a pointer.

  typedef sec_tp_space table_type;

  table_type& result = *(new table_type());

  // Create a handle of the right type for the schema member.

  binary_section_space_schema_member lschema(xns, xschema_path, xauto_access);

  if(xauto_access)
  {
    lschema.get_read_access();
  }

  // Get the section scalar space path from the section vector space.

  poset_path lscalar_space_path = 
    xns.member_poset<vector_type::host_type>(xvector_space_path, xauto_access).scalar_space_path(xauto_access);

  // The table dof map for a section space is mostly the same as the table dof map
  // of the fiber schema, so just copy it. Have to new it because poset_state keeps a pointer.

  array_poset_dof_map& lfiber_map = lschema.fiber_space().table_dof_map();
  array_poset_dof_map* lmap = new array_poset_dof_map(lfiber_map);

  // Replace the fiber scalar space path with the section scalar space path.

  lmap->put_dof("scalar_space_path", lscalar_space_path);

  // Replace the fiber vector space path with the section vector space path.

  lmap->put_dof("vector_space_path", xvector_space_path);
  
  // Create the state.

  result.new_state(xns, xpath, lschema, *lmap);

  if(xauto_access)
  {
    lschema.release_access();
  }

  // Postconditions:

  //  ensure(xns.owns(result, xauto_access));
  ensure(result.path(true) == xpath);
  ensure(result.state_is_not_read_accessible());
  ensure(result.schema(true).path(xauto_access) == xschema_path);

  ensure(result.factor_ct(true) == result.schema(true).fiber_space<fiber_type::host_type>().factor_ct(xauto_access));
  ensure(result.d(true) == result.schema(true).fiber_space<fiber_type::host_type>().d(xauto_access));
  ensure(result.scalar_space_path(true) == 
         xns.member_poset<vector_type::host_type>(xvector_space_path, xauto_access).scalar_space_path(xauto_access));
  ensure(result.p(true) == result.schema(true).fiber_space<fiber_type::host_type>().p(xauto_access));
  ensure(result.dd(true) == result.schema(true).fiber_space<fiber_type::host_type>().dd(xauto_access));
  ensure(result.vector_space_path(true) == xvector_space_path);

  // Exit:

  // cout << "Leaving sec_tp_space::new_table." << endl;
  return result;
}


//==============================================================================
// TABLE DOFS
//==============================================================================

int
fiber_bundle::sec_tp_space::
d(int xp, int xdd) const
{
  return static_cast<int>(pow(static_cast<double>(xdd), xp));
}

bool
fiber_bundle::sec_tp_space::
d_is_valid(const namespace_poset& xns, 
	   const poset_path& xschema_path,
	   const arg_list& xargs, 
	   bool xauto_access) const
{
  // Preconditions:

  require(xschema_path.full());
  require(xns.member_poset(xschema_path, xauto_access).state_is_auto_read_accessible(xauto_access));

  /// @error arg_list attaches to a schema_poset_member however 
  ///        product_section_space_schema_member redefines the dof_map()
  ///        functions which are used by schema_poset_member::invariant().
  ///        See bug #0000401.

  //require(xargs.conforms_to(xns, xschema_path, true, xauto_access));

  require(int(xargs.value("p")) >= 0);

  require(xns.path_is_auto_read_accessible(xargs.value("vector_space_path"), xauto_access));

  // Body:

  poset_path lfiber_schema_path =
    fiber_schema(xauto_access).path(xauto_access);

  int lschema_d = schema_poset_member::row_dof_ct(xns, lfiber_schema_path, xauto_access);

  int ldd = d(xns, poset_path(xargs.value("vector_space_path")), xauto_access);
  int lp  = xargs.value("p");
  int largs_d = d(lp, ldd);

  bool result = (lschema_d == largs_d);

  // Postconditions:


  // Exit:

  return result;
}

int
fiber_bundle::sec_tp_space::
p() const
{
  // Preconditions:

  require(state_is_read_accessible());
  
  // Body:

  int result = sheaf::table_dofs(*this).p;  

  // Postconditions:

  // Exit:

  return result;
}

int
fiber_bundle::sec_tp_space::
p(bool xauto_access) const
{
  // Preconditions:

  require(state_is_auto_read_accessible(xauto_access));
  
  // Body:

  if(xauto_access)
  {
    get_read_access();
  }

  int result = sheaf::table_dofs(*this).p;
  
  if(xauto_access)
  {
    release_access();
  }

  // Postconditions:

  // Exit:

  return result;
}

int
fiber_bundle::sec_tp_space::
dd() const
{
  // Preconditions:

  require(state_is_read_accessible());
  
  // Body:

  int result = sheaf::table_dofs(*this).dd;

  // Postconditions:

  // Exit:

  return result;
}

int
fiber_bundle::sec_tp_space::
dd(bool xauto_access) const
{
  // Preconditions:

  require(state_is_auto_read_accessible(xauto_access));
  
  // Body:

  if(xauto_access)
  {
    get_read_access();
  }

  int result = sheaf::table_dofs(*this).dd;
  
  if(xauto_access)
  {
    release_access();
  }

  // Postconditions:

  // Exit:

  return result;
}

sheaf::poset_path
fiber_bundle::sec_tp_space::
vector_space_path() const
{
  // Preconditions:

  require(state_is_read_accessible());

  // Body:
 
  poset_path result(sheaf::table_dofs(*this).vector_space_path);

  // Postconditions:

  ensure(!result.empty());

  // Exit:

  return result;
}

sheaf::poset_path
fiber_bundle::sec_tp_space::
vector_space_path(bool xauto_access) const
{
  // Preconditions:

  require(state_is_auto_read_accessible(xauto_access));

  // Body:
 
  if(xauto_access)
  {
    get_read_access();
  }

  poset_path result(sheaf::table_dofs(*this).vector_space_path);

  if(xauto_access)
  {
    release_access();
  }

  // Postconditions:

  ensure(!result.empty());

  // Exit:

  return result;
}

fiber_bundle::tensor_variance
fiber_bundle::sec_tp_space::
variance(pod_index_type xmbr_id, bool xauto_access) const
{
  // Preconditions:

  require(state_is_auto_read_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  require(contains_variance_subposets(xauto_access));
  
  // Body:

  if(xauto_access)
  {
    get_read_access();
  }
  
  int lp = p();
  tensor_variance result(lp);

  for(int i=0; i<lp; ++i)
  {
    result.put_variance(i, is_covariant(xmbr_id, i, false));
  }
  
  if(xauto_access)
  {
    release_access();
  }
  
  // Postconditions:

  // Exit:

  return result;
}

fiber_bundle::tensor_variance
fiber_bundle::sec_tp_space::
variance(const scoped_index& xmbr_id, bool xauto_access) const
{
  // Preconditions:

  require(state_is_auto_read_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  require(contains_variance_subposets(xauto_access));
  
  // Body:

  return variance(xmbr_id.hub_pod(), xauto_access);
}

bool
fiber_bundle::sec_tp_space::
variance(pod_index_type xmbr_id, int xi, bool xauto_access) const
{
  // Preconditions:

  require(state_is_auto_read_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  
  // Body:

  bool result = is_covariant(xmbr_id, xi, xauto_access);

  // Postconditions:

  // Exit:

  return result;
}

bool
fiber_bundle::sec_tp_space::
variance(const scoped_index& xmbr_id, int xi, bool xauto_access) const
{
  // Preconditions:

  require(state_is_auto_read_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  
  // Body:

  return variance(xmbr_id.hub_pod(), xi, xauto_access);
}

void
fiber_bundle::sec_tp_space::
put_variance(pod_index_type xmbr_id, const tensor_variance& xvariance, bool xauto_access)
{
  // Preconditions:

  require(state_is_auto_read_write_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  require(xvariance.p() == p(xauto_access));
  
  // Body:

  if(xauto_access)
  {
    get_read_write_access(true);
  }
  
  int lct = covariant_subposet_ct();
  
  for(int i=0; i<lct; ++i)
  {
    put_variance(xmbr_id, i, xvariance.variance(i), false);
  }

  if(xauto_access)
  {
    release_access();
  }

  // Postconditions:

  ensure(variance(xmbr_id, xauto_access) == round_variance(xvariance));
  
  // Exit:

  return;
}

void
fiber_bundle::sec_tp_space::
put_variance(const scoped_index& xmbr_id, const tensor_variance& xvariance, bool xauto_access)
{
  // Preconditions:

  require(state_is_auto_read_write_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  require(xvariance.p() == p(xauto_access));
  
  // Body:

  put_variance(xmbr_id.hub_pod(), xvariance, xauto_access);

  // Postconditions:

  ensure(variance(xmbr_id, xauto_access) == round_variance(xvariance));
  
  // Exit:

  return;
}

void
fiber_bundle::sec_tp_space::
put_variance(pod_index_type xmbr_id, int xi, bool xvariance, bool xauto_access)
{
  // Preconditions:

  require(state_is_auto_read_write_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  require((0 <= xi) && (xi < p(xauto_access)));
  
  // Body:

  if(xvariance)
  {
    put_is_covariant(xmbr_id, xi, xauto_access);
  }
  else
  {
    put_is_contravariant(xmbr_id, xi, xauto_access);
  }
  
  // Postconditions:

  ensure(variance(xmbr_id, xi, xauto_access) == xvariance);
  
  // Exit:

  return;
}

void
fiber_bundle::sec_tp_space::
put_variance(const scoped_index& xmbr_id, int xi, bool xvariance, bool xauto_access)
{
  // Preconditions:

  require(state_is_auto_read_write_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  require((0 <= xi) && (xi < p(xauto_access)));
  
  // Body:

  put_variance(xmbr_id.hub_pod(), xi, xvariance, xauto_access);
  
  // Postconditions:

  ensure(variance(xmbr_id, xi, xauto_access) == xvariance);
  
  // Exit:

  return;
}

fiber_bundle::tensor_variance
fiber_bundle::sec_tp_space::
round_variance(const tensor_variance& xvariance) const
{
  // Preconditions:
  
  // Body:

  // Postconditions:

  // Exit:

  return xvariance;
}

bool
fiber_bundle::sec_tp_space::
is_covariant(pod_index_type xmbr_id, bool xauto_access) const
{
  // Preconditions:

  require(state_is_auto_read_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  
  // Body:

  if(xauto_access)
  {
    get_read_access();
  }

  bool result = true;
  int lp = covariant_subposet_ct();
  for(int i=0; i<lp && result; ++i)
  {
    subposet lsp(this, covariant_subposet_name(i));
    bool result = lsp.contains_member(xmbr_id);
    lsp.detach_from_state();
  }  

  // The above implementation returns the correct result for p == 0.

  assertion(p() == 0 ? result : true);
  
  if(xauto_access)
  {
    release_access();
  }

  // Postconditions:

  
  // Exit:

  return result;
}

bool
fiber_bundle::sec_tp_space::
is_covariant(const scoped_index& xmbr_id, bool xauto_access) const
{
  // Preconditions:

  require(state_is_auto_read_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  
  // Body:

  return is_covariant(xmbr_id.hub_pod(), xauto_access);
}

bool
fiber_bundle::sec_tp_space::
is_covariant(pod_index_type xmbr_id, int xi, bool xauto_access) const
{
  // Preconditions:

  require(state_is_auto_read_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  require((0 <= xi) && (xi < p(xauto_access)));
  require(contains_variance_subposets(xauto_access));
  
  // Body:

  if(xauto_access)
  {
    get_read_access();
  }

  // Since precondition ensures xi >= 0 and xi < p; p can not be 0.
  // So covaraint_subposet_ct() is either p or 1. If only 1,
  // then we have either an stp or an atp and setting the variance
  // of any index is equivalent to setting them all.

  int lxi = (covariant_subposet_ct() > 1) ? xi : 0;

  /// @issue Access by name lookup is not terribly efficient,
  /// but it will have to do until we get id spaces for subposets working
  /// or devise some other mechanism.

  subposet lsp(this, covariant_subposet_name(lxi));
  bool result = lsp.contains_member(xmbr_id);
  lsp.detach_from_state();

  if(xauto_access)
  {
    release_access();
  }
  
  // Postconditions:


  // Exit:

  return result;
}

bool
fiber_bundle::sec_tp_space::
is_covariant(const scoped_index& xmbr_id, int xi, bool xauto_access) const
{
  // Preconditions:

  require(state_is_auto_read_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  require((0 <= xi) && (xi < p(xauto_access)));
  require(contains_variance_subposets(xauto_access));
  
  // Body:

  return is_covariant(xmbr_id.hub_pod(), xi, xauto_access);
}

void
fiber_bundle::sec_tp_space::
put_is_covariant(pod_index_type xmbr_id, bool xauto_access)
{
  // Preconditions:

  require(state_is_auto_read_write_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  
  // Body:

  if(xauto_access)
  {
    get_read_write_access(true);
  }

  int lp = covariant_subposet_ct();
  for(int i=0; i<lp; ++i)
  {
    subposet lcovariant(this, covariant_subposet_name(i));
    lcovariant.insert_member(xmbr_id);
    lcovariant.detach_from_state();
  }  

  if(xauto_access)
  {
    release_access();
  }

  // Postconditions:

  ensure(is_covariant(xmbr_id, xauto_access));
  
  // Exit:

  return;
}

void
fiber_bundle::sec_tp_space::
put_is_covariant(const scoped_index& xmbr_id, bool xauto_access)
{
  // Preconditions:

  require(state_is_auto_read_write_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  
  // Body:

  put_is_covariant(xmbr_id.hub_pod(), xauto_access);

  // Postconditions:

  ensure(is_covariant(xmbr_id, xauto_access));
  
  // Exit:

  return;
}

void
fiber_bundle::sec_tp_space::
put_is_covariant(pod_index_type xmbr_id, int xi, bool xauto_access)
{
  // Preconditions:

  require(state_is_auto_read_write_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  require((0 <= xi) && (xi < p(xauto_access)));

  // Body:

  if(xauto_access)
  {
    get_read_write_access(true);
  }

  // Since precondition ensures xi >= 0 and xi < p; p can not be 0.
  // So covaraint_subposet_ct() is either p or 1. If only 1,
  // then we have either an stp or an atp and setting the variance
  // of any index is equivalent to setting them all.

  int lxi = (covariant_subposet_ct() > 1) ? xi : 0;

  // $$SCRIBBLE: access by name lookup is not terribly efficient,
  // but it will have to do until we get id spaces for subposets working
  // or devise some other mechanism.

  subposet lsp(this, covariant_subposet_name(lxi));
  lsp.insert_member(xmbr_id);
  lsp.detach_from_state();

  if(xauto_access)
  {
    release_access();
  }
  
  // Postconditions:

  ensure(is_covariant(xmbr_id, xi, xauto_access));

  // Exit:

  return;
}

void
fiber_bundle::sec_tp_space::
put_is_covariant(const scoped_index& xmbr_id, int xi, bool xauto_access)
{
  // Preconditions:

  require(state_is_auto_read_write_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  require((0 <= xi) && (xi < p(xauto_access)));

  // Body:

  put_is_covariant(xmbr_id.hub_pod(), xi, xauto_access);
  
  // Postconditions:

  ensure(is_covariant(xmbr_id, xi, xauto_access));

  // Exit:

  return;
}

bool
fiber_bundle::sec_tp_space::
is_contravariant(pod_index_type xmbr_id, bool xauto_access) const
{
  // Preconditions:

  require(state_is_auto_read_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  
  // Body:

  if(xauto_access)
  {
    get_read_access();
  }

  bool result = true;
  int lp = covariant_subposet_ct();
  for(int i=0; i<lp && result; ++i)
  {
    subposet lsp(this, covariant_subposet_name(i));
    bool result = !lsp.contains_member(xmbr_id);
    lsp.detach_from_state();
  }  

  // The above implementation returns the correct result for p == 0.

  assertion(p() == 0 ? result : true);

  if(xauto_access)
  {
    release_access();
  }

  // Postconditions:

  // Can not ensure result == !is_covariant because at0 is both co- and contra-variant.
  
  // Exit:

  return result;
}

bool
fiber_bundle::sec_tp_space::
is_contravariant(const scoped_index& xmbr_id, bool xauto_access) const
{
  // Preconditions:

  require(state_is_auto_read_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  
  // Body:

  return is_contravariant(xmbr_id.hub_pod(), xauto_access);
}

bool
fiber_bundle::sec_tp_space::
is_contravariant(pod_index_type xmbr_id, int xi, bool xauto_access) const
{
  // Preconditions:

  require(state_is_auto_read_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  require((0 <= xi) && (xi < p(xauto_access)));
  
  // Body:

  bool result = !is_covariant(xmbr_id, xi, xauto_access);

  // Postconditions:

  // Can ensure result == !is_covariant because although 
  // at0 is both co- and contra-variant, at0::p() == 0 so this
  // function can not be invoked. But to be consistent,
  // let's just not ensure it.

  //  ensure(result == !is_covariant(xmbr_id, xi, xauto_access));
  
  // Exit:

  return result;
}

bool
fiber_bundle::sec_tp_space::
is_contravariant(const scoped_index& xmbr_id, int xi, bool xauto_access) const
{
  // Preconditions:

  require(state_is_auto_read_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  require((0 <= xi) && (xi < p(xauto_access)));
  
  // Body:

  return is_contravariant(xmbr_id.hub_pod(), xi, xauto_access);
}

void
fiber_bundle::sec_tp_space::
put_is_contravariant(pod_index_type xmbr_id, bool xauto_access)
{
  // Preconditions:

  require(state_is_auto_read_write_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  
  // Body:

  if(xauto_access)
  {
    get_read_write_access(true);
  }

  int lp = covariant_subposet_ct();
  for(int i=0; i<lp; ++i)
  {
    subposet lcovariant(this, covariant_subposet_name(i));
    lcovariant.remove_member(xmbr_id);
    lcovariant.detach_from_state();
  }  

  if(xauto_access)
  {
    release_access();
  }

  // Postconditions:

  ensure(is_contravariant(xmbr_id, xauto_access));
  
  // Exit:

  return;
}

void
fiber_bundle::sec_tp_space::
put_is_contravariant(const scoped_index& xmbr_id, bool xauto_access)
{
  // Preconditions:

  require(state_is_auto_read_write_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  
  // Body:

  put_is_contravariant(xmbr_id.hub_pod(), xauto_access);

  // Postconditions:

  ensure(is_contravariant(xmbr_id, xauto_access));
  
  // Exit:

  return;
}

void
fiber_bundle::sec_tp_space::
put_is_contravariant(pod_index_type xmbr_id, int xi, bool xauto_access)
{
  // Preconditions:

  require(state_is_auto_read_write_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  require((0 <= xi) && (xi < p(xauto_access)));

  // Body:

  if(xauto_access)
  {
    get_read_write_access(true);
  }

  // Since precondition ensures xi >= 0 and xi < p; p can not be 0.
  // So covaraint_subposet_ct() is either p or 1. If only 1,
  // then we have either an stp or an atp and setting the variance
  // of any index is equivalent to setting them all.

  int lxi = (covariant_subposet_ct() > 1) ? xi : 0;
  
  // $$SCRIBBLE: access by name lookup is not terribly efficient,
  // but it will have to do until we get id spaces for subposets working
  // or devise some other mechanism.

  subposet lsp(this, covariant_subposet_name(lxi));
  lsp.remove_member(xmbr_id);
  lsp.detach_from_state();

  if(xauto_access)
  {
    release_access();
  }
  
  // Postconditions:

  ensure(is_contravariant(xmbr_id, xi, xauto_access));
  
  // Exit:

  return;
}

void
fiber_bundle::sec_tp_space::
put_is_contravariant(const scoped_index& xmbr_id, int xi, bool xauto_access)
{
  // Preconditions:

  require(state_is_auto_read_write_accessible(xauto_access));
  require(contains_member(xmbr_id, xauto_access));
  require((0 <= xi) && (xi < p(xauto_access)));

  // Body:

  put_is_contravariant(xmbr_id.hub_pod(), xi, xauto_access);
  
  // Postconditions:

  ensure(is_contravariant(xmbr_id, xi, xauto_access));
  
  // Exit:

  return;
}

// PROTECTED MEMBER FUNCTIONS

fiber_bundle::sec_tp_space::
sec_tp_space()
  : sec_vd_space(new sec_tp, new sec_tp)
{
  // Preconditions:

  // Body:

  // Nothing to do, handled by base class

  // Postconditions:

  ensure(postcondition_of(sec_vd_space::sec_vd_space()));
}

fiber_bundle::sec_tp_space::
sec_tp_space(const sec_tp_space& xother)
  : sec_vd_space(new sec_tp, new sec_tp)
{
  // Preconditions:

  // Body:

  attach_to_state(&xother);
  
  // Postconditions:

  ensure(is_same_state(&xother));
}


fiber_bundle::sec_tp_space::
~sec_tp_space()
{
  // Preconditions:

  // Body:

  // Postconditions:

  // Exit

  return;
}

fiber_bundle::sec_tp_space::
sec_tp_space(sec_tp* xtop, sec_tp* xbottom)
  : sec_vd_space(xtop, xbottom)
{
  // Preconditions:

  require(xtop != 0);
  require(xbottom != 0);
  
  // Body:

  // Nothing to do.

  // Postconditions:

  ensure(postcondition_of(poset_state_handle::poset_state_handle(xtop, xbottom)));
  
  // Exit:

  return;
}

//==============================================================================
// NEW HANDLE, NEW STATE CONSTRUCTORS
//==============================================================================

fiber_bundle::sec_tp_space::
sec_tp_space(namespace_poset& xhost,
	     const string& xname,
	     const arg_list& xargs,
	     const poset_path& xschema_path,
	     bool xauto_access)
  : sec_vd_space(new sec_tp, new sec_tp)
{

  // Preconditions:

  require(precondition_of(sec_tp_space::new_state(same args)));

  require(int(xargs.value("p")) >= 0);

  require(xhost.arg_is_auto_read_accessible("vector_space_path", xargs, xauto_access));  

  // Body:

  new_state(xhost, xname, xargs, xschema_path, xauto_access);

  // Postconditions:

  ensure(postcondition_of(sec_tp_space::new_state(same args)));

  // Exit:

  return;
}

//==============================================================================
// NEW HANDLE, EXISTING STATE CONSTRUCTORS
//==============================================================================

fiber_bundle::sec_tp_space::
sec_tp_space(const namespace_poset& xhost, pod_index_type xindex, bool xauto_access)
  : sec_vd_space(new sec_tp, new sec_tp)
{
  // Preconditions:

  require(xhost.state_is_auto_read_accessible(xauto_access));
  require(xhost.contains_member(xindex, xauto_access));

  if(xauto_access)
  {
    xhost.get_read_access();
  }
  
  require(xhost.is_jim(xindex));

  // Body:

  attach_to_state(&xhost, xindex);

  if(xauto_access)
  {
    xhost.release_access();
  }

  // Postconditions:

  ensure(host() == &xhost);
  ensure(index() == xindex);
}

fiber_bundle::sec_tp_space::
sec_tp_space(const namespace_poset& xhost, const scoped_index& xindex, bool xauto_access)
  : sec_vd_space(new sec_tp, new sec_tp)
{
  // Preconditions:

  require(xhost.state_is_auto_read_accessible(xauto_access));
  require(xhost.contains_member(xindex, xauto_access));

  if(xauto_access)
  {
    xhost.get_read_access();
  }
  
  require(xhost.is_jim(xindex));

  // Body:

  attach_to_state(&xhost, xindex.hub_pod());

  if(xauto_access)
  {
    xhost.release_access();
  }

  // Postconditions:

  ensure(host() == &xhost);
  ensure(index() ==~ xindex);
}

fiber_bundle::sec_tp_space::
sec_tp_space(const namespace_poset& xhost, const string& xname, bool xauto_access)
  : sec_vd_space(new sec_tp, new sec_tp)
{
  // Preconditions:

  require(xhost.state_is_auto_read_accessible(xauto_access));
  require(xhost.contains_member(xname));

  // Body:

  if(xauto_access)
  {
    xhost.get_read_access();
  }

  attach_to_state(&xhost, xname);

  // Postconditions:

  ensure(host() == &xhost);
  ensure(name() == xname);

  if(xauto_access)
  {
    xhost.release_access();
  }
}

fiber_bundle::sec_tp_space::
sec_tp_space(const namespace_poset_member& xmbr, bool xauto_access)
  : sec_vd_space(new sec_tp, new sec_tp)
{
  // Preconditions:

  require(xmbr.state_is_auto_read_accessible(xauto_access));

  // Body:

  if(xauto_access)
  {
    xmbr.get_read_access();
  }

  attach_to_state(&xmbr);

  if(xauto_access)
  {
    xmbr.release_access();
  }

  // Postconditions:

  ensure(index() ==~ xmbr.index());
}

// PRIVATE MEMBER FUNCTIONS


// ===========================================================
// SEC_VD_SPACE FACET
// ===========================================================

// PUBLIC MEMBER FUNCTIONS

// PROTECTED MEMBER FUNCTIONS

sheaf::size_type
fiber_bundle::sec_tp_space::
covariant_subposet_ct() const
{
  // Preconditions:

  require(state_is_read_accessible());

  // Body:

  size_type result = p();
  
  // Postconditions:
  
  // Exit:

  return result;
}

// PRIVATE MEMBER FUNCTIONS


// ===========================================================
// SEC_TUPLE_SPACE FACET
// ===========================================================

// PUBLIC MEMBER FUNCTIONS

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


// ===========================================================
// SEC_REP_SPACE FACET
// ===========================================================

// PUBLIC MEMBER FUNCTIONS

// PROTECTED MEMBER FUNCTIONS

void
fiber_bundle::sec_tp_space::
initialize_arg_list(const namespace_poset& xns, 
		    const string& xname,
		    arg_list& xargs, 
		    const poset_path& xschema_path,
		    bool xauto_access)
{
  // Preconditions:

  require(xns.state_is_auto_read_accessible(xauto_access));

  require(xschema_path.full());
  require(xns.member_poset(xschema_path, xauto_access).state_is_auto_read_accessible(xauto_access));

  /// @error arg_list attaches to a schema_poset_member however 
  ///        product_section_space_schema_member redefines the dof_map()
  ///        functions which are used by schema_poset_member::invariant().
  ///        See bug #0000401.

  //require(xargs.conforms_to(xns, xschema_path, true, xauto_access));

  require(int(xargs.value("p")) >= 0);

  require(xns.path_is_auto_read_accessible(xargs.value("vector_space_path"), xauto_access));

  require(d_is_valid(xns, xschema_path, xargs, xauto_access));
  
  // Body:

  poset_path lvector_space_path(xargs.value("vector_space_path"));

  // Set args required by parent.

  xargs.value("scalar_space_path") = scalar_space_path(xns, lvector_space_path, xauto_access);

  // Initialize inherited args (factor_ct, d).

  sec_vd_space::initialize_arg_list(xns, xname, xargs, xschema_path, xauto_access);

  // Initialize args defined in this class; p and vector_space_path already set.

  xargs.value("dd") = d(xns, lvector_space_path, xauto_access);

  // Done.
  
#ifdef DIAGNOSTIC_OUTPUT
  cout << "sec_tp_space::initialize_arg_list:xargs: " << endl 
       << xargs << endl;
#endif

  // Postconditions:

  ensure(xargs.value("dd") == d(xns, xargs.value("vector_space_path"), xauto_access));
  ensure(xargs.value("scalar_space_path") == scalar_space_path(xns, xargs.value("vector_space_path"), xauto_access));
  ensure(xargs.value("d") == d(xargs.value("p"), xargs.value("dd")));
  ensure(xargs.value("factor_ct") == xargs.value("d"));
  
  // Exit:

  return;
}

// PRIVATE MEMBER FUNCTIONS

bool
fiber_bundle::sec_tp_space::
make_prototype()
{
  bool result = false;

  // Preconditions:

  // Body:

  sec_tp_space* lproto = new sec_tp_space;
  poset_type ltype     = lproto->type_id();

  factory().insert_prototype(lproto);
  factory().insert_prototype(ltype, lproto);

  // Postconditions:

  // Exit:

  return result;
}


//==============================================================================
// POSET_STATE_HANDLE FACET
//==============================================================================

// PUBLIC MEMBER FUNCTIONS

sheaf::poset_type
fiber_bundle::sec_tp_space::
type_id() const
{
  return SEC_TP_SPACE_ID;
}

///@todo: Return string&.
///@todo: Static version.

const char*
fiber_bundle::sec_tp_space::
class_name() const
{
  // Preconditions:

  // Body:

  static const char* result = "sec_tp_space";

  // Postconditions:

  // Exit:

  return result;
}

sheaf::pod_index_type
fiber_bundle::sec_tp_space::
prereq_id(int xi) const
{
  // Preconditions:

  require(state_is_read_accessible());
  require(name_space()->state_is_read_accessible());

  // Body:

  pod_index_type result;

  switch(xi)
  {
    case 0:

      // The first prerequisite is always the schema.

      result = schema().host()->index().pod();
      break;

    case 1:
	
	// The vector space over which this tensor space is built.

      result = name_space()->member_id(vector_space_path().poset_name(), false);
      break;

    default:

      // No other prerequisites.

      result = invalid_pod_index();
      break;
  }

  // Postconditions:

  // Exit:

  return result;
}

fiber_bundle::sec_tp_space&
fiber_bundle::sec_tp_space::
operator=(const poset_state_handle& xother)
{
  // Preconditions:

  require(is_ancestor_of(&xother));

  // Body:

  poset_state_handle::operator=(xother);

  // Postconditions:

  ensure(is_same_state(&xother));

  // Exit:

  return *this;
}

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//==============================================================================
// READ_WRITE_MONITOR_HANDLE FACET
//==============================================================================

// PUBLIC MEMBER FUNCTIONS

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


//==============================================================================
// ANY FACET
//==============================================================================

// PUBLIC MEMBER FUNCTIONS

bool
fiber_bundle::sec_tp_space::
is_ancestor_of(const any* xother) const
{
  bool result;

  // Preconditions:

  // Body:

  result = dynamic_cast<const sec_tp_space*>(xother) != 0;

  // Postconditions:

  // Exit

  return result;
}

fiber_bundle::sec_tp_space*
fiber_bundle::sec_tp_space::
clone() const
{
  sec_tp_space* result;

  // Preconditions:

  // Body:

  result = new sec_tp_space;

  // Postconditions:

  ensure(result != 0);
  ensure(is_same_type(result));
  ensure(!result->is_attached());

  // Exit

  return result;
}

bool
fiber_bundle::sec_tp_space::
invariant() const
{
  bool result = true;


  if(invariant_check())
  {
    disable_invariant_check();

    invariance(sec_vd_space::invariant());

    invariance(state_is_read_accessible() ? factor_ct() == d() : true);

    enable_invariant_check();
  }

  return result;
}

// PROTECTED MEMBER FUNCTIONS

// PRIVATE MEMBER FUNCTIONS


