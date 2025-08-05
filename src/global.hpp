#pragma once
#include <cstdint>

namespace UFEglobal
{
    extern unsigned int rows;
    extern unsigned int cols;
    extern std::uint64_t Selected;

    void updateSize(struct notcurses* nc);
}
