///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Generic.cc
// Copyright   :  (c) Andy Arvanitis 2016
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Generic FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//

#include "Generic.hh"

namespace Data_Generic {

  using namespace PureScript;

  // foreign import zipAll
  //   :: forall a b
  //    . (a -> b -> Boolean)
  //   -> Array a
  //   -> Array b
  //   -> Boolean
  //
  auto zipAll(const any& f, const any::array& xs, const any::array& ys) -> bool {
    const auto length = std::min(xs.size(), ys.size());
    for (any::array::size_type i = 0; i < length; i++) {
      if (not f(xs[i])(ys[i])) {
        return false;
      }
    }
    return true;
  }

  // foreign import zipCompare
  //   :: forall a b
  //    . (a -> b -> Int)
  //   -> Array a
  //   -> Array b
  //   -> Int
  //
  auto zipCompare(const any& f, const any::array& xs, const any::array& ys) -> int {
    const auto xlen = xs.size();
    const auto ylen = ys.size();
    const auto length = std::min(xlen, ylen);
    for (any::array::size_type i = 0; i < length; i++) {
      const int o = f(xs[i])(ys[i]);
      if (o != 0) {
        return o;
      }
    }
    return xlen < ylen ? 1 : xlen > ylen ? -1 : 0;
  }

}
