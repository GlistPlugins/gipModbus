cmake_minimum_required (VERSION 3.10.2)

#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -DENABLE_MODBUSPP_LOGGING")
#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -DENABLE_MODBUSPP_LOGGING")


##### PLUGIN NAME #####
set(pluginname gipModbus)


##### PLUGIN PATHS #####
set(PLUGIN_DIR ${PLUGINS_DIR}/${pluginname})
set(PLUGIN_LIBS_DIR ${PLUGIN_DIR}/libs)


##### PLUGIN SOURCES #####
list(APPEND PLUGIN_SRCS
			${PLUGIN_DIR}/src/gipModbus.cpp
)


##### PLUGIN HEADERS #####
list(APPEND PLUGIN_INCLUDES
			${PLUGIN_DIR}/src
			${PLUGIN_LIBS_DIR}/include
)


##### PLUGIN DEPENDENCY LOCATIONS (IF ANY) #####
if(WIN32)
	list(APPEND PLUGIN_LINKDIRS
				${PLUGIN_LIBS_DIR}/lib/win32
				${PLUGIN_LIBS_DIR}/bin
	)
	
	#set(PLUGIN_LIBDIRS ${PLUGIN_LIBS_DIR}/lib/win32)
	list(APPEND PLUGIN_LIBDIRS
				${PLUGIN_LIBS_DIR}/lib/win32
	)
elseif(LINUX)
	#Linux libs here
elseif(APPLE)
	#Macos libs here
endif(WIN32)


##### PLUGIN DEPENDENCY LINKING (IF ANY) #####					
if(WIN32)
	list(APPEND PLUGIN_LINKLIBS
				#Lib names
				ws2_32
	)
elseif(LINUX)
	list(APPEND PLUGIN_LINKLIBS
				#Lib names
	)
elseif(APPLE)
	list(APPEND PLUGIN_LINKLIBS
				#Lib names
	)
endif(WIN32)
