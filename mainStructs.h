#pragma once

struct Date {
	usi day;
	usi month;
	int year;
	Date() {};
	Date(usi dy, usi mh, int yr) {
		day = dy;
		month = mh;
		year = yr;
	}
};

struct Student {
	char* name = nullptr;
	char* surname = nullptr;
	Date birthDate;
	Teacher teacher;
	Date* missedClass;
	Date* classDates;
	Student() {};
	Student(char* _name, char* _surname, Date bd, Teacher tc) {
		name = set(_name);
		surname = set(_surname);
		birthDate = bd;
		teacher = tc;
	}
	char* set(char* var) {
		int len = strlen(var);
		char* arr = new char[len + 1];
		for (size_t i = 0; i < len; i++)
		{
			arr[i] = var[i];
		}
		arr[len] = '\0';
		return arr;
	}
	int smileyFace() {
		int index = 0;
		char fullSmile = 2;
		char emptySmile = 1;
		int button = 0;
		while (button!=13)
		{

			for (size_t i = 0; i < 5; i++)
			{
				if (i < index)cout << fullSmile;
				else cout << emptySmile;
				button = _getch();
				if (button == 224)
				{
					button = _getch();//left 75 right77
					if (button == 77 && index < 5) index++;
					else if (button == 75 && index > 0)index--;
				}
			}
		}
		return index;
	}
	void givePoint(Teacher& tc) {
		cout << "Please Rate Teachers work: Click Enter to Save! "<<endl;
		tc.points[tc.pointCounter] = smileyFace();
		
	}
};

struct Teacher {
	char* name = nullptr;
	char* surname = nullptr;
	Date birthDate;
	Student* group;
	int studentCount = 0;
	int* points;
	int pointCounter;
	Teacher() {};
	Teacher(char* n, char* s, Date bd) {
		name = n;
		surname = s;
		birthDate = bd;
	}
	char* set(char* var) {
		int len = strlen(var);
		char* arr = new char[len + 1];
		for (size_t i = 0; i < len; i++)
		{
			arr[i] = var[i];
		}
		arr[len] = '\0';
		return arr;
	}
	Student* createGroup(Student* gr, int size, Teacher& tc) {
		Student* arr = new Student[size];
		int button = 0;
		int counter = 0;
		for (size_t i = 0; button != 13; i++) {
			counter = i;
			cout << "Enter Student Name: " << arr[i].name << endl;
			cout << "Enter Student Surname: " << arr[i].surname << endl;
			cout << "Enter Student Birthdate(day month year): " << arr[i].birthDate.day << arr[i].birthDate.month << arr[i].birthDate.year << endl;
			arr[i].teacher;
			cout << "Save&End[Enter]\t\t\tSave&Continue[space]";
			button = _getch();
		}
		tc.studentCount = counter;
		return arr;
	}
};

