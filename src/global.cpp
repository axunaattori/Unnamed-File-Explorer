#include <notcurses/notcurses.h>
namespace UFEglobal
{
    unsigned int rows;
    unsigned int cols;
    void updateSize(struct notcurses* nc)
    {
        notcurses_term_dim_yx(nc, &rows, &cols);
    }
}
