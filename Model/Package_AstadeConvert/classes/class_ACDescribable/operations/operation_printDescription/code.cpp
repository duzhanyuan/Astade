//~~ void printDescription(unsigned int indent, AdeModelElement* element) [ACDescribable] ~~
wxString d = element->GetDescription();

if (!d.empty())
{
    printf("\n");
    pIndent(indent);
    printf("description:\n");
    wxStringTokenizer tokenizer(d, wxS("\n"));
    while ( tokenizer.HasMoreTokens() )
    {
        wxString token = tokenizer.GetNextToken();
        pIndent(indent+1);
        token.Replace(wxS("\""),wxS("\\\""));
        printf("\"%s\"",token.mb_str().data());
        if ( tokenizer.HasMoreTokens() )
            printf("\n");
        else
            printf(";\n");
    }
}