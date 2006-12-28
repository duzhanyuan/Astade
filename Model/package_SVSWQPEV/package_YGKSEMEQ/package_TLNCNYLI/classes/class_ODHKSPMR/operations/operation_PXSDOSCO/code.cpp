//keyboard shortcut
int count = 9;
wxAcceleratorEntry entries[count];
  entries[0].Set(wxACCEL_CTRL,  (int) 'C',     ID_COPY);
  entries[1].Set(wxACCEL_CTRL,  (int) 'V',     ID_PASTE);
  entries[2].Set(wxACCEL_CTRL, (int) 'X',     ID_CUT);
  entries[3].Set(wxACCEL_NORMAL,  WXK_DELETE,  ID_DELETE);
  entries[4].Set(wxACCEL_CTRL, (int) 'G', ID_REGENERATE);
  entries[5].Set(wxACCEL_CTRL, (int) 'A', ID_ACTIVECONFIGURATION);
  entries[6].Set(wxACCEL_NORMAL, WXK_F5, ID_RUN);
  entries[7].Set(wxACCEL_NORMAL, WXK_F6, ID_MAKE);
  entries[8].Set(wxACCEL_NORMAL, WXK_F7, ID_MAKEALL);
  wxAcceleratorTable accel(count, entries);
  this->SetAcceleratorTable(accel);