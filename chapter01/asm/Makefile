MACOS_VERSION := 13.0.0
ARCH 					:= arm64

HelloWorld.o: HelloWorld.s
	as -o HelloWorld.o $<

HelloWorld: HelloWorld.o
	ld -macosx_version_min $(MACOS_VERSION) -o HelloWorld $< -lSystem -syslibroot $(shell xcrun -sdk macosx --show-sdk-path) -e _start -arch $(ARCH)

run: HelloWorld
	./HelloWorld

clean:
	rip HelloWorld HelloWorld.o
