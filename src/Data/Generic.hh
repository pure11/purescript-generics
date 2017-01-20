///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Generic.hh
// Copyright   :  (c) Andy Arvanitis 2015
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Assert FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef Data_Generic_FFI_HH
#define Data_Generic_FFI_HH

#include "PureScript/PureScript.hh"

namespace Data_Generic {
  using namespace PureScript;

  inline auto anyProxy() -> any {
    return Type_Proxy::Proxy();
  };

  // foreign import zipAll
  //   :: forall a b
  //    . (a -> b -> Boolean)
  //   -> Array a
  //   -> Array b
  //   -> Boolean
  //
  auto zipAll(const any&, const any::array&, const any::array&) -> bool;

  // foreign import zipCompare
  //   :: forall a b
  //    . (a -> b -> Int)
  //   -> Array a
  //   -> Array b
  //   -> Int
  //
  auto zipCompare(const any&, const any::array&, const any::array&) -> int;

}

#endif // Data_Generic_FFI_HH
