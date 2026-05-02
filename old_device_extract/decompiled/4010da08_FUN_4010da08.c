// Function : FUN_4010da08
// Address  : 0x4010da08
// Size     : 43 bytes


undefined1 FUN_4010da08(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = 0xf0;
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x3c) != 1) {
      *(ushort *)(param_1 + 0x46) = *(ushort *)(param_1 + 0x46) | 0x10;
      memw();
    }
    memw();
    uVar1 = FUN_4010d894(param_1,1);
  }
  return uVar1;
}

