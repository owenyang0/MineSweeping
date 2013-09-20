#define PRIMARY_XNUM		9	//����X����ķ�������Ŀ
#define PRIMARY_YNUM		9   //����Y����ķ�������Ŀ
#define PRIMARY_MINENUM		10	//�����׵���Ŀ
#define SECONDRY_XNUM		16
#define SECONDRY_YNUM		16
#define SECONDRY_MINENUM	40
#define ADVANCE_XNUM		30
#define ADVANCE_YNUM		16
#define ADVANCE_MINENUM		99

//������صĶ���
#define DEFAULT_FRAME_X		6		//����X�����
#define DEFAULT_FRAME_Y		52

#define LINE_WIDTH_0		3		//�߱�0�Ŀ��
#define LINE_WIDTH_1		2

#define SIDE_WIDTH_0		6		//��0�Ŀ��
#define SIDE_WIDTH_1		5

#define SHELL_S_H			37		//С��ǵĸ߶�
#define SHELL_S_START_X		9		//С��ǵ�x����ʼ����
#define SHELL_S_START_Y		9       //С��ǵ�y����ʼ����
#define SHELL_L_START_X		9       //����ǵ�x����ʼ����
#define SHELL_L_START_Y		52      //����ǵ�y����ʼ����

#define MINEAREA_FRAME_X	12      //����X��С           
#define MINEAREA_FRAME_Y	55

// �׷��鶨��
#define MINE_WIDTH			16         //�׷���Ĵ�С(���Ϊ16��λͼ)
#define MINE_HEIGHT			16
#define MINE_AREA_LEFT		12                
#define MINE_AREA_TOP		55			


#define STATE_NORMAL		0     //����
#define STATE_FLAG			1    //��־Ϊ��
#define STATE_DICEY			2    //δ֪״̬0
#define STATE_BLAST			3    //��ը״̬
#define STATE_ERROR			4   //����״̬
#define STATE_MINE			5   //��״̬
#define STATE_DICEY_DOWN	6  //δ֪״̬1
#define STATE_NUM8			7  //��Χ��8��
#define STATE_NUM7			8 
#define STATE_NUM6			9 
#define STATE_NUM5			10
#define STATE_NUM4			11
#define STATE_NUM3			12
#define STATE_NUM2			13
#define STATE_NUM1			14
#define STATE_EMPTY			15  //����

#define ATTRIB_EMPTY		0
#define ATTRIB_MINE			1


// ��Ϸ״̬
#define GS_WAIT				0
#define GS_RUN				1
#define GS_DEAD				2
#define GS_VICTORY			3

// ��Ϸ����
#define LEVEL_PRIMARY			0
#define LEVEL_SECONDRY			1
#define LEVEL_ADVANCE			2
#define LEVEL_CUSTOM			3

// Ц����ť����ͼ�� ״̬
#define BUTTON_DOWN				0
#define BUTTON_VICTORY			1
#define BUTTON_DEAD				2
#define BUTTON_CLICK			3
#define BUTTON_NORMAL			4

// ʧ��ȥ��ԭ��
#define DC_STRIKE_MINE		0
#define DC_ERROR_MINE		1

// color defines
#define COLOR_BLACK			RGB(0, 0, 0)
#define COLOR_DARK_GRAY		RGB(128, 128, 128)
#define COLOR_GRAY			RGB(192, 192, 192)
#define COLOR_WHITE			RGB(255, 255, 255)

#define DEFAULT_RECORD		999