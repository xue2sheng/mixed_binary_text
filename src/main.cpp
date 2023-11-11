#include <iostream>
//#include <iterator>
#include <boost/program_options.hpp>
#include <exception>
#include <string>
#include "lib.h"

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::string;
namespace po = boost::program_options;

int main(int ac, char** av){

    std::string input;
    std::string output;
    std::string value;
    std::string start;
    std::string end;

    po::options_description desc("Allowed options");
    try {

        desc.add_options()
            ("help", "produce help message")
            ("input,i", po::value<string>(), "input binary file")
            ("output,o", po::value<string>(), "output text file")
            ("value,v", po::value<string>(), "value to find")
            ("start,s", po::value<string>(), "start timestamp to search from")
            ("end,e", po::value<string>(), "end timestamp to search to");

        po::variables_map vm;
        po::store(po::parse_command_line(ac, av, desc), vm);
        po::notify(vm);

        if (vm.count("help")) {
            cout << desc << "\n";
            return 0;
        }

        if (vm.count("input"))
            input = vm["input"].as<string>();
        else {
            cerr << "missing required --input commandline argument";
            return -1;
        }

        if (vm.count("output"))
            output = vm["output"].as<string>();
        else {
            cerr << "missing required --output commandline argument";
            return -1;
        }

        // optional
        if (vm.count("value"))
            value = vm["value"].as<string>();
        if (vm.count("start"))
            start = vm["start"].as<string>();
        if (vm.count("end"))
            end = vm["end"].as<string>();
    }
    catch(exception& e) {
        cerr << "error: " << e.what() << "\n";
        cerr << desc << "\n";
        return 1;
    }
    catch(...) {
        cerr << "Exception of unknown type!\n";
        return 1;
    }

    return process(input.c_str(), input.size(), output.c_str(), output.size(), value.c_str(),
        value.size(), start.c_str(), start.size(), end.c_str(), end.size());
}
