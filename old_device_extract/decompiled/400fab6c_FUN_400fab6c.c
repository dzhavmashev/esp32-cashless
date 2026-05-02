// Function : FUN_400fab6c
// Address  : 0x400fab6c
// Size     : 34 bytes


undefined4 FUN_400fab6c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x1107;
  if ((*(char *)(param_1 + 0x12) != '\0') && (uVar1 = 0x1104, *(char *)(param_1 + 0x11) == '\0')) {
    uVar1 = FUN_400fa598(*(undefined4 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0x10));
  }
  return uVar1;
}

