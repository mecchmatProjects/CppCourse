//
// Created by User on 26.05.2019.
//
#include "../headers/common.h"

class DualStream {
public:
    /** Helper class for writing simultaneously into two streams.
     *
     */
    DualStream(std::ostream& os1, std::ostream& os2) : os1(os1), os2(os2) {}

    template<class T>
    DualStream& operator<<(const T& x) {
        os1 << x;
        os2 << x;
        return *this;
    }
private:
    std::ostream& os1;
    std::ostream& os2;
};
