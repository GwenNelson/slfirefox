
#ifndef BOOST_MPL_AUX_FOLD_OP_HPP_INCLUDED
#define BOOST_MPL_AUX_FOLD_OP_HPP_INCLUDED

// Copyright Aleksey Gurtovoy 2001-2004
//
// Distributed under the Boost Software License, Version 1.0. 
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://www.boost.org/libs/mpl for documentation.

// $Source: /cvsroot/boost/boost/boost/mpl/aux_/fold_op.hpp,v $
// $Date: 2008-03-20 14:41:26 -0700 (Thu, 20 Mar 2008) $
// $Revision: 82858 $

#include <boost/mpl/apply.hpp>

namespace boost { namespace mpl { namespace aux {

// hand-written version is more efficient than bind/lambda expression
template< typename Op >
struct fold_op
{
    template< typename T1, typename T2 > struct apply
    {
        typedef typename apply2<
              Op
            , T1
            , typename T2::type
            >::type type;
    };
};

}}}

#endif // BOOST_MPL_AUX_FOLD_OP_HPP_INCLUDED
