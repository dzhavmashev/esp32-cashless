// Function : FUN_400faa20
// Address  : 0x400faa20
// Size     : 16 bytes


undefined4 FUN_400faa20(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(char *)(param_1 + 0x12) == '\0') {
    uVar1 = 0x1107;
  }
  return uVar1;
}

