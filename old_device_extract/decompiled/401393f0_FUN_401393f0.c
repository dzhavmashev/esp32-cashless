// Function : FUN_401393f0
// Address  : 0x401393f0
// Size     : 41 bytes


int FUN_401393f0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = -0x5100;
  if ((((param_1 != (int *)0x0) && (*param_1 != 0)) && (iVar1 = param_1[2], iVar1 != 0)) &&
     (iVar2 = FUN_40139114(param_1), iVar2 == 0)) {
    iVar2 = FUN_40139174(param_1,iVar1,*(undefined1 *)(*param_1 + 9));
  }
  return iVar2;
}

