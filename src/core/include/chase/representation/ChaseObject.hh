/**
 * @author      <a href="mailto:michele.lora@univr.it">Michele Lora</a>
 * @date        2019
 * @copyright   Copyright (c) 2019 by University of Verona.
 *              Copyright (c) 2019 by Singapore University of Technology and Design.
 *              All rights reserved.
 *              This project is released under the 3-Clause BSD License.
 *
 */

#pragma once

#include <string>

#include "BaseVisitor.hh"

namespace chase {

    /// @brief Enumeration of the nodes types.
    enum nodeType
    {
        object_node,
        specification_node,
        contract_node,
        boolean_node,
        booleanValue_node,
        constant_node,
        dataDeclaration_node,
        declaration_node,
        expression_node,
        identifier_node,
        integer_node,
        integerValue_node,
        name_node,
        numericValue_node,
        range_node,
        real_node,
        realValue_node,
        simpleType_node,
        type_node,
        value_node,
        variable_node,
        proposition_node,
        unaryBooleanOperation_node,
        binaryBooleanOperation_node,
        booleanConstant_node,
        modalOperation_node,
        large_boolean_formula_node,
        unaryTemporalOperation_node,
        binaryTemporalOperation_node,
        graph_edge_node,
        graph_vertex_node,
        graph_node
    };

    /// @brief Base abstract class for all the objects in the abstract syntax tree.
    class ChaseObject
    {
        protected:

            /// @brief Pointer to the parent node. If Null: root object.
            ChaseObject * _parent;

            /// @brief Type of node in the AST.
            nodeType _node_type;

        public:

            /// @brief Constructor.
            ChaseObject();
            /// @brief Destructor.
            virtual ~ChaseObject();


            /// @brief Getter function to the parent pointer.
            /// @return a pointer to the parent pointer.
            ChaseObject * getParent();

            /// @brief Setter function for the parent pointer.
            /// @param parent Pointer to the parent pointer.
            void setParent(chase::ChaseObject * parent );

            /// @brief Main function for the visitor pattern.
            /// @param v The visitor visiting the object.
            /// @return The return value of the visitor.
            virtual int accept_visitor(chase::BaseVisitor &v ) = 0;

            /// @brief Print the object into a string.
            /// @return a String representation of the object.
            virtual std::string getString() = 0;

            /// @brief Function providing the node type ID of the object.
            /// @return the node type of the AST node.
            nodeType IsA();
    };

}

