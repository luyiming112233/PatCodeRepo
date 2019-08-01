#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;

#define maxn 100

map<string, set<int> >::iterator it;
set<int>::iterator sit;
map<string, set<int> > mtitle,mauthor,mkey,mpublisher,myear;

void titleinsert(string title,int id) {
	it = mtitle.find(title);
	if (it == mtitle.end()) {
		set<int> s;
		s.insert(id);
		mtitle[title] = s;
	}
	else {
		it->second.insert(id);
	}
}

void authorinsert(string author, int id) {
	it = mauthor.find(author);
	if (it == mauthor.end()) {
		set<int> s;
		s.insert(id);
		mauthor[author] = s;
	}
	else {
		it->second.insert(id);
	}
}

void keyinsert(string key, int id) {
	it = mkey.find(key);
	if (it == mkey.end()) {
		set<int> s;
		s.insert(id);
		mkey[key] = s;
	}
	else {
		it->second.insert(id);
	}
}

//½«keywords·Ö¸î
void keywordinsert(string keyword, int id) {
	char key[maxn];
	int s = 0,i=0;
	for (s = 0; s < maxn; s++) {
		if (keyword[s] == '\0') {
			key[i] = '\0';
			i = 0;
			keyinsert(key, id);
			break;
		}
		else if (keyword[s] == ' ') {
			key[i] = '\0';
			i = 0;
			keyinsert(key, id);
		}
		else {
			key[i] = keyword[s];
			i++;
		}
	}
}

void publisherinsert(string publisher, int id) {
	it = mpublisher.find(publisher);
	if (it == mpublisher.end()) {
		set<int> s;
		s.insert(id);
		mpublisher[publisher] = s;
	}
	else {
		it->second.insert(id);
	}
}

void yearinsert(string year, int id) {
	it = myear.find(year);
	if (it == myear.end()) {
		set<int> s;
		s.insert(id);
		myear[year] = s;
	}
	else {
		it->second.insert(id);
	}
}

void titlesearch(string title) {
	it = mtitle.find(title);
	if (it == mtitle.end()) {
		printf("Not Found\n");
	}
	else {
		for (sit = it->second.begin(); sit != it->second.end(); sit++) {
			printf("%07d\n", *sit);
		}
	}
}

void authorsearch(string author) {
	it = mauthor.find(author);
	if (it == mauthor.end()) {
		printf("Not Found\n");
	}
	else {
		for (sit = it->second.begin(); sit != it->second.end(); sit++) {
			printf("%07d\n", *sit);
		}
	}
}

void keysearch(string key) {
	it = mkey.find(key);
	if (it == mkey.end()) {
		printf("Not Found\n");
	}
	else {
		for (sit = it->second.begin(); sit != it->second.end(); sit++) {
			printf("%07d\n", *sit);
		}
	}
}

void publishersearch(string publisher) {
	it = mpublisher.find(publisher);
	if (it == mpublisher.end()) {
		printf("Not Found\n");
	}
	else {
		for (sit = it->second.begin(); sit != it->second.end(); sit++) {
			printf("%07d\n", *sit);
		}
	}
}

void yearsearch(string year) {
	it = myear.find(year);
	if (it == myear.end()) {
		printf("Not Found\n");
	}
	else {
		for (sit = it->second.begin(); sit != it->second.end(); sit++) {
			printf("%07d\n", *sit);
		}
	}
}

int main() {
	int N, M,id,type;
	char title[maxn], author[maxn], keys[maxn], publisher[maxn], year[maxn],str[maxn];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d\n", &id);
		cin.getline(title,maxn);
		cin.getline(author, maxn);
		cin.getline(keys, maxn);
		cin.getline(publisher, maxn);
		cin.getline(year, maxn);
		//²åÈëtitle
		titleinsert(title,id);
		authorinsert(author, id);
	    keywordinsert(keys, id);
		publisherinsert(publisher, id);
		yearinsert(year, id);
	}
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d: ", &type);
		cin.getline(str, maxn);
		printf("%d: %s\n", type, str);
		switch (type)
		{
		case 1:titlesearch(str); break;
		case 2:authorsearch(str); break;
		case 3:keysearch(str); break;
		case 4:publishersearch(str); break;
		case 5:yearsearch(str); break;
		}
	}
	return 0;
}