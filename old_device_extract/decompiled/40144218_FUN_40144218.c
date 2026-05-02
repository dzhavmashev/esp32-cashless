// Function : FUN_40144218
// Address  : 0x40144218
// Size     : 1239 bytes


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40144218(uint param_1,uint param_2,int param_3,uint *param_4,uint param_5,uint *param_6,
                 code *param_7,undefined4 param_8)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  uint uStack_100;
  uint uStack_fc;
  uint uStack_f8;
  uint uStack_f4;
  int iStack_ec;
  uint *puStack_e0;
  int iStack_dc;
  uint uStack_d8;
  uint auStack_c0 [23];
  undefined1 auStack_64 [64];
  uint *puStack_24;
  
  memw();
  puVar6 = auStack_c0 + 2;
  memw();
  puStack_24 = _DAT_3ffc5708;
  *param_6 = 0;
  iVar8 = 10;
  puVar5 = puVar6;
  do {
    *puVar5 = 0;
    puVar5[1] = 0xffffffff;
    puVar5 = puVar5 + 2;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  if (param_4 == (uint *)0x0) {
    param_1 = 0xffffd800;
    uVar9 = 0;
    goto LAB_40144513;
  }
  uStack_fc = 0;
  if (param_5 != 0) {
    memw();
    uVar1 = (*(code *)&SUB_4008c01c)(param_5);
    if ((*(uint *)(param_1 + 0x118) & 0x20) == 0) {
      iVar8 = param_1 + 0x70;
      do {
        if (((*(int *)(iVar8 + 4) == 3) &&
            (iVar2 = (*(code *)&SUB_4008b33c)("olicies",*(undefined4 *)(iVar8 + 8),3), iVar2 == 0))
           && (iVar2 = FUN_40143ea4(iVar8 + 0xc,param_5,uVar1), iVar2 == 0)) goto LAB_401443b4;
        iVar8 = *(int *)(iVar8 + 0x18);
      } while (iVar8 != 0);
      uStack_fc = 4;
      memw();
    }
    else {
      puVar5 = (uint *)(param_1 + 0xf8);
      do {
        if (((*puVar5 & 0x1f) == 2) && (iVar8 = FUN_40143ea4(puVar5,param_5,uVar1), iVar8 == 0))
        goto LAB_401443b4;
        puVar5 = (uint *)puVar5[3];
      } while (puVar5 != (uint *)0x0);
      uStack_fc = 4;
    }
  }
LAB_401442a3:
  memw();
  uVar1 = FUN_40186520(param_1 + 0xcc);
  puStack_e0 = param_4 + 1;
  memw();
  iVar8 = FUN_40186858(puStack_e0,uVar1);
  if (iVar8 != 0) {
    uStack_fc = uStack_fc | 0x8000;
  }
  memw();
  iVar8 = FUN_40143f60(param_4,param_1 + 0xcc);
  if (iVar8 != 0) {
    uStack_fc = uStack_fc | 0x10000;
  }
  uStack_100 = 0;
  iStack_dc = 0;
  uVar7 = 0;
LAB_401442ec:
  puVar6[1] = 0;
  uVar9 = uStack_100 + 1;
  *puVar6 = param_1;
  memw();
  iVar8 = FUN_4018680c(param_1 + 0xa8);
  if (iVar8 != 0) {
    puVar6[1] = 1;
  }
  memw();
  iVar8 = FUN_40186814(param_1 + 0x90);
  if (iVar8 != 0) {
    puVar6[1] = puVar6[1] | 0x200;
  }
  if (uVar7 == 0) {
    if ((*(int *)(param_1 + 0x148) == 0) ||
       ((*param_4 & 1 << ((char)*(int *)(param_1 + 0x148) - 1U & 0x1f)) == 0)) {
      puVar6[1] = puVar6[1] | 0x4000;
    }
    memw();
    iVar8 = FUN_40186858(puStack_e0,*(undefined4 *)(param_1 + 0x14c));
    if (iVar8 != 0) {
      puVar6[1] = puVar6[1] | 0x8000;
    }
    uVar11 = param_2;
    if (uVar9 == 1) {
      memw();
      iVar8 = FUN_40143dec(param_1 + 0x50,param_1 + 0x70);
      uVar10 = param_2;
      if (iVar8 != 0) {
        iStack_ec = 2;
        memw();
        uStack_f4 = 1;
        goto LAB_401443e0;
      }
      for (; uVar10 != 0; uVar10 = *(uint *)(uVar10 + 0x154)) {
        if ((*(int *)(param_1 + 8) == *(int *)(uVar10 + 8)) &&
           (iVar8 = (*(code *)&SUB_4008b33c)
                              (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(uVar10 + 0xc)),
           iVar8 == 0)) goto LAB_401446a8;
      }
    }
    iStack_ec = 2;
    uStack_f4 = 1;
LAB_401443e0:
    do {
      uStack_f8 = 0;
      uStack_d8 = 0;
      while (uVar11 != 0) {
        iVar8 = FUN_40143dec(param_1 + 0x50,uVar11 + 0x70);
        if ((iVar8 == 0) &&
           ((((uStack_f4 != 0 && (*(int *)(uVar11 + 0x1c) < 3)) ||
             ((*(int *)(uVar11 + 0x11c) != 0 && (iVar8 = FUN_40144164(uVar11,4), iVar8 == 0)))) &&
            (((int)*(uint *)(uVar11 + 0x120) < 1 || (uVar9 - iStack_dc <= *(uint *)(uVar11 + 0x120))
             ))))) {
          uVar1 = FUN_40138f28(*(undefined4 *)(param_1 + 0x148));
          memw();
          uVar12 = FUN_401864c4();
          iVar8 = FUN_40139210(uVar1,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x14)
                               ,auStack_64);
          if (iVar8 == 0) {
            memw();
            iVar8 = FUN_401864ec(uVar11 + 0xcc,*(undefined4 *)(param_1 + 0x14c));
            if (iVar8 == 0) goto LAB_40144470;
            memw();
            iVar8 = FUN_40139ce0(*(undefined4 *)(param_1 + 0x14c),*(undefined4 *)(param_1 + 0x150),
                                 uVar11 + 0xcc,*(undefined4 *)(param_1 + 0x148),auStack_64,uVar12,
                                 *(undefined4 *)(param_1 + 0x144),*(undefined4 *)(param_1 + 0x140));
          }
          else {
LAB_40144470:
            iVar8 = -1;
          }
          if ((iVar8 == 0) || ((uStack_f4 & 1) == 0)) {
            iVar2 = FUN_4018680c(uVar11 + 0xa8);
            if ((iVar2 == 0) &&
               (iVar2 = FUN_40186814(uVar11 + 0x90), param_5 = (uint)(iVar8 == 0), iVar2 == 0))
            goto LAB_401444ec;
            if (uStack_f8 == 0) {
              uStack_f8 = uVar11;
              uStack_d8 = (uint)(iVar8 == 0);
            }
          }
        }
        uVar11 = *(uint *)(uVar11 + 0x154);
        memw();
      }
      param_5 = uStack_d8;
      uVar11 = uStack_f8;
      if (uStack_f8 != 0) {
LAB_401444ec:
        uStack_f8 = uVar11;
        if (uVar9 != 1) {
          memw();
          iVar8 = FUN_40143dec(param_1 + 0x50,param_1 + 0x70);
          if (iVar8 == 0) {
            iStack_dc = iStack_dc + 1;
          }
        }
        puVar5 = (uint *)0x0;
        if (((uStack_f4 & 1) != 0) || (uVar9 < 9)) goto LAB_40144536;
        goto LAB_40144510;
      }
      if (iStack_ec == 1) goto LAB_40144692;
      iStack_ec = 1;
      memw();
      uVar11 = *(uint *)(param_1 + 0x154);
      uStack_f4 = uVar7;
    } while( true );
  }
  goto LAB_401446a8;
LAB_401443b4:
  uStack_fc = 0;
  memw();
  goto LAB_401442a3;
LAB_40144692:
  auStack_c0[uStack_100 * 2 + 3] = auStack_c0[uStack_100 * 2 + 3] | 8;
LAB_401446a8:
  puVar6 = auStack_c0 + uVar9 * 2;
  param_5 = 0xffffff64;
  auStack_c0[3] = auStack_c0[3] | uStack_fc;
LAB_401446c1:
  uVar9 = uVar9 - 1;
  auStack_c0[1] = puVar6[1];
  if ((param_7 == (code *)0x0) ||
     (param_1 = (*param_7)(param_8,*puVar6,uVar9,auStack_c0 + 1), param_1 == 0)) goto LAB_401446ce;
  if (param_1 == 0xffffd900) {
LAB_40144510:
    param_1 = 0xffffd000;
  }
LAB_40144513:
  *param_6 = 0xffffffff;
  goto LAB_40144519;
LAB_401446ce:
  puVar6 = puVar6 + -2;
  uVar7 = *param_6;
  *param_6 = uVar7 | auStack_c0[1];
  if (uVar9 == 0) goto code_r0x401446e0;
  goto LAB_401446c1;
code_r0x401446e0:
  param_1 = 0;
  if ((uVar7 | auStack_c0[1]) != 0) {
    param_1 = 0xffffd900;
    memw();
  }
LAB_40144519:
  puVar6 = puStack_24;
  puVar5 = _DAT_3ffc5708;
  memw();
  memw();
  if (puStack_24 == _DAT_3ffc5708) {
    return;
  }
  memw();
  (*(code *)&SUB_40082ec4)();
LAB_40144536:
  if (param_5 == 0) {
    puVar6[1] = puVar6[1] | 8;
  }
  iVar2 = uStack_f8 + 0xcc;
  memw();
  iVar8 = FUN_40143f60(param_4,iVar2);
  if (iVar8 != 0) {
    puVar6[1] = puVar6[1] | 0x10000;
  }
  for (iVar8 = param_3; iVar8 != 0; iVar8 = *(int *)(iVar8 + 0xf4)) {
    if (*(int *)(iVar8 + 0x18) != 0) {
      memw();
      iVar3 = FUN_40143dec(iVar8 + 0x34,uStack_f8 + 0x70);
      if (iVar3 == 0) {
        iVar3 = FUN_40144164(uStack_f8,2);
        if (iVar3 == 0) {
          iVar3 = *(int *)(iVar8 + 0xe8);
          if ((iVar3 == 0) || ((*param_4 & 1 << ((char)iVar3 - 1U & 0x1f)) == 0)) {
            puVar5 = (uint *)((uint)puVar5 | 0x20000);
          }
          iVar4 = FUN_40186858(puStack_e0,*(undefined4 *)(iVar8 + 0xec));
          if (iVar4 != 0) {
            puVar5 = (uint *)((uint)puVar5 | 0x40000);
          }
          uVar1 = FUN_40138f28(iVar3);
          iVar3 = FUN_40139210(uVar1,*(undefined4 *)(iVar8 + 0x14),*(undefined4 *)(iVar8 + 0x10),
                               auStack_64);
          if (iVar3 != 0) goto LAB_40144592;
          iVar3 = FUN_40143f60(param_4,iVar2);
          if (iVar3 != 0) {
            puVar5 = (uint *)((uint)puVar5 | 0x10000);
          }
          uVar12 = *(undefined4 *)(iVar8 + 0xec);
          uVar13 = *(undefined4 *)(iVar8 + 0xf0);
          uVar14 = *(undefined4 *)(iVar8 + 0xe8);
          memw();
          uVar1 = FUN_401864c4(uVar1);
          memw();
          iVar3 = FUN_40139ce0(uVar12,uVar13,iVar2,uVar14,auStack_64,uVar1,
                               *(undefined4 *)(iVar8 + 0xe4),*(undefined4 *)(iVar8 + 0xe0));
          if (iVar3 != 0) goto LAB_40144592;
          iVar3 = FUN_4018680c(iVar8 + 0x6c);
          if (iVar3 != 0) {
            puVar5 = (uint *)((uint)puVar5 | 0x20);
          }
          iVar3 = FUN_40186814(iVar8 + 0x54);
          if (iVar3 != 0) {
            puVar5 = (uint *)((uint)puVar5 | 0x400);
          }
          iVar3 = FUN_401441e4(param_1,iVar8);
          if (iVar3 == 0) goto LAB_40144580;
          uVar7 = 2;
        }
        else {
LAB_40144592:
          uVar7 = 0x10;
        }
        puVar5 = (uint *)((uint)puVar5 | uVar7);
        break;
      }
    }
LAB_40144580:
  }
  puVar6[1] = puVar6[1] | (uint)puVar5;
  puVar6 = puVar6 + 2;
  memw();
  param_1 = uStack_f8;
  uVar7 = uStack_f4;
  uStack_100 = uVar9;
  goto LAB_401442ec;
}

