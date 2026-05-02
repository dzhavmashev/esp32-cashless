// Function : FUN_4010cb74
// Address  : 0x4010cb74
// Size     : 482 bytes


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4010cb74(uint *param_1,uint *param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  char *pcVar9;
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  char cStack_28;
  char cStack_24;
  
  param_3 = param_3 & 0xffff;
  if (param_2 == (uint *)0x0) {
    param_2 = &DAT_3f411ef4;
  }
  if (param_1 == (uint *)0x0) {
    return 0xf0;
  }
  if (param_1[0xf] != 0) {
    return 0xfa;
  }
  iVar5 = 3;
  if ((*(byte *)((int)param_1 + 0x31) >> 2 & 1) == 0) {
    iVar5 = 4;
  }
  puVar7 = param_2 + 5;
  if ((((char)*puVar7 == '\x06') && (cVar4 = (char)param_2[4], cVar4 == '\0')) &&
     (uVar8 = *param_2, (uVar8 & 0xc0ff) == 0x80fe)) {
    uStack_34 = param_2[1];
    uStack_30 = param_2[2];
    uStack_2c = param_2[3];
    param_2 = &local_38;
    memw();
    memw();
    local_38 = uVar8;
    cStack_28 = cVar4;
    cStack_24 = (char)*puVar7;
    iVar2 = FUN_401172d4(&local_38);
    if (iVar2 != 0) {
      if (((local_38 & 0xc0ff) == 0x80fe) || (((local_38 & 0x8fff) - 0x1ff & 0xfffffeff) == 0)) {
        cVar4 = *(char *)(iVar2 + 0xee) + '\x01';
      }
      param_2 = &local_38;
      cStack_28 = cVar4;
      memw();
    }
  }
  iVar2 = 0;
  pcVar9 = "_free";
  if (param_3 == 0) {
    param_3 = FUN_4010c910();
    if (param_3 == 0) {
      return 0xfe;
    }
  }
  else {
    do {
      for (puVar7 = (uint *)**(undefined4 **)pcVar9; puVar7 != (uint *)0x0;
          puVar7 = (uint *)puVar7[0xd]) {
        if ((*(ushort *)((int)puVar7 + 0x42) == param_3) &&
           (((*(byte *)((int)param_1 + 0x31) & 4) == 0 || ((*(byte *)((int)puVar7 + 0x31) & 4) == 0)
            ))) {
          cVar4 = (char)puVar7[5];
          cVar1 = (char)param_2[5];
          if ((cVar4 == '\x06') == (cVar1 == '\x06')) {
            uVar6 = *puVar7;
            uVar8 = uVar6;
            if (cVar4 == '\x06') {
              if (((uVar6 == 0) && (puVar7[1] == 0)) && (puVar7[2] == 0)) {
                uVar8 = puVar7[3];
                goto joined_r0x4010cd09;
              }
            }
            else {
joined_r0x4010cd09:
              if (uVar8 == 0) {
                return 0xf8;
              }
            }
            uVar8 = *param_2;
            if (cVar1 == '\x06') {
              if (((uVar8 == 0) && (param_2[1] == 0)) && ((param_2[2] == 0 && (param_2[3] == 0)))) {
                return 0xf8;
              }
              if (((cVar4 == '\x06') && (uVar6 == uVar8)) &&
                 ((puVar7[1] == param_2[1] &&
                  ((puVar7[2] == param_2[2] && (puVar7[3] == param_2[3])))))) {
                uVar6 = (uint)(byte)puVar7[4];
                uVar8 = (uint)(byte)param_2[4];
                memw();
LAB_4010cd1a:
                if (uVar6 == uVar8) {
                  return 0xf8;
                }
              }
            }
            else {
              if (uVar8 == 0) {
                return 0xf8;
              }
              if (cVar1 == cVar4) goto LAB_4010cd1a;
            }
          }
        }
      }
      iVar2 = iVar2 + 1;
      pcVar9 = pcVar9 + 4;
    } while (iVar2 != iVar5);
  }
  cVar4 = (char)param_2[5];
  uVar6 = *param_2;
  uVar8 = uVar6;
  if (cVar4 == '\x06') {
    if (((uVar6 == 0) && (param_2[1] == 0)) && (param_2[2] == 0)) {
      uVar8 = param_2[3];
      goto joined_r0x4010cc45;
    }
  }
  else {
joined_r0x4010cc45:
    if ((uVar8 == 0) && ((char)param_1[5] == cVar4)) goto LAB_4010cd31;
  }
  *(char *)(param_1 + 5) = cVar4;
  memw();
  uVar8 = param_2[5];
  *param_1 = uVar6;
  if ((char)uVar8 == '\x06') {
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    uVar3 = (undefined1)param_2[4];
    param_1[3] = param_2[3];
  }
  else {
    uVar3 = 0;
    param_1[3] = 0;
    param_1[2] = 0;
    param_1[1] = 0;
    memw();
  }
  *(undefined1 *)(param_1 + 4) = uVar3;
  memw();
  memw();
LAB_4010cd31:
  *(short *)((int)param_1 + 0x42) = (short)param_3;
  memw();
  param_1[0xd] = (uint)_DAT_3ffc8410;
  memw();
  _DAT_3ffc8410 = param_1;
  FUN_40113284();
  return 0;
}

