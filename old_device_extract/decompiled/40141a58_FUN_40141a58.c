// Function : FUN_40141a58
// Address  : 0x40141a58
// Size     : 74 bytes


int FUN_40141a58(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iStack_2c;
  int iStack_28;
  
  (*(code *)&SUB_4008b530)(&iStack_2c,0,0xc);
  iVar1 = FUN_401419c8(param_1,param_2,param_3,&iStack_2c);
  if (iVar1 == 0) {
    if ((iStack_2c == 5) || (iStack_2c == 0)) {
      if (iStack_28 != 0) {
        iVar1 = -0x68;
      }
    }
    else {
      iVar1 = -0x68;
    }
  }
  return iVar1;
}

