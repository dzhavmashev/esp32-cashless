// Function : FUN_400fab48
// Address  : 0x400fab48
// Size     : 33 bytes


undefined4 FUN_400fab48(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = 0x1107;
  if (*(char *)(param_1 + 0x12) != '\0') {
    uVar1 = FUN_400fa5d8(*(undefined4 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0x10),param_2,
                         param_3,param_4);
  }
  return uVar1;
}

