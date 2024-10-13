# recursive wildcard
rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))
C_FILE := $(call rwildcard,.,*.c)

MOD_NAME := test

$(MOD_NAME).wasm: $(C_FILE)
	emcc $^ -o $(MOD_NAME).wasm -O3 -s LINKABLE=1 -s EXPORT_ALL=1 -s PURE_WASI=1 -I. -DF3DEX_GBI_2
	mkdir -p ../../build/mods/
	rm ../../build/mods/$(MOD_NAME).wasm
	cp $(MOD_NAME).wasm ../../build/mods/$(MOD_NAME).wasm
