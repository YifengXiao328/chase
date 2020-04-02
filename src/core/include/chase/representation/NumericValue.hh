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

#include "representation/Value.hh"
#include "representation/Type.hh"
#include "utilities.hh"

namespace chase {
    
    /// @brief Abstract class for all the numeric values (e.g., Integers, Doubles, etc.).
    class NumericValue : public Value
    {
        using sptr_type = std::shared_ptr<Type>;

        public:

            /// @brief Numericructor.
            NumericValue();
            /// @brief Destructor.
            ~NumericValue() override;

            /// @brief Getter for the type.
            /// @return the type of the value.
            sptr_type getType();

            /// @brief Setter for the type.
            /// @param t the type of the NumericValue.
            void setType( sptr_type t );

        protected:

            /// @brief Type of the value.
            sptr_type _type;

    };
}

