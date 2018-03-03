/**
 * @author      <a href="mailto:michele.lora@univr.it">Michele Lora</a>
 * @date        March 3, 2018
 * @copyright   Copyright (c) 2015-2018 by University of California, Berkeley.\n
 *              Copyright (c) 2015-2018 by University of Verona.\n
 *              Copyright (c) 2015-2018 by International Business Machines Corporation.\n
 *              Copyright (c) 2016-2018 by University of Southern California.\n
 *              All rights reserved.\n
 *              This project is released under the 3-Clause BSD License.
 *
 * @file	chase/include/Manipulation/FixParentsVisitor.hh
 * @brief
 */



#pragma once

#include "Manipulation/GuideVisitor.hh"
#include "Behaviors/Logics/Logics.hh"


namespace Manipulation {

    /// @brief This visitor fixes the parents pointers of a Well Formed Formula.
    /// @TODO Extend to the entire AST.
    class FixParentsVisitor : public GuideVisitor
    {

            int visitBinaryFormula(
                    Behaviors::Logics::BinaryFormula & o );

            int visitUnaryFormula(
                    Behaviors::Logics::UnaryFormula & o );

            int visitBooleanFormula(
                    Behaviors::Logics::BooleanFormula & o );

            int visitTemporalFormula(
                    Behaviors::Logics::TemporalFormula & o );

            int visitUnaryLogicCombination(
                    Behaviors::Logics::UnaryLogicCombination & o );

            int visitBinaryLogicCombination(
                    Behaviors::Logics::BinaryLogicCombination & o );

            int visitBinaryTemporalFormula(
                    Behaviors::Logics::BinaryTemporalFormula & o );

            int visitUnaryTemporalFormula(
                    Behaviors::Logics::UnaryTemporalFormula & o );


        public:
            FixParentsVisitor();
            ~FixParentsVisitor();

        protected:
            FixParentsVisitor( const FixParentsVisitor & );
            FixParentsVisitor & operator=( const FixParentsVisitor & );

    };

}



