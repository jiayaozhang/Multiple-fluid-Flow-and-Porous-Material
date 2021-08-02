
#include "ObjReader.h"
#include <sstream>
#include <fstream>
using namespace std;


void PIC::ReadPIC(string filename)
{
	minPos.X = 10;
	minPos.Y = 10;
	minPos.Z = 10;
	maxPos.X = -10;
	maxPos.Y = -10;
	maxPos.Z = -10;

	ifstream ifs(filename);//cube bunny Eight
	string s;
	Mian *f;
	POINT3 *v;
	FaXiangLiang *vn;
	WenLi    *vt;
	while (getline(ifs, s))
	{
		if (s.length()<2)continue;
		if (s[0] == 'v') {
			if (s[1] == 't') {//vt 0.581151 0.979929 纹理
				istringstream in(s);
				vt = new WenLi();
				string head;
				in >> head >> vt->TU >> vt->TV;
				VT.push_back(*vt);
			}
			else if (s[1] == 'n') {//vn 0.637005 -0.0421857 0.769705 法向量
				istringstream in(s);
				vn = new FaXiangLiang();
				string head;
				in >> head >> vn->NX >> vn->NY >> vn->NZ;
				VN.push_back(*vn);
			}
			else {//v -53.0413 158.84 -135.806 点
				istringstream in(s);
				v = new POINT3();
				string head;
				in >> head >> v->X >> v->Y >> v->Z;
				if (minPos.X > v->X)minPos.X = v->X;
				if (minPos.Y > v->Y)minPos.Y = v->Y;
				if (minPos.Z > v->Z)minPos.Z = v->Z;
				if (maxPos.X < v->X)maxPos.X = v->X;
				if (maxPos.Y < v->Y)maxPos.Y = v->Y;
				if (maxPos.Z < v->Z)maxPos.Z = v->Z;
				V.push_back(*v);
			}
		}
		else if (s[0] == 'f') {//f 2443//2656 2442//2656 2444//2656 面
			for (int k = s.size() - 1; k >= 0; k--) {
				if (s[k] == '/')s[k] = ' ';
			}
			istringstream in(s);
			f = new Mian();
			string head;
			in >> head;
			int i = 0;
			while (i<3)
			{
				if (V.size() != 0)
				{
					in >> f->V[i];
					f->V[i] -= 1;
				}
				if (VT.size() != 0)
				{
					in >> f->T[i];
					f->T[i] -= 1;
				}
				if (VN.size() != 0)
				{
					in >> f->N[i];
					f->N[i] -= 1;
				}
				i++;
			}
			F.push_back(*f);
		}
	}
}
void PIC::MapSimulateScale(float simscale)
{
	minPos.X /= simscale;
	minPos.Y /= simscale;
	minPos.Z /= simscale;
	maxPos.X /= simscale;
	maxPos.Y /= simscale;
	maxPos.Z /= simscale;
	for (int i = 0; i < V.size(); ++i)
	{
		V[i].X /= simscale;
		V[i].Y /= simscale;
		V[i].Z /= simscale;
	}
	printf("model's min pos is (%f,%f,%f),max pos is (%f,%f,%f)\n",
		minPos.X, minPos.Y, minPos.Z, maxPos.X, maxPos.Y, maxPos.Z);
}