// Function : FUN_400faa84
// Address  : 0x400faa84
// Size     : 42 bytes


undefined4 FUN_400faa84(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = 0x1107;
  if ((*(char *)(param_1 + 0x12) != '\0') && (uVar1 = 0x1104, *(char *)(param_1 + 0x11) == '\0')) {
    uVar1 = FUN_400fa29c(*(undefined4 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0x10),0x41,param_2
                         ,param_3,param_4);
  }
  return uVar1;
}

