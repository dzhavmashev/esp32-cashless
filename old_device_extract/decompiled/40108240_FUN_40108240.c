// Function : FUN_40108240
// Address  : 0x40108240
// Size     : 458 bytes


int FUN_40108240(int param_1,int param_2,int param_3,int param_4,uint *param_5,uint *param_6,
                uint *param_7)

{
  bool bVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint local_38 [4];
  uint local_28;
  uint local_24;
  
  local_38[0] = local_38[0] & 0xffffff00;
  memw();
  local_38[2] = local_38[2] & 0xffffff00;
  memw();
  local_28 = local_28 & 0xffffff00;
  memw();
  iVar5 = 0;
  uVar8 = 0x30;
  do {
    if (param_1 <= (int)uVar8) {
      *param_5 = local_38[0];
      param_5[1] = local_38[1];
      *param_6 = local_38[2];
      param_6[1] = local_38[3];
      *param_7 = local_28;
      param_7[1] = local_24;
      memw();
      return iVar5;
    }
    bVar1 = uVar8 < 0x40;
    if (((((param_2 != 0) && (bVar1)) &&
         ((1 << 0x20 - (0x20 - (uVar8 & 0x1f)) & *(uint *)(param_2 + (uVar8 >> 5) * 4)) != 0)) ||
        (((param_3 != 0 && (bVar1)) &&
         ((1 << 0x20 - (0x20 - (uVar8 & 0x1f)) & *(uint *)(param_3 + (uVar8 >> 5) * 4)) != 0)))) ||
       (((param_4 != 0 && (bVar1)) &&
        ((1 << 0x20 - (0x20 - (uVar8 & 0x1f)) & *(uint *)(param_4 + (uVar8 >> 5) * 4)) != 0)))) {
      uVar6 = FUN_4011b020();
      memw();
      iVar7 = FUN_40107a48(uVar8);
      if (iVar7 == 0) {
        FUN_4011b040(uVar6);
        return -1;
      }
      sVar3 = *(short *)(iVar7 + 10);
      iVar10 = *(int *)(iVar7 + 4);
      sVar2 = *(short *)(iVar7 + 8);
      sVar4 = *(short *)(iVar7 + 0xc);
      memw();
      FUN_4011b040(uVar6);
      bVar1 = uVar8 < 0x40;
      if ((param_2 != 0) && (bVar1)) {
        uVar9 = 1 << 0x20 - (0x20 - (uVar8 & 0x1f));
        if (((uVar9 & *(uint *)(param_2 + (uVar8 >> 5) * 4)) != 0) &&
           ((iVar10 != 0 || ((((int)sVar2 >> 0xf) - (int)sVar2 & 0x8000U) != 0)))) {
          iVar5 = iVar5 + 1;
          local_38[uVar8 >> 5] = local_38[uVar8 >> 5] | uVar9;
        }
      }
      if ((param_3 != 0) && (bVar1)) {
        uVar9 = 1 << 0x20 - (0x20 - (uVar8 & 0x1f));
        if (((uVar9 & *(uint *)(param_3 + (uVar8 >> 5) * 4)) != 0) && (sVar3 != 0)) {
          iVar5 = iVar5 + 1;
          local_38[(uVar8 >> 5) + 2] = local_38[(uVar8 >> 5) + 2] | uVar9;
        }
      }
      if ((param_4 != 0) && (bVar1)) {
        uVar9 = 1 << 0x20 - (0x20 - (uVar8 & 0x1f));
        if (((uVar9 & *(uint *)(param_4 + (uVar8 >> 5) * 4)) != 0) && (sVar4 != 0)) {
          iVar5 = iVar5 + 1;
          local_38[(uVar8 >> 5) + 4] = local_38[(uVar8 >> 5) + 4] | uVar9;
        }
      }
      memw();
      FUN_40108194(iVar7);
    }
    uVar8 = uVar8 + 1;
  } while( true );
}

