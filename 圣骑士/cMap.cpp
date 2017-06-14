#include "stdafx.h"
#include "cMap.h"
#include<iostream>
#include<fstream>
#include<exception>
using namespace std;

cMap::cMap():m_row(0),m_rank(0)
{
	m_MapInfo = nullptr;
}


cMap::cMap(const int & row, const int & rank)
{
	AllocMemory(row, rank);
}

cMap::~cMap()
{
	if (m_MapInfo)
	{
		FreeMemory(m_row, m_rank);
	}
}

void cMap::SetMap(const int & row, const int & rank)
{
	if (m_MapInfo)
	{
		FreeMemory(m_row, m_rank);
	}
	AllocMemory(row, rank);
}

Map_type & cMap::at(const int & row, const int & rank)
{
	return m_MapInfo[row][rank];
}

void cMap::SetMapInfoAt(const int & row, const int & rank, Map_type type)
{
		m_MapInfo[row][rank] = type;
}

bool cMap::LoadMapFromFile(const std::string& fileName)
{
	std::ifstream in(fileName, ios::in);
	if (!in)
	{
		return false;
	}
	int row = 0;
	int rank = 0;
	int terrianSpecies = 0;
	in >> row;
	in >> rank;
	in >> terrianSpecies;
	SetMap(row, rank);
	for (size_t i = 0; i <row; ++i)
	{
		for (size_t j = 0; j < rank; ++j)
		{
			int tmp;
			in >> tmp;
			m_MapInfo[i][j]=static_cast<Map_type>(tmp);
		}
	}
	in.close();
	return true;
}

const int & cMap::GetRow() const
{
	return m_row;
}

const int & cMap::GetRank() const
{
	return m_rank;
}

void cMap::AllocMemory(const int & row, const int & rank) noexcept
{
	m_MapInfo = new Map_type*[row];
	for (size_t i = 0; i < row; ++i)
	{
		m_MapInfo[i] = new Map_type[rank];
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < rank; ++j)
		{
			m_MapInfo[i][j] = Type_Brick;
		}
	}
	m_row = row;
	m_rank = rank;
}

void cMap::FreeMemory(const int & row, const int & rank) noexcept
{
	for (size_t i = 0; i < m_row; ++i)
	{
		delete[] m_MapInfo[i];
		m_MapInfo[i] = nullptr;
	}
	delete m_MapInfo;
	m_MapInfo = nullptr;
}
