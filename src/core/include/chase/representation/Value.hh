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

#include "representation/ChaseObject.hh"
#include "representation/Type.hh"
#include "utilities.hh"

namespace chase {
    
    /// @brief Abstract class for all values.
    class Value : public ChaseObject
    {
        public:

            /// @brief Constructor.
            Value();
            /// @brief Destructor.
            virtual ~Value() override;

            /// @brief Type getter.
            /// @return The type of the value;
            virtual Type * getType() = 0;

        protected:


    };
}

