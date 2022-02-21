#ifndef DATABASE_H
#define DATABASE_H

#include "qsqldatabase.h"
#include "qsqlquery.h"
#include "qsqldriver.h"
#include "qsqlrecord.h"
#include <QVariant>
#include "widget_count.h"

class DataBase
{
public:
	DataBase(QString spath);

public:
	bool createConnection();  //����һ������
	bool createReportTable();       //�������ݿ��
	bool createLastDataTable();       //�������ڱ�����һ����ʷ���ݵı�
	bool insert(QString timestr,cErrorInfo info);
	bool queryByOnce(QString timeStr,long long &ptime,cErrorInfo &info);										//timeStr: yyyyMMddhhmm
	bool queryByDay(QString dayStr,QList<long long> &pTimes,QList<cErrorInfo> &infos);							//daystr : yyyyMMdd
	bool queryByShift(QString pStartTime,QString pEndTime,QList<long long> &pTimes,QList<cErrorInfo> &infos);	//daystr : yyyyMMdd
	bool insertLastData(int AllCount,int failCount,cErrorInfo info);																		//������ʷ����
	bool queryLastData(int &AllCount,int &failCount,cErrorInfo &info);																		//��ѯ��ʷ����

private:
	QString sqlConnectName;
	QString AppPath;
};
#endif