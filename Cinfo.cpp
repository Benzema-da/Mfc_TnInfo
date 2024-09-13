

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
	  // ��ȡ ID
    in >> m_id;
    // ��ȡ��
    in >> m_lastname;
    // ��ȡ��
    in >> m_firstname;
    // ��ȡ����
    in >> m_date;
    // ��ȡʣ������
    std::getline(in, m_content);
    
    // ȥ�� m_content ��ͷ�Ŀո�����У�
    if (!m_content.empty() && m_content[0] == ' ') {
        m_content = m_content.substr(1);
    }
}
