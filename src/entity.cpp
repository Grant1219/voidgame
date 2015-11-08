#include <entity.hpp>

namespace voidgame {
    uint64_t entity::nextid = 1;

    entity::entity () {
        eid = entity::nextid;
        entity::nextid++;
    }
}
