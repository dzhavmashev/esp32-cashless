// Function : FUN_4013a414
// Address  : 0x4013a414
// Size     : 97 bytes


int FUN_4013a414(undefined4 param_1,undefined4 param_2,int *param_3,int *param_4)

{
  int iVar1;
  undefined1 auStack_2c [44];
  
  (*(code *)&SUB_4008b530)(param_4,0,0xc);
  iVar1 = FUN_401419c8(param_1,param_2,auStack_2c,param_4);
  if (iVar1 == 0) {
    iVar1 = FUN_401394fc(auStack_2c,param_3);
    if (iVar1 == 0) {
      iVar1 = 0;
      if ((*param_3 == 1) && (((*param_4 != 5 && (*param_4 != 0)) || (param_4[1] != 0)))) {
        iVar1 = -0x3a80;
      }
    }
    else {
      iVar1 = -0x3c80;
    }
  }
  else {
    iVar1 = iVar1 + -0x3a80;
  }
  return iVar1;
}

