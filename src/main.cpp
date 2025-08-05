#include <notcurses/notcurses.h>
#include <iostream>

#include "files.hpp"
#include "ui.hpp"
#include "global.hpp"

#include <cxxopts.hpp>
#include <ncpp/NotCurses.hh>

int main(int argc, char **argv)
{
    std::string path;
    try {
        cxxopts::Options options("ufe", "Unnamed File Explorer");

        options.add_options()
            ("p,path", "Specify the path to open", cxxopts::value<std::string>())
            ("h,help", "Show this message and exit");
    
        auto result = options.parse(argc, argv);
    
        if (result.count("help"))
        {
            std::cout << options.help() << std::endl;
            exit(0);
        }   
        if (result.count("path"))
        {
            path = result["path"].as<std::string>();
        }

    } 

    catch (const cxxopts::exceptions::exception& e)
    {
        std::cout << e.what() << '\n';
        exit(1);
    };

    //if --path not used use the current path
    if (path == "")
    {
        path = std::filesystem::current_path();
    }
    
    if (!std::filesystem::exists(path))
    {
        std::cout << "Path " << path << " doesn't exist!\n";
        return 1;
    }


    //notcurses init
    if(setlocale(LC_ALL, "") == nullptr){
        return EXIT_FAILURE;
    };

    notcurses_options opts{};
    struct notcurses* nc = notcurses_init(&opts, stdout);

    struct ncplane* stdplane = notcurses_stdplane(nc);

    //get screen::rows and screen::col into the correct numbers
    UFEglobal::updateSize(nc);
     
    while (true)
    {
        ColorBackground(stdplane);
        printfiles(path, stdplane);
        printpath(path, stdplane);
        drawBorder(stdplane);

        notcurses_render(nc);
        usleep(100000); //add a way to only sleep the required time, like refresh until input or screen update.
    }

    notcurses_stop(nc);

    return 0;
}
