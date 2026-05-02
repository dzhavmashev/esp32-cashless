// Function : FUN_40143800
// Address  : 0x40143800
// Size     : 483 bytes


int FUN_40143800(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int iStack_54;
  int iStack_50;
  byte *pbStack_4c;
  int iStack_48;
  undefined1 auStack_44 [4];
  int iStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  int iStack_34;
  byte *pbStack_30;
  uint uStack_2c;
  int iStack_28;
  byte *pbStack_24;
  
  *param_2 = 4;
  *param_3 = 4;
  *param_4 = 0x14;
  iVar5 = -0x2362;
  if (*param_1 != 0x30) goto LAB_40143824;
  iStack_54 = param_1[2];
  iVar2 = iStack_54 + param_1[1];
  if (iStack_54 == iVar2) {
LAB_40143822:
    iVar5 = 0;
    goto LAB_40143824;
  }
  iVar5 = FUN_40141738(&iStack_54,iVar2,&iStack_50,0xa0);
  if (iVar5 == 0) {
    iVar3 = iStack_54 + iStack_50;
    iVar5 = FUN_401437cc(&iStack_54,iVar3,auStack_44);
    if (iVar5 != 0) goto LAB_40143824;
    iVar5 = FUN_401395a4(auStack_44,param_2);
    if (iVar5 != 0) goto LAB_4014385c;
    if (iStack_54 == iVar3) goto LAB_40143873;
LAB_40143867:
    iVar5 = -0x2366;
  }
  else {
    if (iVar5 != -0x62) goto LAB_4014385c;
LAB_40143873:
    if (iStack_54 == iVar2) goto LAB_40143822;
    iVar5 = FUN_40141738(&iStack_54,iVar2,&iStack_50,0xa1);
    if (iVar5 == 0) {
      iVar3 = iStack_54 + iStack_50;
      iVar5 = FUN_401437e4(&iStack_54,iVar3,auStack_44,&iStack_38);
      if ((iVar5 != 0) || (iVar5 = -0x20ae, iStack_40 != 9)) goto LAB_40143824;
      iVar1 = (*(code *)&SUB_4008b33c)("_common",uStack_3c);
      iVar5 = -0x20ae;
      if ((iVar1 != 0) || (iVar5 = -0x2362, iStack_38 != 0x30)) goto LAB_40143824;
      pbVar4 = pbStack_30 + iStack_34;
      pbStack_4c = pbStack_30;
      iVar5 = -0x2360;
      if (pbVar4 <= pbStack_30) goto LAB_40143824;
      uStack_2c = (uint)*pbStack_30;
      memw();
      iVar5 = FUN_40141738(&pbStack_4c,pbVar4,&iStack_28,6);
      if (iVar5 == 0) {
        pbStack_24 = pbStack_4c;
        pbStack_4c = pbStack_4c + iStack_28;
        memw();
        iVar5 = FUN_401395a4(&uStack_2c,param_3);
        if (iVar5 != 0) goto LAB_401438f4;
        if (pbVar4 != pbStack_4c) {
          iVar5 = FUN_40141738(&pbStack_4c,pbVar4,&iStack_48,5);
          if (iVar5 != 0 || iStack_48 != 0) goto LAB_401438f4;
          if (pbVar4 != pbStack_4c) goto LAB_40143867;
        }
      }
      else {
LAB_401438f4:
        iVar5 = iVar5 + -0x2300;
        if (iVar5 != 0) goto LAB_40143824;
      }
      if (iStack_54 != iVar3) goto LAB_40143867;
    }
    else if (iVar5 != -0x62) goto LAB_4014385c;
    if (iStack_54 == iVar2) goto LAB_40143822;
    iVar5 = FUN_40141738(&iStack_54,iVar2,&iStack_50,0xa2);
    if (iVar5 == 0) {
      iVar3 = iStack_54 + iStack_50;
      iVar5 = FUN_4014180c(&iStack_54,iVar3,param_4);
      if (iVar5 == 0) {
        if (iStack_54 != iVar3) goto LAB_40143867;
LAB_40143934:
        if (iStack_54 == iVar2) goto LAB_40143822;
        iVar5 = FUN_40141738(&iStack_54,iVar2,&iStack_50,0xa3);
        if (iVar5 == 0) {
          iVar3 = iStack_54 + iStack_50;
          iVar5 = FUN_4014180c(&iStack_54,iVar3,&uStack_2c);
          if (iVar5 == 0) {
            iVar5 = -0x2366;
            if ((iStack_54 != iVar3) || (iVar5 = -0x2300, uStack_2c != 1)) goto LAB_40143824;
LAB_40143975:
            if (iStack_54 == iVar2) goto LAB_40143822;
            goto LAB_40143867;
          }
        }
        else if (iVar5 == -0x62) goto LAB_40143975;
      }
    }
    else if (iVar5 == -0x62) goto LAB_40143934;
LAB_4014385c:
    iVar5 = iVar5 + -0x2300;
  }
LAB_40143824:
  memw();
  return iVar5;
}

