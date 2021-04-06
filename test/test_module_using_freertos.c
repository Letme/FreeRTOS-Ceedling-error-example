#include "unity.h"

#include "mock_queue.h"

#include "module_using_freertos.h"

module_handle_t module;
static uint32_t module_queue_data[MODULE_QUEUE_DEPTH];

void test_init()
{
    xQueueCreateStatic_ExpectAndReturn(MODULE_QUEUE_DEPTH, sizeof(uint32_t), module_queue_data, &module, module->handle);
    module_init(module_queue_data, &module);
}
