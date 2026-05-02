// Function : FUN_401167d8
// Address  : 0x401167d8
// Size     : 593 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401167d8(int param_1,undefined4 *param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  pbVar4 = *(byte **)(param_1 + 4);
  if (*pbVar4 >> 4 != 4) goto LAB_401167e6;
  uVar6 = (*pbVar4 & 0xf) * 4;
  uVar2 = FUN_40185290(*(undefined2 *)(pbVar4 + 2));
  if (uVar2 < *(ushort *)(param_1 + 8)) {
    FUN_4010bd2c(param_1,uVar2);
  }
  if (((*(ushort *)(param_1 + 10) < uVar6) || (*(ushort *)(param_1 + 8) < uVar2)) || (uVar6 < 0x14))
  goto LAB_401167e6;
  _DAT_3ffc83e4 = *(uint *)(pbVar4 + 0x10);
  DAT_3ffc83f8 = 0;
  _DAT_3ffc83f0 = 0;
  _DAT_3ffc83ec = 0;
  _DAT_3ffc83e8 = 0;
  DAT_3ffc83f4 = 0;
  memw();
  _DAT_3ffc83cc = *(uint *)(pbVar4 + 0xc);
  _DAT_3ffc83d8 = 0;
  _DAT_3ffc83d4 = 0;
  _DAT_3ffc83d0 = 0;
  DAT_3ffc83e0 = 0;
  DAT_3ffc83dc = 0;
  memw();
  puVar5 = param_2;
  if ((*(uint *)(pbVar4 + 0x10) & 0xf0) == 0xe0) {
    if (((*(byte *)((int)param_2 + 0xeb) & 0x20) == 0) ||
       (iVar3 = FUN_40185484(param_2,&DAT_3ffc83e4), iVar3 == 0)) goto LAB_401168a9;
    if ((_DAT_3ffc83e4 != 0x10000e0) || (_DAT_3ffc83cc != 0)) goto LAB_401168d5;
  }
  else {
    iVar3 = FUN_401166c0(param_2);
    if (iVar3 == 0) {
      if (DAT_3ffc83e4 != '\x7f') {
        puVar5 = (undefined4 *)&DAT_3ffc83fc;
        do {
          puVar5 = (undefined4 *)*puVar5;
          if (puVar5 == (undefined4 *)0x0) goto LAB_401168a9;
        } while ((puVar5 == param_2) || (iVar3 = FUN_401166c0(puVar5), iVar3 == 0));
        goto LAB_401168d5;
      }
LAB_401168a9:
      if ((pbVar4[9] != 0x11) || (puVar5 = param_2, *(short *)(pbVar4 + uVar6 + 2) != 0x4400)) {
        memw();
        puVar5 = (undefined4 *)0x0;
        goto LAB_401168d5;
      }
    }
    else {
      if (param_2 == (undefined4 *)0x0) goto LAB_401168a9;
LAB_401168d5:
      if ((_DAT_3ffc83cc != 0) &&
         ((iVar3 = FUN_4018549c(_DAT_3ffc83cc,param_2), iVar3 != 0 ||
          ((_DAT_3ffc83cc & 0xf0) == 0xe0)))) goto LAB_401167e6;
    }
    if (puVar5 == (undefined4 *)0x0) goto LAB_401167e6;
  }
  if ((pbVar4[6] & 0x3f) != 0 || pbVar4[7] != 0) {
LAB_401167e6:
    FUN_4010bb10(param_1);
    return 0;
  }
  _DAT_3ffc83c8 = (*pbVar4 & 0xf) << 2;
  memw();
  memw();
  _DAT_3ffc83b8 = puVar5;
  _DAT_3ffc83bc = param_2;
  _DAT_3ffc83c0 = pbVar4;
  iVar3 = FUN_4010c1b0(param_1,param_2);
  if (iVar3 != 1) {
    memw();
    FUN_4010ba9c(param_1,uVar6);
    bVar1 = pbVar4[9];
    if (bVar1 == 2) {
      FUN_401163c4(param_1,param_2,&DAT_3ffc83e4);
    }
    else {
      if (bVar1 < 3) {
        if (bVar1 == 1) {
          FUN_40115ecc(param_1,param_2);
          goto LAB_401169fa;
        }
      }
      else {
        if (bVar1 == 6) {
          FUN_4010efac(param_1,param_2);
          goto LAB_401169fa;
        }
        if (bVar1 == 0x11) {
          FUN_40113498(param_1,param_2);
          goto LAB_401169fa;
        }
      }
      if (((iVar3 != 2) && (iVar3 = FUN_4018549c(_DAT_3ffc83e4,puVar5), iVar3 == 0)) &&
         ((_DAT_3ffc83e4 & 0xf0) != 0xe0)) {
        FUN_4010baf0(param_1,uVar6);
        FUN_40116068(param_1,2);
      }
      FUN_4010bb10(param_1);
    }
  }
LAB_401169fa:
  memw();
  memw();
  _DAT_3ffc83b8 = (undefined4 *)0x0;
  _DAT_3ffc83bc = (undefined4 *)0x0;
  _DAT_3ffc83c0 = (byte *)0x0;
  _DAT_3ffc83c8 = 0;
  _DAT_3ffc83cc = 0;
  _DAT_3ffc83e4 = 0;
  return 0;
}

