// Function : FUN_400fabbc
// Address  : 0x400fabbc
// Size     : 36 bytes


undefined4 FUN_400fabbc(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x1107;
  if ((*(char *)(param_1 + 0x12) != '\0') && (uVar1 = 0x1104, *(char *)(param_1 + 0x11) == '\0')) {
    uVar1 = FUN_400fa4f4(*(undefined4 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0x10),0xff,param_2
                        );
  }
  return uVar1;
}

