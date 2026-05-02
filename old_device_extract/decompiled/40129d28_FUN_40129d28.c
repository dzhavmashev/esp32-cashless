// Function : FUN_40129d28
// Address  : 0x40129d28
// Size     : 72 bytes


uint FUN_40129d28(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = FUN_4012c940(param_1);
  if (0x3fff < uVar1) {
    uVar1 = 0x4000;
  }
  uVar4 = *(uint *)(param_1 + 0xd8);
  if (uVar4 < uVar1) {
    uVar2 = FUN_401290e4(param_1);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    uVar3 = FUN_40129ce0(param_1);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    if (uVar3 < uVar2) {
      uVar2 = uVar2 - uVar3;
      uVar1 = uVar1 - uVar4;
      return (uVar1 < uVar2) * uVar1 + (uVar1 >= uVar2) * uVar2;
    }
  }
  return 0;
}

