#include "Mentee.h"

#define debug false

using namespace std;

Mentee::Mentee() {
	firstName = "";
	lastName = "";
	bmail = "";
	bNumber = "";
	phoneNum = "";
	gender = "";
	livingComm = "";
	classStand = "";
	school = "";
	hobbies = "";
	major = "";
}

void Mentee::put_info_in(string cell, int column) {
	if (column == 2) {
		this->bmail = cell;
	} else if (column == 3) {
		this->firstName = cell;
	} else if (column == 4) {
		this->lastName = cell;
	} else if (column == 5) {
		this->bNumber = cell;
	} else if (column == 6) {
		this->phoneNum = cell;
	} else if (column == 7) {
		this->gender = cell;
	} else if (column == 9) {
		this->livingComm = cell;
	} else if (column == 10) {
		this->classStand = cell;
	} else if (column == 13) {
		this->school = cell;
	} else if (column == 14) {
		this->track = cell;
	} else if (column == 15) {
		this->hobbies = cell;
	} else if (column >= 16 && column < 42) {
		int n = stoi(cell.c_str());
		this->add_to_interests_ratings(n);
	} else if (column == 42) {
		this->interestPlus = cell;
	} else if (column == 44) {
		this->major = cell;
	}
}

ostream& operator<< (ostream &os, const Mentee &m) {
	os << m.firstName << " " << m.lastName << endl;
	os << m.bNumber << " | " << m.bmail << " | " << m.phoneNum << endl;
	os << "Gender: " << m.gender << endl;
	os << m.classStand << " in " << m.school << endl;
	os << "Major: " << m.major << endl;
	os << "Living in " << m.livingComm << endl;
	os << "Track: " << m.track << endl;

	if (debug) {
		os << "Hobbies:\n\t" << m.hobbies << endl;

		os << "Interest Scores: \n";
		for (int i = 0; i < m.get_ratings_size(); ++i) {
			os << m.get_interest_rating(i) << " ";
		}
		os << endl;
		os << "Mentor Scores: \n";

		/*
		map<string, int>::iterator it;
		for (it = m.mentor_scores.begin(); it != m.mentor_scores.end(); ++it) {
			os << it->first << "\t" << it->second << "%" << endl;
		}
		*/
	}
	
	return os;
}
