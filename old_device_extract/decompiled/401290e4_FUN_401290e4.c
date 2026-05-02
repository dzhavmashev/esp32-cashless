// Function : FUN_401290e4
// Address  : 0x401290e4
// Size     : 36 bytes


int FUN_401290e4(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0xd8);
  uVar1 = FUN_401859c0(param_1);
  if (0x414b < uVar1 - 1) {
    uVar1 = 0x414d;
  }
  iVar2 = -0x6c00;
  if (uVar3 <= uVar1) {
    iVar2 = uVar1 - uVar3;
  }
  return iVar2;
}

