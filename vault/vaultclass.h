#include <iostream>
#include <iomanip>
#include <ios>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;


class Vault {
    public:
        Vault();
        //~Vault();
        
        void SetUsername(string username);
        void SetMaster(string password);
        void SetServiceName(int i, string name);
        void SetPassword(int i, string password);
        void SetSavefile(string filename);
        void SetOutfile(string filename);
        void SetJ(int j);
        void SetInput(ifstream iovar);
        void SetOutput(ofstream iovar);
        void SetSave(ofstream iovar);
        
        const string GetUsername();
        const string GetMaster();
        const string GetServiceName(int i);
        const string GetPassword(int i);
        const string GetSavefile();
        const string GetOutfile();
        const int GetJ();
        const ifstream GetInput();
        const ofstream GetOutput();
        const ofstream GetSaveput();
        
        string RandPass();
        void VaultOut(std::ofstream output);
        void Save(std::ofstream save);
        void Import(std::ifstream input);
    private:
        string username_;
        string masterpass_;
        string service_names_[100];
        string passwords_[100];
        int j_;
        string savefile_;
        string outfile_;
        ifstream input_;
        ofstream output_;
        ofstream save_;
};