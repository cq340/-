#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
#define inf 655535


struct task{
	int time;
	int deadline;
	int cost;
	bool operator < (const task &ta) const
	{
		return deadline < ta.deadline;
	}
};

void init(ifstream &fin, vector<struct task> &job, vector< vector<int> > &map, int &max_deadline){
	int lines = 0;
	fin >> lines;

	struct task tasks;
	for (int i = 0; i < lines; i++){
		fin >> tasks.time >> tasks.deadline >> tasks.cost;
		job.push_back(tasks);
	}

	sort(job.begin(), job.end());

	max_deadline = (job.at(job.size() - 1)).deadline;
	map.resize(lines, vector<int>(max_deadline + 1));

	for (int i = 0; i < lines; i++){
		for (int j = 0; j < max_deadline; j++){
			map[i][j] = inf;
		}
	}

}


void dynamic(vector<struct task> &job, vector< vector<int> > &map, const int &max_deadline){
	vector<struct task>::iterator iter = job.begin();

	for (; iter != job.end(); iter++){
		cout << (*iter).time << " " << (*iter).deadline << " " << (*iter).cost << endl;
	}

	for (int i = 0; i <= max_deadline; i++){
		if (job.at(0).time <= i){
			map[0][i] = 0;
		}
		else{
			map[0][i] = job[0].cost;
		}
	}

	int cur_min = 0;
	for (int i = 1; i<job.size(); i++)
	{
		for (int j = 0; j <= max_deadline; j++){
			// p( i , d ) = min{ p(i-1, d)+wi  ，  p(i-1, min{d, di}-ti) } 
			//p(i - 1, d) + wi 表示决定不做第 i 个任务，p(i - 1, min{ d, di }-ti) 表示决定要做第 i 个任务，
			//这时必须在第 i 个任务的截至时间前做完它（即 min{ d, di }-ti ）

			map[i][j] = map[i - 1][j] + job.at(i).cost;
			cur_min = job.at(i).deadline > j ? j : job.at(i).deadline;

			if ((cur_min >= job.at(i).time) && (map[i][j] > map[i - 1][cur_min - job.at(i).time])){
				map[i][j] = map[i - 1][cur_min - job.at(i).time];
			}
		}
	}

}




int main(){
	vector<struct task> job;
	vector < vector<int> > map;
	int max_deadline = 0;
	ifstream fin("1.txt");
	int count = 0;

	init(fin, job, map, max_deadline);
	dynamic(job, map, max_deadline);
	cout << endl << "最小误时惩罚：" << map[job.size() - 1][max_deadline] << endl;
	job.clear();
	map.clear();
	cout << max_deadline;
	fin.close();
	system("pause");
	return 0;
}