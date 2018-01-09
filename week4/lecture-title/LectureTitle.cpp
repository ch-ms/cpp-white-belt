#include <string>
using namespace std;

struct Specialization {
  string value;
  explicit Specialization(const string& v) {
    value = v;
  }
};

struct Course {
  string value;
  explicit Course(const string& v) {
    value = v;
  }
};

struct Week {
  string value;
  explicit Week(const string& v) {
    value = v;
  }
};

struct LectureTitle {
  string specialization;
  string course;
  string week;

  LectureTitle(Specialization s, Course c, Week w) {
    specialization = s.value;
    course = c.value;
    week = w.value;
  }
};
