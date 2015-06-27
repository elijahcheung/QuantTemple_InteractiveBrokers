/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#ifndef common_defs_h_INCLUDED
#define common_defs_h_INCLUDED

typedef long TickerId;
typedef long OrderId;

enum faDataType { GROUPS=1, PROFILES, ALIASES } ;

inline const char* faDataTypeStr ( faDataType pFaDataType )
{
	switch (pFaDataType) {
		case GROUPS:
			return "GROUPS" ;
			break ;
		case PROFILES:
			return "PROFILES" ;
			break ;
		case ALIASES:
			return "ALIASES" ;
			break ;
	}
	return 0 ;
}

enum MarketDataType { 
	REALTIME = 1, 
	FROZEN = 2
};

#endif /* common_defs_h_INCLUDED */
