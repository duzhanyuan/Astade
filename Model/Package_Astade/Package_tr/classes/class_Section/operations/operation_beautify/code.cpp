//~~ void beautify(unsigned int indent) [Section] ~~
for (std::vector< boost::shared_ptr<Trigger> >::iterator it = myWatches.begin(); it != myWatches.end(); it++)
{
    std::cout 
        << std::setw(indent)
        << " "
        << "watch: ";
    (*it)->beautify(indent);
}

if (mTimeout)
    std::cout 
        << std::endl
        << std::setw(indent)
        << " "
        << "timeout("
        << mTimeout
        << ") :"
        << std::endl;

for (std::vector< boost::shared_ptr<Trigger> >::iterator it = myLines.begin(); it != myLines.end(); it++)
{
    std::cout 
        << std::setw(indent+4)
        << " ";
    (*it)->beautify(indent);
}

for (std::vector<std::string>::iterator it = mNameOrder.begin(); it != mNameOrder.end(); it++)
{
    boost::shared_ptr<tr::Section> sub = mySubSections[*it];
    if (indent)
        std::cout << std::setw(indent) << " ";
        
    std::cout 
        << sub->keyword()
        << " "
        << (*it);
        
    if (!sub->mTestNumber.empty())
        std::cout 
            << " [\""
            << sub->mTestNumber
            << "\"]";
        
    std::cout 
        << " {"
        << std::endl;

    sub->beautify(indent + 4);

    std::cout 
        << std::setw(indent)
        << "};"
        << std::endl
        << std::endl;
}