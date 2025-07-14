#include <notcurses/notcurses.h>
#include <string>
#include <filesystem>
#include <vector>
#include <ncpp/NotCurses.hh>
#include <unistd.h>

#include "global.hpp"
#include "config.hpp"

void printpath(std::string path, struct ncplane* plane)
{
    ncplane_putstr_yx(plane, 0, 0, path.c_str());
}

void printfiles(std::string path, struct ncplane* plane)
{
    std::vector<std::filesystem::directory_entry> entries;
    for (const auto & entry : std::filesystem::directory_iterator(path))
        entries.push_back(entry);

    for (unsigned int i = 2; i < entries.size(); i++)
    {
        if (UFEglobal::cols <= i){
            break;
        }

        if (entries[i].is_directory())
        {
            ncplane_set_bg_rgb(plane, Config::Colors::Directory.BG);
            ncplane_set_fg_rgb(plane, Config::Colors::Directory.FG);
        }
        else if (!access(entries[i].path().c_str(), X_OK)) // executable
        {
            ncplane_set_bg_rgb(plane, Config::Colors::Executable.BG);
            ncplane_set_fg_rgb(plane, Config::Colors::Executable.FG);
        }
        else if (entries[i].is_fifo())
        {
            ncplane_set_bg_rgb(plane, Config::Colors::NamedPipe.BG);
            ncplane_set_fg_rgb(plane, Config::Colors::NamedPipe.FG);
        }
        else if (entries[i].is_socket())
        {
            ncplane_set_bg_rgb(plane, Config::Colors::NamedIPCSocket.BG);
            ncplane_set_fg_rgb(plane, Config::Colors::NamedIPCSocket.FG);
        }
        else if (entries[i].is_symlink())
        {
            ncplane_set_bg_rgb(plane, Config::Colors::SymbolicLink.BG);
            ncplane_set_fg_rgb(plane, Config::Colors::SymbolicLink.FG);
        }
        else if (entries[i].is_character_file())
        {
            ncplane_set_bg_rgb(plane, Config::Colors::Character.BG);
            ncplane_set_fg_rgb(plane, Config::Colors::Character.FG);
        }
        else if (entries[i].is_block_file())
        {
            ncplane_set_bg_rgb(plane, Config::Colors::Block.BG);
            ncplane_set_fg_rgb(plane, Config::Colors::Block.FG);
        }
        else if (entries[i].is_regular_file())
        {
            ncplane_set_bg_rgb(plane, Config::Colors::Regular.BG);
            ncplane_set_fg_rgb(plane, Config::Colors::Regular.FG);
        }
        else if (entries[i].is_other())
        {
            ncplane_set_bg_rgb(plane, Config::Colors::Other.BG);
            ncplane_set_fg_rgb(plane, Config::Colors::Other.FG);
        }

        ncplane_putstr_yx(plane, i, 0, entries[i].path().filename().string().c_str());
    }
}
