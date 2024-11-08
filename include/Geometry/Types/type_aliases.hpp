#include "Geometry/Types/fint_t.hpp"
#include "Geometry/Types/vec2.hpp"

#include <cstdint>

namespace bpw {
    using fint64_t  = fint_t<std::int64_t>;
    using fint32_t  = fint_t<std::int32_t>;

    using Vec2fi64_t = Vec2<fint64_t>;
    using Vec2fi32_t = Vec2<fint32_t>;
    using Vec2i64_t  = Vec2<std::int64_t>;
    using Vec2i32_t  = Vec2<std::int32_t>;
    using Vec2f_t    = Vec2<float>;
    using Vec2d_t    = Vec2<double>;
}