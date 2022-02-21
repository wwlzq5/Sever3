#include "IOCard.h"
IOCardClass::IOCardClass(QWidget *parent)
	:QMainWindow(parent)
{
	ui.setupUi(this);
	initInterfance();
}
void IOCardClass::initInterfance()
{
	ifSHOW = true;
	connect(ui.checkBox,SIGNAL(clicked()),this,SLOT(slot_checkBoxCheck()));
	connect(ui.pushButton,SIGNAL(clicked()),this,SLOT(slot_ClearTable()));
	m_model = new QStandardItemModel();
	m_model->setColumnCount(3);
	m_model->setHeaderData(0,Qt::Horizontal,tr("time"));
	m_model->setHeaderData(1,Qt::Horizontal,tr("ImageID"));
	m_model->setHeaderData(2,Qt::Horizontal,tr("ErrorType"));
	//���ñ������
	ui.tableView->setModel(m_model); 
	//��ͷ��Ϣ��ʾ���� 
	ui.tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);
	ui.tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);	//��ֹ�༭
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //����ѡ��

	//�����п��ɱ� 
	ui.tableView->horizontalHeader()->setResizeMode(0,QHeaderView::Fixed); 
	ui.tableView->horizontalHeader()->setResizeMode(1,QHeaderView::Fixed);
	ui.tableView->horizontalHeader()->setResizeMode(2,QHeaderView::Fixed);
	ui.tableView->setColumnWidth(0,50); 
	ui.tableView->setColumnWidth(1,50);
	ui.tableView->setColumnWidth(2,60);
}

IOCardClass::~IOCardClass()
{
}
void IOCardClass::slot_checkBoxCheck()
{
	ifSHOW = !ifSHOW;
}
void IOCardClass::setEditValue(int* test,QString FailName)
{
	ui.lineEdit->setText(QString::number(test[0]));
	ui.lineEdit_2->setText(QString::number(test[1]));
	ui.lineEdit_3->setText(QString::number(test[2]));
	ui.lineEdit_4->setText(QString::number(test[3]));
	ui.lineEdit_5->setText(QString::number(test[4]));
	ui.lineEdit_6->setText(QString::number(test[5]));
	ui.lineEdit_7->setText(QString::number(test[6]));
	ui.lineEdit_8->setText(QString::number(test[7]));
	ui.lineEdit_9->setText(QString::number(test[8]));
	ui.lineEdit_10->setText(QString::number(test[9]));
	ui.lineEdit_11->setText(QString::number(test[10]));
	ui.lineEdit_12->setText(QString::number(test[11]));
	ui.lineEdit_13->setText(QString::number(test[12]));
	ui.lineEdit_14->setText(QString::number(test[13]));
	ui.lineEdit_15->setText(QString::number(test[14]));
	ui.lineEdit_16->setText(QString::number(test[15]));
	//if(test[22])
	{
		if(ifSHOW)
		{
			if(test[17] == 0)//������ɫ����
			{
				ui.label_Camera->setText("-");
				ui.label_nFailType->setText(FailName);
				ui.label_nFailType->setStyleSheet("color:green");//�ı���ɫ
				//ui.label_nFailType->setStyleSheet("background-color:green");//����ɫ
			}else{//��ɫ�ú�
				ui.label_Camera->setText(QString::number(test[16]));
				ui.label_nFailType->setText(FailName);
				ui.label_nFailType->setStyleSheet("color:red");//�ı���ɫ
				//ui.label_nFailType->setStyleSheet("background-color:red");//����ɫ
				InsertTableList(test[16],FailName);
			}
		}else{
			if(test[17] >0)//������ɫ����
			{
				ui.label_Camera->setText(QString::number(test[16]));
				ui.label_nFailType->setText(FailName);
				ui.label_nFailType->setStyleSheet("color:red");//�ı���ɫ
				//ui.label_nFailType->setStyleSheet("background-color:red");//����ɫ
				InsertTableList(test[16],FailName);
			}
		}
	}
}
void IOCardClass::InsertTableList(int id,QString nName)
{
	QTime time = QTime::currentTime();
	QStandardItem *item1 = new QStandardItem(QObject::tr("%1:%2:%3").arg(time.hour()).arg(time.minute()).arg(time.second()));
	QStandardItem *item2 = new QStandardItem(QObject::tr("%1").arg(id));
	QStandardItem *item3 = new QStandardItem(QObject::tr("%1").arg(nName));
	QList<QStandardItem*> item;
	item<<item1<<item2<<item3;
	m_model->insertRow(0,item);
	ui.tableView->showRow(0);
	if (30 < m_model->rowCount())
	{
		QList<QStandardItem*>  item = m_model->takeRow(m_model->rowCount()-1);
		if (!item.isEmpty())
		{
			qDeleteAll(item);
			item.clear();
		}
	}
}
void IOCardClass::slot_ClearTable()
{
	while(0 < m_model->rowCount())
	{
		QList<QStandardItem*>  item = m_model->takeRow(m_model->rowCount()-1);
		if (!item.isEmpty())
		{
			qDeleteAll(item);
			item.clear();
		}
	}
	int clear[24]={0};
	setEditValue(clear,NULL);
}