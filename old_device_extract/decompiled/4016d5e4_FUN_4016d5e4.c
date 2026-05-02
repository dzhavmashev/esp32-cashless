// Function : FUN_4016d5e4
// Address  : 0x4016d5e4
// Size     : 518 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4016d5e4(byte *param_1,undefined4 param_2)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  int iVar7;
  char cVar8;
  uint uVar9;
  int iVar10;
  short sVar11;
  char cStack_50;
  byte abStack_4f [15];
  int iStack_40;
  int iStack_3c;
  byte *pbStack_38;
  undefined4 uStack_34;
  int iStack_30;
  uint uStack_2c;
  int iStack_28;
  uint uStack_24;
  
  bVar1 = *param_1;
  uVar4 = (uint)bVar1;
  iStack_3c = uVar4 << 1;
  iStack_40 = (int)(short)iStack_3c;
  if (uVar4 < 0x4d) {
    cStack_50 = bVar1 - 0x1a;
    memw();
  }
  else {
    cStack_50 = '2';
    memw();
  }
  bVar2 = uVar4 >= 0x4d;
  pbStack_38 = param_1;
  uStack_34 = param_2;
  FUN_4016d398(0x80,&cStack_50,1,0x2b,abStack_4f,_DAT_3ffca42c,(int)(char)DAT_3ffc075e,0);
  cVar8 = '\0';
  uStack_24 = 0;
  sVar6 = 0;
  uVar4 = abStack_4f[0] + 0x2b;
  uVar5 = uVar4 & 0xff;
  uVar9 = abStack_4f[0] + 0x11;
  DAT_3ffc075e = (byte)uVar4;
  memw();
  abStack_4f[0] = DAT_3ffc075e;
  do {
    iVar10 = (int)(char)uVar9;
    uVar4 = (iVar10 < (int)uStack_24) * uStack_24 + (uint)(iVar10 >= (int)uStack_24) * iVar10;
    uStack_2c = uVar4 & 0xff;
    if ('{' < (char)uVar5) {
      abStack_4f[0] = 0x7b;
    }
    iStack_28 = (int)(char)uVar4;
    iStack_30 = FUN_4016d33c(iStack_28);
    iVar10 = FUN_4016d33c((int)(char)abStack_4f[0]);
    uVar4 = uStack_24;
    if (cVar8 == '\0') {
      uVar4 = 1;
    }
    sVar11 = (short)iStack_30 - (short)iVar10;
    if ((((iStack_40 <= iStack_30) || ((uVar4 & 0xff) == 0)) || (sVar11 < 0x2d)) || (bVar2)) {
      if (!bVar2) goto LAB_4016d6e0;
      bVar2 = false;
      bVar3 = bVar2;
      if (0x2b < sVar11) goto LAB_4016d6cc;
    }
    else {
LAB_4016d6cc:
      if ((sVar11 < 0x2d) && (iStack_40 <= iStack_30)) {
LAB_4016d6e0:
        if ((0x2c < sVar11) || (sVar11 <= sVar6 && 0x2b < sVar11)) {
LAB_4016d6e5:
          *(bool *)uStack_34 = 0x30 < sVar11;
          memw();
          if ((int)((uint)*pbStack_38 * 2) <= iStack_30) {
            return 0;
          }
          return (int)(short)((int)(((uint)*pbStack_38 * 2 - iStack_30) + 1) >> 1);
        }
        bVar2 = false;
        bVar3 = false;
      }
      else {
        bVar2 = true;
        bVar3 = iStack_40 <= iStack_30;
      }
    }
    if ((((iVar10 < 0x51) || (bVar3)) || (abStack_4f[0] == 0x7b)) || (iStack_28 == 0))
    goto LAB_4016d6e5;
    if (bVar2) {
      if ((sVar11 < 0x31) || ((uVar4 & 0xff) == 0)) {
        iVar7 = -8;
        iVar10 = iStack_30 - iStack_3c;
        uVar4 = 0xfc;
      }
      else {
        iVar10 = iStack_30 - iStack_3c;
        uVar5 = iVar10 / 2 - 1;
        uVar4 = uVar5 & 0xff;
        iVar7 = (int)(char)uVar5 << 1;
      }
      if (iVar7 < iVar10) {
        uVar4 = (uint)((iVar10 + -1) - (iVar10 + -1 >> 0x1f)) >> 1 & 0xff;
      }
      uVar9 = uStack_2c + uVar4 & 0xff;
      abStack_4f[0] = (char)(uStack_2c + uVar4) + 0x1a;
      memw();
      sVar6 = 0;
    }
    else {
      uVar9 = (uStack_2c & 0xff) + 2;
      abStack_4f[0] = (char)uStack_2c + 0x1c;
      memw();
      sVar6 = sVar11;
    }
    cVar8 = cVar8 + '\x01';
    if (cVar8 == '\n') goto LAB_4016d6e5;
    uVar5 = (uint)abStack_4f[0];
  } while( true );
}

