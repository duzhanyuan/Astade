fprintf(specificationFile,"\t\t//! \\brief The pointer, holding the actuel state.\n");
fprintf(specificationFile,"\t\tvoid ( %s::* theState )( const %s& );\n\n",theStatechart.GetName().c_str(),theStatechart.GetEventType().c_str());