#include "User.h"
#include <fstream>

const string User::filename = "users.dat";

User::User() {
	this->job = 0;
};

User::User(string username, string password, string name, int job) {
	this->username = username;
	this->password = password;
	this->name = name;
	this->job = job;
}

string User::getUsername() const {
	return this->username;
}

string User::getPassword() const {
	return this->password;
}

string User::getName() const {
	return this->name;
}

int User::getJob() const {
	return this->job;
}

void User::setUsername(const string& username) {
	this->username = username;
}

void User::setPassword(const string& password) {
	this->password = password;
}

void User::setName(const string& name) {
	this->name = name;
}

void User::setJob(const int& job) {
	this->job = job;
}

ostream& operator << (ostream& out, const User& user) {
	if (&out != &cout) {
		int len = user.username.length() + 1;
		out.write((char*)(&len), sizeof(int));
		out.write(user.username.c_str(), len);
		len = user.password.length() + 1;
		out.write((char*)(&len), sizeof(int));
		out.write(user.password.c_str(), len);
		len = user.name.length() + 1;
		out.write((char*)(&len), sizeof(int));
		out.write(user.name.c_str(), len);
		out.write((char*)(&user.job), sizeof(int));
	}
	return out;
}

istream& operator >> (istream& in, User& user) {
	if (&in != &cin) {
		int len;
		in.read((char*)(&len), sizeof(int));
		char* str = new char[len];
		in.read(str, len);
		user.username = str;
		delete[] str;
		in.read((char*)(&len), sizeof(int));
		str = new char[len];
		in.read(str, len);
		user.password = str;
		delete[] str;
		in.read((char*)(&len), sizeof(int));
		str = new char[len];
		in.read(str, len);
		user.name = str;
		delete[] str;
		in.read((char*)(&user.job), sizeof(int));
	}
	return in;
}