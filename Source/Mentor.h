#ifndef MENTOR_H_
#define MENTOR_H_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Mentor {
	vector<int> ratings_expertise;
	public:
		Mentor();
		void put_info_in(string cell, int column);
		void add_to_expertise_ratings(int e) { ratings_expertise.push_back(e); };
		int get_expertise_rating(int index) const { return ratings_expertise[index]; };
		int get_ratings_size() const { return ratings_expertise.size(); };
		friend ostream& operator<<(ostream &os, const Mentor &m);
		string firstName;
		string lastName;
		string bmail;
		string bNumber;
		string phoneNum;
		string gender;
		string livingComm;
		string classStand;
		string school;
		string track;
		string hobbies;
		string expertisePlus;
		string major;

};

#endif