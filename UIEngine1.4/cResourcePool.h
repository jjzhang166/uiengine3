#pragma once
#include<map>
#include<string>
#include<vector>
#include<memory>

namespace MyEngine
{
	/*
	*class cResourcePool
	*��Դ�أ�����ͳһ��Ų�����GDI��Դ�������ʡ�ڴ�����Ч��
	*��Ҫ��ͼ�½�����Ķ��󣬶�Ҫͨ��GetResourcePool()��ȡ�������
	*/
	class cResourcePool
	{
	public:
		/*
		*GetResourcePool();
		*��ȡ��Դ�ض���
		*@return cResourcePool*����������ָ��
		*/
		static cResourcePool* GetResourcePool();

		/*
		*AddObjByKey(std::string, const HGDIOBJ& hobj);
		*ͨ��keyֵ���HGDIOBJ����
		*@Param key��keyֵ
		*@Param hobj��Ҫ�洢����Դ���
		*/
		void AddObjByKey(std::string key, const HGDIOBJ& hobj);

		/*
		*AddMulObjByKey(std::string, const std::list<HGDIOBJ> hobjList);
		*ͨ��keyֵ��Ӵ�����Դ���
		*@Param key��keyֵ
		*@Param hobjList����Դ����б�
		*/
		void AddMulObjByKey(std::string key, const std::vector<HGDIOBJ> hobjList);

		/*
		*GethObjByKey(std::string key);
		*ͨ��keyֵ��ȥGDI����
		*@Param key��keyֵ
		*@return HGDIOBJ�������ڷ���NULL�������򷵻���Ӧ��GDI����
		*/
		HGDIOBJ GethObjByKey(std::string key);

		/*
		*GetMulObjByKey(std::string);
		*ͨ��keyֵ��ȡ������Դ���
		*@Param key��keyֵ
		*@return ��Դ����б�
		*/
		std::vector<HGDIOBJ> GetMulObjByKey(std::string key);

		/*
		*ReleaseByKey(std::string key);
		*�ͷ�ָ��keyֵ����Դ���
		*/
		bool ReleaseByKey(std::string key);
		
		void ReleaseSelf();
	private:
		cResourcePool();
		~cResourcePool();

		std::map<std::string, HGDIOBJ> m_pool;

		std::map<std::string, std::vector<HGDIOBJ>> m_mulPool;
	};
}

