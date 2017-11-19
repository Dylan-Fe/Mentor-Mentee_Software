#ifndef MENTEE_H_
#define MENTEE_H_

#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class Mentee {
	vector<int> ratings_of_interests;
	public:
		Mentee();
		void put_info_in(string cell, int column);
		void add_to_interests_ratings(int d) { ratings_of_interests.push_back(d); };
		void add_to_mentor_scores(float m, string s) { mentor_scores.emplace(m, s); };
		int get_interest_rating(int index) const { return ratings_of_interests[index]; };
		int get_ratings_size() const { return ratings_of_interests.size(); };
		//const map<string, int> &get_mentor_scores() const { return mentor_scores; };
		int get_mentor_score_size() const { return mentor_scores.size(); };
		friend ostream& operator<<(ostream &os, const Mentee &m);
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
		string interestPlus;
		string major;
		map<float, string> mentor_scores;

};

#endif