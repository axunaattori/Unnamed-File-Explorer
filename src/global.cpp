#include "global.hpp"
#include <notcurses/notcurses.h>

namespace UFEglobal
{
    unsigned int rows;
    unsigned int cols;

    std::uint64_t Selected = 0;

    void updateSize(struct ::notcurses* nc)
    {
        notcurses_term_dim_yx(nc, &rows, &cols);
    }
}
