

#include "StdAfx.h"
#include "Cinfo.h"

using namespace std;
Cinfo::Cinfo(void)
{
}
 

Cinfo::Cinfo(int id, string lastname, string firstname, string date, string content)
{
	this->m_id = id;
	this->m_lastname = lastname;
	this->m_firstname = firstname;
	this->m_date = date;
	this->m_content = content;
}
void Cinfo::Load(ifstream& in)
{
	  // 读取 ID
    in >> m_id;
    // 读取姓
    in >> m_lastname;
    // 读取名
    in >> m_firstname;
    // 读取日期
    in >> m_date;
    // 读取剩余内容
    std::getline(in, m_content);
    
    // 去掉 m_content 开头的空格（如果有）
    if (!m_content.empty() && m_content[0] == ' ') {
        m_content = m_content.substr(1);
    }
}
