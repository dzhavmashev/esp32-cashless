// Function : FUN_4014ab74
// Address  : 0x4014ab74
// Size     : 189 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4014ab74(int param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  int *piVar5;
  int iVar6;
  
  if (7 < param_2) {
    FUN_40147fe4(1,0x400,2,0x3f43664f,param_2);
    return;
  }
  iVar2 = param_2 * 4 + param_1;
  puVar1 = *(uint **)(iVar2 + 0x268);
  if (puVar1 != (uint *)0x0) {
    for (iVar3 = 0; iVar3 < (int)(uint)*(ushort *)((int)puVar1 + 0xe); iVar3 = iVar3 + 1) {
      piVar5 = (int *)(iVar3 * 4 + puVar1[6]);
      iVar6 = *piVar5;
      if (iVar6 != 0) {
        *piVar5 = 0;
        puVar1[1] = puVar1[1] - (uint)*(ushort *)(iVar6 + 0x16);
        memw();
        FUN_4015fb50();
        sVar4 = (short)puVar1[2] + -1;
        *(short *)(puVar1 + 2) = sVar4;
        memw();
        if (sVar4 == 0) break;
      }
    }
    *puVar1 = *puVar1 & 0xffffffb9;
    memw();
    FUN_4015fda4((char)puVar1[8]);
    FUN_4014ab3c((char)puVar1[8]);
    if (puVar1[6] != 0) {
      (**(code **)(_DAT_3ffc1a34 + 0xb0))();
    }
    (**(code **)(_DAT_3ffc1a34 + 0xb0))(puVar1);
    *(undefined4 *)(iVar2 + 0x268) = 0;
    *(ushort *)(param_1 + 0x288) =
         (ushort)(0xfffffffefffffffe >> 0x20 - (param_2 & 0x1f)) & *(ushort *)(param_1 + 0x288);
    memw();
  }
  memw();
  return;
}

