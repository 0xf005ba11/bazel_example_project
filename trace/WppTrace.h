#pragma once

#define WPP_CONTROL_GUIDS                                                      \
  WPP_DEFINE_CONTROL_GUID(                                                     \
      TracingGuid, (84bdb2e9, 829e, 41b3, b891, 02f454bc2bd7),                 \
      WPP_DEFINE_BIT(TRACE_DRIVER) /* bit  0 = 0x00000001 */                   \
      WPP_DEFINE_BIT(TRACE_DLL)    /* bit  1 = 0x00000002 */                   \
  )

#define WPP_FLAG_LEVEL_LOGGER(flag, level) WPP_LEVEL_LOGGER(flag)

#define WPP_FLAG_LEVEL_ENABLED(flag, level)                                    \
  (WPP_LEVEL_ENABLED(flag) && WPP_CONTROL(WPP_BIT_##flag).Level >= level)

#define WPP_LEVEL_FLAGS_LOGGER(lvl, flags) WPP_LEVEL_LOGGER(flags)

#define WPP_LEVEL_FLAGS_ENABLED(lvl, flags)                                    \
  (WPP_LEVEL_ENABLED(flags) && WPP_CONTROL(WPP_BIT_##flags).Level >= lvl)

//
// This comment block is scanned by the trace preprocessor to define the
// TraceEvents function.
//
// begin_wpp config
// FUNC SYS_TRACE(LEVEL, FLAGS, MSG, ...);
// end_wpp
//
