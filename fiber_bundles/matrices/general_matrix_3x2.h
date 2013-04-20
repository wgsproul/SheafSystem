

//
// Copyright (c) 2013 Limit Point Systems, Inc. 
//

// Interface for general_matrix_3x2 classes.

#ifndef GENERAL_MATRIX_3X2_H
#define GENERAL_MATRIX_3X2_H

#ifndef SHEAF_DLL_SPEC_H
#include "sheaf_dll_spec.h"
#endif

#ifndef STD_IOSTREAM_H
#include "std_iostream.h"
#endif

namespace fiber_bundle
{

template <typename T> class general_matrix_1x2;
template <typename T> class general_matrix_2x1;
template <typename T> class general_matrix_2x2;
template <typename T> class general_matrix_2x3;
template <typename T> class general_matrix_3x1;
template <typename T> class general_matrix_3x3;

template <typename T> class jcb_e23_row_dofs_type;

//==============================================================================
//==============================================================================

///
/// General matrix with 3 rows and 2 columns.
///
/// Class general_matrix_3x2 is a special kind of matrix class intended to be
/// used in conjunction with various row_dofs_type classes (pod types).
/// The pod types will be converted (cast) to appropriate matrix types.
/// So, this class is also required to be a pod type also (ie: really just a 
/// struct with no inheritance, no constructors, no virtual functions, etc.).
///
///
template <typename T>
class general_matrix_3x2
{
public:

  ///
  /// Operator to convert current to jcb_e23_row_dofs_type.
  ///
  operator jcb_e23_row_dofs_type<T>& () const;

  ///
  /// The number of rows.
  ///
  static int number_of_rows();

  ///
  /// The number of columns.
  ///
  static int number_of_columns();

  ///
  /// Dimension of the underlying elements.
  ///
  static int d();

  ///
  /// Pointer to the first element in row xrow of this matrix.
  /// Facilitates accessing elements via matrix[i][j].
  ///
  T* operator[](int xrow);

  ///
  /// Pointer to the first element in row xrow of this matrix.
  /// Facilitates accessing elements via matrix[i][j].
  ///
  const T* operator[](int xrow) const;

  ///
  /// Conversion (cast) operator to convert to the associated matrix type
  /// (non const version). 
  ///
  operator T* ();

  ///
  /// Conversion (cast) operator to convert to the associated matrix type
  /// (const version). 
  ///
  operator const T* () const;

  ///
  /// Index for row xrow in the linear storage array.
  ///
  int row_index(int xrow) const;

  ///
  /// A 1x2 matrix containing the elements or row xrow.
  ///
  general_matrix_1x2<T> row(int xrow) const;

  ///
  /// A 3x1 matrix containing the elements or column xcolumn.
  ///
  general_matrix_3x1<T> column(int xcolumn) const;

  ///
  /// Linear storage array.
  ///
  T components[6];

  //============================================================================
  //============================================================================

  ///
  /// Assign all elements of this matrix to the value xvalue.
  ///
  void assign(const T& xvalue);

  ///
  /// This matrix multiplied by a scalar (pre-allocated).
  ///
  void multiply(const T& xscalar, general_matrix_3x2<T>& xresult) const;

  ///
  /// This matrix multiplied by a scalar (auto-allocated).
  ///
  general_matrix_3x2<T> multiply(const T& xscalar) const;

  ///
  /// Premultiply matrix xother by this matrix (pre-allocated).
  ///
  void multiply(const general_matrix_2x3<T>& xother,
                general_matrix_3x3<T>& xresult) const;

  ///
  /// Premultiply matrix xother by this matrix (auto-allocated).
  ///
  general_matrix_3x3<T> multiply(const general_matrix_2x3<T>& xother) const;

  ///
  /// Premultiply matrix xother by this matrix (pre-allocated).
  ///
  void multiply(const general_matrix_2x2<T>& xother,
                general_matrix_3x2<T>& xresult) const;

  ///
  /// Premultiply matrix xother by this matrix (auto-allocated).
  ///
  general_matrix_3x2<T> multiply(const general_matrix_2x2<T>& xother) const;

  ///
  /// Premultiply matrix xother by this matrix (pre-allocated).
  ///
  void multiply(const general_matrix_2x1<T>& xother,
                general_matrix_3x1<T>& xresult) const;

  ///
  /// Premultiply matrix xother by this matrix (auto-allocated).
  ///
  general_matrix_3x1<T> multiply(const general_matrix_2x1<T>& xother) const;

  ///
  /// The transpose of the matrix (pre-allocated).
  ///
  void transpose(general_matrix_2x3<T>& xresult) const;

  ///
  /// The transpose of the matrix (auto-allocated).
  ///
  general_matrix_2x3<T> transpose() const;

protected:
private:

};

// =============================================================================
// NON-MEMBER FUNCTIONS
// =============================================================================

///
/// Insert general_matrix_3x2@<T@> xm into output stream xos.
///
template <typename T>
ostream& operator<<(ostream& xos, const general_matrix_3x2<T>& xm);


} // namespace fiber_bundle

#endif // ifndef GENERAL_MATRIX_3X2_H
