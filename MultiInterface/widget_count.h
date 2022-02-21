#ifndef WIDGET_COUNT_H
#define WIDGET_COUNT_H


#include <QWidget>
#include "ui_widget_count.h"

#include <QPushButton>
#include <QStandardItemModel>
#include <QSettings>
#include <QThread>
#include <QDateTime>
#include <QDesktopServices>
#include <QUrl>

#include "pieview.h"
#include "qcustomplot.h"
#include "ExcelObject.h"

#include<windows.h>
#include<tlhelp32.h>

class cErrorInfo;
//������Ϣ��-��һȱ��
class cErrorTypeCountInfo;
//������Ϣ��-ÿ��Сʱ����
class cErrorCountbyTime;
//�Զ���QCustomPlotֱ��ͼbar
class CustomBars;

class ExportExcelThread;

class widget_count : public QWidget
{
	Q_OBJECT

public:
	widget_count(QWidget *parent = 0);
	~widget_count();

	enum table2UpdateType
	{
		APPEND =0,
		UPDATE
	};
private:
	void init();
	void openInNotePad(QString str);
	DWORD GetProcessIdFromName(const char*processName);
	QTime initTime(QTime pTime);

private slots:
	void slots_turnPage();
	void slot_saveRecordOK_clicked();
	void slot_saveRecordCancel_clicked();
	void slot_shiftOK_clicked();
	void slot_shiftCancel_clicked();
	void slots_ShowPie(QModelIndex);
	void slot_HistorySearch_clicked();
	void slot_OpenRecord_clicked();
	void slot_DeleteRecord_clicked();
	void slot_OpenExcel_clicked();
	void slot_SearchShift_clicked();

signals:
	void updateRecordSet();
	void updateShiftSet();

public slots:
	/**********************************************************
		ֻˢ���������߷������߷��ʣ� modelRate������-1
		ֻˢ�¶�ģ�ʣ� total �� failNum ��Ϊ -1
	***********************************************************/
	void slots_updateCountInfo(int total,int failNum,float modelRate);
	/**********************************************************
		������ʾÿ���������ȱ����
	***********************************************************/
	void slots_UpdateTable1(cErrorInfo pCountdates);
	/**********************************************************
		��ʾÿ���С����һ��Сʱ����
		ɾ��������������У����������������
		��ListΪ�գ�ֻ����������
	***********************************************************/
	void slots_UpdateTable2(QList<long long> pTimes,QList<cErrorInfo> pInfos);
	/**********************************************************
		��ʾÿ���С����һ��Сʱ����
		���أ�ֻ���һ�����ݣ����뵽��β����ɾ�����б������
	***********************************************************/
	void slots_UpdateTable2(QString ptime ,cErrorInfo pCountdate);
	/**********************************************************
		����ÿСʱȱ��ռ�ȱ�ͼ
	***********************************************************/
	void slots_ShowPieImage1(cErrorInfo pCountdates);
	/**********************************************************
		����ÿ�����ȱ��ռ�ȱ�ͼ
	***********************************************************/
	void slots_ShowPieImage2(QList<cErrorTypeCountInfo> pCountdates);
	/**********************************************************
		ֱ��ͼ������ÿСʱ����������߷����� 
	***********************************************************/
	void slots_ShowShiftIamge(QString startTime,QString endTime,QList<long long> pTimes,QList<cErrorInfo> pInfos);
	/**********************************************************
		ֱ��ͼ�����ư�μ���������߷����� 
	***********************************************************/
	void slots_ShowShiftIamge(QList<long long> pTimes,QList<cErrorInfo> pInfos);


private:
	Ui::widget_count ui;
	QPushButton *buttonTurn;
	QStandardItemModel *table1Model;
	QStandardItemModel *table2Model;
	PieView *pieImage1;
	QStandardItemModel *PieModel_1;

	PieView *pieImage2;
	QStandardItemModel *PieModel_2;

	QList<QColor> PieItemcolors;
	ExportExcelThread *ExportThread;
};

class ExportExcelThread :public QThread
{
	Q_OBJECT
public:
	ExportExcelThread(QObject *parent = 0);
	~ExportExcelThread();

	void run();
	//void InitShiftTime(QTime pShift1,QTime pShift2,QTime pShift3);

public:
	QDate m_Date;

private:
	QList<QTime> m_shifts;
	int curShift;
	bool iShowAllnum;
};

//�Զ���QCustomPlotֱ��ͼbar
class CustomBars :public QCPBars
{
public:
	explicit CustomBars(QCPAxis *keyAxis , QCPAxis *valueAxis);

	enum CustomBarsFlags{
		CustomBars_NULL = 0,
		CustomBars_Rate
	};

	Qt::Alignment textAlignment() const { return mTextAlignment;}
	double spacing() const {return mSpacing;}
	QFont font() const {return mFont;}

	void setTextAlignment(Qt::Alignment alignment);
	void setSpacing(double spacing);
	void setFont(const QFont &font);

	void setTextSuffix(QString Suffix);

protected:
	Qt::Alignment mTextAlignment;
	double mSpacing;
	QFont mFont;
	CustomBarsFlags m_Flags;
	QString m_TextSuffix;

	virtual void draw(QCPPainter *painter) Q_DECL_OVERRIDE;
};

//������Ϣ��-��һȱ��
class cErrorTypeCountInfo
{
public:
	cErrorTypeCountInfo()
	{
		iErrorType =0;
		iErrorTxt = "";
		iErrorFailCount = 0;
		iFailCount = 0;
		iCheckCount = 0;
		iFrontCount = 0;
		iClampCount = 0;
		iRearCount = 0;
	}
	//��������
	int sum()
	{		
		return iFrontCount+iClampCount+iRearCount;
	}

	void operator= (const cErrorTypeCountInfo pErrorInfo)
	{
		iErrorType = pErrorInfo.iErrorType;
		iErrorTxt = pErrorInfo.iErrorTxt;
		iErrorFailCount = pErrorInfo.iErrorFailCount;
		iFailCount = pErrorInfo.iFailCount;
		iCheckCount = pErrorInfo.iCheckCount;
		iFrontCount = pErrorInfo.iFrontCount;
		iClampCount = pErrorInfo.iClampCount;
		iRearCount =  pErrorInfo.iRearCount;
	}

	void clear()
	{
		iErrorType =0;
		iErrorTxt = "";
		iErrorFailCount =0;
		iFailCount = 0;
		iCheckCount = 0;
		iFrontCount = 0;
		iClampCount = 0;
		iRearCount = 0;
	}

	//ȱ������
	int iErrorType;
	//ȱ�����ƣ��� �� Ӣ��
	QString iErrorTxt;
	//ĳ��ȱ���߷�����
	int iErrorFailCount;
	//�߷�����
	int iFailCount;
	//�������
	int iCheckCount;
	//ǰ���߷���
	int iFrontCount;
	//�г��߷���
	int iClampCount;
	//����߷���
	int iRearCount;
};

//������Ϣ��-ÿ��Сʱ����
class cErrorCountbyTime
{
public:
	cErrorCountbyTime()
	{
		iTime = 0;
		iAllcount = 0;
		iErrorCount = 0;
		iFrontCount = 0;
		iClampCount = 0;
		iRearCount = 0;
	}

	//ͬһʱ���µ��������ͬȱ���������
	void operator+= (const cErrorCountbyTime pCountInfo)
	{
		iFrontCount += pCountInfo.iFrontCount;
		iClampCount += pCountInfo.iClampCount;
		iRearCount  += pCountInfo.iRearCount;
	}

	void operator= (const cErrorCountbyTime pCountInfo)
	{
		iTime = pCountInfo.iTime;
		iAllcount = pCountInfo.iAllcount;
		iErrorCount = pCountInfo.iErrorCount;
		iFrontCount = pCountInfo.iFrontCount;
		iClampCount = pCountInfo.iClampCount;
		iRearCount =  pCountInfo.iRearCount;
	}

	void clear()
	{
		iTime = 0;
		iAllcount = 0;
		iErrorCount = 0;
		iFrontCount = 0;
		iClampCount = 0;
		iRearCount = 0;
	}
	//ת��ʱ���ַ�����ʽ ����2021-07-27 16:00
	QString GetTimeStr()
	{
		QDateTime pTime = QDateTime::fromString(QString::number(iTime),"yyyyMMddhhmm");
		return pTime.toString("yyyy-MM-dd hh:mm");
	}
	//��ȡȱ����
	QString GetFailRate()
	{
		double pRate=0.0;
		if (iAllcount != 0)
			pRate =(double)iErrorCount / iAllcount;
		return QString::number(pRate,'f',2)+"%";
	}

	//ʱ��
	long long iTime;
	//�������
	int iAllcount;
	//ȱ������
	int iErrorCount;
	//ǰ���߷���
	int iFrontCount;
	//�г��߷���
	int iClampCount;
	//����߷���
	int iRearCount;
};

class cErrorInfo
{
public:
	cErrorInfo()
	{
		iAllCount = 0 ;
		iFailCount = 0;
		FrontCount = 0;
		ClampCount = 0;
		RearCount = 0;
		for (int i=0;i<50;i++)
		{
			iErrorByType[i] = 0;
			iFrontErrorByType[i] = 0;
			iClampErrorByType[i] = 0;
			iRearErrorByType[i] = 0;
		}
	}

	void operator+= (const cErrorInfo &pCountInfo)
	{
		iAllCount  += pCountInfo.iAllCount ;
		iFailCount += pCountInfo.iFailCount;
		FrontCount += pCountInfo.FrontCount;
		ClampCount += pCountInfo.ClampCount;
		RearCount  += pCountInfo.RearCount;
		for (int i=0;i<50;i++)
		{
			iErrorByType[i]		 += pCountInfo.iErrorByType[i];
			iFrontErrorByType[i] += pCountInfo.iFrontErrorByType[i];
			iClampErrorByType[i] += pCountInfo.iClampErrorByType[i];
			iRearErrorByType[i]  += pCountInfo.iRearErrorByType[i] ;
		}
	}

	cErrorInfo operator + (const cErrorInfo &pCountInfo)
	{
		cErrorInfo tmp;
		tmp.iAllCount = this->iAllCount   + pCountInfo.iAllCount ;
		tmp.iFailCount= this->iFailCount  + pCountInfo.iFailCount;
		tmp.FrontCount= this->FrontCount  + pCountInfo.FrontCount;
		tmp.ClampCount= this->ClampCount  + pCountInfo.ClampCount;
		tmp.RearCount = this->RearCount   + pCountInfo.RearCount;
		for (int i=0;i<50;i++)
		{
			tmp.iErrorByType[i]		 = this->iErrorByType[i]	  + pCountInfo.iErrorByType[i];
			tmp.iFrontErrorByType[i] = this->iFrontErrorByType[i] + pCountInfo.iFrontErrorByType[i];
			tmp.iClampErrorByType[i] = this->iClampErrorByType[i] + pCountInfo.iClampErrorByType[i];
			tmp.iRearErrorByType[i]  = this->iRearErrorByType[i]  + pCountInfo.iRearErrorByType[i] ;
		}
		return tmp;
	}

	void operator-= (const cErrorInfo &pCountInfo)
	{
		iAllCount  -= pCountInfo.iAllCount ;
		iFailCount -= pCountInfo.iFailCount;
		FrontCount -= pCountInfo.FrontCount;
		ClampCount -= pCountInfo.ClampCount;
		RearCount  -= pCountInfo.RearCount;
		for (int i=0;i<50;i++)
		{
			iErrorByType[i]		 -= pCountInfo.iErrorByType[i];
			iFrontErrorByType[i] -= pCountInfo.iFrontErrorByType[i];
			iClampErrorByType[i] -= pCountInfo.iClampErrorByType[i];
			iRearErrorByType[i]  -= pCountInfo.iRearErrorByType[i] ;
		}
	}

	cErrorInfo operator - (const cErrorInfo &pCountInfo)
	{
		cErrorInfo tmp;
		tmp.iAllCount = this->iAllCount   - pCountInfo.iAllCount ;
		tmp.iFailCount= this->iFailCount  - pCountInfo.iFailCount;
		tmp.FrontCount= this->FrontCount  - pCountInfo.FrontCount;
		tmp.ClampCount= this->ClampCount  - pCountInfo.ClampCount;
		tmp.RearCount = this->RearCount   - pCountInfo.RearCount;
		for (int i=0;i<50;i++)
		{
			tmp.iErrorByType[i]		 = this->iErrorByType[i]	  - pCountInfo.iErrorByType[i];
			tmp.iFrontErrorByType[i] = this->iFrontErrorByType[i] - pCountInfo.iFrontErrorByType[i];
			tmp.iClampErrorByType[i] = this->iClampErrorByType[i] - pCountInfo.iClampErrorByType[i];
			tmp.iRearErrorByType[i]  = this->iRearErrorByType[i]  - pCountInfo.iRearErrorByType[i] ;
		}
		return tmp;
	}

	void operator= (const cErrorInfo &pCountInfo)
	{
		iAllCount =	pCountInfo.iAllCount ;
		iFailCount = pCountInfo.iFailCount;
		FrontCount = pCountInfo.FrontCount;
		ClampCount = pCountInfo.ClampCount;
		RearCount = pCountInfo.RearCount;
		for (int i=0;i<50;i++)
		{
			iErrorByType[i]		 = pCountInfo.iErrorByType[i];
			iFrontErrorByType[i] = pCountInfo.iFrontErrorByType[i];
			iClampErrorByType[i] = pCountInfo.iClampErrorByType[i];
			iRearErrorByType[i]  = pCountInfo.iRearErrorByType[i] ;
		}
	}

	int GetFrontCount()
	{
		int pCount=0;
		for (int i=0;i<50;i++)
		{
			pCount += iFrontErrorByType[i];
		}
		return pCount;
	}

	int GetClampCount()
	{
		int pCount=0;
		for (int i=0;i<50;i++)
		{
			pCount += iClampErrorByType[i];
		}
		return pCount;
	}

	int GetRearCount()
	{
		int pCount=0;
		for (int i=0;i<50;i++)
		{
			pCount += iRearErrorByType[i];
		}
		return pCount;
	}

	int GetFailCount()
	{
		return GetFrontCount() + GetClampCount() + GetRearCount();
	}

	double GetFailRate()
	{
		if (iAllCount > 0)
			return (double)GetFailCount() / iAllCount ;
		else
			return 0.0;
		
	}

	int GetErrorByTypeCount(int ptype)
	{
		if(ptype>=50)
			return 0;
		return iFrontErrorByType[ptype] + iClampErrorByType[ptype] + iRearErrorByType[ptype];
	}

	void Clear()
	{
		iAllCount = 0 ;
		iFailCount = 0;
		FrontCount = 0;
		ClampCount = 0;
		RearCount = 0;
		for (int i=0;i<50;i++)
		{
			iErrorByType[i] = 0;
			iFrontErrorByType[i] = 0;
			iClampErrorByType[i] = 0;
			iRearErrorByType[i] = 0;
		}
	}

	//��������
	int iAllCount;
	//�߷�����
	int iFailCount;
	//ǰ������
	int FrontCount;
	//�г�����
	int ClampCount;
	//�������
	int RearCount;

	//����ȱ�������߷���
	int iErrorByType[50];

	//ǰ�ڵ���ȱ�������߷���
	int iFrontErrorByType[50];
	//�гֵ���ȱ�������߷���
	int iClampErrorByType[50];
	//��ڵ���ȱ�������߷���
	int iRearErrorByType[50];
};

#endif // WIDGET_COUNT_H
