/**
 * @author      <a href="mailto:michele.lora@univr.it">Michele Lora</a>
 * @date        11/12/2019
 *              This project is released under the 3-Clause BSD License.
 *
 */

#pragma once

#include "DSLParser/ChaseLexer.h"
#include "DSLParser/ChaseBaseListener.h"
#include "DSLParser/ChaseListener.h"
#include "DSLParser/ChaseParser.h"

#include "Chase.hh"
#include "DesignProblem.hh"

namespace patternsOnNetworks {

    class SpecBuilder : public ChaseBaseListener {
    public:
        /// @brief Constructor.
        SpecBuilder();

        /// @brief Destructor.
        ~SpecBuilder() override;

        /// @brief Function to access the DesignProblem object being built.
        /// @return A pointer to the design problem built by the parser.
        DesignProblem * getProblem();

        /// @brief Main parsing function.
        /// @param infile The specification file to be parsed.
        /// @return A pointer to the design problem constructed by the parser.
        DesignProblem * parseSpecificationFile( std::string infile );

        // -- PARSER METHODS.
        void enterType(ChaseParser::TypeContext *context) override;
        void enterComponent(ChaseParser::ComponentContext *context) override;
        void enterAbbrev(ChaseParser::AbbrevContext *context) override;

        void
        enterConnections(ChaseParser::ConnectionsContext *context) override;
        void exitConnections(ChaseParser::ConnectionsContext *context) override;
        void enterSwitched(ChaseParser::SwitchedContext *context) override;
        void enterUnswitched(ChaseParser::UnswitchedContext *context) override;
        void enterConn(ChaseParser::ConnContext *context) override;

        void
        enterRequirements(ChaseParser::RequirementsContext *context) override;
        void
        exitRequirements(ChaseParser::RequirementsContext *context) override;
        void enterReq(ChaseParser::ReqContext *context) override;
        void
        enterAssumptions(ChaseParser::AssumptionsContext *context) override;
        void exitAssumptions(ChaseParser::AssumptionsContext *context) override;

        void enterParam(ChaseParser::ParamContext *context) override;

        void visitTerminal( antlr4::tree::TerminalNode * ) override {};
        void visitErrorNode( antlr4::tree::ErrorNode * ) override{};

    protected:

        /// @brief The internal representation of the design problem.
        DesignProblem * _problem;

        /// @brief Flags to manage the parsing of the connections.
        bool _inConnections, _inSwitched, _inUnswitched;
        /// @brief Variable needed to manage switched connections section.
        DomainSpecificType * _currentSwitchType;

        /// @brief Flags to manage the parsing of the functions.
        bool _assumptions, _requirements;

        /// @brief Variable to keep tracked the current function while exploring
        /// the parameters.
        SpecFunction * _currentFunction;

        /// @brief Support function to retrieve the string corresponding to
        /// a name, given an ANTLR4 ChaseParser NameContext.
        /// @param context Pointer to the NameContext fo analyze.
        /// @return String extracted from the context.
        static std::string _getNameFromContext(
                ChaseParser::NameContext * context );
        /// @brief Support function to retrieve the string corresponding to
        /// a name, given an ANTLR4 ChaseParser NameContext.
        /// @param context Reference to the NameContext fo analyze.
        /// @return String extracted from the context.
        static std::string _getNameFromContext(
                Ref< ChaseParser::NameContext > context );

        /// @brief Support function to retrieve the component type given a
        /// a string parsed from the file.
        /// @param t The string specifying the type.
        /// @return The component_type corresponding to the string.
        static component_type _resolveType( std::string t );

        /// @brief Function providing a pointer to a component, given a name or
        /// a abbreviation.
        /// @param str The name or the abbreviation of the component.
        /// @return Pointer to the corresponding component.
        Component * _getComponent( std::string str );

        /// @brief Function parsing a switched connection.
        /// @param The context being parsed.
        void _enterSwitchedConn( ChaseParser::ConnContext * ctx );
        /// @brief Function parsing a non-switched connection.
        /// @param The context being parsed.
        void _enterUnswitchedConn( ChaseParser::ConnContext * ctx );
        /// @brief Function parsing a connection with a specific connector.
        /// @param The context being parsed.
        void _enterSpecificConn( ChaseParser::ConnContext * ctx );
    };

}
