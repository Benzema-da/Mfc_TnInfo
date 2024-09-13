#include "StdAfx.h"
#include "DataInterface.h"


CDataInterface::CDataInterface(void)
{
}


CDataInterface::~CDataInterface(void)
{
}

bool CDataInterface::Open(CString FilePath){
	
	//ifstream in(FilePath, ios::in);
	std::ifstream in(FilePath.GetString()); 
	if (in.is_open())
	{
		int num;	//记录有多少条数据
		in >> num;
		for (int i = 0; i < num; i++)
		{
			Cinfo MyInfo;
			MyInfo.Load(in);
			Info.push_back(MyInfo);
		}
		return true;
	}

	return false;
		
}
void CDataInterface::Add(Cinfo MyInfo){
	Info.push_back(MyInfo);

}

void CDataInterface::Del(int index)
{
	Info.erase(Info.begin() + index);
}
