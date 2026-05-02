// Function : FUN_40171f0c
// Address  : 0x40171f0c
// Size     : 338 bytes


uint FUN_40171f0c(int *param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *piVar9;
  uint *puVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  int iStack_44;
  uint uStack_40;
  uint local_30 [12];
  
  uVar1 = (**(code **)(*param_1 + 0x54))(param_1);
  if (((char)param_1[8] == '\x01') && (-1 < (int)uVar1)) {
    uVar11 = 1 << 0x20 - (0x20 - (uVar1 & 0x1f));
    iStack_44 = 10;
    puVar10 = local_30 + (uVar1 >> 5);
    uVar3 = 0;
    uStack_40 = param_3;
LAB_40171f51:
    do {
      local_30[0]._0_1_ = 0;
      if ((int)uVar1 < 0x40) {
        *puVar10 = *puVar10 | uVar11;
      }
      local_30[3] = 1000000;
      iStack_44 = iStack_44 + -1;
      local_30[2] = 0;
      iVar2 = FUN_400fefac(uVar1 + 1,0,local_30,0,local_30 + 2);
      if (iVar2 < 0) goto LAB_40171f98;
      if (((int)uVar1 < 0x40) && ((uVar11 & *puVar10) != 0)) {
        iVar2 = FUN_40109524(uVar1,param_2,uStack_40,8);
        if (0 < iVar2) {
          uVar3 = uVar3 + iVar2;
          if (param_3 <= uVar3) {
            return uVar3;
          }
          param_2 = param_2 + iVar2;
          uStack_40 = uStack_40 - iVar2;
          iStack_44 = 10;
          goto LAB_40171f51;
        }
        if (iVar2 != 0) {
          uVar13 = (*(code *)&SUB_40085bfc)();
          uVar4 = FUN_401847f4(&DAT_3f424da0);
          uVar5 = (**(code **)(*param_1 + 0x54))(param_1);
          puVar6 = (undefined4 *)FUN_40173a8c();
          uVar12 = *puVar6;
          puVar6 = (undefined4 *)FUN_40173a8c();
          uVar7 = FUN_401745d0(*puVar6);
          uVar8 = (*(code *)&SUB_4000cff8)((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),1000,0);
          FUN_4012105c("ent.cpp",uVar8,uVar4,0x1ad,"er",uVar5,uVar12,uVar7);
          piVar9 = (int *)FUN_40173a8c();
          if (*piVar9 != 0xb) {
            (**(code **)(*param_1 + 0x3c))(param_1);
            return uVar3;
          }
        }
      }
    } while (iStack_44 != 0);
  }
  else {
LAB_40171f98:
    uVar3 = 0;
  }
  return uVar3;
}

