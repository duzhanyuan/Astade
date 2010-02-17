/* vi: set tabstop=4: */

target.SetExt("c");
std::ofstream out(target.GetFullPath().c_str());

wxFileName PrefixName(myAdeComponent->GetFileName());
PrefixName.SetFullName("prolog.cpp");
wxTextFile Gprefixtext(PrefixName.GetFullPath());
if (Gprefixtext.Exists())
	Gprefixtext.Open();
if (Gprefixtext.IsOpened() && Gprefixtext.GetLineCount() > 0)
{
	wxString str;
	for (str = Gprefixtext.GetFirstLine(); !Gprefixtext.Eof(); str = Gprefixtext.GetNextLine())
		out << (const char*)str.c_str() << std::endl;
	if (!str.empty())
		out << (const char*)str.c_str() << std::endl;
	out << std::endl;
}

PrintHeader(out);

PrefixName = source->GetFileName();
PrefixName.SetFullName("prolog.cpp");
wxTextFile prefixtext(PrefixName.GetFullPath());
PrefixName.MakeRelativeTo(wxFileName::GetCwd());

if (prefixtext.Exists())
	prefixtext.Open();
if (prefixtext.IsOpened() && prefixtext.GetLineCount() > 0)
{
	wxString str;
	out << "//****** implementation prolog ******" << std::endl;
	out << "//[" << (const char*)PrefixName.GetFullPath(wxPATH_UNIX).c_str()
		<<   "]" << std::endl;
	for (str = prefixtext.GetFirstLine(); !prefixtext.Eof(); str = prefixtext.GetNextLine())
		out << (const char*)str.c_str() << std::endl;
	if (!str.empty())
		out << (const char*)str.c_str() << std::endl;
	out << "//[EOF]" << std::endl;
	out << "//***********************************" << std::endl;
	out << std::endl;
}

target.SetExt("h");
out << "#include \"" << (const char*)target.GetFullName().c_str();
out << "\"\t // own header" << std::endl;
out << std::endl;

RelationIncludes(out, false);

out << "//****** Trace Macros ***************" << std::endl;
out << "#ifndef NOTIFY_CONSTRUCTOR" << std::endl;
out << "#  define NOTIFY_CONSTRUCTOR(a,b,c)" << std::endl;
out << "#endif" << std::endl;

out << "#ifndef NOTIFY_DESTRUCTOR" << std::endl;
out << "#  define NOTIFY_DESTRUCTOR(a,b)" << std::endl;
out << "#endif" << std::endl;

out << "#ifndef NOTIFY_FUNCTION_CALL" << std::endl;
out << "#  define NOTIFY_FUNCTION_CALL(a,b,c,d,e,f)" << std::endl;
out << "#endif" << std::endl;

out << "#ifndef RETURN" << std::endl;
out << "#  define RETURN(a) return (a)" << std::endl;
out << "#endif" << std::endl;

out << "#ifndef voidRETURN" << std::endl;
out << "#  define voidRETURN return" << std::endl;
out << "#endif" << std::endl << std::endl;

out << "#ifndef LOG" << std::endl;
out << "#  define LOG(...)" << std::endl;
out << "#endif" << std::endl << std::endl;

staticAttribute(out, true, ITEM_IS_PROTECTED);
staticAttribute(out, true, ITEM_IS_PRIVATE);
operations(out, true, false, ITEM_IS_PROTECTED, false);
operations(out, true, false, ITEM_IS_PRIVATE, false);

staticAttribute(out, false, ITEM_IS_PUBLIC);
staticAttribute(out, false, ITEM_IS_PROTECTED);
staticAttribute(out, false, ITEM_IS_PRIVATE);
relationAttribute(out, false);

operations(out, false, false, ITEM_IS_PUBLIC, false);
operations(out, false, false, ITEM_IS_PROTECTED, false);
operations(out, false, false, ITEM_IS_PRIVATE, false);

wxFileName PostfixName(source->GetFileName());
PostfixName.SetFullName("epilog.cpp");
wxTextFile postfixtext(PostfixName.GetFullPath());
PostfixName.MakeRelativeTo(wxFileName::GetCwd());

if (postfixtext.Exists())
	postfixtext.Open();
if (postfixtext.IsOpened() && postfixtext.GetLineCount() > 0)
{
	out << "//****** implementation epilog ******" << std::endl;
	out << "//[" << (const char*)PostfixName.GetFullPath(wxPATH_UNIX).c_str()
		<<   "]" << std::endl;
	wxString str;
	for (str = postfixtext.GetFirstLine(); !postfixtext.Eof(); str = postfixtext.GetNextLine())
		out << (const char*)str.c_str() << std::endl;
	if (!str.empty())
		out << (const char*)str.c_str() << std::endl;
	out << "//[EOF]" << std::endl;
	out << "//***********************************" << std::endl;
}

PostfixName = myAdeComponent->GetFileName();
PostfixName.SetFullName("epilog.cpp");
wxTextFile Gpostfixtext(PostfixName.GetFullPath());
if (Gpostfixtext.Exists())
	Gpostfixtext.Open();
if (Gpostfixtext.IsOpened() && Gpostfixtext.GetLineCount() > 0)
{
	out << std::endl;
	wxString str;
	for (str = Gpostfixtext.GetFirstLine(); !Gpostfixtext.Eof(); str = Gpostfixtext.GetNextLine())
		out << (const char*)str.c_str() << std::endl;
	if (!str.empty())
		out << (const char*)str.c_str() << std::endl;
}

target.SetExt("c");
out.close();
wxDateTime aTime(wxDateTime::Now());
target.SetTimes(&aTime,&aTime,&aTime);