#include "key_codes.h"

namespace poseidon
{
    KeyModifiers operator|(KeyModifiers lhs, KeyModifiers rhs) {
        return static_cast<KeyModifiers>(
            static_cast<std::underlying_type_t<KeyModifiers>>(lhs) |
            static_cast<std::underlying_type_t<KeyModifiers>>(rhs)
            );
    }

    KeyModifiers operator&(KeyModifiers lhs, KeyModifiers rhs) {
        return static_cast<KeyModifiers>(
            static_cast<std::underlying_type_t<KeyModifiers>>(lhs) &
            static_cast<std::underlying_type_t<KeyModifiers>>(rhs)
            );
    }
}