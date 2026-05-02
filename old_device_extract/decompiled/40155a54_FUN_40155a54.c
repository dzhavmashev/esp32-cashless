// Function : FUN_40155a54
// Address  : 0x40155a54
// Size     : 703 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40155a54(int param_1,int param_2,int param_3,undefined1 param_4,undefined2 param_5,
                 undefined4 param_6,byte param_7)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 uVar5;
  byte bVar6;
  char *pcVar7;
  int iVar8;
  undefined4 uVar9;
  uint uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  uint uStack_54;
  int iStack_30;
  uint uStack_2c;
  int iStack_28;
  
  uStack_2c = (uint)param_7;
  memw();
  (*(code *)&SUB_4008b3d0)(param_1 + 4,param_2 + 10,6);
  iStack_28 = param_1 + 10;
  memw();
  (*(code *)&SUB_4008b530)(iStack_28,0,0x20);
  iVar2 = FUN_40186a1c(*(undefined4 *)(param_3 + 0x24));
  if (iVar2 == 0) {
    *(undefined1 *)(param_1 + 0x2f) = 0;
    memw();
    memw();
    (*(code *)&SUB_4008c0f8)
              (iStack_28,*(int *)(param_3 + 0x24) + 2,*(undefined1 *)(*(int *)(param_3 + 0x24) + 1))
    ;
    uVar5 = *(undefined1 *)(*(int *)(param_3 + 0x24) + 1);
  }
  else {
    *(undefined1 *)(param_1 + 0x2f) = 1;
    memw();
    uVar5 = 0;
    memw();
  }
  *(undefined1 *)(param_1 + 0x2a) = uVar5;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  memw();
  pcVar7 = *(char **)(param_3 + 0x48);
  if (pcVar7 != (char *)0x0) {
    if (*pcVar7 == -0x23) {
      pcVar7 = pcVar7 + 4;
    }
    if ((pcVar7[3] & 4U) != 0) {
      bVar6 = pcVar7[3] & 3;
      if (bVar6 == 1) {
        memw();
        uVar5 = 1;
      }
      else {
        if (bVar6 != 3) goto LAB_40155afc;
        uVar5 = 2;
      }
      *(undefined1 *)(param_1 + 0x2c) = uVar5;
      memw();
    }
  }
LAB_40155afc:
  uVar5 = *(undefined1 *)(param_3 + 4);
  *(undefined1 *)(param_1 + 0x2d) = param_4;
  *(undefined1 *)(param_1 + 0x2b) = uVar5;
  memw();
  uVar1 = *(undefined2 *)(param_3 + 0x72);
  iVar2 = *(int *)(param_3 + 0x34);
  *(undefined2 *)(param_1 + 0x30) = param_5;
  *(undefined2 *)(param_1 + 0x32) = uVar1;
  memw();
  uVar3 = 0;
  uVar4 = 0;
  if (iVar2 != 0) {
    if ((_DAT_3ffc89a4 == 0) || (*(code **)(_DAT_3ffc89a4 + 0x3c) == (code *)0x0)) {
      FUN_40147fe4(1,8,1,"_wpa_ie");
    }
    else {
      memw();
      (**(code **)(_DAT_3ffc89a4 + 0x3c))(iVar2,*(byte *)(iVar2 + 1) + 2,&uStack_60);
    }
    *(undefined4 *)(param_1 + 0x40) = uStack_5c;
    *(undefined4 *)(param_1 + 0x44) = uStack_58;
    uVar3 = uStack_60;
    uVar4 = uStack_54;
  }
  iVar2 = *(int *)(param_3 + 0x3c);
  if (iVar2 != 0) {
    if ((_DAT_3ffc89a4 == 0) || (*(code **)(_DAT_3ffc89a4 + 0x3c) == (code *)0x0)) {
      FUN_40147fe4(1,8,1,"");
    }
    else {
      memw();
      (**(code **)(_DAT_3ffc89a4 + 0x3c))(iVar2,*(byte *)(iVar2 + 1) + 2,&uStack_60);
    }
    uVar3 = uVar3 | uStack_60;
    *(undefined4 *)(param_1 + 0x40) = uStack_5c;
    *(undefined4 *)(param_1 + 0x44) = uStack_58;
    uVar4 = uStack_54;
  }
  iVar2 = *(int *)(param_3 + 0x38);
  if (((iVar2 != 0) && (_DAT_3ffc8a64 != 0)) && (*(code **)(_DAT_3ffc8a64 + 4) != (code *)0x0)) {
    memw();
    iVar2 = (**(code **)(_DAT_3ffc8a64 + 4))(iVar2,*(char *)(iVar2 + 1) + '\x02',&uStack_60);
    if (iVar2 == 0) {
      uVar3 = uVar3 | uStack_60;
      uVar4 = uStack_54;
    }
  }
  if ((uVar4 & 0xfffffefd) == 0) {
    if (uVar3 == 1) {
      uVar5 = 2;
    }
    else if ((int)uVar3 < 2) {
      if (uVar3 != 0) goto LAB_40155c73;
      if ((*(ushort *)(param_3 + 6) & 0x10) == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
    }
    else if (uVar3 == 2) {
      uVar5 = 3;
    }
    else {
      if (uVar3 != 3) goto LAB_40155c73;
      uVar5 = 4;
    }
  }
  else if (uVar4 == 0x1000) {
    uVar5 = 8;
  }
  else if ((uVar4 & 0x20000) == 0) {
    if ((uVar4 - 0x80 < 2) || (uVar4 == 1)) {
      if ((uVar3 & 3) == 0) goto LAB_40155c73;
      uVar5 = 5;
    }
    else if (uVar4 == 0x400) {
      if (uVar3 != 2) goto LAB_40155c73;
      uVar5 = 6;
    }
    else {
      if ((((uVar4 & 0xfffffeff) != 0x402) && (uVar4 != 0x500)) || (uVar3 != 2)) goto LAB_40155c73;
      uVar5 = 7;
    }
  }
  else {
    if ((uVar3 & 2) == 0) goto LAB_40155c73;
    uVar5 = 9;
  }
  *(undefined1 *)(param_1 + 0x2e) = uVar5;
  memw();
LAB_40155c73:
  if (*(int *)(param_3 + 0x50) != 0) {
    *(undefined1 *)(param_1 + 0x48) = 1;
    memw();
  }
  uVar3 = 0;
  iVar8 = *(int *)(param_3 + 0x28);
  iStack_30 = *(int *)(param_3 + 0x44);
  memw();
  for (iVar2 = iVar8; iVar2 - iVar8 < (int)(uint)*(byte *)(iVar8 + 1); iVar2 = iVar2 + 1) {
    if (*(byte *)(iVar2 + 2) == 0x82) {
      uVar3 = uVar3 | 1;
    }
    else if ((*(byte *)(iVar2 + 2) & 0x7f) == 0xc) {
      uVar3 = uVar3 | 2;
    }
  }
  if (*(int *)(param_3 + 0x2c) != 0) {
    uVar3 = uVar3 | 2;
  }
  if (iStack_30 != 0) {
    uVar3 = uVar3 | 4;
  }
  uVar9 = *(undefined4 *)(param_3 + 0x20);
  *(uint *)(param_1 + 0x4c) = uVar3;
  memw();
  FUN_40154f70(param_1,uVar9);
  *(char *)(param_1 + 0x5c) = (char)uStack_2c;
  memw();
  if ((*(code **)(_DAT_3ffc89a4 + 0x50) != (code *)0x0) &&
     (*(char *)(_DAT_3ffc8800 + 0x154) != '\x05')) {
    memw();
    (**(code **)(_DAT_3ffc89a4 + 0x50))
              (5,param_2 + 0x18,*(int *)(param_3 + 0x14) + 0xc,param_2 + 10,
               (int)*(char *)(param_1 + 0x2d),*(undefined1 *)(param_1 + 0x2b),0,0);
  }
  return;
}

