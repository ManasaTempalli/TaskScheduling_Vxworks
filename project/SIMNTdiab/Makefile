# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))
WRVX_COMPBASE := $(subst \,/,$(WRVX_COMPBASE))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

JOBS?=1
TARGET_JOBS?=$(JOBS)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = SIMNTdiab
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/WindRiver/workspace
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/AssignmentRTS



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = simpc
CPU = SIMNT
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tX86LH:vxworks69
VSB_DIR = $(WIND_BASE)/target/lib
VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 

IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\"   



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
DEBUGFLAGS_Linker = -XO -Xsize-opt
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif


#Project Targets
PROJECT_TARGETS = AssignmentRTS/$(MODE_DIR)/AssignmentRTS.out \
	 AssignmentRTS_partialImage/$(MODE_DIR)/AssignmentRTS_partialImage.o


#Rules

# AssignmentRTS
ifeq ($(DEBUG_MODE),1)
AssignmentRTS/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
AssignmentRTS/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
AssignmentRTS/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
AssignmentRTS/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
AssignmentRTS/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
AssignmentRTS/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
AssignmentRTS/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
AssignmentRTS/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
AssignmentRTS/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
AssignmentRTS/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
AssignmentRTS/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
AssignmentRTS/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
AssignmentRTS/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
AssignmentRTS/$(MODE_DIR)/% : IDE_LIBRARIES = 
AssignmentRTS/$(MODE_DIR)/% : IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\"   
AssignmentRTS/$(MODE_DIR)/% : PROJECT_TYPE = DKM
AssignmentRTS/$(MODE_DIR)/% : DEFINES = 
AssignmentRTS/$(MODE_DIR)/% : EXPAND_DBG = 0
AssignmentRTS/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
AssignmentRTS/$(MODE_DIR)/% : CPU = SIMNT
AssignmentRTS/$(MODE_DIR)/% : TOOL_FAMILY = diab
AssignmentRTS/$(MODE_DIR)/% : TOOL = diab
AssignmentRTS/$(MODE_DIR)/% : TOOL_PATH = 
AssignmentRTS/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks69
AssignmentRTS/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
AssignmentRTS/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
AssignmentRTS/$(MODE_DIR)/% : LIBPATH = 
AssignmentRTS/$(MODE_DIR)/% : LIBS = 
AssignmentRTS/$(MODE_DIR)/% : OBJ_DIR := AssignmentRTS/$(MODE_DIR)

OBJECTS_AssignmentRTS = AssignmentRTS_partialImage/$(MODE_DIR)/AssignmentRTS_partialImage.o

ifeq ($(TARGET_JOBS),1)
AssignmentRTS/$(MODE_DIR)/AssignmentRTS.out : $(OBJECTS_AssignmentRTS)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_AssignmentRTS) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c pentium -tags $(VSB_DIR)/tags/simpc/SIMNT/common/dkm.tags > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -ei1518,4177,4223,4301,4550,5409,1606 -ei4193,4826,4381,4237,1573,4007,4082,4177,4223,4260,4550,5361,5828 -ei1522,4092,4111,4144,4152,4167,4171,4174,4186,4188,4191,4192,4223,4231,4236,4284,4375,4494,4513,5152,5457 -Xforce-declarations  $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES)  $(IDE_DEFINES) $(DEFINES) -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tX86LH:vxworks69 -X -r5 -f 0x90,1,1 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_AssignmentRTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

else
AssignmentRTS/$(MODE_DIR)/AssignmentRTS.out : AssignmentRTS/$(MODE_DIR)/AssignmentRTS.out_jobs

endif
AssignmentRTS/$(MODE_DIR)/AssignmentRTS_compile_file : $(FILE) ;

_clean :: AssignmentRTS/$(MODE_DIR)/AssignmentRTS_clean

AssignmentRTS/$(MODE_DIR)/AssignmentRTS_clean : 
	$(TRACE_FLAG)if [ -d "AssignmentRTS" ]; then cd "AssignmentRTS"; rm -rf $(MODE_DIR); fi


# AssignmentRTS_partialImage
ifeq ($(DEBUG_MODE),1)
AssignmentRTS_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
AssignmentRTS_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
AssignmentRTS_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
AssignmentRTS_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
AssignmentRTS_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
AssignmentRTS_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
AssignmentRTS_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
AssignmentRTS_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
AssignmentRTS_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
AssignmentRTS_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
AssignmentRTS_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
AssignmentRTS_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
AssignmentRTS_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
AssignmentRTS_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
AssignmentRTS_partialImage/$(MODE_DIR)/% : IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\"   
AssignmentRTS_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
AssignmentRTS_partialImage/$(MODE_DIR)/% : DEFINES = 
AssignmentRTS_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
AssignmentRTS_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = simpc
AssignmentRTS_partialImage/$(MODE_DIR)/% : CPU = SIMNT
AssignmentRTS_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
AssignmentRTS_partialImage/$(MODE_DIR)/% : TOOL = diab
AssignmentRTS_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
AssignmentRTS_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:vxworks69
AssignmentRTS_partialImage/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
AssignmentRTS_partialImage/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
AssignmentRTS_partialImage/$(MODE_DIR)/% : LIBPATH = 
AssignmentRTS_partialImage/$(MODE_DIR)/% : LIBS = 
AssignmentRTS_partialImage/$(MODE_DIR)/% : OBJ_DIR := AssignmentRTS_partialImage/$(MODE_DIR)

AssignmentRTS_partialImage/$(MODE_DIR)/Objects/AssignmentRTS/sortrts.o : $(PRJ_ROOT_DIR)/sortrts.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xsystem-headers-warn -ei1518,4177,4223,4301,4550,5409,1606 -ei4193,4826,4381,4237,1573,4007,4082,4177,4223,4260,4550,5361,5828 -ei1522,4092,4111,4144,4152,4167,4171,4174,4186,4188,4191,4192,4223,4231,4236,4284,4375,4494,4513,5152,5457 -Xforce-declarations   -Xmake-dependency=0xd $(IDE_DEFINES) $(DEFINES) $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


OBJECTS_AssignmentRTS_partialImage = AssignmentRTS_partialImage/$(MODE_DIR)/Objects/AssignmentRTS/sortrts.o

ifeq ($(TARGET_JOBS),1)
AssignmentRTS_partialImage/$(MODE_DIR)/AssignmentRTS_partialImage.o : $(OBJECTS_AssignmentRTS_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tX86LH:vxworks69 -X -r5 -f 0x90,1,1  -o "$@" $(OBJECTS_AssignmentRTS_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

else
AssignmentRTS_partialImage/$(MODE_DIR)/AssignmentRTS_partialImage.o : AssignmentRTS_partialImage/$(MODE_DIR)/AssignmentRTS_partialImage.o_jobs

endif
AssignmentRTS_partialImage/$(MODE_DIR)/AssignmentRTS_partialImage_compile_file : $(FILE) ;

_clean :: AssignmentRTS_partialImage/$(MODE_DIR)/AssignmentRTS_partialImage_clean

AssignmentRTS_partialImage/$(MODE_DIR)/AssignmentRTS_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "AssignmentRTS_partialImage" ]; then cd "AssignmentRTS_partialImage"; rm -rf $(MODE_DIR); fi

force : 

TARGET_JOBS_RULE?=echo update makefile template
%_jobs : 
	$(TRACE_FLAG)$(TARGET_JOBS_RULE)

DEP_FILES := AssignmentRTS_partialImage/$(MODE_DIR)/Objects/AssignmentRTS/sortrts.d
-include $(DEP_FILES)


WIND_SCOPETOOLS_BASE := $(subst \,/,$(WIND_SCOPETOOLS_BASE))

clean_scopetools :
	$(TRACE_FLAG)rm -rf $(PRJ_ROOT_DIR)/.coveragescope/db

CLEAN_STEP := clean_scopetools


-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

TARGET_JOBS_RULE=$(MAKE) -f $(MAKEFILE) --jobs $(TARGET_JOBS) $(MFLAGS) $* TARGET_JOBS=1
ifeq ($(JOBS),1)
main_all : external_build  $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"
else
main_all : external_build 
	@$(MAKE) -f $(MAKEFILE) --jobs $(JOBS) $(MFLAGS) $(PROJECT_TARGETS) TARGET_JOBS=1;\
	echo "make: built targets of `pwd`"
endif 

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
