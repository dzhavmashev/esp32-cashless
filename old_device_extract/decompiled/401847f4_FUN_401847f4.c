// Function : FUN_401847f4
// Address  : 0x401847f4
// Size     : 47 bytes


int FUN_401847f4(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar2 = 0;
  while (iVar4 = iVar2, cVar1 = *(char *)(param_1 + iVar4), cVar1 != '\0') {
    if ((cVar1 == '/') || (iVar2 = iVar4 + 1, cVar1 == '\\')) {
      iVar3 = iVar4 + 1;
      iVar2 = iVar3;
    }
  }
  return param_1 + iVar3;
}

