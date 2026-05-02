// Function : FUN_40113c24
// Address  : 0x40113c24
// Size     : 241 bytes


undefined1 FUN_40113c24(int param_1,int param_2,uint *param_3,undefined2 param_4)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint auStack_38 [14];
  
  if ((param_3 == (uint *)0x0 || param_2 == 0) || (param_1 == 0)) {
    return 0xf0;
  }
  if ((*(char *)(param_1 + 0x14) != '.') && (*(char *)(param_1 + 0x14) != (char)param_3[5])) {
    return 0xfa;
  }
  if (((((char)param_3[5] == '\x06') && (uVar4 = *param_3, uVar2 = FUN_40109eec(0), uVar4 == uVar2))
      && (uVar4 = param_3[1], uVar2 = FUN_40109eec(0), uVar4 == uVar2)) &&
     (uVar4 = param_3[2], uVar2 = FUN_40109eec(0xffff), uVar4 == uVar2)) {
    auStack_38[0] = param_3[3];
    memw();
    uVar1 = FUN_40113c24(param_1,param_2,auStack_38,param_4);
    return uVar1;
  }
  if (*(char *)(param_1 + 0x30) == '\0') {
    if ((char)param_3[5] == '\x06') {
      if ((*param_3 & 0xff) == 0xff) {
LAB_40113ccd:
        if (*(char *)(param_1 + 0x44) == '\0') {
          if ((char)param_3[5] == '\0') {
            if ((*(int *)(param_1 + 0x40) == 0) || (*(int *)(param_1 + 0x40) == 0x615f7264))
            goto LAB_40113cf6;
            iVar3 = FUN_401167b0(param_1,param_1 + 0x40);
            goto LAB_40113cd8;
          }
        }
        else {
          iVar3 = FUN_4010b938();
LAB_40113cd8:
          if (iVar3 != 0) goto LAB_40113cda;
        }
        if ((char)param_3[5] != '\x06') goto LAB_40113cf6;
      }
      iVar3 = FUN_401172d4(param_1,param_3);
    }
    else {
      if ((*param_3 & 0xf0) == 0xe0) goto LAB_40113ccd;
LAB_40113cf6:
      iVar3 = FUN_401167b0(param_1,param_3);
    }
  }
  else {
    iVar3 = FUN_4010b938();
  }
  if (iVar3 == 0) {
    return 0xfc;
  }
LAB_40113cda:
  uVar1 = FUN_40113b68(param_1,param_2,param_3,param_4,iVar3);
  return uVar1;
}

