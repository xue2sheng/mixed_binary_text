#include <iostream>
//#include <iterator>
#include <boost/program_options.hpp>
#include <exception>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::string;
namespace po = boost::program_options;

int main(int ac, char** av){

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
/*
        if (vm.count("compression")) {
            cout << "Compression level was set to "
                 << vm["compression"].as<double>() << ".\n";
        } else {
            cout << "Compression level was not set.\n";
        }
        */
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
    return 0;
}
