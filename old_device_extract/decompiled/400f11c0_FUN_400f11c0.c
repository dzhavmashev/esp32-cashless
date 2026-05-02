// Function : FUN_400f11c0
// Address  : 0x400f11c0
// Size     : 83 bytes


bool FUN_400f11c0(char *param_1,char *param_2)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_40184778(param_1);
  if (iVar2 == 0) {
    bVar1 = true;
    if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
      bVar1 = false;
    }
  }
  else if (param_2 == (char *)0x0) {
    if (-1 < param_1[0xf]) {
      param_1 = *(char **)param_1;
    }
    bVar1 = *param_1 == '\0';
  }
  else {
    if (-1 < param_1[0xf]) {
      param_1 = *(char **)param_1;
    }
    iVar2 = func_0x4008bdf4(param_1,param_2);
    bVar1 = iVar2 == 0;
  }
  return bVar1;
}

