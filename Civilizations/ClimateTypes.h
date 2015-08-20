#pragma once

#ifndef CLIMATETYPES_H
#define CLIMATETYPES_H


enum ClimateType : unsigned char
{
	clim_unknown	= 0,

	clim_permafrost	= 1,
	clim_tundra		= 2,
	clim_temperate	= 3,
	clim_savanna	= 4,
	clim_tropics	= 5,
	clim_desert		= 6,

	clim_end
};


#endif // CLIMATETYPES_H
