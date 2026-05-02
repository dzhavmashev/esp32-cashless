// Function : FUN_40131340
// Address  : 0x40131340
// Size     : 346 bytes


undefined4 FUN_40131340(undefined1 *param_1,uint param_2,uint *param_3,char *param_4,uint param_5)

{
  char cVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  byte bVar8;
  int iVar9;
  uint uVar10;
  char *pcVar11;
  
  uVar10 = 0;
  uVar6 = 0;
  uVar4 = 0;
  while (uVar4 < param_5) {
    iVar9 = param_5 - uVar4;
    uVar5 = uVar4;
    bVar2 = false;
    while( true ) {
      cVar3 = param_4[uVar5];
      uVar4 = param_5;
      if (cVar3 != ' ') break;
      uVar5 = uVar5 + 1;
      bVar2 = true;
      iVar9 = iVar9 + -1;
      if (iVar9 == 0) goto LAB_4013135c;
    }
    if (param_5 == uVar5) break;
    cVar1 = cVar3;
    if ((1 < param_5 - uVar5) && (cVar3 == '\r')) {
      cVar1 = (param_4 + uVar5)[1];
    }
    if (cVar1 != '\n') {
      if (bVar2) {
        return 0xffffffd4;
      }
      if (cVar3 < '\0') {
        return 0xffffffd4;
      }
      if (cVar3 == '=') {
        uVar10 = uVar10 + 1;
        if (2 < uVar10) {
          return 0xffffffd4;
        }
      }
      else {
        if (uVar10 != 0) {
          return 0xffffffd4;
        }
        memw();
        uVar4 = FUN_4013343c();
        if ((uVar4 & 0x80) != 0) {
          return 0xffffffd4;
        }
      }
      uVar6 = uVar6 + 1;
    }
    uVar4 = uVar5 + 1;
  }
LAB_4013135c:
  if (uVar6 == 0) {
    *param_3 = 0;
  }
  else {
    uVar6 = ((uVar6 & 7) * 6 + 7 >> 3) + ((uVar6 >> 3) * 6 - uVar10);
    if ((param_1 == (undefined1 *)0x0) || (param_2 < uVar6)) {
      *param_3 = uVar6;
      memw();
      return 0xffffffd6;
    }
    pcVar11 = param_4 + uVar4;
    uVar4 = 0;
    uVar6 = 0;
    uVar10 = uVar6;
    puVar7 = param_1;
    while (pcVar11 != param_4) {
      bVar8 = *param_4 - 10;
      if ((0x16 < bVar8) || ((1 << (bVar8 & 0x1f) & 0x400009U) == 0)) {
        uVar4 = uVar4 << 6;
        if (*param_4 == '=') {
          uVar6 = uVar6 + 1;
        }
        else {
          memw();
          cVar3 = FUN_4013343c();
          uVar4 = uVar4 | (int)cVar3;
        }
        uVar10 = uVar10 + 1;
        if (uVar10 == 4) {
          *puVar7 = (char)(uVar4 >> 0x10);
          memw();
          if (uVar6 < 2) {
            puVar7[1] = (char)(uVar4 >> 8);
            memw();
            if (uVar6 == 0) {
              puVar7[2] = (char)uVar4;
              memw();
              puVar7 = puVar7 + 3;
              memw();
              uVar10 = 0;
              goto LAB_40131451;
            }
            puVar7 = puVar7 + 2;
            uVar6 = 1;
            memw();
          }
          else {
            puVar7 = puVar7 + 1;
          }
          uVar10 = 0;
        }
      }
LAB_40131451:
      param_4 = param_4 + 1;
      memw();
    }
    *param_3 = (int)puVar7 - (int)param_1;
    memw();
  }
  memw();
  return 0;
}

