// Function : FUN_401869d0
// Address  : 0x401869d0
// Size     : 27 bytes


void FUN_401869d0(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x1c) | 0x400;
  if (param_2 == 0) {
    uVar1 = *(uint *)(param_1 + 0x1c) & 0xfffffbff;
  }
  *(uint *)(param_1 + 0x1c) = uVar1;
  memw();
  return;
}

