// Function : FUN_401286b0
// Address  : 0x401286b0
// Size     : 391 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401286b0(undefined4 param_1,int param_2,int param_3,undefined1 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte local_66 [66];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  memw();
  iVar1 = FUN_401857ec(param_1);
  iVar2 = FUN_40128d5c(param_1);
  iVar3 = FUN_40128a18();
  iVar4 = FUN_40128a18();
  uVar5 = FUN_40128a30(&DAT_3f42161c,1);
  if ((iVar3 != 0 && iVar4 != 0) && (uVar5 != 0 && (iVar3 != 0 && iVar4 != 0))) goto LAB_4012875f;
  do {
    FUN_40128a7c(iVar3,0);
    iVar3 = 0;
    do {
      FUN_40128a7c(iVar4,0);
      FUN_40128a7c(uVar5,0);
      uVar5 = 0xffffffff;
      if (iVar3 != 0) {
        iVar4 = FUN_40128a18();
        if (((iVar4 == 0) || (iVar6 = FUN_40128b74(param_4,iVar3,iVar1,iVar4), iVar6 < 0)) ||
           (iVar6 = FUN_40128b74(iVar4,iVar3,iVar1,iVar4), iVar6 < 0)) {
LAB_40128728:
          uVar5 = 0xffffffff;
          iVar2 = 0;
        }
        else {
          uVar5 = FUN_40128c44(iVar3);
          uVar8 = (uVar5 ^ 0xffffffff) & uVar5 - 1;
          iVar6 = 0;
          while (iVar2 != iVar6) {
            pbVar11 = local_66 + iVar6;
            pbVar9 = (byte *)(param_2 + iVar6);
            pbVar10 = (byte *)(param_3 + iVar6);
            iVar6 = iVar6 + 1;
            *pbVar11 = *pbVar9 ^ (byte)((int)uVar8 >> 0x1f) & (*pbVar9 ^ *pbVar10);
            memw();
            memw();
          }
          iVar2 = FUN_40128a30(local_66,iVar2);
          if (iVar2 == 0) goto LAB_40128728;
          iVar6 = FUN_40128b74(iVar4,iVar2,iVar1,iVar4);
          uVar5 = 0xffffffff;
          if (-1 < iVar6) {
            memw();
            uVar5 = 0xffffffff;
            uVar7 = FUN_40128c7c(iVar4,iVar1);
            if (uVar7 != 0xfffffffe) {
              uVar7 = uVar7 ^ (int)uVar8 >> 0x1f & 0xfffffffeU;
              uVar5 = ((uVar7 ^ 1) - 1 & (uVar7 ^ 0xfffffffe)) >> 0x1f;
            }
          }
        }
        FUN_40128a7c(iVar4,1);
        FUN_40128a7c(iVar3,1);
        FUN_40128a7c(iVar2,1);
      }
      iVar1 = iStack_24;
      iVar3 = _DAT_3ffc5708;
      memw();
      memw();
      if (iStack_24 == _DAT_3ffc5708) {
        return;
      }
      (*(code *)&SUB_40082ec4)();
      param_4 = &DAT_3ffc5708;
LAB_4012875f:
      iVar6 = FUN_40128b3c(iVar1,uVar5,iVar4);
    } while (((-1 < iVar6) && (iVar6 = FUN_40128c5c(iVar3,iVar4), -1 < iVar6)) &&
            (iVar6 = FUN_40128ad8(iVar3,uVar5,iVar3), -1 < iVar6));
  } while( true );
}

