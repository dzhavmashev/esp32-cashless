// Function : FUN_400f87b4
// Address  : 0x400f87b4
// Size     : 503 bytes


int FUN_400f87b4(uint *param_1,int param_2,int param_3,uint *param_4)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint *puStack_3c;
  uint uStack_34;
  uint *puStack_30;
  
  uVar12 = param_1[0x37];
  iVar8 = 0;
  uVar2 = *param_1;
  puStack_3c = param_1 + 7;
  uVar7 = uVar2 + uVar12;
  puStack_30 = param_1 + 0x27;
  do {
    if ((int)(uint)*(byte *)((int)param_1 + 5) <= iVar8) {
      if (uVar7 < *param_1) {
        if (param_2 == 0) {
          memw();
          uVar3 = (*(code *)&SUB_40094b80)();
          FUN_4012113c(1,"_common","failed\n",uVar3,"_common");
        }
LAB_400f88a8:
        iVar8 = 0x2002;
      }
      else {
        iVar8 = 0;
        param_1[0x37] = (param_1[0x37] - (uVar2 + uVar12)) + uVar7;
        memw();
      }
      return iVar8;
    }
    iVar4 = FUN_400f8574(uVar7,puStack_3c,8,1);
    if (iVar4 != 0) {
      uVar3 = (*(code *)&SUB_40094b80)();
      FUN_4012113c(1,"_common","gth %d\n",uVar3,"_common",uVar7);
      return iVar4;
    }
    if (param_3 != 0) {
      FUN_400f8b50(param_3,puStack_3c,8);
    }
    uVar5 = puStack_3c[1];
    if (((uVar5 & 3) != 0) || (0xffffff < uVar5)) {
      if (param_2 == 0) {
        uVar3 = (*(code *)&SUB_40094b80)();
        FUN_4012113c(1,"_common","0x%08x\n",uVar3,"_common",param_1[(iVar8 + 2) * 2 + 4]);
      }
      goto LAB_400f88a8;
    }
    uVar7 = uVar7 + 8;
    uVar9 = *puStack_3c;
    if (((uVar9 + 0xbff30000 < 0x330000) || (uVar9 + 0xc0c00000 < 0x400000)) &&
       (((uVar9 ^ uVar7) & 0xffff) != 0)) {
      if (param_2 == 0) {
        memw();
        uVar3 = (*(code *)&SUB_40094b80)();
        memw();
        FUN_4012113c(1,"_common","h 0x%x\n",uVar3,"_common",iVar8,uVar9,uVar7);
      }
      goto LAB_400f88a8;
    }
    iVar4 = FUN_400f84dc();
    memw();
    uStack_34 = uVar7;
    for (; uVar5 != 0; uVar5 = uVar5 - uVar9) {
      uVar9 = (iVar4 - (uint)((uStack_34 & 0xffff) != 0)) * 0x10000;
      uVar9 = (uVar9 < uVar5) * uVar9 + (uVar9 >= uVar5) * uVar5;
      if (param_4 != (uint *)0x0) {
        iVar6 = FUN_400f84ec(uStack_34,uVar9);
        if (iVar6 == 0) {
          uVar3 = (*(code *)&SUB_40094b80)();
          memw();
          FUN_4012113c(1,"_common","0x%08x\n",uVar3,"_common",uStack_34,uVar9);
          return -1;
        }
        for (uVar10 = 0; uVar10 < uVar9; uVar10 = uVar10 + 4) {
          *param_4 = *param_4 ^ *(uint *)(iVar6 + uVar10);
          if ((param_3 != 0) && ((uVar10 & 0x3ff) == 0)) {
            uVar11 = uVar9 - uVar10;
            memw();
            FUN_400f8b50(param_3,(uint *)(iVar6 + uVar10),
                         (uVar11 < 0x400) * uVar11 + (uint)(uVar11 >= 0x400) * 0x400);
          }
        }
        FUN_400f8558(iVar6);
      }
      uStack_34 = uStack_34 + uVar9;
    }
    iVar8 = iVar8 + 1;
    *puStack_30 = uVar7;
    puVar1 = puStack_3c + 1;
    puStack_3c = puStack_3c + 2;
    uVar7 = uVar7 + *puVar1;
    memw();
    puStack_30 = puStack_30 + 1;
  } while( true );
}

