// Function : FUN_40169034
// Address  : 0x40169034
// Size     : 341 bytes


uint FUN_40169034(int param_1,uint param_2,int param_3,char *param_4,uint param_5,uint param_6,
                 byte param_7)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  ushort local_60 [8];
  uint uStack_50;
  int iStack_4c;
  uint uStack_48;
  int iStack_44;
  uint uStack_40;
  char *pcStack_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  int iStack_2c;
  
  uStack_50 = (uint)param_7;
  uStack_38 = param_6 & 0xff;
  iStack_4c = param_1;
  iStack_44 = param_3;
  (*(code *)&SUB_4008b3d0)(local_60,0x3ffc32bc,10);
  uVar4 = 0;
  uVar5 = 0;
  iVar2 = (int)uStack_38 / 6 + ((int)uStack_38 >> 0x1f);
  uStack_40 = param_5 & 0xff;
  uStack_34 = uStack_38 + iVar2 * -6;
  iVar6 = (param_5 & 0xff) - 1;
  uStack_48 = param_2 & 0xff;
  uVar3 = 0;
  uStack_30 = uStack_34 & 0xffff;
  pcStack_3c = param_4;
  iStack_2c = iVar2 * 2;
  do {
    if ((uVar4 == (int)*param_4) && ((int)uVar3 < iVar6)) {
      uVar3 = uVar3 + 1 & 0xff;
      param_4 = pcStack_3c + uVar3;
      cVar1 = *param_4;
      while (uVar4 = uStack_38, iVar2 = iStack_2c, uVar8 = uStack_30, uVar9 = uStack_34,
            cVar1 == '\0') {
        if (iVar6 <= (int)uVar3) goto LAB_401690f2;
        uVar3 = uVar3 + 1 & 0xff;
        param_4 = pcStack_3c + uVar3;
        cVar1 = *param_4;
      }
      if ((int)uVar3 < iVar6) {
        uVar4 = 0;
        iVar2 = 0;
        uVar8 = 0;
        uVar9 = 0;
      }
    }
    else {
      iVar2 = (uVar4 / 6) * 2;
      uVar8 = uVar4 % 6;
      uVar9 = uVar4 % 6;
    }
LAB_401690f2:
    iVar2 = (*(ushort *)((int)local_60 + iVar2) & 0x1fff) * 8;
    uVar8 = (uint)*(byte *)(iStack_44 + uVar3) * 0x100 + iVar2 + uVar8 & 0xffff;
    puVar7 = (uint *)(((int)(char)uVar5 >> 1) * 4 + iStack_4c);
    if ((uVar5 & 1) == 0) {
      *puVar7 = uVar8;
    }
    else {
      *puVar7 = *puVar7 + uVar8 * 0x10000;
    }
    if (uStack_50 != 0) {
      FUN_40168620(0x3ffc3344,uVar5,uVar8,*(byte *)(iStack_44 + uVar3),iVar2,uVar9,uStack_40,uVar3,
                   (int)*param_4);
    }
    if (uStack_48 < uVar4) {
      if (uStack_50 != 0) {
        FUN_40168620(0x3ffc3374,uVar5 & 0xff);
        return uVar5 & 0xff;
      }
      return uVar5 & 0xff;
    }
    uVar5 = uVar5 + 1;
    uVar4 = uVar4 + 1 & 0xff;
    if (uVar5 == 0x7f) {
      return 0x55;
    }
  } while( true );
}

