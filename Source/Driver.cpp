#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <cmath>
#include <map>

#include "Mentee.h"
#include "Mentor.h"

#define MAXSCORE 160
#define MAXOUTPUT 5

using namespace std;

vector<Mentee> mentees;
vector<Mentor> mentors;

void print_list(vector<Mentee> &mentees, vector<Mentor> &mentors) {

	ofstream outFile;
	outFile.open("Results.txt");

	outFile << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	outFile << "\n\tResults of Matchmaking\n" << endl;
	outFile << "================================================================" << endl << endl;

	int count = 0;
	if (mentors.size() < MAXOUTPUT) {
		count = mentors.size();
	} else {
		count = MAXOUTPUT;
	}

	map<float, string>::reverse_iterator it;

	for (int i = 0; i < mentees.size(); ++i) {
		if (i > 0) outFile << "\n---------------------------------------------------\n" << endl;

		outFile << mentees[i] << endl;
		outFile << "Best Mentors for Mentee\n" << endl;

		int k = 0;
		for (it = mentees[i].mentor_scores.rbegin(); it != mentees[i].mentor_scores.rend(); ++it) {
			
			outFile << "\t" << it->second << "\t\t" << (int) it->first << "%" << endl;

			if (k+1 >= count) {
				break;
			}
			++k;
		}
		
	}
	outFile << "\n================================================================";
	outFile.close();
}

void matching(vector<Mentee> &mentees, vector<Mentor> &mentors) {

	float rating_score = 0;
	float final_score = 0;
	string fullName = "";

	for (int i = 0; i < mentees.size(); ++i) {
		
		for (int j = 0; j < mentors.size(); ++j) {

			//Check if they live in the same living community
			if (mentees[i].livingComm == mentors[j].livingComm) {
				rating_score += 5;
			}

			//Check if they are in the same school
			if (mentees[i].school == mentors[j].school) {
				rating_score += 5;
			}

			//Check if they have the same track
			if (mentees[i].track == mentors[j].track) {
				rating_score += 10;
			}

			//Check if their most interest is the same as best expertise
			if (mentees[i].interestPlus == mentors[j].expertisePlus) {
				rating_score += 10;
			}

			//Compare the ratings between the mentor and mentee for each question
			for (int k = 0; k < mentees[i].get_ratings_size(); ++k) {
				
				int n1 = mentees[i].get_interest_rating(k);
				int n2 = mentors[j].get_expertise_rating(k);

				int diff = n1 - n2;

				//cout << "n1: " << n1 << " | n2: " << n2 << " | diff: " << abs(diff) << endl;

				if (diff == 0) {
					rating_score += 5;
				} else if (abs(diff) == 1) {
					rating_score += 4;
				} else if (abs(diff) == 2) {
					rating_score += 3;
				} else if (abs(diff) == 3) {
					rating_score += 2;
				} else if (abs(diff) == 4) {
					rating_score += 1;
				} 

			}
			fullName = mentors[j].firstName + " " + mentors[j].lastName;
			final_score = (rating_score/MAXSCORE) * 100;
			//cout << "rating score: " << rating_score << endl;
			//cout << "final score: " << final_score << endl << endl;
			mentees[i].add_to_mentor_scores(final_score, fullName);
			rating_score = 0;
		}
	}
}

void add_to_Mentees(string fileIn) {

	fileIn.append(".csv");

	ifstream inFile;
	inFile.open(fileIn);

	if (!inFile.is_open()) {
		cout << "\tERROR: Could not open file: " << fileIn << endl;
		cout << "\tMake sure it is in the correct folder with this program\n" << endl;
		exit(1);
	} else {
		cout << "\t'" + fileIn + "' \tsucessfully opened\n" << endl;
	}

	string line;
	int skip = 0;
	while (getline(inFile, line)) {
		Mentee m;

		stringstream lineStream(line);
		string cell;
		int column_count = 1;
		while (getline(lineStream, cell,',') && skip > 0 && column_count <= 44) {
			cell.erase(remove( cell.begin(), cell.end(), '\"' ),cell.end());
			m.put_info_in(cell, column_count);
			//cout << cell << " " << column_count << endl;
			++column_count;
		}

		if (skip > 0) {
		 	mentees.push_back(m);	
		}

		++skip;
	}

	inFile.close();

}

void add_to_Mentors(string fileIn) {

	fileIn.append(".csv");

	ifstream inFile;
	inFile.open(fileIn);

	if (!inFile.is_open()) {
		cout << "\tERROR: Could not open file: " << fileIn << endl;
		cout << "\tMake sure it is in the correct folder with this program" << endl;
		exit(1);
	} else {
		cout << "\t'" + fileIn + "' \tsucessfully opened\n" << endl;
	}

	string line;
	int skip = 0;
	while (getline(inFile, line)) {
		Mentor m;

		stringstream lineStream(line);
		string cell;
		int column_count = 1;
		while (getline(lineStream, cell,',') && skip > 0 && column_count <= 44) {
			cell.erase(remove( cell.begin(), cell.end(), '\"' ),cell.end());
			m.put_info_in(cell, column_count);
			//cout << cell << " " << column_count << endl;
			++column_count;
		}

		if (skip > 0) {
		 	mentors.push_back(m);	
		}

		++skip;
	}

	inFile.close();
}

int main (int arg, char* agrs[]) {
	
	string fileName1;
	string fileName2;
	cout << "\n\tEnter a file name for MENTEES: ";
	getline(cin, fileName1);
	cout << endl;
	cout << "\tEnter a file name for MENTORS: ";
	getline(cin, fileName2);
	cout << endl;

	add_to_Mentees(fileName1);
	add_to_Mentors(fileName2);

	matching(mentees, mentors);

	for (int i = 0; i < mentees.size(); ++i) {
		//cout << mentees[i] << endl;
	}
	for (int i = 0; i < mentors.size(); ++i) {
		//cout << mentors[i] << endl;
	}

	print_list(mentees, mentors);

}
