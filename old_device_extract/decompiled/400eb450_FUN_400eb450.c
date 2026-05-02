// Function : FUN_400eb450
// Address  : 0x400eb450
// Size     : 87 bytes


void FUN_400eb450(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x90) != 0) {
    iVar1 = FUN_400f1a9c();
    uVar3 = *(uint *)(param_1 + 0x90);
    uVar2 = iVar1 - *(int *)(param_1 + 0x760);
    if (uVar3 << 1 < uVar2) {
      (*(code *)&LAB_40184472_2)(param_1 + 0xb0,7);
      *(undefined1 *)(param_1 + 0x765) = 7;
    }
    else if ((*(char *)(param_1 + 0x764) == '\0') &&
            (((uVar3 < (uint)(iVar1 - *(int *)(param_1 + 0x75c)) || (uVar3 < uVar2)) &&
             (iVar1 = FUN_400eb3c0(param_1,&DAT_3f409944), iVar1 != 0)))) {
      *(undefined1 *)(param_1 + 0x764) = 1;
    }
  }
  return;
}

