// Function : FUN_40105eec
// Address  : 0x40105eec
// Size     : 417 bytes


undefined4 FUN_40105eec(char *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  ushort *puVar5;
  ushort *puVar6;
  int iVar7;
  ushort *puVar8;
  ushort *puVar9;
  uint uVar10;
  
  (*(code *)&SUB_4008b530)(param_3 + 8,0,4);
  *param_3 = 1;
  uVar4 = 0xffffffff;
  param_3[3] = 1;
  param_3[1] = 2;
  param_3[2] = 2;
  param_3[4] = 0;
  param_3[6] = 0;
  param_3[5] = 0;
  param_3[7] = 0;
  if (((7 < param_2) && (uVar4 = 0xfffffffe, *param_1 == -0x23)) &&
     ((uint)(byte)param_1[1] == param_2 - 2)) {
    memw();
    iVar1 = (*(code *)&LAB_401850ee_2)(param_1 + 2);
    uVar4 = 0xfffffffe;
    if ((iVar1 == 0x50f201) && (*(short *)(param_1 + 6) == 1)) {
      iVar1 = param_2 - 8;
      puVar8 = (ushort *)(param_1 + 8);
      if (iVar1 < 4) {
        if (0 < iVar1) {
          return 0xfffffffd;
        }
      }
      else {
        uVar4 = FUN_40105c4c();
        param_3[2] = uVar4;
        iVar1 = param_2 - 0xc;
        puVar8 = (ushort *)(param_1 + 0xc);
      }
      if (iVar1 < 2) {
        uVar4 = 0xfffffffb;
      }
      else {
        param_3[1] = 0;
        puVar9 = puVar8 + 1;
        uVar3 = (uint)*puVar8;
        if (uVar3 == 0) {
          return 0xfffffffc;
        }
        if (iVar1 + -2 < (int)(uVar3 * 4)) {
          return 0xfffffffc;
        }
        puVar5 = puVar9;
        do {
          puVar6 = puVar5 + 2;
          memw();
          uVar2 = FUN_40105c4c(puVar5);
          param_3[1] = param_3[1] | uVar2;
          puVar5 = puVar6;
        } while (puVar6 != puVar8 + uVar3 * 2 + 1);
        iVar7 = iVar1 + -2 + uVar3 * -4;
        if (1 < iVar7) {
          param_3[3] = 0;
          iVar1 = iVar1 + uVar3 * -4 + -4;
          uVar2 = (uint)puVar9[uVar3 * 2];
          if (uVar2 == 0) {
            return 0xfffffffa;
          }
          if (iVar1 < (int)(uVar2 * 4)) {
            return 0xfffffffa;
          }
          puVar8 = puVar9 + uVar3 * 2 + 1;
          do {
            memw();
            iVar7 = (*(code *)&LAB_401850ee_2)(puVar8);
            uVar10 = 1;
            if (((iVar7 != 0x50f201) && (uVar10 = 2, iVar7 != 0x50f202)) &&
               (uVar10 = 0x10, iVar7 != 0x50f200)) {
              uVar10 = 0;
            }
            puVar8 = puVar8 + 2;
            param_3[3] = param_3[3] | uVar10;
          } while (puVar8 != puVar9 + uVar3 * 2 + uVar2 * 2 + 1);
          if ((int)(iVar1 + uVar2 * -4) < 2) {
            return 0;
          }
          param_3[4] = (uint)(puVar9 + uVar3 * 2 + 1)[uVar2 * 2];
          memw();
          return 0;
        }
        uVar4 = 0xfffffff9;
        iVar1 = iVar7;
      }
      if (iVar1 != 1) {
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}

