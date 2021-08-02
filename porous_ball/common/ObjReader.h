#pragma once
#include<vector>
using namespace std;
struct POINT3 {
	double X;
	double Y;
	double Z;
};
struct WenLi {
	double TU;
	double TV;
};
struct FaXiangLiang {
	double NX;
	double NY;
	double NZ;
};
struct Mian {
	int V[3];
	int T[3];
	int N[3];
};
class PIC
{

public:
	vector<POINT3> V;//V�������㡣��ʽΪV X Y Z��V�����X Y Z��ʾ�����������ꡣ������
	vector<WenLi>  VT;//��ʾ�������ꡣ��ʽΪVT TU TV��������
	vector<FaXiangLiang> VN;//VN����������ÿ�������ε��������㶼Ҫָ��һ������������ʽΪVN NX NY NZ��������
	vector<Mian> F;//F���档�������ŵ�����ֵ�ֱ������������Ķ��㡢�������ꡢ��������������
				   //��ĸ�ʽΪ��f Vertex1/Texture1/Normal1 Vertex2/Texture2/Normal2 Vertex3/Texture3/Normal3
	void ReadPIC(string filename);
	void MapSimulateScale(float simscale);
	POINT3 minPos;
	POINT3 maxPos;
};
