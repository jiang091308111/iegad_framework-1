#ifndef __MYSQL_HELPER__
#define __MYSQL_HELPER__


// ============ ˵�� ============
//
// @�������� : 2015-10-03
// @������ : iegad
//
// ============================
// @��; :  MySQL ���ݿ���ʲ��� ����
// ============================
//
// @�޸ļ�¼:
// =======================================
//  ����                     �޸���                                   �޸�˵��
// =======================================


#ifdef WIN32

#include <windows.h>
#endif // WIN32


#include <mysql/mysql.h>


#include <string>
#include <queue>
#include <mutex>
#include "data/iegad_dbtab.h"


namespace iegad {
namespace mysql {


    class mysql_helper {
    // mysql ��������
    public:
	// ============================
	// @��; : ������ ��������
	// ============================
	typedef std::unique_lock<std::mutex> lock_t;


	// ============================
	// @��; : ���캯��
	// @PS : ���ʼ�� mysql ����ָ��, 
	//	    ���ʧ��, ����Ӧ�ó�����쳣�˳�
	// ============================
	explicit mysql_helper();


	// ============================
	// @��; : ���캯��
	// @PS : �ڶ����ͷ�ʱ, ��ر����ݿ�����.
	// ============================
	~mysql_helper();


	// ============================
	// @��; : �����ݿ�����
	// @host : mysql������ IP �� ������
	// @port : �˿�
	// @usr : �û���
	// @pwd : ����
	// @db : ���ݿ�����
	// @charset : �ַ���
	// @����ֵ : �ɹ����ӷ���0, ���򷵻� -1;
	// ============================
	int open(const std::string & host, unsigned int port,
	    const std::string & usr, const std::string & pwd,
	    const std::string & db, const std::string & charset = "gbk");


	// ============================
	// @��; : ִ��DML����
	// @sqlstr : DML���
	// @����ֵ : �ɹ�, ������Ӱ�������, ���򷵻�-1;
	// ============================
	int exec(const std::string & sqlstr);


	// ============================
	// @��; : ִ��DML�������
	// @sqlque : ��Ҫִ�е�����DML���
	// @����ֵ : �ɹ�, ������Ӱ�������, ���򷵻�-1;
	// ============================
	int exec_trans(std::queue<std::string> & sqlque);


	// ============================
	// @��; : ִ�в�ѯ����, ����� ���ݱ�tab
	// @sqlstr : DQL���
	// @tab : �����������ݵ� ���ݱ�����ָ��
	// @����ֵ : �ɹ�����0, ���򷵻�-1;
	// ============================
	int query(const std::string & sqlstr, iegad::data::db_tab & tab);


	// ============================
	// @��; : ִ�д洢����
	// @sqlstr : �洢���̵������
	// @����ֵ : �ɹ�����0, ���򷵻�-1;
	// @PS : ���ﷵ�سɹ�ֻ��˵�� MySQL API ���óɹ�, 
	//	    ���������洢���̱���ִ�гɹ�;
	// ============================
	int call_proc(const std::string & sqlstr);


	// ============================
	// @��; : ִ�д洢����
	// @sqlstr : �洢���̵������
	// @out_param : ���������������
	// @����ֵ : �ɹ�����0, ���򷵻�-1;
	// ============================
	int call_proc(const std::string & sqlstr, std::vector<std::string> & out_param);


	// ============================
	// @��; : �ر�mysql����
	// @����ֵ : void
	// ============================
	void close();

    private:
	// MYSQL �������
	MYSQL * conn_;
	// ������
	std::mutex mtx_;



	// ����
	mysql_helper(const mysql_helper &);
	mysql_helper & operator=(const mysql_helper &);
    }; // class mysql_helper;



} // namespace mysql;
} // namespace iegad;


#endif // __MYSQL_HELPER__