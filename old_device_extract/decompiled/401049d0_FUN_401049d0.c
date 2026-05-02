// Function : FUN_401049d0
// Address  : 0x401049d0
// Size     : 51 bytes


undefined4 FUN_401049d0(char *param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  
  cVar1 = *param_1;
  if (param_2 != 0) {
    if (cVar1 == '0') {
      uVar2 = FUN_40105cf0();
      return uVar2;
    }
    if (cVar1 == -0xc) {
      uVar2 = FUN_40105cc0();
      return uVar2;
    }
  }
  uVar2 = 0;
  if (cVar1 != 'D') {
    uVar2 = FUN_40105eec(param_1,param_2,param_3);
  }
  return uVar2;
}

