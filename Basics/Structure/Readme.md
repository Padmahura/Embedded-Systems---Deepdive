## Packed Structure
Packed structure uses larger program memory due to its complexity in alignment

- arm-none-eabi-objdump -h -S test2_target.elf  > "test2_target.list"
-  text	   data	    bss	    dec	    hex	filename
-  5180	     92	   1900	   7172	   1c04	test2_target.elf

## Unpacked Structure
Unpacked structure uses lesser program memory due to its lesser complexity in alignment

- arm-none-eabi-size  test2_target.elf 
-  text	   data	    bss	    dec	    hex	filename
-  5160	     92	   1900	   7152	   1bf0	test2_target.elf

