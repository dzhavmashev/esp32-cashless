// Function : FUN_4013a8c4
// Address  : 0x4013a8c4
// Size     : 267 bytes


int FUN_4013a8c4(undefined4 param_1,char *param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iStack_48;
  char *pcStack_44;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined1 auStack_38 [4];
  int iStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [44];
  
  if (param_5 == 0) {
    return -0x3c00;
  }
  memw();
  pcStack_44 = param_2;
  iVar1 = FUN_40141738(&pcStack_44,param_2 + param_3,&iStack_48,0x30);
  if (iVar1 == 0) {
    pcVar3 = pcStack_44 + iStack_48;
    iVar1 = FUN_401419c8(&pcStack_44,pcVar3,auStack_38,auStack_2c);
    if ((iVar1 == 0) &&
       (iVar1 = FUN_40141738(&pcStack_44,pcVar3,&iStack_48,4), pcVar3 = pcStack_44, iVar1 == 0)) {
      iVar1 = FUN_40139640(auStack_38,&uStack_3c,&local_40);
      if (iVar1 == 0) {
        memw();
        iVar1 = FUN_401430a4(auStack_2c,0,local_40,uStack_3c,param_4,param_5,pcStack_44,iStack_48,
                             pcVar3);
        if (iVar1 != 0) {
          iVar2 = -0x1e00;
LAB_4013a946:
          if (iVar1 == iVar2) {
            return -0x3b80;
          }
          return iVar1;
        }
      }
      else if (iStack_34 == 10) {
        iVar1 = (*(code *)&SUB_4008b33c)(&DAT_3f4223d8,uStack_30);
        if (iVar1 != 0) {
          return -0x3980;
        }
        memw();
        iVar1 = FUN_40142b1c(auStack_2c,0,param_4,param_5,pcStack_44,iStack_48,pcVar3);
        if (iVar1 != 0) {
          return iVar1;
        }
        if (*pcVar3 != '0') {
          return -0x3b80;
        }
      }
      else {
        if (iStack_34 != 9) {
          return -0x3980;
        }
        iVar1 = (*(code *)&SUB_4008b33c)(&DAT_3f4223e3,uStack_30);
        if (iVar1 != 0) {
          return -0x3980;
        }
        memw();
        iVar1 = FUN_40143530(auStack_2c,0,param_4,param_5,pcStack_44,iStack_48,pcVar3);
        if (iVar1 != 0) {
          iVar2 = -0x2e00;
          goto LAB_4013a946;
        }
      }
      iVar1 = FUN_4013a7f4(param_1,pcVar3,iStack_48);
      return iVar1;
    }
  }
  return iVar1 + -0x3d00;
}

