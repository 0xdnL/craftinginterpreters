SRC_DIR	:= src/main/java
OUT_DIR	:= target/classes

SRCS		:= $(wildcard $(SRC_DIR)/*.java)
# SRCS  := src/main/java/Application.java src/main/java/HelloWorld.java

CLS			:= $(SRCS:$(SRC_DIR)/%.java=$(OUT_DIR)/%.class)
# CLS   := target/classes/Application.class target/classes/HelloWorld.class

JC			:= javac
JCFLAGS	:= -d $(OUT_DIR)/ -cp $(SRC_DIR)/
JAVA		:= java
J_OPTS 	:=


.SUFFIXES: .java

# targets that do not produce output files
.PHONY: all clean

# default target(s)
all: $(CLS)

$(CLS): $(OUT_DIR)/%.class: $(SRC_DIR)/%.java
	$(JC) $(JCFLAGS) $<

run: $(CLS)
	$(JAVA) $(JAVA_OPTIONS) -cp $(OUT_DIR) $(subst /,.,$(SRC_DIR)).$(notdir $(basename $<))


clean:
	rip $(OUT_DIR)/$(SRC_DIR)/*.class
