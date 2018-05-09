// This file is part of LatCommon.
//
// LatCommon
// Copyright (C) 2012-2016  Pierre L'Ecuyer and Universite de Montreal
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "latcommon/PODWeights.h"
#include <sstream>

#include <boost/lexical_cast.hpp>
using boost::lexical_cast;
using boost::bad_lexical_cast;

namespace LatCommon
{

//===========================================================================

PODWeights::PODWeights ()
{
}

//===========================================================================

Weight PODWeights::getWeight (const Coordinates& projection) const
{
   return m_orderDependentWeights.getWeight(projection) * m_productWeights.getWeight(projection);
}

//===========================================================================

void PODWeights::format(std::ostream& os) const
{
   using LatCommon::operator<<;
   os << "PODWeights(" << m_orderDependentWeights << ", " << m_productWeights << ")";
}

} // namespace LatCommon

//===========================================================================

#ifdef WITH_XML
#include "xmlerror.hpp"

namespace LatCommon
{

PODWeights* PODWeights::createFromXML (const pugi::xml_node& root)
{
   PODWeights* o = new PODWeights();

   pugi::xml_node node;

   try {
      // order-dependent weights
      node = root.child("order-dependent");
      if (!node)
         throw pugi::xml_error(root, "missing <order-dependent> element");
      OrderDependentWeights* odw = OrderDependentWeights::createFromXML(*node);
      o->m_orderDependentWeights = *odw;
      delete odw;

      // product weights
      node = root.child("product");
      if (!node)
         throw pugi::xml_error(root, "missing <product> element");
      ProductWeights* pw = ProductWeights::createFromXML(*node);
      o->m_productWeights = *pw;
      delete pw;

      return o;
   }
   catch (bad_lexical_cast& e) {
      delete o;
      throw pugi::xml_error(node, e.what());
   }
}

} // namespace LatCommon
#endif