// Class automatically generated by Dev-C++ New Class wizard

#ifndef ASTADETREE_H
#define ASTADETREE_H

#include <wx/window.h>
#include <wx/imaglist.h>
#include <wx/treectrl.h>


class CAstadeTree : public wxTreeCtrl
{

	DECLARE_DYNAMIC_CLASS(CAstadeTree);
	
    public:
        CAstadeTree();
        // class constructor
		CAstadeTree(wxWindow* parent,
                  wxWindowID id, 
                  const wxPoint& pos = wxDefaultPosition, 
                  const wxSize& size = wxDefaultSize, 
                  long style = wxTR_HAS_BUTTONS, 
                  const wxValidator& validator = wxDefaultValidator,
                  const wxString& name = "listCtrl");
		// class destructor
		~CAstadeTree();
        virtual int OnCompareItems(const wxTreeItemId& item1,
                                   const wxTreeItemId& item2);
};

#endif // ASTADETREE_H

