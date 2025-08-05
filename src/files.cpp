#include <filesystem>
#include <vector>
#include <ncpp/NotCurses.hh>
#include "global.hpp"
#include "config.hpp"
#include "files.hpp"

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
            if (Config::Colors::Directory.BG != 0) ncplane_set_bg_rgb(plane, Config::Colors::Directory.BG);
            if (Config::Colors::Directory.FG != 0) ncplane_set_fg_rgb(plane, Config::Colors::Directory.FG);
        }
        else if (!access(entries[i].path().c_str(), X_OK)) // executable
        {
            if (Config::Colors::Executable.BG != 0) ncplane_set_bg_rgb(plane, Config::Colors::Executable.BG);
            if (Config::Colors::Executable.FG != 0) ncplane_set_fg_rgb(plane, Config::Colors::Executable.FG);
        }
        else if (entries[i].is_fifo())
        {
            if (Config::Colors::NamedPipe.BG != 0) ncplane_set_bg_rgb(plane, Config::Colors::NamedPipe.BG);
            if (Config::Colors::NamedPipe.FG != 0) ncplane_set_fg_rgb(plane, Config::Colors::NamedPipe.FG);
        }
        else if (entries[i].is_socket())
        {
            if (Config::Colors::NamedIPCSocket.BG != 0) ncplane_set_bg_rgb(plane, Config::Colors::NamedIPCSocket.BG);
            if (Config::Colors::NamedIPCSocket.FG != 0) ncplane_set_fg_rgb(plane, Config::Colors::NamedIPCSocket.FG);
        }
        else if (entries[i].is_symlink())
        {
            if (Config::Colors::SymbolicLink.BG != 0) ncplane_set_bg_rgb(plane, Config::Colors::SymbolicLink.BG);
            if (Config::Colors::SymbolicLink.FG != 0) ncplane_set_fg_rgb(plane, Config::Colors::SymbolicLink.FG);
        }
        else if (entries[i].is_character_file())
        {
            if (Config::Colors::Character.BG != 0) ncplane_set_bg_rgb(plane, Config::Colors::Character.BG);
            if (Config::Colors::Character.FG != 0) ncplane_set_fg_rgb(plane, Config::Colors::Character.FG);
        }
        else if (entries[i].is_block_file())
        {
            if (Config::Colors::Block.BG != 0) ncplane_set_bg_rgb(plane, Config::Colors::Block.BG);
            if (Config::Colors::Block.FG != 0) ncplane_set_fg_rgb(plane, Config::Colors::Block.FG);
        }
        else if (entries[i].is_regular_file())
        {
            if (Config::Colors::Regular.BG != 0) ncplane_set_bg_rgb(plane, Config::Colors::Regular.BG);
            if (Config::Colors::Regular.FG != 0) ncplane_set_fg_rgb(plane, Config::Colors::Regular.FG);
        }
        else if (entries[i].is_other())
        {
            if (Config::Colors::Other.BG != 0) ncplane_set_bg_rgb(plane, Config::Colors::Other.BG);
            if (Config::Colors::Other.FG != 0) ncplane_set_fg_rgb(plane, Config::Colors::Other.FG);
        }

        ncplane_putstr_yx(plane, i, 0, entries[i].path().filename().string().c_str());
    }
}
