# recursive wildcard
rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))
C_FILE := $(call rwildcard,src,*.c)
C_FILE += $(call rwildcard,lib,*.c)

MOD_NAME := test

$(MOD_NAME): $(MOD_NAME).wasm $(MOD_NAME).otr

$(MOD_NAME).wasm: $(C_FILE)
	emcc $^ -o $(MOD_NAME).wasm -O3 -s LINKABLE=1 -s EXPORT_ALL=1 -s PURE_WASI=1 -Ilib -Iinclude -DF3DEX_GBI
	mkdir -p ../../build/mods/
	rm ../../build/mods/$(MOD_NAME).wasm || true
	cp $(MOD_NAME).wasm ../../build/mods/$(MOD_NAME).wasm

$(MOD_NAME).otr:
	../../build/torch/src/torch-build/torch header -o course/test.bin
	../../build/torch/src/torch-build/torch otr course/test.bin
	rm ../../build/mods/$(MOD_NAME).otr || true
	cp $(MOD_NAME).otr ../../build/mods/$(MOD_NAME).otr

%.bin: %.c
	gcc -c $< -o $(@:.bin=.o) -Ilib -m32 -mbig-endian -DF3DEX_GBI
	ld -t -e 0 -Tdata=00000000 -Map $(@:.bin=.map) -o $(@:.bin=.elf) $(@:.bin=.o) --no-check-sections
	objcopy -O binary --only-section=.data $(@:.bin=.elf) $@

clean:
	rm $(MOD_NAME).wasm $(MOD_NAME).otr torch.hash.yml