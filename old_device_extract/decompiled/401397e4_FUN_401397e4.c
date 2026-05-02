// Function : FUN_401397e4
// Address  : 0x401397e4
// Size     : 751 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_401397e4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,uint param_5,
                char *param_6,int *param_7)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  byte *pbVar4;
  char *pcVar5;
  char cVar6;
  byte bVar7;
  char *pcVar8;
  int iVar9;
  undefined4 uVar10;
  uint uStack_38;
  byte local_34 [16];
  char *pcStack_24;
  
  memw();
  memw();
  pcStack_24 = _DAT_3ffc5708;
  iVar9 = -0x1480;
  pcVar1 = param_6;
  if (param_1 != (undefined4 *)0x0) {
    memw();
    pcVar1 = (char *)(*(code *)&SUB_4008ca5c)(param_4,param_2);
    iVar9 = -0x1080;
    if (pcVar1 != (char *)0x0) {
      pcVar2 = (char *)(*(code *)&SUB_4008ca5c)(param_4,param_3);
      if ((pcVar2 == (char *)0x0) || (pcVar2 <= pcVar1)) {
        iVar9 = -0x1080;
      }
      else {
        iVar9 = (*(code *)&SUB_4008c01c)(param_2);
        pcVar1 = pcVar1 + iVar9;
        if (*pcVar1 == ' ') {
          pcVar1 = pcVar1 + 1;
        }
        if (*pcVar1 == '\r') {
          pcVar1 = pcVar1 + 1;
        }
        iVar9 = -0x1080;
        if (*pcVar1 == '\n') {
          pcVar8 = pcVar1 + 1;
          iVar9 = (*(code *)&SUB_4008c01c)(param_3);
          pcVar5 = pcVar2 + iVar9;
          if (*pcVar5 == ' ') {
            pcVar5 = pcVar5 + 1;
          }
          if (*pcVar5 == '\r') {
            pcVar5 = pcVar5 + 1;
          }
          if (*pcVar5 == '\n') {
            pcVar5 = pcVar5 + 1;
          }
          *param_7 = (int)pcVar5 - param_4;
          if (0x15 < (int)pcVar2 - (int)pcVar8) {
            memw();
            iVar9 = (*(code *)&SUB_4008b33c)(pcVar8,&DAT_3f422278,0x16);
            if (iVar9 == 0) {
              cVar6 = pcVar1[0x17];
              if (cVar6 == '\r') goto LAB_401398d4;
              pcVar5 = pcVar1 + 0x17;
              goto LAB_401398b2;
            }
          }
          pcVar5 = (char *)0x0;
          pcVar1 = pcVar5;
          goto LAB_401399c1;
        }
      }
    }
  }
LAB_401398b8:
  pcVar2 = pcStack_24;
  memw();
  memw();
  if (pcStack_24 == _DAT_3ffc5708) {
    return iVar9;
  }
  (*(code *)&SUB_40082ec4)();
LAB_401398d4:
  pcVar5 = pcVar1 + 0x18;
  cVar6 = pcVar1[0x18];
LAB_401398b2:
  if (cVar6 == '\n') goto LAB_401398de;
  goto LAB_401398b5;
LAB_401398de:
  pcVar8 = pcVar5 + 1;
  iVar9 = -0x1280;
  if ((int)pcVar2 - (int)pcVar8 < 0xe) goto LAB_401398b8;
  iVar9 = (*(code *)&SUB_4008b33c)(pcVar8,"CRYPTED",0xe);
  if ((iVar9 != 0) || ((int)pcVar2 - (int)pcVar8 < 0x16)) {
    iVar9 = -0x1280;
    goto LAB_401398b8;
  }
  iVar9 = (*(code *)&SUB_4008b33c)(pcVar8,"o: AES-",0x16);
  if (iVar9 == 0) {
    pcVar1 = &DAT_00000005;
  }
  else {
    iVar9 = (*(code *)&SUB_4008b33c)(pcVar8,"28-CBC,",0x16);
    if (iVar9 == 0) {
      pcVar1 = &DAT_00000006;
    }
    else {
      iVar3 = (*(code *)&SUB_4008b33c)(pcVar8,"92-CBC,",0x16);
      iVar9 = -0x1280;
      if (iVar3 != 0) goto LAB_401398b8;
      pcVar1 = &DAT_00000007;
    }
  }
  if ((int)pcVar2 - (int)(pcVar5 + 0x17) < 0x20) {
LAB_40139944:
    iVar9 = -0x1200;
    goto LAB_401398b8;
  }
  (*(code *)&SUB_4008b530)(local_34,0,0x10);
  cVar6 = pcVar5[0x17];
  bVar7 = cVar6 - 0x30;
  if (9 < bVar7) {
    if ((byte)(cVar6 + 0xbfU) < 6) {
      bVar7 = cVar6 - 0x37;
    }
    else {
      if (5 < (byte)(cVar6 + 0x9fU)) goto LAB_40139944;
      bVar7 = cVar6 + 0xa9;
    }
  }
  local_34[0] = bVar7 << 4 | local_34[0];
  memw();
  pcVar8 = pcVar5 + 0x38;
  if (pcVar5[0x37] != '\r') {
    pcVar8 = pcVar5 + 0x37;
  }
  if (*pcVar8 != '\n') {
LAB_401398b5:
    iVar9 = -0x1100;
    goto LAB_401398b8;
  }
  pcVar8 = pcVar8 + 1;
  pcVar5 = (char *)0x1;
LAB_401399c1:
  if (pcVar2 <= pcVar8) goto LAB_401398b5;
  memw();
  iVar3 = FUN_40131340(0,0,&uStack_38,pcVar8,(int)pcVar2 - (int)pcVar8);
  iVar9 = -0x112c;
  if (iVar3 == -0x2c) goto LAB_401398b8;
  pbVar4 = (byte *)FUN_4013ae30(1,uStack_38);
  iVar9 = -0x1180;
  if (pbVar4 == (byte *)0x0) goto LAB_401398b8;
  iVar9 = FUN_40131340(pbVar4,uStack_38,&uStack_38,pcVar8,(int)pcVar2 - (int)pcVar8);
  if (iVar9 != 0) {
    FUN_4013ae54(pbVar4,uStack_38);
    FUN_4013ae44(pbVar4);
    iVar9 = iVar9 + -0x1100;
    goto LAB_401398b8;
  }
  if (pcVar5 == (char *)0x0) goto LAB_40139abe;
  if (param_5 == 0) {
    FUN_4013ae54(pbVar4,uStack_38);
    FUN_4013ae44(pbVar4);
    iVar9 = -0x1300;
    goto LAB_401398b8;
  }
  if (pcVar1 == &DAT_00000005) {
    uVar10 = 0x10;
LAB_40139a5d:
    iVar9 = FUN_4013967c(local_34,uVar10,pbVar4,uStack_38,param_5,param_6);
    if (iVar9 != 0) {
      memw();
      FUN_4013ae44(pbVar4);
      goto LAB_401398b8;
    }
  }
  else {
    if (pcVar1 == &DAT_00000006) {
      uVar10 = 0x18;
      goto LAB_40139a5d;
    }
    if (pcVar1 == &DAT_00000007) {
      uVar10 = 0x20;
      goto LAB_40139a5d;
    }
  }
  if (((uStack_38 < 3) || (param_5 = (uint)*pbVar4, param_5 != 0x30)) ||
     (param_5 = 0x83, 0x83 < pbVar4[1])) {
    FUN_4013ae54(pbVar4);
    FUN_4013ae44(pbVar4);
    iVar9 = -0x1380;
    goto LAB_401398b8;
  }
LAB_40139abe:
  *param_1 = pbVar4;
  param_1[1] = uStack_38;
  memw();
  iVar9 = 0;
  goto LAB_401398b8;
}

