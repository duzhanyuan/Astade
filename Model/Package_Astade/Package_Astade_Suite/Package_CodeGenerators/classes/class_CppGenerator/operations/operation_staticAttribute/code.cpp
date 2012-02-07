//~~ void staticAttribute(std::ofstream& out, bool spec, int visibility) [CppGenerator] ~~

std::set<const AdeAttribute*, AdeElementCompare> attrs;

wxFileName attributes(source->GetFileName());
attributes.AppendDir(wxS("attributes"));

if (wxDir::Exists(attributes.GetPath()))
{
	wxDir dir(attributes.GetPath());
	wxString filename;

	bool cont = dir.GetFirst(&filename, wxS("*.ini"));
	while (cont)
	{
		wxFileName FullName(attributes);
		FullName.SetFullName(filename);
		const AdeModelElement* pe = AdeModelElement::CreateNewElement(FullName);
		if ((pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_ATTRIBUTE &&
			(pe->GetType() & visibility) == visibility)
		{
			const AdeAttribute* pa = dynamic_cast<const AdeAttribute*>(pe);
			assert(pa);
            if (pa->IsStatic())
				attrs.insert(pa);
			else
				delete pa;
		}
		else
			delete pe;
		cont = dir.GetNext(&filename);
	}
}

std::set<const AdeAttribute*>::iterator it;

for (it = attrs.begin(); it != attrs.end(); ++it)
{
	const AdeAttribute* pa = *it;
	if (spec)
	{
		out << "/** "
			<< (const char*)pa->GetDescription().c_str()
			<< std::endl;
		if (pa->IsDeprecated())
			out << "@deprecated "
				<< (const char*)pa->GetDeprecatedDesc().c_str()
				<< std::endl;
		out << "*/"
			<< std::endl;

		out << "\tstatic ";
		if (pa->IsConst())
			out << "const ";
		out << (const char*)pa->GetCodingType().c_str()
			<< "\t"
			<< (const char*)pa->GetName().c_str();

		if (pa->IsDeprecated())
			out << " __attribute__ ((deprecated))";

		out << ";"
			<< std::endl;
	}
	else
	{
		if (pa->IsConst())
			out << "const ";
		out << (const char*)pa->GetCodingType().c_str()
			<< "\t"
			<< (const char*)getNamespace(source->getNamespace()).c_str()
			<< (const char*)source->GetName().c_str()
			<< "::"
			<< (const char*)pa->GetName().c_str();
		wxString Default(pa->GetDefault());
		if (!Default.empty())
			out << " = "
				<< (const char*)Default.c_str();
		out << ";"
			<< std::endl;
	}
	out << std::endl;
	delete pa;
}
