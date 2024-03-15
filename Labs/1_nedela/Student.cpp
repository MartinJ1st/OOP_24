#include <iostream>

using namespace std;

struct Course {
    char name[100];
    int code, n_of_students;

    void read_c() {
        cin >> name >> code;
        n_of_students = 0;
    }
};

struct Student {
    char ime[20];
    int indeks, n_of_courses;
    Course courses[10];

    void read_s() {
        cin >> ime >> indeks >> n_of_courses;
    }

    void read_code(int index) {
        cin >> courses[index].code;
    }
};

int get_most_popular_course(Course courses[], int n_of_courses) {
    int max_students = 0;
    int most_popular_course_code = -1;

    for (int i = 0; i < n_of_courses; i++) {
        if (courses[i].n_of_students > max_students) {
            max_students = courses[i].n_of_students;
            most_popular_course_code = courses[i].code;
        }
    }

    return most_popular_course_code;
}

int main() {
    int br_studenti, br_kursevi;
    Course kursevi[20];
    Student student[200];
    cin >> br_studenti >> br_kursevi;
    for (int i = 0; i < br_kursevi; ++i) {
        kursevi[i].read_c();
    }
    for (int i = 0; i < br_studenti; ++i) {
        student[i].read_s();
        for (int j = 0; j < student[i].n_of_courses; ++j) {
            student[i].read_code(j);

            for (int k = 0; k < br_kursevi; k++) {
                if (kursevi[k].code == student[i].courses[j].code) {
                    kursevi[k].n_of_students++;
                    break;
                }
            }
        }
    }
    int baran_index = get_most_popular_course(kursevi, br_kursevi);
    for (int i = 0; i < br_kursevi; ++i) {
        if (kursevi[i].code == baran_index) {
            cout << "Najpopularen kurs e: " << kursevi[i].name << endl;
            break;
        }
    }
    return 0;
}
