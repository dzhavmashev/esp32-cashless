// Function : FUN_401295b8
// Address  : 0x401295b8
// Size     : 977 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401295b8(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 uint param_6)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 *puVar10;
  int iVar11;
  int iVar12;
  uint in_t0;
  int iStack_bc;
  undefined4 uStack_b8;
  undefined1 auStack_b2 [46];
  undefined1 auStack_84 [48];
  undefined1 auStack_54 [48];
  int iStack_24;
  
  memw();
  memw();
  iStack_24 = _DAT_3ffc5708;
  uVar7 = in_t0;
  if ((param_3 != 0) && (param_4 = *(int *)(param_3 + 0xc), param_4 != 0)) {
    uVar2 = *(uint *)(param_3 + 0x14);
    if ((uVar2 <= *(uint *)(param_3 + 0x10)) &&
       (param_6 = *(uint *)(param_3 + 0x18), param_6 <= *(uint *)(param_3 + 0x10) - uVar2)) {
      param_4 = param_4 + uVar2;
      if (*(int *)(param_2 + 0x90) != 0) {
        uVar7 = *(uint *)(*(int *)(param_2 + 0x90) + 4);
        if (((uVar7 & 0xfffffffd) != 8) && (iVar6 = 0, uVar7 != 6)) goto LAB_401296d0;
        iVar12 = *(int *)(param_2 + 8);
        iVar6 = param_4;
        iVar11 = param_3;
        if (*(int *)(param_2 + 4) != iVar12) {
          uVar7 = in_t0;
          if (param_6 < 8) goto LAB_4012969c;
          param_6 = param_6 - 8;
          *(uint *)(param_3 + 0x14) = uVar2 + 8;
          *(uint *)(param_3 + 0x18) = param_6;
          iVar6 = param_4 + 8;
          iVar11 = param_4;
        }
        param_4 = iVar6;
        uVar7 = in_t0;
        if (*(uint *)(param_3 + 0x18) < *(uint *)(param_2 + 0x10)) goto LAB_4012969c;
        *(uint *)(param_3 + 0x18) = *(uint *)(param_3 + 0x18) - *(uint *)(param_2 + 0x10);
        memw();
        FUN_40129220(auStack_54,param_2 + 0x24,iVar12,iVar11);
        FUN_401291b0(auStack_b2,&uStack_b8,param_3);
        param_6 = param_4 - *(int *)(param_3 + 0xc);
        memw();
        iVar6 = FUN_4013313c(param_2 + 0x90,auStack_54,*(undefined4 *)(param_2 + 4),auStack_b2,
                             uStack_b8,param_4,*(int *)(param_2 + 0x10) + *(int *)(param_3 + 0x18),
                             param_4,*(int *)(param_3 + 0x10) - param_6,&iStack_bc,
                             *(int *)(param_2 + 0x10));
        uVar7 = in_t0;
        if (iVar6 != 0) {
          if (iVar6 != -0x6300) goto LAB_401296b4;
          goto LAB_4012969c;
        }
        if (*(int *)(param_3 + 0x18) == iStack_bc) goto LAB_401296b4;
      }
    }
  }
LAB_401295cc:
  do {
    iVar6 = -0x6c00;
    memw();
LAB_401296b4:
    do {
      do {
        while( true ) {
          param_3 = iStack_24;
          param_2 = _DAT_3ffc5708;
          memw();
          memw();
          if (iStack_24 == _DAT_3ffc5708) {
            return;
          }
          (*(code *)&SUB_40082ec4)();
          in_t0 = uVar7;
LAB_401296d0:
          bVar1 = uVar7 != 2;
          uVar7 = in_t0;
          if (bVar1) goto LAB_401295cc;
          if (1 < *(int *)(param_2 + 0xd0)) {
            iVar6 = *(int *)(param_2 + 4);
          }
          if (((uint)(*(int *)(param_2 + 4) + iVar6) <= param_6) &&
             ((uint)(*(int *)(param_2 + 0xc) + 1 + iVar6) <= param_6)) break;
LAB_4012969c:
          iVar6 = -0x7180;
        }
        bVar1 = false;
        if (*(int *)(param_2 + 0x4c) == 1) {
          *(uint *)(param_3 + 0x18) = param_6 - *(int *)(param_2 + 0xc);
          memw();
          FUN_401291b0(auStack_b2,&uStack_b8,param_3);
          param_6 = param_2 + 0x40;
          iVar6 = FUN_4013935c(param_6,auStack_b2,uStack_b8);
          bVar1 = false;
          if (iVar6 == 0) {
            iVar6 = FUN_4013935c(param_6,param_4,*(undefined4 *)(param_3 + 0x18));
            if (iVar6 == 0) {
              iVar6 = FUN_4013937c(param_6,auStack_54);
              bVar1 = false;
              if (iVar6 == 0) {
                iVar6 = FUN_401393f0(param_6);
                if (iVar6 != 0) goto LAB_40129939;
                iVar6 = FUN_401862dc(param_4 + *(int *)(param_3 + 0x18),auStack_54,
                                     *(undefined4 *)(param_2 + 0xc));
                if (iVar6 == 0) {
                  bVar1 = true;
                  iVar6 = 0;
                }
                else {
                  iVar6 = -0x7180;
                  bVar1 = false;
                }
              }
            }
            else {
LAB_40129939:
              bVar1 = false;
            }
          }
          memw();
          FUN_4013ae54(auStack_54,*(undefined4 *)(param_2 + 0xc));
          uVar7 = in_t0;
          if (iVar6 != 0) goto LAB_401296b4;
        }
        uVar2 = *(uint *)(param_2 + 4);
        param_6 = *(uint *)(param_3 + 0x18);
        if (param_6 % uVar2 != 0) goto LAB_4012969c;
        param_6 = param_2 + 0x24;
        if (1 < *(int *)(param_2 + 0xd0)) {
          memw();
          (*(code *)&SUB_4008b3d0)(param_6,param_4,uVar2);
          param_4 = param_4 + uVar2;
          *(uint *)(param_3 + 0x14) = *(int *)(param_3 + 0x14) + uVar2;
          *(uint *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) - uVar2;
        }
        memw();
        iVar6 = FUN_4013309c(param_2 + 0x90,param_6,uVar2,param_4,*(undefined4 *)(param_3 + 0x18),
                             param_4,&iStack_bc);
      } while (iVar6 != 0);
      if (*(int *)(param_3 + 0x18) != iStack_bc) break;
      if (*(int *)(param_2 + 0xd0) < 2) {
        memw();
        (*(code *)&SUB_4008b3d0)(param_6,param_2 + 0xb8,*(undefined4 *)(param_2 + 4));
      }
      param_6 = (uint)*(byte *)(param_4 + *(int *)(param_3 + 0x18) + -1);
      iVar11 = param_6 + 1;
      if (!bVar1) {
        iVar11 = *(int *)(param_2 + 0xc) + 1 + param_6;
      }
      memw();
      uVar2 = FUN_40186348(*(int *)(param_3 + 0x18),iVar11);
      param_6 = param_6 & uVar2;
      uVar8 = param_6 + 1;
      if (*(int *)(param_2 + 0xd0) < 1) break;
      uVar9 = *(uint *)(param_3 + 0x18);
      uVar3 = uVar9 - ((uVar9 < 0x100) * uVar9 + (uint)(uVar9 >= 0x100) * 0x100);
      iVar11 = 0;
      while (uVar3 < *(uint *)(param_3 + 0x18)) {
        memw();
        uVar4 = FUN_40186348(uVar3,uVar9 - uVar8);
        puVar10 = (undefined1 *)(param_4 + uVar3);
        memw();
        uVar3 = uVar3 + 1;
        memw();
        uVar5 = FUN_40186358(*puVar10,param_6);
        iVar11 = iVar11 + (uVar4 & uVar5);
      }
      memw();
      param_6 = FUN_40186358(iVar11,uVar8);
      param_6 = uVar2 & 1 & param_6;
      uVar2 = FUN_40186338(param_6);
      iVar11 = *(int *)(param_3 + 0x18) - (uVar8 & uVar2);
      *(int *)(param_3 + 0x18) = iVar11;
      if (bVar1) {
        if (param_6 == 0) goto LAB_4012969c;
        goto LAB_401296b4;
      }
      memw();
      (*(code *)&SUB_4008b530)(auStack_84,0,0x30);
      (*(code *)&SUB_4008b530)(auStack_54,0,0x30);
      *(int *)(param_3 + 0x18) = iVar11 - *(int *)(param_2 + 0xc);
      memw();
      FUN_401291b0(auStack_b2,&uStack_b8,param_3);
      iVar6 = -0x6c00;
      if (*(int *)(param_2 + 0xd0) < 1) goto LAB_401296b4;
      uVar2 = *(int *)(param_3 + 0x18) + (uVar8 & uVar2);
      iVar11 = (uint)(uVar2 < 0x100) * 0x100 + (uVar2 >= 0x100) * uVar2 + -0x100;
      memw();
      iVar6 = FUN_40133518(param_2 + 0x40,auStack_b2,uStack_b8,param_4,*(int *)(param_3 + 0x18),
                           iVar11,uVar2,auStack_84);
      bVar1 = false;
      if (iVar6 == 0) {
        memw();
        FUN_401334f8(auStack_54,param_4,*(undefined4 *)(param_3 + 0x18),iVar11,uVar2,
                     *(undefined4 *)(param_2 + 0xc));
        iVar11 = FUN_401862dc(auStack_54,auStack_84,*(undefined4 *)(param_2 + 0xc));
        bVar1 = true;
        if (iVar11 != 0) {
          param_6 = 0;
        }
      }
      memw();
      FUN_4013ae54(auStack_54,*(undefined4 *)(param_2 + 0xc));
      FUN_4013ae54(auStack_84,*(undefined4 *)(param_2 + 0xc));
      if (iVar6 != 0) goto LAB_401296b4;
      if (param_6 == 0) goto LAB_4012969c;
    } while (bVar1);
  } while( true );
}

