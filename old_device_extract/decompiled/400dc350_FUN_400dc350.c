// Function : FUN_400dc350
// Address  : 0x400dc350
// Size     : 73 bytes


int FUN_400dc350(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((*(char *)(param_1 + 0x30) != '\0') && (*(char *)(param_1 + 0x50) != '\0')) {
    uVar2 = *(uint *)(param_1 + 0x78);
    if (*(char *)(param_1 + 0x70) != '\0') {
      iVar1 = FUN_400f1a9c();
      uVar2 = iVar1 + (uVar2 - *(int *)(param_1 + 0x74));
    }
    iVar1 = FUN_400f1a9c();
    uVar4 = iVar1 - *(int *)(param_1 + 0x34);
    uVar3 = 0;
    if (uVar2 < uVar4) {
      uVar3 = uVar4 - uVar2;
    }
    if (uVar3 / 1000 < *(uint *)(param_1 + 0x38)) {
      return *(uint *)(param_1 + 0x38) - uVar3 / 1000;
    }
  }
  return 0;
}

