/**
 * @author      <a href="mailto:michele.lora@univr.it">Michele Lora</a>
 * @date        1/23/2020
 *              This project is released under the 3-Clause BSD License.
 *
 */


#include <utility>

#include "chase/representation/System.hh"
#include "chase/utilities/ClonedDeclarationVisitor.hh"

using namespace chase;

System::System( std::string name ) :
    _name(new Name(name))
{
    _name->setParent(this);
}

System::~System() = default;

void System::addDeclaration(Declaration *declaration)
{
    _declarations.insert(declaration);
    declaration->setParent(this);
}

void System::addContract(Contract *contract)
{
    _contracts.insert(contract);
    contract->setParent(this);
}

std::set<Declaration *> &System::getDeclarationsSet() {
    return _declarations;
}

std::set<Contract *> &System::getContractsSet() {
    return _contracts;
}




int System::accept_visitor(chase::BaseVisitor &v) {
    return v.visitSystem(*this);
}

std::string System::getString() {
    std::string ret("SYSTEM:\t" + _name->getString() + "\n");

    ret += "DECLARATIONS:\n";
    for(auto it = _declarations.begin(); it != _declarations.end(); ++it)
    {
        ret += (*it)->getString();
        ret += "\n";
    }
    ret += "\n";

    ret += "CONTRACTS:\n";
    for(auto it = _contracts.begin(); it != _contracts.end(); ++it)
    {
        ret += (*it)->getString();
        ret += "\n";
    }

    return ret;
}

System *System::clone()
{
    auto ret = new System(_name->getString());

    std::map< Declaration *, Declaration * > declaration_map;

    for(auto it = _declarations.begin(); it != _declarations.end(); ++it)
    {
        Declaration * current = *it;
        auto dec = current->clone();
        std::pair< Declaration *, Declaration * > p(current, dec);
        ret->addDeclaration(dec);
        declaration_map.insert(p);
    }

    for(auto it = _contracts.begin(); it != _contracts.end(); ++it) {
        ret->addContract((*it)->clone());
    }

    for(auto it = _components.begin(); it != _components.end(); ++it)
    {
        ret->addComponent((*it)->clone());
    }


    ClonedDeclarationVisitor c(declaration_map);
    ret->accept_visitor(c);

    return ret;
}

Name * System::getName()
{
    return _name;
}

void System::setName(Name * name)
{
    _name = name;
    _name->setParent(this);
}

void System::addComponent(Component * component)
{
    _components.insert(component);
    component->setParent(this);
}

std::set<Component *> &System::getComponentsSet() {
    return _components;
}
