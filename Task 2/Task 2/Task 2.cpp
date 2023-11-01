#include <iostream>
#include <vector>
using namespace std;

class Singlton {
private:
	Singlton() {}


	vector<string> getEntries;
public:
	static Singlton& getInstence() {
		static Singlton instence;
		return instence;
	}



	vector<string> getLogs() {
		return this->getEntries;
	}

	void log(string text) {
		getEntries.push_back(text);
	}
};

int main()
{
	Singlton& singlton = Singlton::getInstence();

	singlton.log("Error: failed to read the file");
	singlton.log("Information: downloaded data from the server");


	vector<string> logEntries = singlton.getLogs();

	for (int i = 0; i < logEntries.size(); i++) {
		cout << logEntries[i] << endl;
	}

	


}