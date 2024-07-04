#pragma once

#define MODULE_NAME_STRING(STR_NAME) static constexpr auto STR_NAME = MODULE_NAME_XSTRING(STR_NAME)
#define MODULE_NAME_XSTRING(STR_NAME) #STR_NAME

namespace Module {

namespace Name {

MODULE_NAME_STRING(IFACE_MANAGER);
MODULE_NAME_STRING(LAG_MANAGER);
MODULE_NAME_STRING(PORT_MANAGER);

} // namespace Name

} // namespace Module
