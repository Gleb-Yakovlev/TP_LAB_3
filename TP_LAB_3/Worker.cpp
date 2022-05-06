#include "Worker.h"

Worker::Worker() {

}

Worker::~Worker() {

}


int Worker::cash() {
	return 0;
}

string Worker::getData(int data)
{
	switch (data)
	{
	case 1:
		return name;
		break;
	case 2:
		return surname;
		break;
	case 3:
		return phone;
		break;
	case 4:
		return address;
		break;
	}
}

void Worker::setData(int data, string sData)
{
	switch (data)
	{
	case 1:
		name = sData;
		break;
	case 2:
		surname = sData;
		break;
	case 3:
		phone = sData;
		break;
	case 4:
		address = sData;
		break;
	default:
		break;
	}
}


void Worker::ToFile(string data, int order) {
	ofstream out("team.txt", ios::app);
	if (!out) { cout << "The File is Empty" << endl; return; }
	if (order == 1) out << data << " ";
	if (order == 0) out << data << endl;
}


bool Worker::is_empty(ifstream& pFile)
{
	return pFile.peek() == -1;
}