if (!options.isSet(AdeSearch::Attribute))
	return AdeSearch::notfound;

return AdeFileElement::Search(options);