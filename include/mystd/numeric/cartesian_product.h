#ifndef _MYSTD_NUMERIC_CARTESIAN_PRODUCT
#define _MYSTD_NUMERIC_CARTESIAN_PRODUCT

namespace mystd
{
  /////////////////////////////////////////////////////////////////////////////
  /// Computes the cartesian product of two ranges and store at an output
  /// range.
  /// Input ranges must not overlap with output range but may overlap with
  /// each other.
  /// Requires that the following expression is valid:
  ///   *out_first = { *first1, *first2 };
  /////////////////////////////////////////////////////////////////////////////
  template<typename FwdItr1, typename FwdItr2, typename OutItr>
  OutItr cartesian_product(FwdItr1 first1, FwdItr1 last1
                         , FwdItr2 first2, FwdItr2 last2
                         , OutItr out_first)
  {
    while (first1 != last1)
    {
      auto tmp_first2 = first2;
      while (tmp_first2 != last2)
      {
        *out_first = { *first1, *tmp_first2 };
        ++out_first;
        ++tmp_first2;
      }
      ++first1;
    }
    return out_first;
  }

  /////////////////////////////////////////////////////////////////////////////
  /// Computes the cartesian product of two ranges and store at an output
  /// range.
  /// Input ranges must not overlap with output range but may overlap with
  /// each other.
  /// Values are combined using the provided binary operator.
  /////////////////////////////////////////////////////////////////////////////
  template<typename FwdItr1, typename FwdItr2, typename OutItr, typename BiOp>
  OutItr cartesian_product(FwdItr1 first1, FwdItr1 last1
                         , FwdItr2 first2, FwdItr2 last2
                         , OutItr out_first, BiOp&& combinator)
  {
    while (first1 != last1)
    {
      auto tmp_first2 = first2;
      while (tmp_first2 != last2)
      {
        *out_first = combinator(*first1, *tmp_first2);
        ++out_first;
        ++tmp_first2;
      }
      ++first1;
    }
    return out_first;
  }
}

#endif