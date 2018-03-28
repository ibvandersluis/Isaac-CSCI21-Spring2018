#include "vaultclass.h"

//////~~CONSTRUCTOR/DESTRUCTOR~~//////

Vault::Vault() {
    username_ = "unperson";
    masterpass_ = -1;
    //service_names_ = "empty";
    //passwords_ = "empty";
    srand(time(0));
    return;
}

// Vault::~Vault() {            //deleted -- no destructor necessary
//     delete username_;
//     delete masterpass_;
//     delete service_names_;
//     delete passwords_;
//     return;
// }

//////~~SETTERS~~//////

void Vault::SetUsername(string username) {
    username_ = username;
    return;
}

void Vault::SetMaster(string password) {
    masterpass_ = password;
    return;
}

void Vault::SetServiceName(int i, string name) {
    service_names_[i] = name;
    return;
}

void Vault::SetPassword(int i, string password) {
    passwords_[i] = password;
    return;
}

void Vault::SetJ(int j) {
    j_ = j;
    return;
}

void Vault::SetSavefile(string filename) {
    savefile_ = filename;
    return;
}

void Vault::SetOutfile(string filename) {
    outfile_ = filename;
    return;
}

void Vault::SetInput(ifstream& iovar) {
    input_ = iovar;
    return;
}

void Vault::SetOutput(ofstream& iovar) {
    output_ = iovar;
    return;
}

void Vault::SetSaveput(ofstream& iovar) {
    saveput_ = iovar;
    return;
}

//////~~GETTERS~~//////

const string Vault::GetUsername() {
    return username_;
}

const string Vault::GetMaster() {
    return masterpass_;
}

const string Vault::GetServiceName(int i) {
    return service_names_[i];
}

const string Vault::GetPassword(int i) {
    return passwords_[i];
}

const int Vault::GetJ() {
    return j_;
}

const string Vault::GetSavefile() {
    return savefile_;
}

const string Vault::GetOutfile() {
    return outfile_;
}

const ifstream& Vault::GetInput() {
    return input_;
}

const ofstream& Vault::GetOutput() {
    return output_;
}

const ofstream& Vault::GetSaveput() {
    return saveput_;
}

//////~~OTHER MEMBER FUNCTIONS~~//////

string Vault::RandPass() {
    string generate = "";
    char next_char = ' ';
    for (int i = 0; i < 10; i++) {
        next_char = rand() % 93 + 33;               //generates random number between 33 and 126
        generate.push_back(next_char);
    }
    return generate;
}

void Vault::VaultOut(std::ofstream output) {
    output.open(outfile_);
    output << setw(20) << left << "Service" << "|";
    output << right << "Password" << endl;
    output << setfill('-') << setw(41) << "" << endl;
    output << setw(20) << setfill(" ");
    for (int i = 0; i < 100; i++) {
        if ((vault1.GetServiceName(i).empty() != true) && (vault1.GetUsername(i).empty() != true)) {
            output << left << vault1.GetServiceName(i) << "|" << right << vault1.GetPassword(i) << endl;
        }
    }
    output.close();
}

void Vault::Save(std::ofstream save) {
    save.open(vault1.GetSavefile());
    save << vault1.GetUsername() << endl;
    save << vault1.GetMaster() << endl;
    save << vault1.GetJ() << endl;
    for (int i = 0; i < vault1.GetJ(); i++) {
        save << vault1.GetPassword(i) << endl;
    }
    for (int i = 0; i < vault1.GetJ(); i++) {
        save << vault1.GetServiceName(i) << endl;
    }
    save.close();
    return;
}

void Vault::Import(std::ifstream input) {
    input.open(vault1.GetSavefile());
    input >> usr_input;
    vault1.SetUsername(usr_input);
    input >> usr_input;
    vault1.SetMaster(usr_input);
    input >> usr_input;
    vault1.SetJ(usr_input);
    for (int i = 0; i < vault1.GetJ(); i++) {
        input >> usr_input;
        vault1.SetPassword(i, usr_input);
    }
    for (int i = 0; i < vault1.GetJ(); i++) {
        input >> usr_input;
        vault1.SetServiceName(i, usr_input);
    }
    input.close();
    return;
}