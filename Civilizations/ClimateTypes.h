#pragma once

#ifndef CLIMATETYPES_H
#define CLIMATETYPES_H


enum ClimateType : unsigned char
{
	clim_unknown	= 0,

	clim_glacier	= 1,
	clim_permafrost	= 2,
	clim_tundra		= 3,
	clim_temperate	= 4,
	clim_savanna	= 5,
	clim_tropics	= 6,
	clim_desert		= 7,

	clim_end
};


#endif // CLIMATETYPES_H
