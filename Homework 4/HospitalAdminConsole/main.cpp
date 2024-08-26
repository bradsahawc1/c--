#include <iostream>
#include <fstream>
#include "Patient.cpp"
#include "Logger.cpp"
using namespace std;

void addByFile(vector<Patient*>& Hospital) {
    string input;
    string f, m, l, s, d;
    string ph, temp;
    int p, t;
    vector<string> a;
    string key, sub1, sub2;
    int pos;
    cout << "Name the file you want read: ";
    cin >> input;
    cout << "\n\n";
    ifstream inputFile;
    inputFile.open(input, ios::in);
    if (inputFile.fail()) {
        cout << "failed";
    }
    while (getline(inputFile, key)) {
        pos = key.find(":");
        sub1 = key.substr(0, pos);
        sub2 = key.substr(pos + 1);
        if ( sub1 == "firstName") {
            f = sub2;
        }
        else if (sub1 == "middleName") {
            m = sub2;
        }
        else if (sub1 == "lastName") {
            l = sub2;
        }
        else if (sub1 == "suffix") {
            s = sub2;
        }
        else if (sub1 == "ailment") {
            a.push_back(sub2);
        }
        else if (sub1 == "doctor") {
            d = sub2;
        }
        else if (sub1 == "treated") {
            t = stoi(sub2);
        }
        else if (sub1 == "priority") {
            if (t == 1) {
                p = -1;
            }
            else {
                p = stoi(sub2);
            }
        }
        else if (key.empty()) {
            Patient * p1 = new Patient(f, m, l, s, p, a, d, t);
            Hospital.push_back(p1);
        }
    }
    Patient * p1 = new Patient(f, m, l, s, p, a, d, t);
    Hospital.push_back(p1);
    inputFile.close();
}

void patientByDoctor(vector<Patient*>& Hospital, string doctor) {
    vector<int> key;
    for (int i = 0; i < Hospital.size(); ++i) {
        if (doctor == Hospital[i]->getDoctor()) {
            key.push_back(i);
        }
    }
    if (key.empty()) {
        cout << "There are no Patients under this Doctor" << endl;
    }
    else {
        cout << "List of Patients:" << endl;
        for (int i = 0; i < key.size(); ++i) {
            cout << Hospital[key[i]]->getFname() << " " << Hospital[key[i]]->getMname() <<
                 " " << Hospital[key[i]]->getLname() << " " << Hospital[key[i]]->getSuffix() << endl;
        }
    }
}

int nextToTreat(vector<Patient*>& Hospital) {
    int temp;
    for (int i = 0; i < Hospital.size(); ++i) {
        if (Hospital[i]->getPriority() != -1) {
            temp = Hospital[i]->getPriority();
        }
    }
    int index = 0;
    for (int i = 0; i < Hospital.size(); ++i) {
        if (temp >= Hospital[i]->getPriority() && Hospital[i]->getPriority() > 0) {
            temp = Hospital[i]->getPriority();
            index = i;
        }
    }
    if (Hospital[index]->getPriority() == -1) {
        cout << "There are no patients to be treated." << endl;
    }
    else {
        cout << "The next Patient is: " << Hospital[index]->getFname() << " " << Hospital[index]->getMname() <<
             " " << Hospital[index]->getLname() << " " << Hospital[index]->getSuffix() << endl;
        return index;
    }
}

int findPatient(vector<Patient*>& Hospital, string f, string l) {
    int index = 0;
    int temp = -1;
    for (Patient *point : Hospital) {
        if (point->getLname() == l) {
            if (point->getFname() == f) {
                temp = index;
            }
        }
        index++;
    }
    if (temp == -1) {
        cout << "This Patient is not in the system" << endl;
    }
    return temp;
}

void add(vector<Patient*>& Hospital) {
    string f, m, l, s, d, temp;
    char answer;
    int p, t;
    vector<string> a;

    cout << "Enter Patient First name: ";
    cin >> f;
    cout << "Enter Patient Middle name: ";
    cin >> m;
    cout << "Enter Patient Last name: ";
    cin >> l;
    cout << "Does Patient have a suffix? y/n" << endl;
    cin >> answer;
    if (answer == 'y') {
        cout << "Enter Patients suffix: ";
        cin >> s;
    }
    else {
        s = ' ';
    }
    cout << "Doctor's name: ";
    cin >> d;
    cout << "Have they been treated (y/n): ";
    cin >> answer;
    if (answer == 'y') {
     t = 1;
     p = -1;
    }
    else {
        t = 0;
        cout << "Enter the priority: ";
        cin >> p;
    }
    cout << "What are the symptoms?" << endl;
    int done = 0;
    while (done == 0) {
        cin >> temp;
        a.push_back(temp);
        cout << "Press 1 to exit or 0 to continue" << endl;
        cin >> done;
    }

    Patient* p1 = new Patient(f, m, l, s, p, a, d, t);
    Hospital.push_back(p1);
}

void remove(vector<Patient*>& Hospital) {
    string f, l;
    int i;
    cout << "Who do you want to remove?" << endl;
    cout << "First name: ";
    cin >> f;
    cout << "Last name: ";
    cin >> l;
    i = findPatient(Hospital, f, l);
    Hospital.erase(Hospital.begin() + i);
}

int main() {
    int action = 1;
    int debug = 0;
    string filename1, filename2;
    vector<Patient*> Hospital;
    Logger log = Logger::getInstance();

    cout << "Type the name of the file that you want to record activities: ";
    cin >> filename1;
    log.setLogName(filename1);
    cout << "Type the name of the file that you want to record debug activities: ";
    cin >> filename2;
    log.setDebugName(filename2);
    cout << "Checking to make sure they work" << endl;
    log.fileWorks();
    cout << "\n\n";

    while (action != 0) {
        cout << "What would you like to do?" << endl;
        cout << "Press 10 for help or 0 to exit" << endl;
        cin >> action;
        if (Hospital.empty() && (action == 2 || (action >= 4 && action <= 9))) {
            cout << "Hospital is empty" << endl;
        }
        else if (action == 10) {
            log.log("Requesting help log");
            cout << "Add a Patient = 1" << endl;
            cout << "Remove a Patient = 2" << endl;
            cout << "Add Patients from file = 3" << endl;
            cout << "Treat a Patient = 4" << endl;
            cout << "Print Patient report = 5" << endl;
            cout << "Print report of all Patients = 6" << endl;
            cout << "Who is the next Patient = 7" << endl;
            cout << "Treat all Patients = 8" << endl;
            cout << "List of Patients by Doctor = 9" << endl;
            cout << "Toggle Debug mode = 11" << endl;
        }
        else if (action == 1) {
            log.log("Adding a Patient");
            add((vector<Patient*>&)Hospital);
        }
        else if (action == 2) {
            log.log("Removing a Patient");
            remove((vector<Patient*>&)Hospital);
        }
        else if (action == 3) {
            log.log("Adding Patients from file");
            addByFile((vector<Patient*>&)Hospital);
        }
        else if (action == 4) {
            log.log("Treating next Patient");
            int index;
            index = nextToTreat((vector<Patient*>&)Hospital);
            Hospital[index]->setTreated(1);
            Hospital[index]->setPriority(-1);
        }
        else if (action == 5) {
            log.log("Printing Patient Report");
            string f1, l1;
            int temp;

            cout << "Who do you want to print a report of?" << endl;
            cout << "First name: ";
            cin >> f1;
            cout << "\nLast Name: ";
            cin >> l1;
            while (f1.empty() || l1.empty()) {
                if (f1.empty()) {
                    cout << "Please enter First name: ";
                    cin >> f1;
                }
                if (l1.empty()){
                    cout << "Please enter Last name: ";
                    cin >> l1;
                }
            }
            temp = findPatient((vector<Patient*>&)Hospital, f1, l1);
            Hospital[temp]->report();
        }
        else if (action == 6) {
            log.log("Printing report of all Patients in Triage");
            cout << "Report:" << endl;
            for (int i = 0; i < Hospital.size(); ++i) {
                if (Hospital[i]->getTreated() != 1) {
                    Hospital[i]->report();
                }
            }
        }
        else if (action == 7) {
            log.log("Printing next Patient to get treated");
            nextToTreat((vector<Patient*>&)Hospital);
        }
        else if (action == 8) {
            log.log("Treating all Patients");
            for (int i = 0; i < Hospital.size(); ++i) {
                Hospital[i]->setTreated(1);
                Hospital[i]->setPriority(-1);
            }
        }
        else if (action == 9) {
            log.log("Listing Patients by doctor name");
            string doctor;
            cout << "Which Doctor do you want a list of Patients for?: ";
            cin >> doctor;
            patientByDoctor((vector<Patient*>&)Hospital, doctor);
        }
        else if (action == 11) {

            if (log.isDebug()) {
                log.log("Exiting debug mode");
                log.setDebug(false);
            }
            else {
                log.log("Entering debug mode");
                log.setDebug(true);
            }
        }
        else if (action > 11 || action < 0) {
            cout << "Not a valid option..." << endl;
        }
    }
    return 0;
}
