#pragma once
#include"cIDDialogBase.h"

enum Quit_Status
{
	Quit_OK,
	Quit_Cancel,
};

class cSelectRowRank:public cIDDialogBase
{
public:
	cSelectRowRank(const UINT& IDD, HINSTANCE hInst = NULL, HWND hPWnd = NULL);

	~cSelectRowRank();

	void SetRow(const unsigned& row);

	void SetRank(const unsigned& rank);

	void SetTerrianSpecies(const unsigned TerrianSpecies);

	const unsigned& GetTerrianSpecies() const;

	const unsigned& GetRow() const;

	const unsigned& GetRank() const;

	virtual void Show() override;

	virtual bool initDialog(HWND hWnd) override;

	void AddItemToComBox();

	void SetQuitStatus(const Quit_Status& status);

	const Quit_Status& GetStatus();
private:
	unsigned m_row;

	unsigned m_rank;

	unsigned m_terrianSpecies;
	
	Quit_Status m_quitStatus;
};