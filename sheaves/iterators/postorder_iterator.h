
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

// Interface for class postorder_iterator


#ifndef POSTORDER_ITERATOR_H
#define POSTORDER_ITERATOR_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef FILTERED_DEPTH_FIRST_ITERATOR_H
#include "filtered_depth_first_iterator.h"
#endif

namespace sheaf
{
  
///
/// Dperecated. Use postorder_itr.
/// Specialization of the filtered depth-first iterator which exposes
/// the POSTVISIT_ACTION to the client.
///
class SHEAF_DLL_SPEC postorder_iterator : public filtered_depth_first_iterator
{
public:

  // CANONICAL MEMBERS

  ///
  /// Default constructor; creates an unattached iterator,
  /// with and all-pass filter
  ///
  postorder_iterator();

  ///
  /// Copy constructor
  ///
  postorder_iterator(const postorder_iterator& xother);

  ///
  /// Destructor
  ///
  ~postorder_iterator();

  ///
  /// True if other conforms to this
  ///
  virtual bool is_ancestor_of(const any* other) const;

  ///
  /// Make a new instance of the same type as this
  ///
  virtual postorder_iterator* clone() const;

  ///
  /// The class invariant.
  ///
  bool invariant() const;

  // OTHER CONSTRUCTORS

  ///
  /// Creates an iterator anchored at xanchor, with no filter.
  /// If xdown, iterate in the down direction, otherwise iterate up.
  /// If xstrict, iterate over strict up/down set only.
  ///
  postorder_iterator(const abstract_poset_member& xanchor,
		     bool xdown,
		     bool xstrict);

  ///
  /// Creates an iterator anchored at xanchor, filtered by xfilter.
  /// If xdown, iterate in the down direction, otherwise iterate up.
  /// If xstrict, iterate over strict up/down set only.
  ///
  postorder_iterator(const abstract_poset_member& xanchor,
		     const subposet& xfilter,
		     bool xdown,
		     bool xstrict);

  ///
  /// Creates an iterator anchored at xanchor, filtered by xfilter_index.
  /// If xdown, iterate in the down direction, otherwise iterate up.
  /// If xstrict, iterate over strict up/down set only.
  ///
  postorder_iterator(const abstract_poset_member& xanchor,
		     pod_index_type xfilter_index,
		     bool xdown,
		     bool xstrict);

  ///
  /// Creates an iterator anchored at xanchor, filtered by xfilter_index.
  /// If xdown, iterate in the down direction, otherwise iterate up.
  /// If xstrict, iterate over strict up/down set only.
  ///
  postorder_iterator(const abstract_poset_member& xanchor,
		     const scoped_index& xfilter_index,
		     bool xdown,
		     bool xstrict);

  ///
  /// Creates an iterator anchored at xanchor, filtered by xfilter_name.
  /// If xdown, iterate in the down direction, otherwise iterate up.
  /// If xstrict, iterate over strict up/down set only.
  ///
  postorder_iterator(const abstract_poset_member& xanchor,
		     const std::string& xfilter_name,
		     bool xdown,
		     bool xstrict);
};

} // namespace sheaf

#endif // ifndef POSTORDER_ITERATOR_H
