// Function : FUN_401356b4
// Address  : 0x401356b4
// Size     : 91 bytes


void FUN_401356b4(int param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x60) != 1) {
      FUN_40131548(param_1 + 4);
      FUN_40131548(param_1 + 0x10);
      FUN_40131548(param_1 + 0x1c);
      FUN_401356a8(param_1 + 0x28);
      FUN_40131548(param_1 + 0x4c);
    }
    uVar1 = 0;
    if (*(int *)(param_1 + 0x74) != 0) {
      for (; uVar1 < *(uint *)(param_1 + 0x78); uVar1 = uVar1 + 1) {
        FUN_401356a8(*(int *)(param_1 + 0x74) + uVar1 * 0x24);
      }
      FUN_4013ae44();
    }
    FUN_4013ae54(param_1,0x7c);
  }
  return;
}

