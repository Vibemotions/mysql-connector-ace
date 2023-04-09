#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "student.pb.h"

using namespace std;

int main() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    tutorial::Student student;

    student.set_id(201721130206);
    *student.mutable_name() = "Hins";
    student.set_email("zhubin77@ustc.edu");

    tutorial::Student::PhoneNumber *phone_number_1 = student.add_phone();
    phone_number_1->set_number("123456789");
    phone_number_1->set_type(tutorial::Student::MOBILE);

    tutorial::Student::PhoneNumber *phone_number_2 = student.add_phone();
    phone_number_2->set_number("987654321");
    phone_number_2->set_type(tutorial::Student::HOME);

    // serialize student object to string
    string serializedStr;
    student.SerializeToString(&serializedStr);
    cout << "serialization result: " << serializedStr << endl;
    cout << "debugString: " << student.DebugString() << endl;

    // deserialize student object from string
    tutorial::Student deserializedStudent;
    if (!deserializedStudent.ParseFromString(serializedStr)) {
        cerr << "Failed to parse student." << endl;
        return -1;
    }
    cout << "deserializedStudent debugString: " << deserializedStudent.DebugString() << endl;
    cout << "Student ID: " << deserializedStudent.id() << endl;
    cout << "Student Name: " << deserializedStudent.name() << endl;
    if (deserializedStudent.has_email()) {
        cout << "Student Email: " << deserializedStudent.email() << endl;
    }
    for (int i = 0; i < deserializedStudent.phone_size(); i++) {

        const tutorial::Student::PhoneNumber& phone_number = deserializedStudent.phone(i);

        switch (phone_number.type()) {
            case tutorial::Student::MOBILE :
                cout << "Mobile Phone #: " << endl;
                break;
            case tutorial::Student::HOME :
                cout << "Home Phone #: " << endl;
                break;
            }
            cout << phone_number.number() << endl;
    }

    google::protobuf::ShutdownProtobufLibrary();
}
