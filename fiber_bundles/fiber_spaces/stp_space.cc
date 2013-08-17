
//
// Copyright (c) 2013 Limit Point Systems, Inc.
//

// Implementation for class stp_space.

#include "stp_space.h"

#include "abstract_poset_member.impl.h"
#include "assert_contract.h"
#include "at1_space.h"
#include "stp.h"
#include "fiber_bundles_namespace.h"
#include "namespace_poset.impl.h"
#include "namespace_poset_member.h"
#include "poset_handle_factory.h"

using namespace fiber_bundle; // Workaround for MS C++ bug.
using namespace fiber_bundle::vd_algebra;

//#define DIAGNOSTIC_OUTPUT

//==============================================================================
// STP_SPACE FACET public member functions
//==============================================================================

///
const string&
fiber_bundle::stp_space::
standard_schema_poset_name()
{
  // Preconditions:


  // Body:

  static const string& result = stp::standard_schema_poset_name();

  // Postconditions:

  ensure(!result.empty());

  // Exit:

  return result;
}

///
const sheaf::poset_path&
fiber_bundle::stp_space::
standard_schema_path()
{
  // Preconditions:


  // Body:

  static const poset_path& result = stp::standard_schema_path();

  // Postconditions:

  ensure(result.full());
  ensure(result.poset_name() == standard_schema_poset_name());

  // Exit:

  return result;
}

sheaf::arg_list
fiber_bundle::stp_space::
make_arg_list(int xp, const poset_path& xvector_space_path)
{
  // Preconditions:


  // Body:

  // $$SCRIBBLE: dmb I don't think we need this routine; it's the same as tp_space.

  sheaf::arg_list result = tp_space::make_arg_list(xp, xvector_space_path);

  
#ifdef DIAGNOSTIC_OUTPUT
  cout << "stp_space::make_arg_list:result: " << result << endl;
#endif

  // Postconditions:

  ensure(unexecutable("result.conforms_to(schema of this class)"));
  ensure(result.value("p") == xp);
  ensure(result.value("vector_space_path") == xvector_space_path);
  
  // Exit:

  return result;
}

int
fiber_bundle::stp_space::
d(const namespace_poset& xns, int xp, const poset_path& xvector_space_path, bool xauto_access)
{
  // Preconditions:

  require(xp >= 0);
  
  require(xns.path_is_auto_read_accessible<vector_space_type>(xvector_space_path, xauto_access));
 
  // Body:

  int ldd = xns.member_poset<vector_space_type>(xvector_space_path, xauto_access).d();  

  stp_space ltmp;
  int result = ltmp.d(xp, ldd);

  // Postconditions:

  ensure(result >= 0);

  // Exit:

  return result;
}

void
fiber_bundle::stp_space::
new_table(namespace_type& xns, 
          const poset_path& xpath, 
          const poset_path& xschema_path, 
          int xp,
          const poset_path& xvector_space_path, 
          bool xauto_access)
{
  // cout << endl << "Entering stp_space::new_table." << endl;

  // Preconditions:

  require(xns.state_is_auto_read_write_accessible(xauto_access));

  require(!xpath.empty());
  require(!xns.contains_path(xpath, xauto_access));

  require(xschema_path.full());
  require(xns.path_is_auto_read_accessible(xschema_path, xauto_access));
  require(schema_poset_member::conforms_to(xns, xschema_path, standard_schema_path(), xauto_access));

  require(xns.path_is_auto_read_accessible<vector_space_type>(xvector_space_path, xauto_access));

  require(d(xns, xschema_path, xauto_access) == d(xns, xp, xvector_space_path, xauto_access));  

  // Body:

  // Create the table; have to new it because namespace keeps a pointer.

  typedef stp_space table_type;

  table_type* ltable = new table_type();

  // Create a handle of the right type for the schema member.

  schema_poset_member lschema(&xns, xschema_path, xauto_access);

  if(xauto_access)
  {
    lschema.get_read_access();
  }

  // Get the dimension (== number of row dofs) defined by the schema.

  int ld = lschema.row_dof_ct();

  // Get the dimension of the domain vector space.

  int ldd = xns.member_poset<vector_space_type>(xvector_space_path, xauto_access).d();

  // Get the scalar space path from the domain vector space.

  poset_path lscalar_space_path = xns.member_poset<vector_space_type>(xvector_space_path, xauto_access).scalar_space_path(xauto_access);
  
  // Create the table dof map and set dof values;
  // must be newed because poset_state::_table keep a pointer to it.

  array_poset_dof_map* lmap = new array_poset_dof_map(&lschema, true);
  lmap->put_dof("factor_ct", ld);
  lmap->put_dof("d", ld);
  lmap->put_dof("scalar_space_path", lscalar_space_path);
  lmap->put_dof("p", xp);
  lmap->put_dof("dd", ldd);
  lmap->put_dof("vector_space_path", xvector_space_path);
  
  // Create the state.

  ltable->new_state(xns, xpath, lschema, *lmap);

  if(xauto_access)
  {
    lschema.release_access();
  }


  // Postconditions:

  ensure(xns.contains_path(xpath, xauto_access));
  ensure(xns.member_poset(xpath, xauto_access).state_is_not_read_accessible());
  ensure(xns.member_poset(xpath, xauto_access).schema(true).path(true) == xschema_path);

  ensure(xns.member_poset<stp_space>(xpath, xauto_access).factor_ct(true) == 
         xns.member_poset<stp_space>(xpath, xauto_access).d(true));

  ensure(xns.member_poset<stp_space>(xpath, xauto_access).d(true) == 
         d(xns, xschema_path, xauto_access));

  ensure(xns.member_poset<stp_space>(xpath, xauto_access).scalar_space_path(true) == 
         xns.member_poset<vector_space_type>(xvector_space_path, xauto_access).scalar_space_path(xauto_access) );

  ensure(xns.member_poset<tp_space>(xpath, xauto_access).p(true) == xp);

  ensure(xns.member_poset<tp_space>(xpath, xauto_access).dd(true) == 
         xns.member_poset<vector_space_type>(xvector_space_path, xauto_access).d());

  ensure(xns.member_poset<stp_space>(xpath, xauto_access).vector_space_path(true) == 
         xvector_space_path );

  // Exit:

  // cout << "Leaving stp_space::new_table." << endl;
  return;
} 

// ===========================================================
// STP_SPACE FACET protected member functions
// ===========================================================
 
fiber_bundle::stp_space::
stp_space()
  : tp_space(new stp, new stp)
{
  // Preconditions:

  // Body:

  // Nothing to do, handled by base class

  // Postconditions:

  ensure(postcondition_of(tp_space::tp_space()));
}



fiber_bundle::stp_space::
stp_space(const stp_space& xother)
  : tp_space(new stp, new stp)
{
  // Preconditions:

  // Body:

  attach_to_state(&xother);
  
  // Postconditions:

  ensure(is_same_state(&xother));
}


fiber_bundle::stp_space::
~stp_space()
{
  // Preconditions:

  // Body:

  // Postconditions:

  // Exit

  return;
}

fiber_bundle::stp_space::
stp_space(stp* xtop, stp* xbottom)
  : tp_space(xtop, xbottom)
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

fiber_bundle::stp_space::
stp_space(namespace_poset& xhost,
	    const string& xname,
	    const arg_list& xargs,
	    const poset_path& xschema_path,
	    bool xauto_access)
  : tp_space(new stp, new stp)
{

  // Preconditions:

  require(precondition_of(stp_space::new_state(same args)));

  require(int(xargs.value("p")) >= 0);

  require(!poset_path(xargs.value("vector_space_path")).empty());
  require(xhost.contains_poset(poset_path(xargs.value("vector_space_path")), xauto_access));
  require(xhost.member_poset(poset_path(xargs.value("vector_space_path")), xauto_access).state_is_auto_read_accessible(xauto_access));

  // Body:

  new_state(xhost, xname, xargs, xschema_path, xauto_access);

  // Postconditions:

  ensure(postcondition_of(stp_space::new_state(same args)));

  // Exit:

  return;
}

//==============================================================================
// NEW HANDLE, EXISTING STATE CONSTRUCTORS
//==============================================================================

fiber_bundle::stp_space::
stp_space(const namespace_poset& xhost, pod_index_type xindex, bool xauto_access)
  : tp_space(new stp, new stp)
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

fiber_bundle::stp_space::
stp_space(const namespace_poset& xhost, const scoped_index& xindex, bool xauto_access)
  : tp_space(new stp, new stp)
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

fiber_bundle::stp_space::
stp_space(const namespace_poset& xhost, const string& xname, bool xauto_access)
  : tp_space(new stp, new stp)
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



fiber_bundle::stp_space::
stp_space(const namespace_poset_member& xmbr, bool xauto_access)
  : tp_space(new stp, new stp)
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

// ===========================================================
// TP_SPACE FACET public member functions
// ===========================================================

int
fiber_bundle::stp_space::
d(int xp, int xdd) const
{
  return static_cast<int>(binomial_coefficient(xdd+xp-1, xp));
}

///
fiber_bundle::tensor_variance
fiber_bundle::stp_space::
round_variance(const tensor_variance& xvariance) const
{
  // Preconditions:
  
  // Body:

  tensor_variance result(xvariance);
  result.purify();

  // Postconditions:

  ensure(result.is_pure());
  ensure_for_all(i, 0, result.p(), result.variance(i) == xvariance.variance(0));

  // Exit:

  return xvariance;
}


// ===========================================================
// TP_SPACE FACET protected member functions
// ===========================================================

sheaf::size_type
fiber_bundle::stp_space::
covariant_subposet_ct() const
{
  return 1;
}
 

// ===========================================================
// POSET FACET
// =========================================================== 

bool
fiber_bundle::stp_space::
make_prototype()
{
  bool result = false;

  // Preconditions:

  // Body:


  stp_space* lproto = new stp_space;
  poset_type ltype = lproto->type_id();

  factory().insert_prototype(lproto);
  factory().insert_prototype(ltype, lproto);

  // Postconditions:

  // Exit:

  return result;
}

//==============================================================================
// POSET_STATE_HANDLE FACET
//==============================================================================



sheaf::poset_type
fiber_bundle::stp_space::
type_id() const
{
  return STP_SPACE_ID;
}

///@todo: Return string&.
///@todo: Static version.

const char*
fiber_bundle::stp_space::
class_name() const
{
  // Preconditions:


  // Body:

  static const char* result = "stp_space";

  // Postconditions:

  // Exit:

  return result;
}

fiber_bundle::stp_space&
fiber_bundle::stp_space::
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

//==============================================================================
// ANY FACET
//==============================================================================

bool
fiber_bundle::stp_space::
is_ancestor_of(const any* xother) const
{
  bool result;

  // Preconditions:

  // Body:

  result = dynamic_cast<const stp_space*>(xother) != 0;

  // Postconditions:

  // Exit

  return result;
}

fiber_bundle::stp_space*
fiber_bundle::stp_space::
clone() const
{
  stp_space* result;

  // Preconditions:

  // Body:

  result = new stp_space;

  // Postconditions:

  ensure(result != 0);
  ensure(is_same_type(result));
  ensure(!result->is_attached());

  // Exit

  return result;
}

bool
fiber_bundle::stp_space::
invariant() const
{
  bool result = true;


  if(invariant_check())
  {
    disable_invariant_check();

    invariance(tp_space::invariant());
    
    enable_invariant_check();
  }

  return result;
}


