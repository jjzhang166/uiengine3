��UI�����Ƕ�win32API��һ����װ�ǳ��ʺ϶�win32API����Ϥ������Ҫʹ��win32API��̵Ŀ���ʹ�á�

class cGameEngine������������Ҫ�����UI����Ĺ���ͨ�����������ڽ����ϴ�������UIԪ�أ�������UIԪ�ء�
��˵����ֻ�Ǽ�˵������������ã���ϸ˵����ʹ�÷����ɲ鿴��ĿԴ����

/*
cBaseUI
����UI��Ļ���
*/
class cBaseUI   

/*
cAmination
����Ԫ�ؼ̳���cBaseUI
*/
class cAmination:public cBaseUI

/*
cButton
��ťԪ�ؼ̳���cBaseUI
*/
class cButton :public cBaseUI

/*
cCircle
ԲԪ�ؼ̳���cBaseUI
*/
class cCircle:public cBaseUI

/*
cLine
ֱ��Ԫ�ؼ̳���cBaseUI
*/
class cLine:public cBaseUI

/*
cMyTimer
��ʱ����
*/
class cMyTimer

/*
cPicture
ͼƬԪ�ؼ̳���cBaseUI
*/
class cPicture:public cBaseUI

/*
Polygon
�Ա���Ԫ�ؼ̳���cBaseU
���ݶ���λ���ѭ�����������γɶ����
*/
class cPolygon:public cBaseUI

/*
cRectangle
����Ԫ�ؼ̳���cBaseU
*/
class cRectangle:public cBaseUI

/*
cText
�ı�Ԫ�ؼ̳���cBaseU
*/
class cText:public cBaseUI

/*
cTriangle
������Ԫ�ؼ̳���cBaseU
*/
class cTriangle:public cBaseUI