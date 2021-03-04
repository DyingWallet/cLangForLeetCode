//�����Ŷ�����һ���ɱ�̻����ˣ������˳�ʼλ����ԭ��(0, 0)��
//С������ȸ�����������һ��ָ��command�������˾ͻ�����ѭ������ָ��Ĳ�������ƶ���ָ�������֣�
//U : ��y���������ƶ�һ��
//R : ��x���������ƶ�һ��
//���ҵ��ǣ��� xy ƽ���ϻ���һЩ�ϰ�����ǵ�������obstacles��ʾ��������һ�������ϰ���ͻᱻ��١�
//�����յ�����(x, y)�����ػ������ܷ���õص����յ㡣����ܣ�����true�����򷵻�false��
//ʾ�� 1��
//���룺command = "URR", obstacles = [], x = 3, y = 2
//�����true
//���ͣ�U(0, 1)->R(1, 1)->R(2, 1)->U(2, 2)->R(3, 2)��
//ʾ�� 2��
//���룺command = "URR", obstacles = [[2, 2]], x = 3, y = 2
//�����false
//���ͣ��������ڵ����յ�ǰ������(2, 2)���ϰ��
//ʾ�� 3��
//���룺command = "URR", obstacles = [[4, 2]], x = 3, y = 2
//�����true
//���ͣ������յ���������ϰ���Ҳ��Ӱ�췵�ؽ����
//���ƣ�
//2 <= command�ĳ��� <= 1000
//command��U��R���ɣ���������һ��U��������һ��R
//0 <= x <= 1e9, 0 <= y <= 1e9
//0 <= obstacles�ĳ��� <= 1000
//obstacles[i]��Ϊԭ������յ�

#include"leetCode.h"

bool canReach(char* command, int** obstacles, int obstaclesSize, int* obstaclesColSize, int x, int y, int curX, int curY,int cmd);
bool isTraped(int** obs, int obsRowSize, int* obsColSize, int curX, int curY);
static int cmdLen = 0;
bool robot(char* command, int** obstacles, int obstaclesSize, int* obstaclesColSize, int x, int y) {
	cmdLen = strlen(command);
	if (cmdLen < 2 || cmdLen > 1000) return false;
	return canReach(command,obstacles,obstaclesSize,obstaclesColSize,x,y,0,0,0);
}

bool canReach(char* command, int** obs, int obsRowSize, int* obsColSize, int x, int y, int curX, int curY, int cmd) {
	if (curX == x && curY == y) return true;
	if (curX > 1e9 || curY > 1e9) return false;
	if (isTraped(obs,obsRowSize,obsColSize,curX,curY)) return false;	//����Ƿ����ϰ���
	if (cmd > cmdLen) cmd = 0;
	if (command[cmd] == 'U')
		return canReach(command, obs, obsRowSize, obsColSize, x, y + 1, curX, curY, cmd++);
	if (command[cmd] == 'R')
		return canReach(command, obs, obsRowSize, obsColSize, x + 1, y, curX, curY, cmd++);
	return false;
}

bool isTraped(int** obs, int obsSize, int* obsColSize, int curX, int curY) {
	int* temp = NULL;
	for (int i = 0; i < obsSize; i++) {
		temp = obs[i];
		if (temp[0] == curX && temp[1] == curY) return true;
	}
	return false;
}