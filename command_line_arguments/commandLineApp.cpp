#include <iostream>
#include <getopt.h>
using namespace std;

int main(int argc, char* argv[]) {
    char short_options[] = "hv";
    int opt;
    while ((opt = getopt(argc, argv, short_options)) != -1) {
        switch (opt) {
            case 'h':
                cout << "Usage: myprogram [options]\n\n"
                     << "Options:\n"
                     << "  -h    Print this help message\n"
                     << "  -v    Print the version number\n";
                break;
            case 'v':
                cout << "myprogram v1.0.0\n";
                break;
            default:
                cout << "Unknown option. Use '-h' for usage information.\n";
                break;
        }
    }

    if (argc == 1) {
        cout << "Use '-h' for usage information.\n";
    }

    return 0;
}