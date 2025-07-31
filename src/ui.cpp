#include <ncpp/NotCurses.hh>
#include <notcurses/notcurses.h>
#include <string>
#include "config.hpp"
#include "global.hpp"

#define COLOR Config::Colors

void ColorBackground(struct ncplane* plane)
{ 
    if (COLOR::Background != 0)
        {
        ncplane_set_bg_rgb(plane, COLOR::Background);
        std::string str;
        for (unsigned int i = 0; i < UFEglobal::cols; i++)
        {
            str += " ";
        }
        for (unsigned int i = 0; i < UFEglobal::rows; i++)
        {
            ncplane_putstr_yx(plane, i, 0, str.c_str()); //i QUITE literally cant find a better way to do this
        }
    }
}

void drawBorder(struct ncplane* plane)
{
    std::string str;
    for (unsigned int i = 0; i < UFEglobal::cols; i++)
    {
         str += Config::UserInterface::horizontal;
    }

    if (COLOR::Horizontal.BG != 0) ncplane_set_bg_rgb(plane, COLOR::Horizontal.BG);
    if (COLOR::Horizontal.FG != 0) ncplane_set_fg_rgb(plane, COLOR::Horizontal.FG);
    ncplane_putstr_yx(plane, 1, 0, str.c_str());
}
