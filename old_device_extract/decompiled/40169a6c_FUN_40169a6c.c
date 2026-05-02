// Function : FUN_40169a6c
// Address  : 0x40169a6c
// Size     : 467 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40169a6c(uint param_1,char param_2,byte *param_3,int param_4,int param_5,int param_6,
                 byte param_7,int param_8)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  byte local_60 [16];
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  int iStack_44;
  byte *pbStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  uint uStack_30;
  
  uStack_50 = param_1 & 0xff;
  uStack_4c = (uint)param_7;
  iStack_44 = 0x80;
  if (uStack_50 == 0) {
    iStack_44 = 0;
  }
  pbStack_40 = param_3;
  iStack_3c = param_4;
  iStack_38 = param_5;
  iStack_34 = param_6;
  (*(code *)&SUB_4008b3d0)(local_60,0x3ffc32bc,10);
  uVar2 = (uStack_4c - DAT_3ffc0740) - 2 & 0xff;
  uStack_48 = uVar2;
  if (param_2 == '\0') {
    uVar2 = 0;
  }
  if (uVar2 < uStack_4c) {
    uVar3 = 0;
    uStack_30 = (uint)(uStack_50 != 0);
    uVar4 = 0;
    do {
      if (param_2 == '\0') {
        if ((uVar2 & 1) == 0) {
          uVar1 = *(ushort *)((uVar2 >> 1) * 4 + param_8);
        }
        else {
          uVar1 = *(ushort *)((uVar2 >> 1) * 4 + param_8 + 2);
        }
        uVar6 = (uint)uVar1;
        uVar3 = ((int)uVar6 >> 3 & 1U) * 6 + (uVar6 & 7);
      }
      else {
        uVar6 = (uint)local_60[(uVar3 / 6) * 2] * 8 + uVar3 % 6 & 0xff | (uint)*pbStack_40 << 8;
      }
      if ((uVar2 < uStack_48) || (uStack_30 != 0)) {
        if ((uVar6 & 0xffffff00) != (uint)pbStack_40[uVar4] << 8) {
          uVar4 = uVar4 + 1 & 0xff;
        }
        iVar12 = 0;
        iVar13 = 0x80;
        uVar5 = *(uint *)(uVar4 * 4 + iStack_3c);
        uVar7 = uVar5 >> 0x10;
        uVar5 = uVar5 & 0xffff;
        iVar10 = 0x200000;
        if (uStack_50 == 0) goto LAB_40169bac;
      }
      else {
        uVar5 = *(uint *)(((int)DAT_3ffca519 - 1U & 0xffff) * 4 + iStack_34);
        uVar7 = uVar5 >> 0x10;
        uVar5 = uVar5 & 0xffff;
LAB_40169bac:
        uVar8 = uVar3 / 6;
        uVar11 = *(uint *)(((uVar8 < 3) * uVar8 + (uint)(uVar8 >= 3) * 3) * 4 + iStack_38);
        uVar8 = uVar11 >> 0x10;
        iVar13 = (int)uVar8 >> 1;
        iVar10 = (uVar11 & 0xffff) << 0xd;
        iVar12 = uVar8 << 0x1f;
      }
      iVar9 = 0;
      if (uStack_50 == 0) {
        uVar8 = uVar6 >> 3 & 0x1f;
        uVar8 = (uVar8 >> 4) + (uVar6 >> 3 & 1) + (uVar8 >> 3 & 1) + (uVar8 >> 2 & 1) +
                (uVar8 >> 1 & 1);
        iVar9 = (*(ushort *)(((uVar8 < 3) * uVar8 + (uint)(uVar8 >= 3) * 3) * 2 + 0x3ffca500) &
                0x7ff) << 2;
      }
      (**(code **)(_DAT_3ffc7e64 + 0x34))
                (uVar6 * 0x20000 + uVar7 * 0x100 + iVar13,uVar5 * 0x400000 + iVar12 + iVar10 + iVar9
                 ,uVar2 + iStack_44 & 0xff);
      if (param_2 != '\0') {
        uVar3 = uVar3 + 1 & 0xff;
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < uStack_4c);
  }
  return;
}

