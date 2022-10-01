#include "list.h"
#include "quad.h"
int main() {
	list <quad*>b;int cnt=0,good=0; 
	srand(time(0));
	cout << "Practicing. Input negative value to halt." << endl;
	while (1) 	{
		int gen1 = (rand() % 9) + 1;int gen2 = (rand() % 9) + 1;int gen3 = (rand() % 9) + 1;
		double temp;quad* base;
		switch (rand()%5) {
		case 0:
			base = new rect(gen1,gen2);
			break;
		case 1:
			base = new diamond(gen1,gen2);
			break;
		case 2:
			base = new square(gen1);
			break;
		case 3:
			base = new para(gen1,gen2);
			break;
		default:
			base = new trapezoid(gen1,gen2,gen3);
			break;
		}
	base->print(); cout << "?";
	cin >> temp;
	if (temp < 0) break;
	cout << "Your answer is " << (temp == base->area() ? "correct" : "incorrect") << endl << endl;
	base->change(temp, temp == base->area());
	b.push_back(base);
	}
out:cout << endl << endl << endl << "Reviewing..." << endl;
	for (auto i = b.begin(); i != b.end(); ++i) {
		(*i)->print(); cout << (*i)->area() << ", answer=" << (*i)->answer() << ((*i)->Ifcorrect() ? " V" : " X") << endl;
        ++cnt;if((*i)->Ifcorrect())++good;	
	}
	cout << endl << "Total: " << cnt << ", Correct: " << good << endl;
	return 0;
}