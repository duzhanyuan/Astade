// -*- C++ -*- generated by wxGlade 0.4.1 on Wed Sep 12 07:31:15 2007

#include <wx/wx.h>
#include <wx/image.h>
#include "CodeEditControl.h"

#ifndef GENERATEDFRAME_H
#define GENERATEDFRAME_H

// begin wxGlade: ::dependencies
// end wxGlade


class GeneratedFrame: public wxFrame {
public:
    // begin wxGlade: GeneratedFrame::ids
    enum {
        CANCEL_BUTTON = wxID_HIGHEST + 1000,
        OK_BUTTON = wxID_HIGHEST + 1001
    };
    // end wxGlade

    GeneratedFrame(wxWindow* parent, int id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_FRAME_STYLE);

private:
    // begin wxGlade: GeneratedFrame::methods
    void set_properties();
    void do_layout();
    // end wxGlade

protected:
    // begin wxGlade: GeneratedFrame::attributes
    wxStatusBar* generatedFrame_statusbar;
    CodeEditControl* myEditControl;
    wxPanel* editPanel;
    wxButton* cancel_button;
    wxButton* ok_button;
    wxPanel* buttonPanel;
    // end wxGlade
}; // wxGlade: end class


#endif // GENERATEDFRAME_H
