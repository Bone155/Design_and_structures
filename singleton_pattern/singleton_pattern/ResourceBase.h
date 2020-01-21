#pragma once
#include <string>
using std::string;
class ResourceBase
{
protected:
	ResourceBase(const string& filename) : m_filename(filename) {};
public:
	~ResourceBase() {};
	string getFilename() { return m_filename; }
	virtual void* getData() = 0;

	template<typename T>
	T* as() { return (T*)gateData(); }
protected:
	string m_filename;
};

