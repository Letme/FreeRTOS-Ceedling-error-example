#ifndef TEST_SUPPORT_QUEUE_H
#define TEST_SUPPORT_QUEUE_H

#include "FreeRTOS.h"

struct QueueDefinition; /* Using old naming convention so as not to break kernel aware debuggers. */
typedef struct QueueDefinition * QueueHandle_t;

typedef struct xSTATIC_QUEUE
{
	void *pvDummy1[ 3 ];

	union
	{
		void *pvDummy2;
		UBaseType_t uxDummy2;
	} u;

	StaticList_t xDummy3[ 2 ];
	UBaseType_t uxDummy4[ 3 ];
	uint8_t ucDummy5[ 2 ];

	#if( ( configSUPPORT_STATIC_ALLOCATION == 1 ) && ( configSUPPORT_DYNAMIC_ALLOCATION == 1 ) )
		uint8_t ucDummy6;
	#endif

	#if ( configUSE_QUEUE_SETS == 1 )
		void *pvDummy7;
	#endif

	#if ( configUSE_TRACE_FACILITY == 1 )
		UBaseType_t uxDummy8;
		uint8_t ucDummy9;
	#endif

} StaticQueue_t;

QueueHandle_t xQueueGenericCreateStatic( const UBaseType_t uxQueueLength, const UBaseType_t uxItemSize, uint8_t *pucQueueStorage, StaticQueue_t *pxStaticQueue, const uint8_t ucQueueType );
#define xQueueCreateStatic( uxQueueLength, uxItemSize, pucQueueStorage, pxQueueBuffer ) xQueueGenericCreateStatic( ( uxQueueLength ), ( uxItemSize ), ( pucQueueStorage ), ( pxQueueBuffer ), ( queueQUEUE_TYPE_BASE ) )

#endif