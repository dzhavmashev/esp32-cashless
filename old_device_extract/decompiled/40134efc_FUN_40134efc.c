// Function : FUN_40134efc
// Address  : 0x40134efc
// Size     : 43 bytes


int FUN_40134efc(int param_1,undefined4 param_2)

{
  int iVar1;
  
  do {
    iVar1 = FUN_401860ec(param_2,param_1 + 4);
    if (iVar1 < 0) {
      return 0;
    }
    iVar1 = FUN_40131bcc(param_2,param_2,param_1 + 4);
  } while (iVar1 == 0);
  return iVar1;
}

