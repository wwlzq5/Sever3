#ifndef STOOL_H
#define STOOL_H


#define HORIZONTAL24 sizeof(int)*24
#define HORIZONTAL4 sizeof(int)*4



// #define IP1 "10.41.61.15"
// #define IP2 "10.41.63.241"
// #define IP3 "10.41.61.10"

#define IP1 "192.168.250.201"
#define IP2 "192.168.250.202"
#define IP3 "192.168.250.203"

#define PASSWORD "123456"

enum StateEnum
{
	SENDDATA,//��������ģʽ
	GETSUCCESS,//�������ݳɹ�
	CLEAR,//��������ʧ��
	CONNECT,//�����������ӻ���
	LOCKSCREEN,
	ALERT,//�������ͱ���
	SEVERS,//������
	IMAGE,//��ʾͼ�����
	NLEADING,
	NCLAMPING,
	NBACKING,
	MAININTERFACE,
	SYSTEMMODEADD,
	SYSTEMMODESELECT,
	SYSTEMMODEDELTE,
	ONLYSHOWSEVER,
	FRONTSTATE
};
enum UnitEnum
{
	LEADING, //ǰ��
	CLAMPING,//�г�
	BACKING//���
};

struct IpStruct
{
	QString ipAddress; //ip��ַ
	int startTime; //ʱ�䣬�����ж��Ƿ����������ж�
	bool nstate; //Ŀǰ����״̬
};
struct MyErrorType
{
	int id;
	int nType;
	int nErrorArea;
};
struct MyStruct
{
	StateEnum nState;//����״̬��־λ
	UnitEnum nUnit;//���͵��豸��־λ
	int nCount;//���ĳ���
	int nFail;//ǰ��ͨ��out3�õ����߷�����
	char nTemp[256];//ǰ�˵Ķ������
};

typedef struct _ErrorInfo
{
	int	iErrorTypeCount;					
	QList<QString> iErrorType;
}s_ErrorInfo;

#endif