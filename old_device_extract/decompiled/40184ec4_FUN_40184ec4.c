// Function : FUN_40184ec4
// Address  : 0x40184ec4
// Size     : 23 bytes


byte FUN_40184ec4(int param_1)

{
  byte bVar1;
  
  bVar1 = 0;
  if (param_1 != 0) {
    bVar1 = 0;
    if (*(int *)(param_1 + 0x10) != 0) {
      bVar1 = *(byte *)(*(int *)(param_1 + 0x10) + 0xeb) & 1;
    }
  }
  return bVar1;
}

