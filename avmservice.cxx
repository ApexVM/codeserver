#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " --start|--stop|--reload" << endl;
        return 1;
    }

    if (strcmp(argv[1], "--start") == 0) {
        cout << "Installing: " << argv[2] << endl;
        string installCommand = "bash ~/.avm/service/start.avm";
        int result = system(installCommand.c_str());
        if (result == 0) {
            cout << "Successfully started avmservice!" << endl;
        } else {
            cerr << "Didn't you see avmservice is running?" << endl;
        }
    } else if (strcmp(argv[1], "--stop") == 0) {
        cout << "Uninstalling: " << argv[2] << endl;
        string uninstallCommand = "bash ~/.avm/service/stop.avm";
        int result = system(uninstallCommand.c_str());
        if (result == 0) {
            cout << "Instance is stopping" << endl;
        } else {
            cerr << "Did you say stop? Uh we ran into issue!" << endl;
        }
    } else if (strcmp(argv[1], "--reload") == 0) {
        cout << "Flashing: " << argv[2] << endl;
        string flashCommand = "bash ~/.avm/service/reload.avm";
        int result = system(flashCommand.c_str());
        if (result == 0) {
            cout << "RunCode is restarting" << endl;
        } else {
            cerr << "Internal server issue." << endl;
        }
    } else {
        cerr << "Unknown option: " << argv[1] << endl;
        return 0;
    }

    return 0;
}
