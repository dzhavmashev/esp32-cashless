// Function : FUN_40186c6c
// Address  : 0x40186c6c
// Size     : 58 bytes


void FUN_40186c6c(int param_1,ushort param_2)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 0x78);
  if (param_2 < uVar1) {
    *(ushort *)(param_1 + 0x7c) = param_2;
    memw();
    memw();
  }
  else {
    *(ushort *)(param_1 + 0x7c) = uVar1;
    memw();
  }
  if (param_2 >> 1 < uVar1) {
    *(ushort *)(param_1 + 0x7a) = param_2 >> 1;
    memw();
    memw();
    return;
  }
  *(ushort *)(param_1 + 0x7a) = uVar1;
  memw();
  memw();
  return;
}

