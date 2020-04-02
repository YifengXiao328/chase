/**
 * @author      <a href="mailto:michele.lora@univr.it">Michele Lora</a>
 * @date        2019
 * @copyright   Copyright (c) 2019 by University of Verona.
 *              Copyright (c) 2019 by Singapore University of Technology and Design.
 *              All rights reserved.
 *              This project is released under the 3-Clause BSD License.
 *
*/

#include "representation/RealValue.hh"
#include "representation/Real.hh"

using namespace chase;
using namespace std;

using sptr_realval = std::shared_ptr<RealValue>;

RealValue::RealValue( double value ) :
    NumericValue(),
    _value(value)
{
    _node_type = realValue_node;
    setType(make_shared<Real>());
}

RealValue::~RealValue()
{
}

RealValue::RealValue( const RealValue & o ) :
    NumericValue(),
    _value(o._value)
{
    _node_type = realValue_node;
}

RealValue & RealValue::operator=( const RealValue &o )
{
    _value = o._value;
    return *this;
}

double RealValue::getValue()
{
    return _value;
}

void RealValue::setValue( const double v )
{
    _value = v;
}

int RealValue::accept_visitor( BaseVisitor &v )
{
    return v.visitRealValue( *this );
}

std::string RealValue::getString()
{
    return std::to_string(_value);
}

sptr_realval RealValue::clone()
{
    auto ret = make_shared<RealValue>(_value);
    ret->setType(_type);
    return ret;
}
