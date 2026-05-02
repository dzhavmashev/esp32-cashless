// Function : FUN_400d3f78
// Address  : 0x400d3f78
// Size     : 673 bytes


/* WARNING: Removing unreachable block (ram,0x400d40d6) */

int FUN_400d3f78(byte *param_1,uint *param_2)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  short sVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  
  if (*param_1 == 0x2b) {
    param_1 = param_1 + 1;
    iVar7 = 0;
  }
  else {
    iVar7 = 0;
    if (*param_1 == 0x2d) {
      param_1 = param_1 + 1;
      iVar7 = 1;
    }
  }
  if (*param_1 != 0x2e && 9 < (byte)(*param_1 - 0x30)) {
    return 0;
  }
  uVar9 = 0;
  uVar10 = 0;
  while( true ) {
    uVar3 = (uint)(byte)(*param_1 - 0x30);
    if (9 < uVar3) break;
    if ((0x19999999 < uVar10) || ((uVar10 == 0x19999999 && (0x99999999 < uVar9))))
    goto LAB_400d4028;
    uVar12 = uVar9 * 10;
    iVar11 = uVar10 * 10 + (int)((ulonglong)uVar9 * 10 >> 0x20);
    if ((iVar11 == -1) && (uVar10 = 0xffffffff, uVar9 = uVar12, (uVar3 ^ 0xffffffff) < uVar12))
    goto LAB_400d4028;
    uVar9 = uVar3 + uVar12;
    uVar10 = (uint)(uVar9 < uVar12) + iVar11;
    param_1 = param_1 + 1;
  }
  if (*param_1 == 0) {
    if (iVar7 == 0) {
      *(byte *)(param_2 + 2) = (byte)param_2[2] & 0x80 | 8;
      *param_2 = uVar9;
      param_2[1] = uVar10;
      return 1;
    }
    if ((uVar10 < 0x80000001) && ((uVar10 != 0x80000000 || (uVar9 == 0)))) {
      *(byte *)(param_2 + 2) = (byte)param_2[2] & 0x80 | 10;
      *param_2 = -uVar9;
      param_2[1] = -(uint)(-uVar9 != 0) - uVar10;
      return iVar7;
    }
  }
LAB_400d4028:
  uVar13 = CONCAT44(uVar10,uVar9);
  sVar8 = 0;
  while( true ) {
    if (uVar13 < 0x10000000000000) break;
    uVar13 = (*(code *)&SUB_4000cff8)((int)uVar13,(int)(uVar13 >> 0x20),10,0);
    sVar8 = sVar8 + 1;
  }
  sVar2 = (short)param_1;
  while( true ) {
    iVar11 = (int)(short)((short)param_1 + (sVar8 - sVar2));
    if (9 < (byte)(*param_1 - 0x30)) break;
    param_1 = param_1 + 1;
  }
  if (*param_1 == 0x2e) {
    while( true ) {
      param_1 = param_1 + 1;
      uVar10 = *param_1 - 0x30 & 0xff;
      if (9 < uVar10) break;
      if (uVar13 < 0x1999999999999) {
        uVar9 = uVar10 + (int)uVar13 * 10;
        uVar13 = CONCAT44((uint)(uVar9 < uVar10) +
                          (int)(uVar13 >> 0x20) * 10 + (int)((uVar13 & 0xffffffff) * 10 >> 0x20),
                          uVar9);
        iVar11 = (int)(short)((short)iVar11 + -1);
      }
    }
  }
  iVar5 = 0;
  if ((*param_1 & 0xdf) == 0x45) {
    if (param_1[1] == 0x2d) {
      param_1 = param_1 + 2;
      iVar5 = 1;
    }
    else if (param_1[1] == 0x2b) {
      param_1 = param_1 + 2;
    }
    else {
      param_1 = param_1 + 1;
    }
    iVar4 = 0;
    while ((*param_1 - 0x30 & 0xff) < 10) {
      iVar4 = (*param_1 - 0x30) + iVar4 * 10;
      if (0x134 < iVar4 + iVar11) {
        bVar1 = (byte)param_2[2];
        if (iVar5 != 0) {
          uVar10 = 0x80000000;
          if (iVar7 == 0) {
            uVar10 = 0;
          }
          *(byte *)(param_2 + 2) = bVar1 & 0x80 | 0xc;
          *param_2 = 0;
          param_2[1] = uVar10;
          return iVar5;
        }
        uVar10 = 0xfff00000;
        if (iVar7 == 0) {
          uVar10 = 0x7ff00000;
        }
        uVar9 = 0;
        goto LAB_400d418d;
      }
      param_1 = param_1 + 1;
    }
    if (iVar5 != 0) {
      iVar4 = -iVar4;
    }
  }
  else {
    iVar4 = 0;
  }
  if (*param_1 != 0) {
    return 0;
  }
  uVar10 = iVar11 + iVar4;
  uVar14 = (*(code *)&SUB_4000c978)();
  if ((int)uVar10 < 1) {
    uVar10 = -uVar10;
    pcVar6 = "s:%d\n";
  }
  else {
    pcVar6 = &DAT_3f4021c0;
  }
  iVar11 = 0;
  do {
    if (uVar10 == 0) {
LAB_400d41ff:
      uVar10 = (uint)((ulonglong)uVar14 >> 0x20);
      uVar9 = (uint)uVar14;
      if (iVar7 != 0) {
        uVar10 = uVar10 ^ 0x80000000;
      }
      bVar1 = (byte)param_2[2];
LAB_400d418d:
      *(byte *)(param_2 + 2) = bVar1 & 0x80 | 0xc;
      *param_2 = uVar9;
      param_2[1] = uVar10;
      return 1;
    }
    if (iVar11 == 9) {
      uVar14 = 0x7ff8000000000000;
      goto LAB_400d41ff;
    }
    if ((uVar10 & 1) != 0) {
      uVar15 = FUN_400d3e5c(pcVar6,iVar11);
      uVar14 = (*(code *)&SUB_4006358c)
                         ((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),(int)uVar15,
                          (int)((ulonglong)uVar15 >> 0x20));
    }
    uVar10 = (int)uVar10 >> 1;
    iVar11 = iVar11 + 1;
  } while( true );
}

