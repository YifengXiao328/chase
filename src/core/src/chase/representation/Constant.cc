/**
 * @author      <a href="mailto:michele.lora@univr.it">Michele Lora</a>
 * @date        2019
 * @copyright   Copyright (c) 2019 by University of Verona.
 *              Copyright (c) 2019 by Singapore University of Technology and Design.
 *              All rights reserved.
 *              This project is released under the 3-Clause BSD License.
 *
*/

#include "representation/Constant.hh"

using namespace chase;

Constant::Constant( Type * type, Name * name ) :
    DataDeclaration( type, name )
{
    _node_type = constant_node;

    _name->setParent(this);
    _type->setParent(this);
}

Constant::~Constant()
{
    if(_name != nullptr) delete _name;
    if(_type != nullptr) delete _type;
}

Constant::Constant( const Constant &o ) :
    DataDeclaration( o._type, o._name )
{
    _node_type = constant_node;
    _name->setParent(this);
    _type->setParent(this);
}

Constant & Constant::operator=(const Constant &o )
{
    if( &o != this )
    {
        /// @todo Implement the copy properly.
    }
    return *this;
}

std::string Constant::getString()
{
    std::string ret;
    if( _name != nullptr && _type != nullptr )
    {
        ret += _type->getString();
        ret += " ";
        ret += _name->getString();
    }
    else{
        ret = std::string("NULL CONSTANT");
    }
    return ret;

}

int Constant::accept_visitor( BaseVisitor &v )
{
    return v.visitConstant(*this);
}
