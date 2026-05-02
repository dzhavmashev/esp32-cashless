// Function : FUN_40113770
// Address  : 0x40113770
// Size     : 517 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40113770(uint *param_1,uint *param_2,short param_3)

{
  char cVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  undefined1 uVar5;
  uint *puVar6;
  short sVar7;
  uint uVar8;
  undefined4 uVar9;
  uint *puVar10;
  uint uVar11;
  uint local_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  char cStack_28;
  undefined1 uStack_24;
  
  if (param_2 == (uint *)0x0) {
    param_2 = &DAT_3f411ef4;
  }
  uVar9 = 0xf0;
  puVar6 = _DAT_3ffc8424;
  if (param_1 != (uint *)0x0) {
    for (; bVar2 = false, puVar6 != (uint *)0x0; puVar6 = (uint *)puVar6[0xd]) {
      if (puVar6 == param_1) {
        bVar2 = true;
        break;
      }
    }
    if ((((char)param_2[5] == '\x06') && ((char)param_2[4] == '\0')) &&
       ((local_38 = *param_2, (local_38 & 0xc0ff) == 0x80fe ||
        (((local_38 & 0x8fff) - 0x1ff & 0xfffffeff) == 0)))) {
      uStack_24 = 6;
      memw();
      uStack_34 = param_2[1];
      uStack_30 = param_2[2];
      uStack_2c = param_2[3];
      cStack_28 = 0;
      memw();
      param_2 = &local_38;
      memw();
      iVar4 = FUN_401172d4(&local_38);
      if (iVar4 != 0) {
        if (((local_38 & 0xc0ff) == 0x80fe) ||
           (cStack_28 = '\0', ((local_38 & 0x8fff) - 0x1ff & 0xfffffeff) == 0)) {
          cStack_28 = *(char *)(iVar4 + 0xee) + '\x01';
        }
        param_2 = &local_38;
        memw();
      }
    }
    puVar6 = _DAT_3ffc8424;
    puVar10 = _DAT_3ffc8424;
    if (param_3 == 0) {
      sVar7 = 0x4000;
      do {
        puVar10 = _DAT_3ffc8424;
        sVar3 = -0x4000;
        if (_DAT_3ffbe0ce != -1) {
          sVar3 = _DAT_3ffbe0ce + 1;
        }
        while( true ) {
          _DAT_3ffbe0ce = sVar3;
          if (puVar10 == (uint *)0x0) {
            memw();
            param_3 = _DAT_3ffbe0ce;
            goto LAB_401138b4;
          }
          if (*(short *)((int)puVar10 + 0x3a) == _DAT_3ffbe0ce) break;
          puVar10 = (uint *)puVar10[0xd];
          sVar3 = _DAT_3ffbe0ce;
        }
        sVar7 = sVar7 + -1;
      } while (sVar7 != 0);
      memw();
LAB_4011390d:
      uVar9 = 0xf8;
      memw();
    }
    else {
      while (puVar10 != (uint *)0x0) {
        if ((puVar10 != param_1) &&
           ((((*(byte *)((int)param_1 + 0x31) & 4) == 0 ||
             ((*(byte *)((int)puVar10 + 0x31) & 4) == 0)) &&
            (*(short *)((int)puVar10 + 0x3a) == param_3)))) {
          cVar1 = (char)puVar10[5];
          if (cVar1 == (char)param_2[5]) {
            uVar8 = *puVar10;
            uVar11 = *param_2;
            if (cVar1 == '\x06') {
              if (((((uVar8 != uVar11) || (puVar10[1] != param_2[1])) ||
                   ((puVar10[2] != param_2[2] ||
                    ((puVar10[3] != param_2[3] || ((char)puVar10[4] != (char)param_2[4])))))) &&
                  ((uVar11 != 0 || (((param_2[1] != 0 || (param_2[2] != 0)) || (param_2[3] != 0)))))
                  ) && (((uVar8 != 0 || (puVar10[1] != 0)) ||
                        ((puVar10[2] != 0 || (puVar10[3] != 0)))))) goto LAB_4011387b;
              goto LAB_4011390d;
            }
            if (((uVar8 == uVar11) || (uVar11 == 0)) || (uVar8 == 0)) goto LAB_4011390d;
          }
          if ((cVar1 == '.') || ((char)param_2[5] == '.')) goto LAB_4011390d;
        }
LAB_4011387b:
        memw();
        puVar10 = (uint *)puVar10[0xd];
      }
LAB_401138b4:
      *(char *)(param_1 + 5) = (char)param_2[5];
      memw();
      if ((char)param_2[5] == '\x06') {
        *param_1 = *param_2;
        param_1[1] = param_2[1];
        param_1[2] = param_2[2];
        uVar5 = (undefined1)param_2[4];
        param_1[3] = param_2[3];
      }
      else {
        *param_1 = *param_2;
        uVar5 = 0;
        param_1[3] = 0;
        param_1[2] = 0;
        param_1[1] = 0;
        memw();
      }
      uVar9 = 0;
      *(undefined1 *)(param_1 + 4) = uVar5;
      *(short *)((int)param_1 + 0x3a) = param_3;
      memw();
      if (!bVar2) {
        param_1[0xd] = (uint)puVar6;
        _DAT_3ffc8424 = param_1;
      }
    }
  }
  memw();
  return uVar9;
}

