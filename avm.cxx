#include <iostream>
#include <cstdlib> 
#include <cstring> 
using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " --start|--stop|--forwad|--help" << endl;
        return 1;
    }

    if (strcmp(argv[1], "--start") == 0) {
        cout << "Starting your script" << argv[2] << endl;
        int result = system("bash .RunCode.avm");
        if (result == 0) {
            cout << "The script finished." << endl;
        } else {
            cerr << "We couldn't start the script. Please check your script context. If the error persist please contact support" << endl;
        }
    } else if (strcmp(argv[1], "--stop") == 0) {
        cout << "Stopping instance" << argv[2] << endl;
        int result = system("bash .stop.avm");
        if (result == 0) {
            cout << "Instance stopped." << endl;
        } else {
            cerr << "Internal server error! Contact support." << endl;
        }
    } else if (strcmp(argv[1], "--forwad") == 0) {
        cout << "Forwading port 8080 for testing." << argv[2] << endl;
        system("bash .RunCode-forwad.avm");
        int result = system("bash .RunCode-forwad.avm");
        if (result == 0) {
            cout << "Tunnel ran successfully." << endl;
        } else {
            cerr << "We couldn't create tunnel! Please contact support or change domain or port." << endl;
        }
    } else if (strcmp(argv[1], "--help") == 0) {
        cout << "Usage: " << argv[0] << " --start|--stop|--forwad|--help" << endl;
      else {
        cerr << "Unknown option: " << argv[1] << endl;
        return 1;
    }

    return 0;
}
}
