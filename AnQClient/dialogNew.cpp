// dialogNew.cpp : implementation file
//

#include "stdafx.h"
#include "TrayCalender.h"
#include "dialogNew.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// dialogNew dialog


dialogNew::dialogNew(CWnd* pParent /*=NULL*/)
	: CDialog(dialogNew::IDD, pParent)
{
	//{{AFX_DATA_INIT(dialogNew)
	m_pass = _T("");
	m_pass2 = _T("");
	m_len = 2048;
	m_name = _T("");
	//}}AFX_DATA_INIT
}


void dialogNew::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(dialogNew)
	DDX_Text(pDX, IDC_EDIT_pass, m_pass);
	DDV_MaxChars(pDX, m_pass, 100);
	DDX_Text(pDX, IDC_EDIT_pass2, m_pass2);
	DDV_MaxChars(pDX, m_pass2, 100);
	DDX_Text(pDX, IDC_EDIT_len, m_len);
	DDV_MinMaxLong(pDX, m_len, 512, 51200000);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDV_MaxChars(pDX, m_name, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(dialogNew, CDialog)
	//{{AFX_MSG_MAP(dialogNew)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// dialogNew message handlers

void dialogNew::OnOK() 
{
	
	UpdateData();	
	if(m_pass2!=m_pass){
		AfxMessageBox("���벻һ��");
		return ;
	}
	if(m_name==""){
		AfxMessageBox("���Ʋ���Ϊ��");
		return;
	}
	if(m_name=="."||m_name==".."||m_name.Find('/')>=0||
		m_name.Find('/')>=0||
		m_name.Find('\\')>=0||
		m_name.Find(':')>=0||
		m_name.Find('*')>=0||
		m_name.Find('?')>=0||
		m_name.Find('\"')>=0||
		m_name.Find('<')>=0||
		m_name.Find('>')>=0||
		m_name.Find('|')>=0
		){
			AfxMessageBox("���Ʋ��淶");
			return;
		}
	CFileFind ff;
	if(ff.FindFile(m_name+".pem")){
		AfxMessageBox("������ͬ���Ƶ�����,��ѡ�����������");
			return;
	}
	
	
		
	CDialog::OnOK();
}

void dialogNew::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
