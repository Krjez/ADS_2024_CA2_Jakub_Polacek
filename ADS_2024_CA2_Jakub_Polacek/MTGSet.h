#pragma once

class MTGSet
{
	int baseSetSize;
	string block;
	float cardsphereSetId;
	string code;
	bool isFoilOnly;
	bool isForeignOnly;
	bool isNonFoilOnly;
	bool isOnlineOnly;
	bool isPartialPreview;
	string keyruneCode;
	string languages;
	float mcmId;
	float mcmIdExtras;
	string mcmName;
	string mtgoCode;
	string name;
	string parentCode;
	string releaseDate;
	float tcgplayerGroupId;
	string tokenSetCode;
	int totalSetSize;
	string type;

public:
	MTGSet() {};
	MTGSet(int baseSetSize,	string block, float cardsphereSetId, string code, bool isFoilOnly, bool isForeignOnly, bool isNonFoilOnly, bool isOnlineOnly, bool isPartialPreview, string keyruneCode, string languages, float mcmId, float mcmIdExtras, string mcmName, string mtgoCode, string name, string parentCode, string releaseDate, float tcgplayerGroupId, string tokenSetCode, int totalSetSize, string type);

};


MTGSet::MTGSet(int baseSetSize, string block, float cardsphereSetId, string code, bool isFoilOnly, bool isForeignOnly, bool isNonFoilOnly, bool isOnlineOnly, bool isPartialPreview, string keyruneCode, string languages, float mcmId, float mcmIdExtras, string mcmName, string mtgoCode, string name, string parentCode, string releaseDate, float tcgplayerGroupId, string tokenSetCode, int totalSetSize, string type)
{
	this->baseSetSize = baseSetSize;
	this->block = block;
	this->cardsphereSetId = cardsphereSetId;
	this->code = code;
	this->isFoilOnly = isFoilOnly;
	this->isForeignOnly = isForeignOnly;
	this->isNonFoilOnly = isNonFoilOnly;
	this->isOnlineOnly = isOnlineOnly;
	this->isPartialPreview = isPartialPreview;
	this->keyruneCode = keyruneCode;
	this->languages = languages;
	this->mcmId = mcmId;
	this->mcmIdExtras = mcmIdExtras;
	this->mcmName = mcmName;
	this->mtgoCode = mtgoCode;
	this->name = name;
	this->parentCode = parentCode;
	this->releaseDate = releaseDate;
	this->tcgplayerGroupId = tcgplayerGroupId;
	this->tokenSetCode = tokenSetCode;
	this->totalSetSize = totalSetSize;
	this->type = type;
}
