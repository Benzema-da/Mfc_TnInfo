#pragma once
#include "Cinfo.h"
class CDataInterface
{
public:
	CDataInterface(void);
	~CDataInterface(void);
	bool Open(CString FilePath);
	void Add(Cinfo MyInfo);
	void Del(int index);
	void Amend(int index, Cinfo MyInfo);
	Cinfo Find(int id);
	bool Save();


	vector<Cinfo> Info;
};

