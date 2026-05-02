// Function : FUN_4015f558
// Address  : 0x4015f558
// Size     : 101 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_4015f558(int param_1,int param_2,undefined1 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = _DAT_3ffbff04;
  if (param_2 != 0) {
    puVar3 = (undefined1 *)(*(int *)(*(int *)(param_2 + 4) + 4) - _DAT_3ffbff04);
    *(undefined1 **)(*(int *)(param_2 + 4) + 4) = puVar3;
    uVar5 = *(uint *)(param_1 + 0x98);
    *(short *)(param_2 + 0x16) = (short)iVar1 + *(short *)(param_2 + 0x16);
    memw();
    uVar4 = uVar5 + 1;
    *(uint *)(param_1 + 0x98) = uVar4;
    *(uint *)(param_1 + 0x9c) = (uint)(uVar4 < uVar5) + *(int *)(param_1 + 0x9c);
    puVar3[2] = (char)(uVar4 >> 0x10);
    memw();
    puVar3[1] = (char)((uint)*(undefined4 *)(param_1 + 0x98) >> 8);
    memw();
    uVar2 = *(undefined4 *)(param_1 + 0x98);
    puVar3[3] = param_3;
    *puVar3 = (char)uVar2;
    memw();
  }
  memw();
  return param_2 != 0;
}

