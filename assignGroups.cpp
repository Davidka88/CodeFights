// $Id: assignGroups.cpp,v 1.0 2018/06/06 21:19:55 david Exp david $
#define DB(A) cout << #A "=" << (A) << endl
#define DB1(A) DB(A)
#define DB2(A,B) cout << #A "=" << (A) << " " #B "=" << (B) << endl
#define DB3(A,B,C) cout << #A "=" << (A) \
                         << " " #B "=" << (B) \
						 << " " #C "=" << (C) << endl

#include <algorithm>

int assignGroups(std::vector<int> timeEstimates, int groupSize)
{
	int remainingInGroup {groupSize};
	vector<int>::iterator pTm;	// time taken for student's presentation
	int totalTime {0};;
	int ctr {0};

	sort(timeEstimates.begin(), timeEstimates.end());

	for (pTm = --timeEstimates.end(); pTm >= timeEstimates.begin(); --pTm) {
		if (ctr == 0) {
			totalTime += *pTm;
			ctr = groupSize;
		}
		--ctr;
	}

	return totalTime;
}
