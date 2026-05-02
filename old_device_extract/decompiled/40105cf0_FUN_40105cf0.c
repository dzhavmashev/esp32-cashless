// Function : FUN_40105cf0
// Address  : 0x40105cf0
// Size     : 506 bytes


undefined4 FUN_40105cf0(char *param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  uint uVar9;
  ushort *puVar10;
  
  (*(code *)&SUB_4008b530)(param_3 + 8,0,4);
  *param_3 = 2;
  param_3[1] = 8;
  param_3[2] = 8;
  param_3[3] = 1;
  param_3[4] = 0;
  param_3[6] = 0;
  param_3[5] = 0;
  param_3[7] = 0x20;
  if (param_2 < 4) {
    return 0xffffffff;
  }
  if (*param_1 != '0') {
    return 0xfffffffe;
  }
  if ((uint)(byte)param_1[1] != param_2 - 2) {
    return 0xfffffffe;
  }
  if (*(short *)(param_1 + 2) != 1) {
    return 0xfffffffe;
  }
  iVar6 = param_2 - 4;
  puVar10 = (ushort *)(param_1 + 4);
  if (iVar6 < 4) {
    if (0 < iVar6) {
      return 0xfffffffd;
    }
  }
  else {
    memw();
    uVar3 = FUN_40105c04();
    param_3[2] = uVar3;
    iVar6 = param_2 - 8;
    puVar10 = (ushort *)(param_1 + 8);
  }
  if (iVar6 < 2) {
    uVar3 = 0xfffffffb;
  }
  else {
    param_3[1] = 0;
    puVar4 = puVar10 + 1;
    uVar5 = (uint)*puVar10;
    if (uVar5 == 0) {
      return 0xfffffffc;
    }
    if (iVar6 + -2 < (int)(uVar5 * 4)) {
      return 0xfffffffc;
    }
    puVar8 = puVar4;
    do {
      memw();
      uVar1 = FUN_40105c04(puVar8);
      puVar8 = puVar8 + 2;
      param_3[1] = param_3[1] | uVar1;
    } while (puVar10 + uVar5 * 2 + 1 != puVar8);
    iVar7 = iVar6 + -2 + uVar5 * -4;
    iVar6 = iVar6 + 2 + uVar5 * -4;
    if (1 < iVar7) {
      param_3[3] = 0;
      iVar7 = iVar6 + -6;
      uVar1 = (uint)puVar4[uVar5 * 2];
      if (uVar1 == 0) {
        return 0xfffffffa;
      }
      if (iVar7 < (int)(uVar1 * 4)) {
        return 0xfffffffa;
      }
      puVar10 = puVar4 + uVar5 * 2 + 1;
      do {
        memw();
        iVar2 = (*(code *)&LAB_401850ee_2)(puVar10);
        uVar9 = 1;
        if ((((iVar2 != 0xfac01) && (uVar9 = 2, iVar2 != 0xfac02)) &&
            (uVar9 = 0x400, iVar2 != 0xfac08)) &&
           ((uVar9 = 0x80, iVar2 != 0xfac05 && (uVar9 = 0x100, iVar2 != 0xfac06)))) {
          uVar9 = 0;
        }
        puVar10 = puVar10 + 2;
        param_3[3] = param_3[3] | uVar9;
      } while (puVar4 + uVar5 * 2 + uVar1 * 2 + 1 != puVar10);
      puVar10 = puVar4 + uVar5 * 2 + 1 + uVar1 * 2;
      iVar6 = iVar6 + -2 + uVar1 * -4;
      if ((int)(iVar7 + uVar1 * -4) < 2) {
        return 0;
      }
      param_3[4] = (uint)*puVar10;
      if (iVar6 < 8) {
        return 0;
      }
      iVar6 = iVar6 + -8;
      uVar5 = (uint)puVar10[1];
      param_3[5] = uVar5;
      if ((int)(uVar5 * 0x10) <= iVar6) {
        param_3[6] = puVar10 + 2;
        if ((int)(iVar6 + uVar5 * -0x10) < 4) {
          return 0;
        }
        memw();
        uVar3 = FUN_40105c04(puVar10 + 2 + uVar5 * 8);
        param_3[7] = uVar3;
        memw();
        iVar6 = FUN_40105ca0();
        if (iVar6 != 0) {
          return 0;
        }
        return 0xfffffff6;
      }
      param_3[5] = 0;
      memw();
      return 0xfffffff7;
    }
    uVar3 = 0xfffffff9;
    iVar6 = iVar7;
  }
  if (iVar6 != 1) {
    return 0;
  }
  return uVar3;
}

