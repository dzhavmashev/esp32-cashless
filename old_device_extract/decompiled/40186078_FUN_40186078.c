// Function : FUN_40186078
// Address  : 0x40186078
// Size     : 114 bytes


uint FUN_40186078(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 4);
  while ((uVar1 != 0 && (*(int *)(*(int *)(param_1 + 8) + uVar1 * 4 + -4) == 0))) {
    uVar1 = uVar1 - 1;
  }
  uVar2 = *(uint *)(param_2 + 4);
  while( true ) {
    if (uVar2 == 0) {
      return (uint)(uVar1 != 0);
    }
    if (*(int *)(*(int *)(param_2 + 8) + uVar2 * 4 + -4) != 0) break;
    uVar2 = uVar2 - 1;
  }
  if (uVar1 <= uVar2) {
    if (uVar1 < uVar2) {
      return 0xffffffff;
    }
    while( true ) {
      uVar1 = uVar1 - 1;
      if (uVar1 == 0xffffffff) {
        return 0;
      }
      uVar3 = *(uint *)(*(int *)(param_1 + 8) + uVar1 * 4);
      uVar2 = *(uint *)(*(int *)(param_2 + 8) + uVar1 * 4);
      if (uVar2 < uVar3) break;
      if (uVar3 < uVar2) {
        return 0xffffffff;
      }
    }
    return 1;
  }
  return 1;
}

