#include "vaultmain.h"


int main() {
    
    char usr_cmd = ' ';             //declares variable for storing user commands
    char usr_cmd2 = ' ';            //declares secondary variable for storing user commands
    string usr_input = "";          //declares variable for string input form user
    string filename = "";           //declares variable for storing filename for file I/O
    
    
    
    cout << "Welcome to PASSVAULT" << endl;                         //prints welcome message and initial menu to user
    cout << "Enter the task you wish to complete:" << endl;
    cout << "    N - Create New Vault" << endl;
    cout << "    R - Retrieve Saved Vault" << endl;
    cin >> usr_cmd;                                                 //gets user command
    while ((usr_cmd != 'N') && (usr_cmd != 'n') && (usr_cmd != 'R') && (usr_cmd != 'r')) {
        cout << "Invalid command. Please re-enter:" << endl;        //prompts user for valid command while the given command was not a listed option
        cin >> usr_cmd;
    }
    
    switch (usr_cmd) {
        case 'N':                                                   //user chooses to make new vault
        case 'n':
            cout << "Enter your desired username:" << endl;         //prompts user for username and stores it as a class variable
            cin >> usr_input;
            vault1.SetUsername(usr_input);
            cout << "Enter your master password:" << endl;          //prompts user for master password and stores it as a class variable
            cin >> usr_input;
            vault1.SetMaster(usr_input);
            cout << "Verify your master password:" << endl;         //prompts user to verify their master password and compares it with the initial entry
            cin >> usr_input;
            while (usr_input != vault1.GetMaster()) {               //prompts user to re-enter both passwords until them match
                cout << "The password you entered does not match your previous entry." << endl;
                cout << "Re-enter your password:" << endl;
                cin >> usr_input;
                vault1.SetMaster(usr_input);
                cout << "Verify password:" << endl;
                cin >> usr_input;
            }
            cout << "Your master password has been verified. Please store it somewhere safe." << endl;
            break;
        case 'R':                                                   //user chooses to recover saved vault
        case 'r':
            cout << "Enter username:" << endl;                      //prompts user to enter their username
            cin >> usr_input;
            filename = usr_input;
            filename.append(".txt");
            vault1.SetSavefile(filename);                           //appends the file extension ".txt" to the user's username and assigns it to a class variable
            Import();                                               //program searches for a savefile by the name of their username.txt
            cout << "Your vault has been recovered. Enter your master password:" << endl;
            cin >> usr_input;                                       //after finding the vault, prompts user for their password
            while (usr_input != vault1.GetMaster()) {               //continues prompting for a password until the passwords match
                cout << "Invalid password. Try again." << endl;
                cin >> usr_input;
            }
            break;
    }
    
    while ((usr_cmd != 'Q') && (usr_cmd != 'q')) {                  //loop runs intil user enters 'Q' or 'q'
        cout << "What would you like to do?" << endl;               //presents user with list of options
        cout << "    1 - Store Password" << endl;
        cout << "    2 - Retrieve/Change Password" << endl;
        cout << "    3 - Output File" << endl;
        cout << "    Q - Quit" << endl;
        cin >> usr_cmd;                                             //prompts user for command
        while ((usr_cmd < 1) || (usr_cmd > 3)) {                    //if command is above or below the range of options, prompts user for command again
            cout << "Invalid command. Please re-enter:" << endl;
            cin >> usr_cmd;
        }
        
        switch (usr_cmd) {
            case 1:                                                             //user chooses to store a password
                {
                vault1.SetJ(0);                                                 //sets J to zero
                cout << "What service is this password for?" << endl;           //prompts user for the associated service
                cin >> usr_input;
                vault1.SetServiceName(vault1.GetJ(), usr_input);                //assigns the service name to the first available slot in the service_names_[] array
                cout << "Would you like to assign a random password or your own?" << endl;
                cout << "    1 - Random Password" << endl;
                cout << "    2 - Specify Password" << endl;
                while ((usr_cmd != 1) && (usr_cmd != 2)) {                      //while the user's command isn't valid, prompts for valid command
                    cout << "Invalid command. Please re-enter:" << endl;
                    cin >> usr_cmd2;
                }
                switch (usr_cmd2) {                                             
                    case 1:                                                     //if user wants random password, assigns random password to next available slot in passwords[] array
                        {
                        vault1.SetPassword(vault1.GetJ(), vault1.RandPass());
                        }
                        break;
                    case 2:                                                     //if user wants to specify password...
                        {
                        cout << "Enter your password:" << endl;                 //prompts user for the password
                        cin >> usr_input;
                        vault1.SetPassword(vault1.GetJ(), usr_input);
                        cout << "Verify your password:" << endl;                //prompts user to verify their password
                        cin >> usr_input;
                        while (usr_input != vault1.GetPassword(vault1.GetJ())) {//prompts user to re-enter passwords until they match
                            cout << "The password you entered does not match your previous entry." << endl;
                            cout << "Re-enter your password:" << endl;
                            cin >> usr_input;
                            vault1.SetPassword(vault1.GetJ(), usr_input);
                            cout << "Verify password:" << endl;
                            cin >> usr_input;
                        }
                        }
                        break;
                    default:
                        break;
                }
                cout << "Your password for " << vault1.GetServiceName(vault1.GetJ()) << " is " << vault1.GetPassword(vault1.GetJ()) << "." << endl;
                vault1.SetJ(vault1.GetJ() + 1);                                 //increments the class's J variable
                }
                break;
            case 2:
                {
                cout << "Which service would you like to retrieve your password for?" << endl;
                cin >> usr_input;
                int found_at = -1;                                              //initializes variable to track the location of a stored password
                for (int i = 0; i < vault1.GetJ(); i++) {                       //for as many 
                    if (MakeLower(vault1.GetServiceName(i)) == MakeLower(usr_input)) {
                        found_at = i;
                    }
                }
                if (found_at > -1) {
                    cout << "Your password for " << vault1.GetServiceName(found_at) << " is " << vault1.GetPassword(found_at) << endl;
                } else {
                    cout << "The specified service was not found in the vault." << endl;
                }
                cout << "Would you like to change this password?" << endl;
                cout << "    Y - Yes" << endl;
                cout << "    N - No" << endl;
                cin >> usr_cmd;
                while ((usr_cmd != 'N') && (usr_cmd != 'n') && (usr_cmd != 'Y') && (usr_cmd != 'y')) {
                    cout << "Invalid command. Please re-enter:" << endl;
                    cin >> usr_cmd;
                }
                
                switch (usr_cmd) {
                    case 'Y':
                    case 'y':
                        {
                        cout << "Enter new password:" << endl;
                        cin >> usr_input;
                        vault1.SetPassword(vault1.GetJ(), usr_input);
                        cout << "Verify your password:" << endl;
                        cin >> usr_input;
                        while (usr_input != vault1.GetPassword(vault1.GetJ())) {
                            cout << "The password you entered does not match your previous entry." << endl;
                            cout << "Re-enter your password:" << endl;
                            cin >> usr_input;
                            vault1.SetPassword(vault1.GetJ(), usr_input);
                            cout << "Verify password:" << endl;
                            cin >> usr_input;
                        }
                        }
                        break;
                }
                }
                break;
            case 3:
                {
                filename = vault1.GetUsername();
                filename.append("_outfile.txt");
                vault1.SetOutfile(filename);
                VaultOut();
                cout << "Your passwords have been printed to " << vault1.GetOutfile() << endl;
                }
                break;
        }
    }
    Save();
    
    return 0;
}

string MakeLower(string str) {
    string new_str = "";
    char new_char = ' ';
    for (int i = 0; i < str.length(); i++) {
        new_char = tolower(str.at(i));
        new_str.push_back(new_char);
    }
    return new_str;
}

void VaultOut() {
    output.open(vault1.GetOutfile());
    output << setw(20) << left << "Service" << "|";
    output << right << "Password" << endl;
    output << setfill('-') << setw(41) << "" << endl;
    output << setw(20) << left << setfill(" ");
    for (int i = 0; i < 100; i++) {
        if ((service_names_[i].empty() != true) && (passwords_[i].empty() != true)) {
            output << service_names_[i] << "|" << right << passwords_[i] << endl;
        }
    }
    output.close();
}

void Save() {
    save.open(vault1.GetSavefile());
    save << vault1.GetUsername() << endl;
    save << vault1.GetMaster() << endl;
    save << vault1.GetJ() << endl;
    for (int i = 0; i < vault1.GetJ(); i++) {
        save << vault1.GetPassword(i) << endl;
    }
    for (int i = 0; i < j_; i++) {
        save << vault1.GetServiceName(i) << endl;
    }
    save.close();
    return;
}

void Import() {
    input.open(vault1.GetSavefile());
    while (!input.is_open()) {
        cout << "We found no user with that username." << endl;
        cout << "Please re-enter username: " << endl;
        cin >> usr_input;
        filename = usr_input;
        filename.append(".txt");
        vault1.SetSavefile(filename);
        input.open(vault1.GetSavefile());
    }
    while (!input.eof()) {
        input >> usr_input;
        vault1.SetUsername(usr_input);
        input >> usr_input;
        vault1.SetMaster(usr_input);
        input >> usr_input;
        vault1.SetJ(static_cast<int>(usr_input))
        for (int i = 0; i < vault1.GetJ(); i++) {
            input >> usr_input;
            vault1.SetPassword(i, usr_input);
        }
        for (int i = 0; i < j_; i++) {
            input >> usr_input;
            vault1.SetServiceName(i, usr_input);
        }
    }
    input.close();
    return;
}