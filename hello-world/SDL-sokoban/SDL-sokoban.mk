##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=SDL-sokoban
ConfigurationName      :=Debug
WorkspacePath          := "/home/david/perso/dev/learn-c/hello-world"
ProjectPath            := "/home/david/perso/dev/learn-c/hello-world/SDL-sokoban"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=David
Date                   :=08/11/17
CodeLitePath           :="/home/david/.codelite"
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="SDL-sokoban.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)SDL $(LibrarySwitch)SDL_image 
ArLibs                 :=  "SDL" "SDL_image" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/include/SDL 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/error.c$(ObjectSuffix) $(IntermediateDirectory)/event.c$(ObjectSuffix) $(IntermediateDirectory)/sdlimage.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/david/perso/dev/learn-c/hello-world/SDL-sokoban/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/error.c$(ObjectSuffix): error.c $(IntermediateDirectory)/error.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/david/perso/dev/learn-c/hello-world/SDL-sokoban/error.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/error.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/error.c$(DependSuffix): error.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/error.c$(ObjectSuffix) -MF$(IntermediateDirectory)/error.c$(DependSuffix) -MM "error.c"

$(IntermediateDirectory)/error.c$(PreprocessSuffix): error.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/error.c$(PreprocessSuffix) "error.c"

$(IntermediateDirectory)/event.c$(ObjectSuffix): event.c $(IntermediateDirectory)/event.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/david/perso/dev/learn-c/hello-world/SDL-sokoban/event.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/event.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/event.c$(DependSuffix): event.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/event.c$(ObjectSuffix) -MF$(IntermediateDirectory)/event.c$(DependSuffix) -MM "event.c"

$(IntermediateDirectory)/event.c$(PreprocessSuffix): event.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/event.c$(PreprocessSuffix) "event.c"

$(IntermediateDirectory)/sdlimage.c$(ObjectSuffix): sdlimage.c $(IntermediateDirectory)/sdlimage.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/david/perso/dev/learn-c/hello-world/SDL-sokoban/sdlimage.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sdlimage.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sdlimage.c$(DependSuffix): sdlimage.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sdlimage.c$(ObjectSuffix) -MF$(IntermediateDirectory)/sdlimage.c$(DependSuffix) -MM "sdlimage.c"

$(IntermediateDirectory)/sdlimage.c$(PreprocessSuffix): sdlimage.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sdlimage.c$(PreprocessSuffix) "sdlimage.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


