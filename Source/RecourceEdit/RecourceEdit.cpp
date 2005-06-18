//---------------------------------------------------------------------------
//
// Name:        RecourceEdit.cpp
// Author:      
// Created:     25.04.2005 19:19:46
// Copyright:
//
//---------------------------------------------------------------------------

#ifdef __GNUG__
    #pragma implementation "RecourceEdit.cpp"
#endif

/* for compilers that support precompilation
   includes "wx/wx.h" */

#include "wx/wxprec.h"
#include "../treeview/AstadeDef.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif


#include "RecourceEdit.h"

////Header Include Start
////Header Include End



//----------------------------------------------------------------------------
// RecourceEdit
//----------------------------------------------------------------------------

    ////Event Table Start
    BEGIN_EVENT_TABLE(RecourceEdit,wxDialog)

    EVT_CLOSE(RecourceEdit::RecourceEditClose)
	EVT_INIT_DIALOG(RecourceEdit::InitDialog)
	EVT_BUTTON(ID_CANCEL,RecourceEdit::Cancel)
	EVT_BUTTON(ID_SAVEANDEXIT,RecourceEdit::Save)
    EVT_CHECKBOX(ID_VIRTUAL, RecourceEdit::UncheckStatic)
    EVT_CHECKBOX(ID_STATIC, RecourceEdit::UncheckVirtual)
    	
    END_EVENT_TABLE()
    ////Event Table End



RecourceEdit::RecourceEdit( wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style )
    : wxDialog( parent, id, title, position, size, style)
{
    CreateGUIControls();
}

RecourceEdit::~RecourceEdit()
{
    
} 

void RecourceEdit::CreateGUIControls(void)
{
	this->SetSize(8,8,506,483);
	this->SetTitle(_("Recource Edit"));
	this->Center();
}

void RecourceEdit::Cancel(wxCommandEvent& event)
{
    Destroy();
}

void RecourceEdit::UncheckStatic(wxCommandEvent& event)
{
    if (VirtualField && StaticField)
        if (VirtualField->IsChecked())
            StaticField->SetValue(false); 
}

void RecourceEdit::UncheckVirtual(wxCommandEvent& event)
{
    if (VirtualField && StaticField)
        if (StaticField->IsChecked())
            VirtualField->SetValue(false); 
}

void RecourceEdit::Save(wxCommandEvent& event)
{
    if (NameEditField)
    {
        wxString theName = NameEditField->GetValue();
        theName.Replace(" ","_");
        
        if (theName.size()==0)
            theName = "JohnDoe";
        wxWriteResource("Astade","Name",theName,file);
    }
        
    if (TypeEditField)
    {
        wxString theName = TypeEditField->GetValue();
        wxWriteResource("Astade","CodingType",theName,file);
    }
        
    if (ConstField)
    {
        if (ConstField->IsChecked())
            wxWriteResource("Astade","Const","yes",file);
        else
            wxWriteResource("Astade","Const","no",file);
    }
        
    if (VirtualField)
    {
        if (VirtualField->IsChecked())
            wxWriteResource("Astade","Virtual","yes",file);
        else
            wxWriteResource("Astade","Virtual","no",file);
    }
        
    if (StaticField)
    {
        if (StaticField->IsChecked())
            wxWriteResource("Astade","Static","yes",file);
        else
            wxWriteResource("Astade","Static","no",file);
    }
        
    if (m_private)
    {
        if (m_private->GetValue())    
        {
            m_iType |= ITEM_IS_PRIVATE;
            m_iType &= ~ITEM_IS_PROTECTED; 
            m_iType &= ~ITEM_IS_PUBLIC; 
        }
        else
        if (m_public->GetValue())    
        {
            m_iType &= ~ITEM_IS_PRIVATE;
            m_iType &= ~ITEM_IS_PROTECTED; 
            m_iType |= ITEM_IS_PUBLIC; 
        }
        else
        if (m_protected->GetValue())    
        {
            m_iType &= ~ITEM_IS_PRIVATE;
            m_iType |= ITEM_IS_PROTECTED; 
            m_iType &= ~ITEM_IS_PUBLIC; 
        }    
    }    

    wxWriteResource("Astade","Type",m_iType,file);
    Destroy();
}

void RecourceEdit::RecourceEditClose(wxCloseEvent& event)
{
    // --> Don't use Close with a wxDialog,
    // use Destroy instead.
    Destroy();
}

void RecourceEdit::InitDialog(wxInitDialogEvent& event)
{
    m_iType = 0;
	new wxButton(this, ID_CANCEL, _("cancel") , wxPoint(25,422),wxSize(100,32) );
	
	myBitmap =  new wxStaticBitmap(this, ID_THEBITMAP, wxNullBitmap, wxPoint(25,15),wxSize(48,48) );
	
    if ((file.size()>0) && (wxGetResource("Astade","Type",&m_iType,file)))
	{
        new wxButton(this, ID_SAVEANDEXIT, _("Save and Exit") , wxPoint(388,422),wxSize(100,32) );

    	switch (m_iType&0xfff00000)
    	{
             case ITEM_IS_CLASS:         myBitmap->SetBitmap(wxIcon("ICO05",wxBITMAP_TYPE_ICO_RESOURCE));break;
             case ITEM_IS_COMPONENT:     myBitmap->SetBitmap(wxIcon("ICO06",wxBITMAP_TYPE_ICO_RESOURCE));break;
             case ITEM_IS_ATTRIBUTE:     myBitmap->SetBitmap(wxIcon("ICO07",wxBITMAP_TYPE_ICO_RESOURCE));break;
             case ITEM_IS_PARAMETER:     myBitmap->SetBitmap(wxIcon("ICO17",wxBITMAP_TYPE_ICO_RESOURCE));break;
             case ITEM_IS_OPERATION:     
                 if (m_iType & ITEM_IS_NORMALOP)
                     //Normal Operation
                     myBitmap->SetBitmap(wxIcon("ICO08",wxBITMAP_TYPE_ICO_RESOURCE));
                 else
                 if (m_iType & ITEM_IS_DEST)
                     //Destructor
                     myBitmap->SetBitmap(wxIcon("ICO23",wxBITMAP_TYPE_ICO_RESOURCE));
                 else
                     //Constructor
                     myBitmap->SetBitmap(wxIcon("ICO20",wxBITMAP_TYPE_ICO_RESOURCE));
                 break;
             default: myBitmap->SetBitmap(wxIcon("ICO00",wxBITMAP_TYPE_ICO_RESOURCE));
        }    
    }
    else
    {
    	myBitmap->SetBitmap(wxIcon("ICO00",wxBITMAP_TYPE_ICO_RESOURCE));
    }  

    char* hp;

    if ((file.size()>0) && (wxGetResource("Astade","Const",&hp,file)))
	{
    	m_oName = hp;
	    ConstField =  new wxCheckBox(this, ID_CONST, _("const") , wxPoint(25,58),wxSize(80,32) );
	    ConstField->SetValue(m_oName=="yes");
    } 
	else 
	    ConstField = NULL;
     
    if ((file.size()>0) && (wxGetResource("Astade","Virtual",&hp,file)))
	{
    	m_oName = hp;
	    VirtualField =  new wxCheckBox(this, ID_VIRTUAL, _("virtual") , wxPoint(105,58),wxSize(80,32) );
	    VirtualField->SetValue(m_oName=="yes");
    } 
	else 
	    VirtualField = NULL;
     
    if ((file.size()>0) && (wxGetResource("Astade","Static",&hp,file)))
	{
    	m_oName = hp;
	    StaticField =  new wxCheckBox(this, ID_STATIC, _("static") , wxPoint(185,58),wxSize(80,32) );
	    StaticField->SetValue(m_oName=="yes");
    } 
	else 
	    StaticField = NULL;
     
    if ((file.size()>0) && (wxGetResource("Astade","Name",&hp,file)))
	{
    	m_oName = hp;
        NameEditField =  new wxTextCtrl(this, ID_NAMEEDITFIELD, m_oName , wxPoint(100,12),wxSize(375,21) );
	    NameEditField->SetMaxLength(128);
        if ((m_iType & ITEM_IS_NORMALOP)==0) 
            NameEditField->SetEditable(false);
	    (new wxStaticText(this, ID_NAME ,_("name:") ,wxPoint(60,12)))->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
	}
	else 
	    NameEditField = NULL;
               
    if ((file.size()>0) && (wxGetResource("Astade","CodingType",&hp,file)))
	{
    	m_oCodingType = hp;
        TypeEditField =  new wxTextCtrl(this, ID_NAMEEDITFIELD, m_oCodingType , wxPoint(100,33),wxSize(375,21) );
	    TypeEditField->SetMaxLength(128);
	    (new wxStaticText(this, ID_TYPE ,_("type:") ,wxPoint(60,33)))->SetFont(wxFont(10, wxSWISS ,wxNORMAL,wxNORMAL,FALSE));
	}
	else 
	    TypeEditField = NULL;

    if ((m_iType&ITEM_IS_PRIVATE)||
        (m_iType&ITEM_IS_PROTECTED)||
        (m_iType&ITEM_IS_PUBLIC))
    {
    	m_private =  new wxRadioButton(this, ID_M_PRIVATE ,_("private") ,wxPoint(266,58),wxSize(80,32) );
    	m_protected =  new wxRadioButton(this, ID_M_PROTECTED ,_("protected") ,wxPoint(346,58),wxSize(80,32) );
    	m_public =  new wxRadioButton(this, ID_M_PUBLIC ,_("public") ,wxPoint(426,58),wxSize(80,32) );
    
        if (m_iType&ITEM_IS_PRIVATE)
        {
            m_private->SetValue(true);
            m_protected->SetValue(false);
            m_public->SetValue(false);
        }
        else    
        if (m_iType&ITEM_IS_PROTECTED)
        {
            m_private->SetValue(false);
            m_protected->SetValue(true);
            m_public->SetValue(false);
        }
        else    
        if (m_iType&ITEM_IS_PUBLIC)
        {
            m_private->SetValue(false);
            m_protected->SetValue(false);
            m_public->SetValue(true);
        }
    } 
    else
    {
        m_private = NULL;
        m_protected = NULL;
        m_public = NULL;
    }       
               
   	myBitmap->Enable(true);
}

 
